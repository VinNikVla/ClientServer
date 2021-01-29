#include "conditioner.h"



Conditioner::Conditioner(Settings* _set, const QString &_ip, const quint16 &_port, QObject *parent):
    QObject(parent),
    m_set(_set),
    m_ip(_ip),
    m_port(_port)
{

    Temperature* m_temperature = new Temperature(&ControlTypes::stringTypeTemperature,
                                                ControlTypes::Conditioner::Temperature,
                                                &ControlTypes::stateTemperature,
                                                this);
    m_map[m_temperature->getTypeDetector()] = m_temperature;

    Pressure* m_pressure = new Pressure(&ControlTypes::stringTypePressure,
                                          ControlTypes::Conditioner::Pressure,
                                          &ControlTypes::statePressure,
                                          this);

    m_map[m_pressure->getTypeDetector()] = m_pressure;

    Humadity* m_humadity = new Humadity(&ControlTypes::stringTypeHumadity,
                                        ControlTypes::Conditioner::Humadity,
                                        &ControlTypes::stateHumadity,
                                        this);

    m_map[m_humadity->getTypeDetector()] = m_humadity;

    m_temperature->slotChangeTypeValue(m_set->getTypeTemperature());
    m_humadity->slotChangeTypeValue(m_set->getTypeHumadity());
    m_pressure->slotChangeTypeValue(m_set->getTypePressure());

    com.reserve(5);//зарезервировал в отправляемом массиве 5 байта


}

ValueModel *Conditioner::getDetector(ControlTypes::Conditioner type)
{
    if(m_map.contains(type))
    {
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
    ControlTypes::Conditioner tmp;
    intToChar convert;

    tmp = static_cast<ControlTypes::Conditioner>(data.at(0));
    if(data.size() == 5)
    {
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
    else
    {
        qDebug() << "Неверный формат пакета!!!";
    }


}

