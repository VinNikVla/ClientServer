#include "control.h"

Control::Control(const QString& _name, const ControlTypes::Conditioner& _typeHandler, const ControlTypes::TypeControl& _typeControl, QWidget *parent):
    QWidget(parent),
    m_name(_name),
    typeHandler(_typeHandler),
    typeControl(_typeControl)
{
    layout = new QHBoxLayout(this);
    nameHandler = new QLabel(_name, this);
    layout->addWidget(nameHandler);
    controlWidget = createControlWiget(typeControl);
    createSignalForWidget();
    layout->addWidget(controlWidget);
    layout->setContentsMargins(13,13,13,13);
    setLayout(layout);

}

QString Control::getName() const
{
    return m_name;
}

void Control::handlerSignal(const int value)
{
    emit valueChanged(typeHandler, value);
}

QWidget *Control::createControlWiget(const ControlTypes::TypeControl &type)
{
    switch (type)
    {
    case ControlTypes::TypeControl::HorizontalSlider:
        return new QSlider(Qt::Horizontal,this);

    case ControlTypes::TypeControl::VerticalSlider:
        return new QSlider(Qt::Vertical, this);

    case ControlTypes::TypeControl::Button:
        return new QPushButton(this);

    case ControlTypes::TypeControl::SpinBox:
        return new QSpinBox(this);

    case ControlTypes::TypeControl::Dial:
        return new QDial(this);
    }
}

void Control::createSignalForWidget()
{
    switch (typeControl) {
    case ControlTypes::TypeControl::HorizontalSlider:
        QObject::connect(static_cast<QSlider*>(controlWidget), &QSlider::valueChanged, this, &Control::handlerSignal);

//    case ControlTypes::TypeControl::VerticalSlider:
//        return new QSlider(Qt::Vertical, this);

//    case ControlTypes::TypeControl::Button:
//        return new QPushButton(this);

//    case ControlTypes::TypeControl::SpinBox:
//        return new QSpinBox(this);

//    case ControlTypes::TypeControl::Dial:
//        return new QDial(this);
    }
}
