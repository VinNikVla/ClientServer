#include "temperature.h"


Temperature::Temperature(const QVector<QString> *_listMeasurments, const ControlTypes::Conditioner &_typeDetector, const QVector<int> *_border, QObject *parent):
  ValueModel(_listMeasurments, _typeDetector, _border, parent)
{
//    m_value = 0;
}

void Temperature::slotChangeTypeValue(const QString &type)
{
    if(!checkAvailabilityMeasurments(type))
    {
        qDebug() << "Вы пытаетесь установить неизвестный тип измерений";
    }

    qDebug() << typeid(this).name() << m_value << type;
    QString tmp;

    if(type == "°C")
    {
        tmp = QString::number(m_value) + " " + type;
    }

    if(type == "K")
    {
        tmp = QString::number((m_value + 273.15)) + " " + type;
    }

    if(type == "°F")
    {
        tmp = QString::number((m_value * 9. / 5 + 32)) + " " + type;
    }

    if(m_typeMeasurments != type)
    {
        m_typeMeasurments = type;
        emit changeTypeMeasurment(m_typeMeasurments);
    }

     emit signalValueChanged(tmp);
}


