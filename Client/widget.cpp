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

    View* newWidget1 = new View(ControlTypes::Conditioner::Temperature, "Temperature", true, this);
    Vlayout->addWidget(newWidget1);

    View* newWidget2 = new View(ControlTypes::Conditioner::Humadity, "Humadity", true, this);
    Vlayout->addWidget(newWidget2);

    View* newWidget3 = new View(ControlTypes::Conditioner::Pressure, "Pressure", false, this);
    Vlayout->addWidget(newWidget3);

    QLabel* control = new QLabel("Control", this);
    //control->setFrameStyle(QFrame::Plain | QFrame::StyledPanel);
    control->setFrameShape(QFrame::StyledPanel);
    Vlayout->addWidget(control);

    Control* temperature = new Control("Temperature", ControlTypes::TypeControl::HorizontalSlider, this);
    Vlayout->addWidget(temperature);

    Control* onOff = new Control("System of Conditioner", ControlTypes::TypeControl::Button, this);
    Vlayout->addWidget(onOff);

    Control* direction = new Control("Air flow direction", ControlTypes::TypeControl::HorizontalSlider, this);
    Vlayout->addWidget(direction);



    setLayout(Vlayout);

    //ui
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotActivated(QAction *pAction)
{
    qDebug() << pAction->text();
}

void Widget::customMenuRequested(QWidget *button)
{

}
