#include "pressure.h"

Pressure::Pressure(const QVector<QString> *_listMeasurments, const ControlTypes::Conditioner &_typeDetector, const QVector<int> *_border, QObject *parent):
    ValueModel(_listMeasurments, _typeDetector, _border, parent)
{
//    m_value = 0;
}

void Pressure::slotChangeTypeValue(const QString &type)
{
    if(!checkAvailabilityMeasurments(type))
    {
        qDebug() << "Вы пытаетесь установить неизвестный тип измерений";
        return;
    }

    qDebug() << typeid(this).name() << m_value << type;

    QString tmp;

    if(type == "мм.рт.ст")
    {
        tmp = QString::number(m_value) + " " + type;
    }

    if(type == "Па")
    {
        tmp = QString::number(m_value * 133.) + " " + type;
    }



    m_typeMeasurments = type;
    emit signalValueChanged(tmp);
}
