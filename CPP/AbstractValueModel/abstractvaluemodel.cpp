#include "abstractvaluemodel.h"

AbstractValueModel::AbstractValueModel(const ControlTypes::Conditioner &_typeDetector, QObject *parent) :
    QObject(parent),
    m_typeDetector(_typeDetector)
{
    m_value = -1;
}

ControlTypes::Conditioner AbstractValueModel::getTypeDetector() const
{
    return m_typeDetector;
}

const int *AbstractValueModel::getValue() const
{
    return &m_value;
}

void AbstractValueModel::slotSetValue(int value)
{
    qDebug() << m_typeDetector << m_value << " " << value;
    if(value == m_value)
        return;

    m_value = value;

    emit signalChangeValue(m_typeDetector, m_value);
}

void AbstractValueModel::slotSetGUI(const ControlTypes::Conditioner &type, const int value)
{
    qDebug() << m_typeDetector << m_value << " " << value;
    if(value == m_value)
        return;

    m_value = value;

    emit signalChangeValue(m_typeDetector, m_value);
}
