#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mainLayout = new QVBoxLayout(this);

    createControlBox();

    mainLayout->addWidget(control);

    createStateBox();

    mainLayout->addWidget(state);

    slotEnabledControl(ControlTypes::Conditioner::OnOff, 0);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::slotEnabledControl(const ControlTypes::Conditioner &type, const int value)
{
    for(auto itb = elementsOnGUI.begin(), ite = elementsOnGUI.end(); itb != ite; ++itb)
    {
        qDebug() << (*itb)->getTypeDetector() << static_cast<bool>(value);
        if(ControlTypes::Conditioner::OnOff != (*itb)->getTypeDetector())
        {
            (*itb)->setEnabled(value);
        }
    }
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

const QVector<AbstractGUI *> *Widget::getVectorElementsOnGUI() const
{
    return &elementsOnGUI;
}

void Widget::createStateBox()
{
    QVBoxLayout* hlayout = new QVBoxLayout(this);
    state = new QGroupBox("Состояние", this);

    elementsOnGUI.append(new ChangeMeasurmentWidget(true,
                                                    false,
                                                    &ControlTypes::measurmentsDirection,
                                                    ControlTypes::Conditioner::Direction,
                                                    this));

    for(auto itb = elementsOnGUI.begin(), ite = elementsOnGUI.end(); itb != ite; ++itb)
    {
        if(dynamic_cast<ChangeMeasurmentWidget*>(*itb))
        {
            hlayout->addWidget(*itb);
        }
    }

    state->setLayout(hlayout);

}

void Widget::createControlBox()
{
    QVBoxLayout* hlayout = new QVBoxLayout(this);
    control = new QGroupBox("Управление", this);


    elementsOnGUI.append(new SliderSetValue("°C",
                                           &ControlTypes::borderTemperature,
                                           1,
                                           ControlTypes::Conditioner::Temperature,
                                           this));

    elementsOnGUI.append(new SliderSetValue("%",
                                           &ControlTypes::borderHumadity,
                                           10,
                                           ControlTypes::Conditioner::Humadity,
                                           this));


    elementsOnGUI.append(new SliderSetValue("мм.рт.ст.",
                                           &ControlTypes::borderPressure,
                                           120,
                                           ControlTypes::Conditioner::Pressure,
                                           this));

    elementsOnGUI.append(new ControlButton(true,
                                           ControlTypes::Conditioner::OnOff,
                                           this,
                                           &ControlTypes::stringTypeServer));



    for(auto itb = elementsOnGUI.begin(), ite = elementsOnGUI.end(); itb != ite; ++itb)
    {
        if(dynamic_cast<AbstractControl*>(*itb))
        {
            hlayout->addWidget(*itb);
        }
    }

    control->setLayout(hlayout);
}
