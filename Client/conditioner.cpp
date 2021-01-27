#include "conditioner.h"


Conditioner::Conditioner(Settings* _set, const QString &_ip, const quint16 &_port, QObject *parent):
    QObject(parent),
    m_set(_set),
    m_ip(_ip),
    m_port(_port)
{
    m_map[ControlTypes::Conditioner::Temperature] =  &m_temperature;

    m_map[ControlTypes::Conditioner::Humadity] =  &m_humadity;

    m_map[ControlTypes::Conditioner::Pressure] =  &m_pressure;

    typeTemperature = m_set->getTypeTemperature();
    typePressure = m_set->getTypePressure();
    m_temperature = 100;
    m_pressure = 0;
    m_humadity = 0;




}

void Conditioner::changeValue(const ControlTypes::Conditioner &typeParameter, const double value)
{
    if(m_map.contains(typeParameter))
    {
            *(m_map[typeParameter]) = value;
            unitConverter(typeTemperature);
    }
}

void Conditioner::changeTypeMeasurementsTemperature(const QString& type)
{

        if(type == "K")
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



}

void Conditioner::changeTypePressure(const QString &type)
{
    if(type == "мм.рт.ст")
    {
        convertPressure(ControlTypes::TypeDisplayPressure::MillimetersOfMercury);
    }

    if(type == "Па")
    {
        convertPressure(ControlTypes::TypeDisplayPressure::Pascal);
    }

}

void Conditioner::unitConverter(const ControlTypes::TypeDisplayTemperature type)
{

    QString tmp;
    switch (type) {
    case ControlTypes::TypeDisplayTemperature::Celsius:
        tmp = QString::number(m_temperature) + " °C";
        break;
    case ControlTypes::TypeDisplayTemperature::Kelvin:
        tmp = QString::number((m_temperature + 273.15)) + "  K";
        break;
    case ControlTypes::TypeDisplayTemperature::Fahrenheit:
        tmp = QString::number((m_temperature * 9 / 5 + 32)) + " °F";
        break;
    default:
        qDebug() << "Unknown type measurement";
        break;
    }

    typeTemperature = type;
    m_set->setTypeTemperature(type);
    emit signalTemperatureChanged(tmp);

}

void Conditioner::convertPressure(const ControlTypes::TypeDisplayPressure type)
{
    QString tmp;
    switch (type) {
    case ControlTypes::TypeDisplayPressure::MillimetersOfMercury:
        tmp = QString::number(m_pressure) + " " + "мм.рт.ст";
        break;
    case ControlTypes::TypeDisplayPressure::Pascal:
        tmp = QString::number((m_pressure * 133)) + " " + "Па";
        break;
    default:
        qDebug() << "Unknown type measurement";
        break;
    }

    typePressure = type;
    m_set->setTypePressure(type);
    emit signalPressureChanged(tmp);
}
