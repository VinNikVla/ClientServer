#ifndef SLIDERCONTROL_H
#define SLIDERCONTROL_H

#include "AbstrcatViewModel/CustomSlider/abstractcontrol.h"
#include "global.h"
class SliderControl:public AbstractControl
{
public:
    SliderControl(const QString& _typeMeasurments,
                  const QPair<int, int>* _borders,
                  const int _step,
                  const ControlTypes::Conditioner& _typeDetector,
                  QWidget* parent = nullptr);

protected:
    virtual QWidget* createControlWidget() override;



private:
    const QPair<int, int>* m_borders;
    int m_step;

protected:
    QString m_typeMeasurments;
    QLabel* labelValueSlider;

private slots:
    void m_visualisationSliderValue(const int value);
    void m_handlerSignal(const int value);

};

#endif // SLIDERCONTROL_H
