#ifndef HANDLERSTATE_H
#define HANDLERSTATE_H

#include "AbstrcatViewModel/HandlerState/circlestate.h"
#include "AbstrcatViewModel/abstractgui.h"
class HandlerState:public AbstractGUI
{
public:
    HandlerState();



signals:
    void signalChangeTypeMeasurements(const QString& type);
protected:
    virtual QWidget* createControlWidget() override;
};

#endif // HANDLERSTATE_H
