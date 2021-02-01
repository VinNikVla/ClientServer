#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    Pal = palette();

    // устанавливаем цвет фона
    Pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(Pal);

    setWindowTitle("Кондиционер Витязь");

    QVBoxLayout* Vlayout = new QVBoxLayout(this);


    createChangeBackground();

    Vlayout->addWidget(changeBackground);

    createStateBox();

    Vlayout->addWidget(state);

    createControlBox();

    Vlayout->addWidget(control);

    setLayout(Vlayout);

    slotEnabledControl(ControlTypes::Conditioner::RequestParameters, 0);
}
Widget::~Widget()
{

}

AbstractGUI *Widget::getElementOnGUI(ControlTypes::Conditioner key)
{
    for(QVector<AbstractGUI*>::iterator itb = elementsOnGUI.begin(), ite = elementsOnGUI.end(); itb != ite; ++itb)
    {
        if((*itb)->getTypeDetector() == key)
        {
            qDebug() << "GUI object " << (*itb)->getTypeDetector();
            return *itb;
        }
    }
}

const SliderControl *Widget::getControlTemperature() const
{
    return temperature;
}

void Widget::slotEnabledControl(const ControlTypes::Conditioner &type, const int value)
{
    Q_UNUSED(type)
    for(auto itb = elementsOnGUI.begin(), ite = elementsOnGUI.end(); itb != ite; ++itb)
    {
        qDebug() << (*itb)->getTypeDetector() << static_cast<bool>(value);
        if(ControlTypes::Conditioner::RequestParameters != (*itb)->getTypeDetector() && ControlTypes::Conditioner::OnOff != (*itb)->getTypeDetector())
        {
            (*itb)->setEnabled(value);
        }
    }
}


void Widget::m_setBackground()
{

    if(white->isChecked())
    {
        setPalette(style()->standardPalette());

    }
    else if(black->isChecked())
    {

        // Настраиваем палитру для цветовых ролей элементов интерфейса
        Pal.setColor(QPalette::Window, QColor(53, 53, 53));
        Pal.setColor(QPalette::WindowText, Qt::white);
        Pal.setColor(QPalette::Base, QColor(25, 25, 25));
        Pal.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        Pal.setColor(QPalette::ToolTipBase, Qt::white);
        Pal.setColor(QPalette::ToolTipText, Qt::white);
        Pal.setColor(QPalette::Text, Qt::white);
        Pal.setColor(QPalette::Button, QColor(53, 53, 53));
        Pal.setColor(QPalette::ButtonText, Qt::white);
        Pal.setColor(QPalette::BrightText, Qt::red);
        Pal.setColor(QPalette::Link, QColor(42, 130, 218));
        Pal.setColor(QPalette::Highlight, QColor(42, 130, 218));
        Pal.setColor(QPalette::HighlightedText, Qt::black);
        Pal.setColor(QPalette::Background, Qt::black);
        setPalette(Pal);
    }

    //repaint();

    setAutoFillBackground(true);
}

void Widget::createChangeBackground()
{
    changeBackground = new QGroupBox("Тема оформления", this);

    white = new QRadioButton("Светлая", this);
    white->setChecked(true);
    black = new QRadioButton("Темная", this);

    connect(white, &QRadioButton::clicked, this, &Widget::m_setBackground);
    connect(black, &QRadioButton::clicked, this, &Widget::m_setBackground);

    QHBoxLayout* hlayout = new QHBoxLayout(this);

    hlayout->addWidget(white);
    hlayout->addWidget(black);
    changeBackground->setLayout(hlayout);
}

void Widget::createStateBox()
{
    QVBoxLayout* hlayout = new QVBoxLayout(this);
    state = new QGroupBox("Состояния", this);

    elementsOnGUI.append(new HandlerState(ControlTypes::Conditioner::ComplexState, this));


    elementsOnGUI.append(new ChangeMeasurmentWidget(true,
                                                    true,
                                                    &ControlTypes::measurmentsTemperature,
                                                    ControlTypes::Conditioner::Temperature,
                                                    this));

    elementsOnGUI.append(new ChangeMeasurmentWidget(true,
                                                    true,
                                                    &ControlTypes::measurmentsPressure,
                                                    ControlTypes::Conditioner::Pressure,
                                                    this));

    elementsOnGUI.append(new ChangeMeasurmentWidget(true,
                                                    false,
                                                    &ControlTypes::measurmentsHumadity,
                                                    ControlTypes::Conditioner::Humadity,
                                                    this));

    for(auto itb = elementsOnGUI.begin(), ite = elementsOnGUI.end(); itb != ite; ++itb)
    {

        hlayout->addWidget(*itb);
    }

    state->setLayout(hlayout);
}

void Widget::createControlBox()
{
    QVBoxLayout* hlayout = new QVBoxLayout(this);
    control = new QGroupBox("Управление", this);

    elementsOnGUI.append(new SliderControl("°",
                                           &ControlTypes::borderDirection,
                                           10,
                                           ControlTypes::Conditioner::Direction,
                                           this));

    temperature = new SliderControl("°C",
                                    &ControlTypes::borderTemperature,
                                    1,
                                    ControlTypes::Conditioner::Temperature,
                                    this);
    elementsOnGUI.append(temperature);

    elementsOnGUI.append(new ControlButton(true,
                                           ControlTypes::Conditioner::OnOff,
                                           this,
                                           &ControlTypes::stringTypeServer));

    elementsOnGUI.append( new ControlButton(false,
                                            ControlTypes::Conditioner::RequestParameters,
                                            this));


    for(auto itb = elementsOnGUI.begin(), ite = elementsOnGUI.end(); itb != ite; ++itb)
    {
        if(dynamic_cast<AbstractControl*>(*itb))
        {
            hlayout->addWidget(*itb);
        }
    }

    control->setLayout(hlayout);

}


