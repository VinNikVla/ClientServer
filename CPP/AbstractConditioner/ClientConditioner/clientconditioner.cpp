#include "clientconditioner.h"

ClientConditioner::ClientConditioner(Settings *_set, QObject *parent):
    AbstractConditioner(parent),
    m_set(_set)
{
    m_client = new UDPclient("127.0.0.1", "127.0.0.1", 1112, this, 1111);

    QObject::connect(this, &ClientConditioner::signalSendRequest, m_client, &UDPclient::sendDataTo);
    QObject::connect(m_client,&UDPclient::receiveData, this, &ClientConditioner::slotResponse);

    m_map[ControlTypes::Conditioner::Temperature] = new ChangeMeasurment(&ControlTypes::measurmentsTemperature,
                                                                         &ControlTypes::stateTemperature,
                                                                         ControlTypes::Conditioner::Temperature,
                                                                         this);


    m_map[ControlTypes::Conditioner::Pressure] = new ChangeMeasurment(&ControlTypes::measurmentsPressure,
                                                                      &ControlTypes::statePressure,
                                                                      ControlTypes::Conditioner::Pressure,
                                                                      this);



    m_map[ControlTypes::Conditioner::Humadity] = new ChangeMeasurment(&ControlTypes::measurmentsHumadity,
                                                                      &ControlTypes::stateHumadity,
                                                                      ControlTypes::Conditioner::Humadity,
                                                                      this);


    m_map[ControlTypes::Conditioner::OnOff] = new AbstractValueModel(ControlTypes::Conditioner::OnOff,
                                                                     this);

    m_map[ControlTypes::Conditioner::Direction] = new AbstractValueModel(ControlTypes::Conditioner::Direction,
                                                                         this);

    m_map[ControlTypes::Conditioner::RequestParameters] = new AbstractValueModel(ControlTypes::Conditioner::RequestParameters,
                                                                                 this);

    for(auto itb = ControlTypes::state.begin(), ite = ControlTypes::state.end(); itb != ite; ++itb)
    {
        if(m_map.contains(*itb))
        QObject::connect(static_cast<ChangeState*>(m_map[*itb]), &ChangeState::signalStateChanged, this, &ClientConditioner::slotChangeState);
    }

    connectSettings();

}

void ClientConditioner::slotChangeState()
{
    DeviceState tmp = DeviceState::Green;

    for(auto itb = ControlTypes::state.begin(), ite = ControlTypes::state.end(); itb != ite; ++itb)
    {

        if(m_map.contains(*itb))
            tmp = tmp + static_cast<ChangeState*>(m_map[*itb])->getState();
    }

    emit signalChangeComplexState(tmp);
}

void ClientConditioner::connectSettings()
{

    static_cast<ChangeMeasurment*>(m_map[ControlTypes::Conditioner::Pressure])->slotChangeTypeMeasurments(m_set->getTypePressure());
    static_cast<ChangeMeasurment*>(m_map[ControlTypes::Conditioner::Temperature])->slotChangeTypeMeasurments(m_set->getTypeTemperature());
    static_cast<ChangeMeasurment*>(m_map[ControlTypes::Conditioner::Humadity])->slotChangeTypeMeasurments("%");
    QObject::connect(static_cast<ChangeMeasurment*>(m_map[ControlTypes::Conditioner::Temperature]),
                     &ChangeMeasurment::signalChangeTypeMeasurments,
                     m_set,
                     &Settings::setTypeTemperature);

    QObject::connect(static_cast<ChangeMeasurment*>(m_map[ControlTypes::Conditioner::Pressure]),
                     &ChangeMeasurment::signalChangeTypeMeasurments,
                     m_set,
                     &Settings::setTypePressure);

}
