#include "humadity.h"

Humadity::Humadity(const QVector<QString> *_listMeasurments, const ControlTypes::Conditioner &_typeDetector, const QVector<int> *_border, QObject *parent):
    ValueModel(_listMeasurments, _typeDetector, _border, parent)
{
//    m_value = 0;
}

void Humadity::slotChangeTypeValue(const QString &type)
{
    if(!checkAvailabilityMeasurments(type))
    {
        qDebug() << "Вы пытаетесь установить неизвестный тип величины для" << m_typeDetector;
        return;
    }

    qDebug() << typeid(this).name() << m_value << type;

    QString tmp;

    if(type == "%")
    {
        tmp = QString::number(m_value) + " " + type;
    }



    m_typeMeasurments = type;
    //m_set->setTypeTemperature(type);
    emit signalValueChanged(tmp);
}
