#ifndef SLIDERSETVALUE_H
#define SLIDERSETVALUE_H

#include "AbstrcatViewModel/CustomSlider/Slider/slidercontrol.h"


class SliderSetValue:public SliderControl
{
    Q_OBJECT
public:
    SliderSetValue(const QString& _typeMeasurments,
                   const QPair<int, int>* _borders,
                   const int _step,
                   const ControlTypes::Conditioner& _typeDetector,
                   QWidget* parent = nullptr);


public slots:
    void setValue(const ControlTypes::Conditioner& type, const int value);

};

#endif // SLIDERSETVALUE_H
