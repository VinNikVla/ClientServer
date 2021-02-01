#include "gui.h"
#include "ui_gui.h"

GUI::GUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUI)
{
    ui->setupUi(this);
    QVBoxLayout* Vlayout = new QVBoxLayout(this);


    QLabel* state = new QLabel("Управление", this);
    state->setFrameStyle(QFrame::Plain | QFrame::StyledPanel);
    Vlayout->addWidget(state);


    controlOnGUI[ControlTypes::Conditioner::Temperature] = new Control(ControlTypes::Conditioner::Temperature, ControlTypes::TypeControl::HorizontalSlider, this);

    controlOnGUI[ControlTypes::Conditioner::Humadity] = new Control(ControlTypes::Conditioner::Humadity, ControlTypes::TypeControl::HorizontalSlider, this);

    controlOnGUI[ControlTypes::Conditioner::Pressure] = new Control(ControlTypes::Conditioner::Pressure, ControlTypes::TypeControl::HorizontalSlider, this);

//    controlOnGUI[ControlTypes::Conditioner::Direction] = new Control(ControlTypes::Conditioner::Direction, ControlTypes::TypeControl::HorizontalSlider, this);
//    controlOnGUI[ControlTypes::Conditioner::Direction]->setDisabled(true);

    for(auto itb = controlOnGUI.begin(), ite = controlOnGUI.end(); itb != ite; ++itb)
    {
         Vlayout->addWidget(itb.value());
         qDebug() << "Добавление " << itb.value()->getTypeDetector();
    }


    setLayout(Vlayout);


}

GUI::~GUI()
{
    delete ui;
}

Control *GUI::getControl(ControlTypes::Conditioner key)
{
    if(controlOnGUI.contains(key))
    {
        qDebug() << "Подключение сигналов и слотов GUI" << "key" << toString(key) << " " <<  controlOnGUI[key]->getTypeDetector();
            return controlOnGUI[key];
    }

    qDebug() << "Unknown key";
}
