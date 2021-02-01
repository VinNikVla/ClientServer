#include "slidersetvalue.h"


SliderSetValue::SliderSetValue(const QString &_typeMeasurments,
                               const QPair<int, int> *_borders,
                               const int _step,
                               const ControlTypes::Conditioner &_typeDetector,
                               QWidget *parent):
    SliderControl(_typeMeasurments, _borders, _step, _typeDetector, parent)
{
}


void SliderSetValue::setValue(const ControlTypes::Conditioner &type, const int value)
{

    Q_UNUSED(type);
    static_cast<QSlider*>(m_widget)->setValue(value);
}
