#include "control.h"

Control::Control(const QString& _name,const ControlTypes::TypeControl& _type, QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    type = new QLabel(_name, this);
    layout->addWidget(type);
    controlWidget = createControlWiget(_type);
    layout->addWidget(controlWidget);
    layout->setContentsMargins(13,13,13,13);
    setLayout(layout);

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
