#include "conditionerserver.h"

ConditionerServer::ConditionerServer(const UDPclient *udpSender, QObject *parent):
    QObject(parent)
{
    QObject::connect(this, &ConditionerServer::sendResponseToClient, udpSender, &UDPclient::sendDataTo);
    QObject::connect(udpSender, &UDPclient::receiveData, this, &ConditionerServer::requestFromClient);

    m_state = ControlTypes::Server::OFF;

    sendCommandToClient(ControlTypes::Conditioner::OnOff, static_cast<int>(m_state));

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

    for(auto itb = ControlTypes::command.begin(), ite = ControlTypes::command.end(); itb != ite; ++itb)
    {
        QObject::connect(this->m_map[*itb], &ValueModel::signalValueToClient, this, &ConditionerServer::sendCommandToClient);
    }


}

ValueModel *ConditionerServer::getDetector(ControlTypes::Conditioner type)
{
    if(m_map.contains(type))
    {
                qDebug() << "Подключение сигналов и слотов логика" << m_map[type]->getTypeDetector();
        return m_map[type];


    }
    qDebug() << "Unknown key " << type;
}

void ConditionerServer::sendCommandToClient(const ControlTypes::Conditioner &typeParameter, const int value)
{
    qDebug() << typeParameter << " " << value << " " << sizeof(value);


    intToChar convert;
    convert.x = value;

    com[0] = static_cast<quint8>(typeParameter);
    com[1] = convert.ch[3];
    com[2] = convert.ch[2];
    com[3] = convert.ch[1];
    com[4] = convert.ch[0];

    emit sendResponseToClient(com);
}

void ConditionerServer::requestFromClient(QString senderIP, int senderPort, QByteArray data)
{
    //Если порт и адрес не принадлежат серверу выходим
//    if(senderIP != m_IP && senderPort != m_Port)
//    {
//        qDebug() << "Попыка управления кондиционером с не установленного IP";
//        return;
//    }

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
