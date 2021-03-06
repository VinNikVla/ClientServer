#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QStyle>
#include "global.h"
#include "AbstrcatViewModel/ChangeMeasurments/changemeasurmentwidget.h"
#include "AbstrcatViewModel/HandlerState/handlerstate.h"
#include "AbstrcatViewModel/CustomSlider/Slider/slidercontrol.h"
#include "AbstrcatViewModel/CustomSlider/ControlButton/controlbutton.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    AbstractGUI* getElementOnGUI(ControlTypes::Conditioner key);

    const SliderControl *getControlTemperature() const;

public slots:
    void slotEnabledControl(const ControlTypes::Conditioner& type, const int value);

private slots:
    void m_setBackground();
private:
    QVector<AbstractGUI*> elementsOnGUI;
    QGroupBox* changeBackground;
    QGroupBox* state;
    QGroupBox* control;
    QRadioButton* white;
    QRadioButton* black;

    SliderControl* temperature;
    QPalette Pal;

    void createChangeBackground();
    void createStateBox();
    void createControlBox();


};

#endif // WIDGET_H
