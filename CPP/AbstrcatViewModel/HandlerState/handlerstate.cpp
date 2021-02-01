#include "handlerstate.h"

HandlerState::HandlerState(const ControlTypes::Conditioner &_typeDetector, QWidget *parent) :
    AbstractGUI(_typeDetector, parent)
{
    layout = new QHBoxLayout(this);

    QLabel* label = new QLabel(toString(m_typeDetector), this);
    m_widget = createControlWidget();

    layout->addWidget(label);
    layout->addWidget(m_widget);

            layout->setContentsMargins(13,13,13,13);

}

void HandlerState::slotChangeState(const DeviceState &state)
{
    static_cast<CircleState*>(m_widget)->changeState(state);
}

QWidget *HandlerState::createControlWidget()
{
    CircleState* state = new CircleState(this);
    return state;
}
