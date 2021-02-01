#include "controlbutton.h"

ControlButton::ControlButton(const bool _needLabel, const ControlTypes::Conditioner &_typeDetector, QWidget *parent, const QVector<QString> *_switch):
    AbstractControl(_typeDetector, parent),
    m_needLabel(_needLabel)
{

    setSwitch(_switch);
    layout = new QHBoxLayout(this);

    m_widget = createControlWidget();

    if(_needLabel)
    {
        QLabel* label = new QLabel(toString(m_typeDetector), this);
        static_cast<QPushButton*>(m_widget)->setText("Включить");
        layout->addWidget(label);
    }
    else
    {
        static_cast<QPushButton*>(m_widget)->setText(toString(m_typeDetector));
    }


    layout->addWidget(m_widget);

    layout->setContentsMargins(13,13,13,13);
    setLayout(layout);


}

void ControlButton::setSwitch(const QVector<QString> *_switch)
{
    if(!_switch)
    {
        qDebug() << "!!!!Ошибка инициализация вектора nullptr!!!";
        return;
    }


    if(_switch->size() != 2)
    {
        qDebug() << "Выбран неверный размер вектора для реализации переключения";
        return;
    }



    m_switch = _switch;
}

void ControlButton::slotSetValue(const ControlTypes::Conditioner &type, const int value)
{
    Q_UNUSED(type)

    if(m_switch)
    {
        static_cast<QPushButton*>(m_widget)->setText(m_switch->at(value));
    }
}

QWidget *ControlButton::createControlWidget()
{

    QPushButton* button = new QPushButton(this);
    QObject::connect(button, &QPushButton::clicked, this, &ControlButton::m_handlerSignal);


    return button;
}

void ControlButton::m_handlerSignal()
{

    qDebug() << m_typeDetector << " click";
    if(m_switch)
    {
        static bool valueOnOff = false;
        valueOnOff = !valueOnOff;
        emit signalValueChanged(m_typeDetector, static_cast<int>(valueOnOff));
        return;
    }

    static int valueRequest = 0;
    emit signalValueChanged(m_typeDetector, ++valueRequest);

}
