#include "serverconditioner.h"

ServerConditioner::ServerConditioner(QObject *parent):
    AbstractConditioner(parent)
{
    m_server = new UDPCLient("127.0.0.1", 1112, "127.0.0.1", 1111, this);

    QObject::connect(this, &ServerConditioner::signalSendRequest, m_server, &UDPCLient::sendDataTo);
    QObject::connect(m_server, &UDPCLient::receiveData, this, &ServerConditioner::slotResponse);

    m_map[ControlTypes::Conditioner::Temperature] = new AbstractValueModel(ControlTypes::Conditioner::Temperature,
                                                                           this);
    m_map[ControlTypes::Conditioner::Temperature]->slotSetValue(5);

    m_map[ControlTypes::Conditioner::Pressure] = new AbstractValueModel(ControlTypes::Conditioner::Pressure,
                                                                        this);

    m_map[ControlTypes::Conditioner::Pressure]->slotSetValue(0);

    m_map[ControlTypes::Conditioner::Humadity] = new AbstractValueModel(ControlTypes::Conditioner::Humadity,
                                                                        this);
    m_map[ControlTypes::Conditioner::Humadity]->slotSetValue(0);

    m_map[ControlTypes::Conditioner::OnOff] = new AbstractValueModel(ControlTypes::Conditioner::OnOff,
                                                                     this);
    m_map[ControlTypes::Conditioner::OnOff]->slotSetValue(0);


    m_map[ControlTypes::Conditioner::Direction] = new ChangeMeasurment(&ControlTypes::measurmentsDirection,
                                                                       &ControlTypes::stateDirection,
                                                                       ControlTypes::Conditioner::Direction,
                                                                       this);

    static_cast<ChangeMeasurment*>(m_map[ControlTypes::Conditioner::Direction])->slotChangeTypeMeasurments("°");
    m_map[ControlTypes::Conditioner::Direction]->slotSetValue(10);

    m_map[ControlTypes::Conditioner::RequestParameters] = new AbstractValueModel(ControlTypes::Conditioner::RequestParameters,
                                                                                 this);

    QObject::connect(m_map[ControlTypes::Conditioner::RequestParameters], &AbstractValueModel::signalChangeValue, this, &ServerConditioner::requestParameters);
    //QObject::connect(m_map[ControlTypes::Conditioner::RequestParameters], &AbstractValueModel::signalChangeValue, this, &ServerConditioner::firstConnection);

    for(auto itb = m_map.begin(), ite = m_map.end();itb != ite; ++itb)
    {
        if(itb.key() != ControlTypes::Conditioner::RequestParameters)
        {
        QObject::connect(itb.value(), &AbstractValueModel::signalChangeValue, this, &ServerConditioner::slotRequest);
        }
    }

}

const QMap<ControlTypes::Conditioner, AbstractValueModel *> *ServerConditioner::getPointerToMap()
{
    return &m_map;
}

void ServerConditioner::requestParameters(const ControlTypes::Conditioner &type, const int value)
{
    Q_UNUSED(value);

        for(auto itb = m_map.begin(), ite = m_map.end(); itb != ite; ++itb)
        {
            qDebug() << itb.key() << *(itb.value()->getValue());
            if(itb.key() != ControlTypes::Conditioner::RequestParameters)
            {
                emit itb.value()->signalChangeValue(itb.value()->getTypeDetector(), *(itb.value()->getValue()));
            }
        }
}

