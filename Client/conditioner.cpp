#include "conditioner.h"



Conditioner::Conditioner(Settings* _set, const QString &_ip, const quint16 &_port, QObject *parent):
    QObject(parent),
    m_set(_set),
    m_ip(_ip),
    m_port(_port)
{



    m_map[ControlTypes::Conditioner::Temperature] = new Temperature(&ControlTypes::stringTypeTemperature,
                                                                ControlTypes::Conditioner::Temperature,
                                                                &ControlTypes::stateTemperature,
                                                                this);
    m_map[ControlTypes::Conditioner::Pressure] = new Pressure(&ControlTypes::stringTypePressure,
                                                              ControlTypes::Conditioner::Pressure,
                                                              &ControlTypes::statePressure,
                                                              this);


    m_map[ControlTypes::Conditioner::Humadity] = new Humadity(&ControlTypes::stringTypeHumadity,
                                                              ControlTypes::Conditioner::Humadity,
                                                             &ControlTypes::stateHumadity,
                                        this);


    m_map[ControlTypes::Conditioner::OnOff] = new Server(&ControlTypes::stringTypeServer,
                                                         ControlTypes::Conditioner::OnOff,
                                                         &ControlTypes::stateServer,
                                                         this);



    m_map[ControlTypes::Conditioner::Temperature]->slotChangeTypeValue(m_set->getTypeTemperature());
    m_map[ControlTypes::Conditioner::Pressure]->slotChangeTypeValue(m_set->getTypePressure());
    m_map[ControlTypes::Conditioner::Humadity]->slotChangeTypeValue(m_set->getTypeHumadity());

    QObject::connect(m_map[ControlTypes::Conditioner::Temperature], &ValueModel::changeTypeMeasurment, m_set, &Settings::setTypeTemperature);
    QObject::connect(m_map[ControlTypes::Conditioner::Pressure], &ValueModel::changeTypeMeasurment, m_set, &Settings::setTypePressure);

    com.reserve(5);//зарезервировал в отправляемом массиве 5 байт

    for(auto itb = ControlTypes::state.begin(), ite = ControlTypes::state.end(); itb != ite; ++itb)
    {
        if(m_map.contains(*itb))
        QObject::connect(m_map[*itb], &ValueModel::signalStateChanged, this, &Conditioner::slotChangeState);
    }
}

ValueModel *Conditioner::getDetector(ControlTypes::Conditioner type)
{
    if(m_map.contains(type))
    {
                qDebug() << "Подключение сигналов и слотов" << m_map[type]->getTypeDetector();
        return m_map[type];

    }
    qDebug() << "Unknown key " << type;
}



void Conditioner::sendCommand(const ControlTypes::Conditioner &typeParameter, const int value)
{
    qDebug() << typeParameter << " " << value << " " << sizeof(value);


    intToChar convert;
    convert.x = value;

    com[0] = static_cast<quint8>(typeParameter);
    com[1] = convert.ch[3];
    com[2] = convert.ch[2];
    com[3] = convert.ch[1];
    com[4] = convert.ch[0];

    emit sendCommandToServer(com, m_ip);
}

void Conditioner::responseFromServer(QString senderIP, int senderPort, QByteArray data)
{
    //Если порт и адрес не принадлежат серверу выходим
    Q_UNUSED(senderIP)
    Q_UNUSED(senderPort)
    if(data.size() != 5)
    {
        qDebug() << "Неверный формат пакета!!!";
        return;
    }

    ControlTypes::Conditioner tmp;
    intToChar convert;

    tmp = static_cast<ControlTypes::Conditioner>(data.at(0));

        for(int i = sizeof(int) - 1; i >= 0; i--)
        {
            convert.ch[i] = data.at(sizeof(int) - i);
        }

        qDebug() << tmp << " " << convert.x;
        if(m_map.contains(tmp))
        {
            m_map[tmp]->slotSetValue(convert.x);
        }



}

void Conditioner::slotChangeState()
{
     DeviceState tmp = DeviceState::Green;

    for(auto itb = ControlTypes::state.begin(), ite = ControlTypes::state.end(); itb != ite; ++itb)
    {
        if(m_map.contains(*itb))
            tmp = tmp + m_map[*itb]->getState();
    }

    emit signalChangeComlexState(tmp);

}


