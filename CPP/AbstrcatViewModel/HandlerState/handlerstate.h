#ifndef HANDLERSTATE_H
#define HANDLERSTATE_H

#include <QWidget>
#include "AbstrcatViewModel/abstractgui.h"
#include "AbstrcatViewModel/HandlerState/circlestate.h"
class HandlerState : public AbstractGUI
{
    Q_OBJECT
public:
    explicit HandlerState(const ControlTypes::Conditioner &_typeDetector, QWidget *parent = nullptr);


public slots:
    void slotChangeState(const DeviceState& state);
protected:
    virtual QWidget* createControlWidget() override;

};

#endif // HANDLERSTATE_H
