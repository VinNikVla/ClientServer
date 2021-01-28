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

    m_temperature = 100;
    m_pressure = 0;
    m_humadity = 0;

    com.reserve(5);//зарезервировал в отправляемом массиве 3 байта

}

void Conditioner::changeValue(const ControlTypes::Conditioner &typeParameter, const double value)
{
    if(m_map.contains(typeParameter))
    {
            *(m_map[typeParameter]) = value;
            slotChangeTypeTemperature(typeTemperature);
    }
}

void Conditioner::slotChangeTypeTemperature(const QString& type)
{


    QString tmp;

   if(type == "°C")
   {
        tmp = QString::number(m_temperature) + " °C";
   }

   if(type == "K")
   {
        tmp = QString::number((m_temperature + 273.15)) + "  K";
   }

   if(type == "°F")
   {
        tmp = QString::number((m_temperature * 9 / 5 + 32)) + " °F";
   }

    typeTemperature = type;
    m_set->setTypeTemperature(type);
    emit signalTemperatureChanged(tmp);


}

void Conditioner::slotChangeTypePressure(const QString &type)
{
    QString tmp;
    if(type == "мм.рт.ст")
    {
        tmp = QString::number(m_pressure) + " " + type;
    }

    if(type == "Па")
    {
        tmp = QString::number(m_pressure * 133) + " " + type;
    }


    typePressure = type;
    m_set->setTypePressure(type);
    emit signalPressureChanged(tmp);

}

void Conditioner::sendCommand(const ControlTypes::Conditioner &typeParameter, const int value)
{
    qDebug() << typeParameter << " " << value << " " << sizeof(value);


    intToChar convert;
    convert.x = value;
    qDebug() << "1byte = " << convert.ch[0];
    qDebug() << "2byte = " << convert.ch[1];
    qDebug() << "3byte = " << convert.ch[2];
    qDebug() << "4byte = " << convert.ch[3];
    quint8 frst= value & 0x000000ff;
    quint8 second = value & 0x0000ff00;
    qDebug() << hex << frst << hex << second << hex << value;
    com[0] = static_cast<quint8>(typeParameter);
    com[1] = convert.ch[3];
    com[2] = convert.ch[2];
    com[3] = convert.ch[1];
    com[4] = convert.ch[0];

    emit sendCommandToServer(com, m_ip);
}

