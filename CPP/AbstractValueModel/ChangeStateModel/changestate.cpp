#include "changestate.h"


ChangeState::ChangeState(const QVector<int> *_borderState, const ControlTypes::Conditioner &_typeDetector, QObject *parent):
    AbstractValueModel(_typeDetector, parent),
    m_borderState(_borderState)
{
    m_state = DeviceState::Unknown;

    QObject::connect(this, &ChangeState::signalChangeValue, this, &ChangeState::m_slotChangeState);
}

DeviceState ChangeState::getState() const
{
    return m_state;
}

void ChangeState::m_slotChangeState(const ControlTypes::Conditioner &type, const int value)
{
    Q_UNUSED(type)
    Q_UNUSED(value)
    DeviceState tmp = m_changeState();

    if(m_state == tmp)
        return;

    m_state = tmp;

    qDebug() << "set state " << m_state;

    emit signalStateChanged();

}

DeviceState ChangeState::m_changeState()
{
    if(m_borderState->size() != 4)
    {
        qDebug() << "You use wrong vector for border state";
        return DeviceState::Unknown;
    }

    if(m_value >= m_borderState->at(0) && m_value <= m_borderState->at(1))
    {
        return DeviceState::Green;
    }

    if(m_value >= m_borderState->at(2) && m_value <= m_borderState->at(3))
    {
        return DeviceState::Yellow;
    }

    return DeviceState::Red;
}
