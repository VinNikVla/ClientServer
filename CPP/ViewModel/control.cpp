#include "control.h"


Control::Control(const ControlTypes::Conditioner &_typeDetector, const ControlTypes::TypeControl &_typeControl, QWidget *parent):
    QWidget(parent),
    m_typeDetector(_typeDetector),
    m_typeControl(_typeControl)
{
    m_name = toString(m_typeDetector);
    layout = new QHBoxLayout(this);
    nameHandler = new QLabel(m_name, this);
    layout->addWidget(nameHandler);
    controlWidget = createControlWiget(m_typeControl);
    createSignalForWidget();
    layout->addWidget(controlWidget);
    layout->setContentsMargins(13,13,13,13);
    setLayout(layout);
}

QString Control::getName() const
{
    return m_name;
}

ControlTypes::Conditioner Control::getTypeDetector() const
{
    return m_typeDetector;
}

void Control::handlerSignal(const int value)
{
    emit valueChanged(m_typeDetector, value);
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
    switch (m_typeControl) {
    case ControlTypes::TypeControl::HorizontalSlider:
        QObject::connect(static_cast<QSlider*>(controlWidget), &QSlider::valueChanged, this, &Control::handlerSignal);

//    case ControlTypes::TypeControl::VerticalSlider:
//        return new QSlider(Qt::Vertical, this);

//    case ControlTypes::TypeControl::Button:
//        QObject::connect(static_cast<QPushButton*>(controlWidget), &QPushButton::click, this, &Control::handlerButton);

//    case ControlTypes::TypeControl::SpinBox:
//        return new QSpinBox(this);

//    case ControlTypes::TypeControl::Dial:
//        return new QDial(this);
    }
}
