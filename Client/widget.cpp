#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout* Vlayout = new QVBoxLayout(this);

    QLabel* state = new QLabel("State", this);
    state->setFrameStyle(QFrame::Plain | QFrame::StyledPanel);
    Vlayout->addWidget(state);

    View* viewTemperature = new View("ViewTemperature", true, this, &ControlTypes::stringTypeTemperature);
    Vlayout->addWidget(viewTemperature);
    elementsOnGUI[viewTemperature->getName()] = viewTemperature;

    View* viewPressure = new View("ViewPressure", true, this,  &ControlTypes::stringTypePressure);
    Vlayout->addWidget(viewPressure);
    elementsOnGUI[viewPressure->getName()] = viewPressure;

    View*  viewHimadity = new View("ViewHumadity", false, this);
    Vlayout->addWidget(viewHimadity);
    elementsOnGUI[viewHimadity->getName()] = viewHimadity;

    QLabel* control = new QLabel("Control", this);
    control->setFrameShape(QFrame::StyledPanel);
    Vlayout->addWidget(control);

    Control* temperature = new Control("ControlTemperature", ControlTypes::TypeControl::HorizontalSlider, this);
    Vlayout->addWidget(temperature);
    //elementsOnGUI[viewPressure->getName()] = viewPressure;

    Control* onOff = new Control("System of Conditioner", ControlTypes::TypeControl::Button, this);
    Vlayout->addWidget(onOff);
    //elementsOnGUI[viewPressure->getName()] = viewPressure;

    Control* direction = new Control("Air flow direction", ControlTypes::TypeControl::HorizontalSlider, this);
    Vlayout->addWidget(direction);
    //elementsOnGUI[viewPressure->getName()] = viewPressure;



    setLayout(Vlayout);

}

View *Widget::getView(QString key)
{
    if(elementsOnGUI.contains(key))
    {
            return elementsOnGUI[key];
    }

    qDebug() << "Unknown key";
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotActivated(QAction *pAction)
{
    qDebug() << pAction->text();
}

