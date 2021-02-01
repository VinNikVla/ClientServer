#ifndef CHANGESTATEMODEL_H
#define CHANGESTATEMODEL_H

#include "AbstractValueModel/abstractvaluemodel.h"
#include "QVector"

class ChangeState:public AbstractValueModel
{
    Q_OBJECT
public:
    ChangeState(const QVector<int>* _borderState, const ControlTypes::Conditioner& _typeDetector, QObject *parent = nullptr);
    DeviceState getState() const;
signals:
    void signalStateChanged();

protected:
    const QVector<int>* m_borderState;
    DeviceState m_state;

private slots:
    void m_slotChangeState(const ControlTypes::Conditioner& type, const int value);

private:
    DeviceState m_changeState();
};

#endif // CHANGESTATEMODEL_H
