#include "conditioner.h"


Conditioner::Conditioner(Settings* set, const QString &_ip, const quint16 &_port, QObject *parent):
    QObject(parent),
    m_ip(_ip),
    m_port(_port)
{
    m_map[ControlTypes::Conditioner::Temperature] =  &m_temperature;

    m_map[ControlTypes::Conditioner::Humadity] =  &m_humadity;

    m_map[ControlTypes::Conditioner::Pressure] =  &m_pressure;
    typePressure = ControlTypes::TypeDisplayPressure::MillimetersOfMercury;//set->getTypePressure;
    //typeTemperature = set->getTypeTemperature;
    m_temperature = 0;
    m_pressure = 0;
    m_humadity = 0;


}

void Conditioner::changeValue(const ControlTypes::Conditioner &typeParameter, const double value)
{
    if(m_map.contains(typeParameter))
    {
            *(m_map[typeParameter]) = value;
    }
}

void Conditioner::changeChangeTypeMeasurements(const ControlTypes::Conditioner &sensor, const QString &type)
{
    if(sensor == ControlTypes::Conditioner::Temperature)
    {
        if(type == " K")
        {
            unitConverter(ControlTypes::TypeDisplayTemperature::Kelvin);
        }

        if(type == "°C")
        {
            unitConverter(ControlTypes::TypeDisplayTemperature::Celsius);
        }

        if(type == "°F")
        {
            unitConverter(ControlTypes::TypeDisplayTemperature::Fahrenheit);
        }
        ;
    }


}

void Conditioner::unitConverter(const ControlTypes::TypeDisplayTemperature type)
{
    if(typeTemperature == type)
        return;

    QString tmp;
    switch (type) {
    case ControlTypes::TypeDisplayTemperature::Celsius:
        tmp = QString::number(m_temperature) + "°C";
        typeTemperature = type;
        break;
    case ControlTypes::TypeDisplayTemperature::Kelvin:
        tmp = QString::number((m_temperature + 273.15)) + "°C";
        break;
    case ControlTypes::TypeDisplayTemperature::Fahrenheit:
        tmp = QString::number((m_temperature * 9 / 5 + 32)) + "°F";
        break;
    default:
        break;
    }

    typeTemperature = type;

    emit signalValueChanged(tmp);

}
