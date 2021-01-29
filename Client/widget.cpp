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

    View* viewTemperature = new View(ControlTypes::Conditioner::Temperature, true, &ControlTypes::stringTypeTemperature, this);
    Vlayout->addWidget(viewTemperature);
    elementsOnGUI[viewTemperature->getTypeDetector()] = viewTemperature;

    View* viewPressure = new View(ControlTypes::Conditioner::Pressure, true, &ControlTypes::stringTypePressure, this);
    Vlayout->addWidget(viewPressure);
    elementsOnGUI[viewPressure->getTypeDetector()] = viewPressure;

    View*  viewHimadity = new View(ControlTypes::Conditioner::Humadity, false, &ControlTypes::stringTypeHumadity, this);
    Vlayout->addWidget(viewHimadity);
    elementsOnGUI[viewHimadity->getTypeDetector()] = viewHimadity;

    QLabel* control = new QLabel("Control", this);
    control->setFrameShape(QFrame::StyledPanel);
    Vlayout->addWidget(control);

    Control* controlTemperature = new Control("ControlTemperature", ControlTypes::Conditioner::Temperature, ControlTypes::TypeControl::HorizontalSlider, this);
    Vlayout->addWidget(controlTemperature);
    controlOnGUI[controlTemperature->getName()] = controlTemperature;

    statusBar = new QStatusBar(this);
    Vlayout->addWidget(statusBar);

//    Control* onOff = new Control("System of Conditioner", ControlTypes::TypeControl::Button, this);
//    Vlayout->addWidget(onOff);
//    //elementsOnGUI[viewPressure->getName()] = viewPressure;

//    Control* direction = new Control("Air flow direction", ControlTypes::TypeControl::HorizontalSlider, this);
//    Vlayout->addWidget(direction);
    //elementsOnGUI[viewPressure->getName()] = viewPressure;



    setLayout(Vlayout);

}

View *Widget::getView(ControlTypes::Conditioner key)
{
    if(elementsOnGUI.contains(key))
    {
            return elementsOnGUI[key];
    }

    qDebug() << "Unknown key " << key;
}

Control *Widget::getControl(QString key)
{
    if(controlOnGUI.contains(key))
    {
            return controlOnGUI[key];
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

void Widget::slotShowMessage(const QString &msg)
{
    statusBar->showMessage(msg);
}

