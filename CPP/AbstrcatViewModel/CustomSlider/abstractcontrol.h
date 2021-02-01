#ifndef CUSTOMSLIDER_H
#define CUSTOMSLIDER_H

#include "AbstrcatViewModel/abstractgui.h"
#include "global.h"
#include <QSlider>
class AbstractControl:public AbstractGUI
{
    Q_OBJECT
public:
    AbstractControl(const ControlTypes::Conditioner& _typeDetector, QWidget* parent = nullptr);

signals:
    void signalValueChanged(const ControlTypes::Conditioner& type, const int value);
protected:
    virtual QWidget* createControlWidget() = 0;

};

#endif // CUSTOMSLIDER_H
