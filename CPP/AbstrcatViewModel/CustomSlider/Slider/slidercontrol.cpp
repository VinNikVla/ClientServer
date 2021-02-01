#include "slidercontrol.h"


SliderControl::SliderControl(const QString &_typeMeasurments,
                             const QPair<int, int> *_borders,
                             const int _step,
                             const ControlTypes::Conditioner &_typeDetector,
                             QWidget *parent):
    AbstractControl(_typeDetector, parent),
    m_typeMeasurments(_typeMeasurments),
    m_borders(_borders),
    m_step(_step)
{

    layout = new QHBoxLayout(this);

    QLabel* label = new QLabel(toString(m_typeDetector), this);
    layout->addWidget(label);

    QHBoxLayout* layoutSlider = new QHBoxLayout(this);
    labelValueSlider = new QLabel(QString::number(m_borders->first) + " " + m_typeMeasurments, this);

    m_widget = createControlWidget();

    layoutSlider->addWidget(m_widget);
    layoutSlider->addSpacing(3);
    layoutSlider->addWidget(labelValueSlider);

    layout->addItem(layoutSlider);

    layout->setContentsMargins(13,13,13,13);
    setLayout(layout);
}

QWidget *SliderControl::createControlWidget()
{
    QSlider* slider = new QSlider(Qt::Horizontal, this);
    if(m_borders)
        slider->setRange(m_borders->first, m_borders->second);
    slider->setTickPosition(QSlider::TicksBothSides);
    slider->setTickInterval(m_step);
    slider->setSingleStep(m_step);
    QObject::connect(slider, &QSlider::valueChanged, this, &SliderControl::m_visualisationSliderValue);
    QObject::connect(slider, &QSlider::valueChanged, this, &SliderControl::m_handlerSignal);

    return slider;

}

void SliderControl::m_visualisationSliderValue(const int value)
{
    labelValueSlider->setText(QString::number(value) + " " + m_typeMeasurments);
}

void SliderControl::m_handlerSignal(const int value)
{
    emit signalValueChanged(m_typeDetector, value);
}
