#ifndef CONTROLBUTTON_H
#define CONTROLBUTTON_H

#include "AbstrcatViewModel/CustomSlider/abstractcontrol.h"
#include "global.h"

class ControlButton:public AbstractControl
{
    Q_OBJECT
public:
    ControlButton(const bool _needLabel, const ControlTypes::Conditioner& _typeDetector, QWidget* parent = nullptr, const QVector<QString>* _switch = nullptr);
    void setSwitch(const QVector<QString>* _switch);

public slots:
    void slotSetValue(const ControlTypes::Conditioner& type, const int value);

protected:
     virtual QWidget* createControlWidget() override;

private:
    bool m_needLabel;
    const QVector<QString>* m_switch = nullptr;
    void m_handlerSignal();




};

#endif // CONTROLBUTTON_H
