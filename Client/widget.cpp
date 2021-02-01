#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("Кондиционер Витязь");

    QVBoxLayout* Vlayout = new QVBoxLayout(this);

    //
    ;




    QLabel* state = new QLabel("State", this);
    state->setFrameStyle(QFrame::Plain | QFrame::StyledPanel);
    Vlayout->addWidget(state);

    QHBoxLayout* hLayout = new QHBoxLayout(this);

    QLabel* stateName =  new QLabel("Комплексное состояние", this);
    hLayout->addWidget(stateName);


    stateCircle = new CircleState(this);

    hLayout->addWidget(stateCircle);
    hLayout->setContentsMargins(13,13,13,13);

    Vlayout->addItem(hLayout);

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

    Control* controlTemperature = new Control(ControlTypes::Conditioner::Temperature, ControlTypes::TypeControl::HorizontalSlider, this);
    Vlayout->addWidget(controlTemperature);
    controlOnGUI[ControlTypes::Conditioner::Temperature] = controlTemperature;



    Control* controlDirection = new Control(ControlTypes::Conditioner::Direction, ControlTypes::TypeControl::HorizontalSlider, this);
    Vlayout->addWidget(controlDirection);
    controlOnGUI[controlDirection->getTypeDetector()] = controlDirection;



    Vlayout->addWidget(new QLabel(toString(ControlTypes::Conditioner::OnOff), this));

    QPushButton* requestState = new QPushButton("Отправить запрос", this);
    Vlayout->addWidget(requestState);

    statusBar = new QStatusBar(this);
    Vlayout->addWidget(statusBar);

    slotDisableControl();
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

Control *Widget::getControl(ControlTypes::Conditioner key)
{
    if(controlOnGUI.contains(key))
    {
        return controlOnGUI[key];
    }

    qDebug() << "Unknown key";
}

CircleState *Widget::getState() const
{
    return stateCircle;
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

void Widget::slotEnabledControl()
{
    for(auto itb = elementsOnGUI.begin(), ite = elementsOnGUI.end(); itb != ite; ++itb)
    {
        itb.value()->setEnabled(true);
    }

    for(auto itb = controlOnGUI.begin(), ite = controlOnGUI.end(); itb != ite; ++itb)
    {
        itb.value()->setEnabled(true);
    }
}

void Widget::slotDisableControl()
{
    for(auto itb = elementsOnGUI.begin(), ite = elementsOnGUI.end(); itb != ite; ++itb)
    {
        itb.value()->setDisabled(true);
    }

    for(auto itb = controlOnGUI.begin(), ite = controlOnGUI.end(); itb != ite; ++itb)
    {
        itb.value()->setDisabled(true);
    }
}

