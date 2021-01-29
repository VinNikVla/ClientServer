#include "valuemodel.h"

ValueModel::ValueModel(const QVector<QString> *_listMeasurments, const ControlTypes::Conditioner &_typeDetector, const QVector<int> *_border, QObject *parent):
        QObject(parent),
    m_listMesurments(_listMeasurments),
    m_typeDetector(_typeDetector),
    m_border(_border)

{
    m_value = 0;
}

void ValueModel::slotSetValue(int value)
{
    if(value == m_value)
    {
       return;
    }

    m_value = value;
    slotSetState();


    slotChangeTypeValue(m_typeMeasurments);
}


DeviceState ValueModel::getState() const
{
    return m_state;
}

ControlTypes::Conditioner ValueModel::getTypeDetector() const
{
    return m_typeDetector;
}

QString ValueModel::getTypeMeasurments() const
{
    return m_typeMeasurments;
}

void ValueModel::slotSetState()
{
    DeviceState tmp = m_changeState();

    if(m_state == tmp)
        return;

    m_state = tmp;


}

DeviceState ValueModel::m_changeState()
{
    if(m_border->size() != 4)
    {
        qDebug() << "You use wrong vector for border state";
        return DeviceState::Unknown;
    }

    if(m_value >= m_border->at(0) && m_value <= m_border->at(1))
    {
        return DeviceState::Green;
    }

    if(m_value >= m_border->at(2) && m_value <= m_border->at(3))
    {
        return DeviceState::Yellow;
    }

    return DeviceState::Red;
}

bool ValueModel::checkAvailabilityMeasurments(const QString &type)
{
    for(QVector<QString>::const_iterator itb = m_listMesurments->begin(), ite = m_listMesurments->end(); itb != ite; ++itb)
    {
        if(type == *itb)
        {
            return true;
        }
    }

    return false;
}



