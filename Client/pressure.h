#ifndef PRESSURE_H
#define PRESSURE_H

#include "valuemodel.h"

class Pressure:public ValueModel
{
public:
    Pressure(const QVector<QString>* _listMeasurments,const ControlTypes::Conditioner& _typeDetector, const QVector<int>* _border, QObject* parent = nullptr);
    virtual void slotChangeTypeValue(const QString &type) override;
};

#endif // PRESSURE_H
