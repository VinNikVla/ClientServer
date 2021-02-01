#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QStyle>
#include "global.h"
#include "AbstrcatViewModel/CustomSlider/Slider/slidercontrol.h"
#include "AbstrcatViewModel/CustomSlider/Slider/slidersetvalue.h"
#include "AbstrcatViewModel/CustomSlider/ControlButton/controlbutton.h"

#include "AbstrcatViewModel/CustomSlider/abstractcontrol.h"
#include "AbstrcatViewModel/ChangeMeasurments/changemeasurmentwidget.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public slots:
    void slotEnabledControl(const ControlTypes::Conditioner& type, const int value);

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    AbstractGUI* getElementOnGUI(ControlTypes::Conditioner key);
    const QVector<AbstractGUI*> * getVectorElementsOnGUI() const;

private:
    Ui::Widget *ui;

    QVector<AbstractGUI*> elementsOnGUI;
    QGroupBox* state;
    QGroupBox* control;

    QLayout* mainLayout;

    void createStateBox();
    void createControlBox();
};

#endif // WIDGET_H
