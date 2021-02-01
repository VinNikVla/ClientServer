#include "changemeasurment.h"

ChangeMeasurment::ChangeMeasurment(const Measurments *_vecMeasurments, const QVector<int> *_borderState, const ControlTypes::Conditioner &_typeDetector, QObject *parent):
    ChangeState(_borderState, _typeDetector, parent),
    m_vecMeasurments(_vecMeasurments)
{
    QObject::connect(this, &ChangeMeasurment::signalChangeValue, this, &ChangeMeasurment::m_slotHandlerInsade);
}

bool ChangeMeasurment::m_checkAvailabilityMeasurments(const QString &type)
{
    for(Measurments::const_iterator itb = m_vecMeasurments->begin(), ite = m_vecMeasurments->end(); itb != ite; ++itb)
    {
        if(type == itb->first)
        {
            return true;
        }
    }

    return false;
}

void ChangeMeasurment::slotChangeTypeMeasurments(const QString &type)
{
    if(!m_checkAvailabilityMeasurments(type))
    {
        qDebug() << "Вы пытаетесь установить неизвестный тип измерений" << type;
        return;
    }

    qDebug() << typeid(this).name() << m_value  << " " << m_typeDetector << " " << type;

    QString tmp;

    for( auto itb = m_vecMeasurments->begin(), ite = m_vecMeasurments->end(); itb != ite; ++itb)
    {
        if(itb->first == type)
        {
            tmp = QString::number(m_value * itb->second.first + itb->second.second) + " " + type;
        }
    }

    if(m_typeMeasurments != type)
    {
        m_typeMeasurments = type;
        emit signalChangeTypeMeasurments(m_typeMeasurments);
    }

    emit signalChangeValueMeasurments(tmp);
}

void ChangeMeasurment::m_slotHandlerInsade(const ControlTypes::Conditioner &type, const int value)
{
    Q_UNUSED(type)
    Q_UNUSED(value)
    slotChangeTypeMeasurments(m_typeMeasurments);
}
