#ifndef TEMPERATURE_H
#define TEMPERATURE_H

//#include "valuemodel.h"
#include "ValueModel/valuemodel.h"

class Temperature:public ValueModel
{
public:
    Temperature(const QVector<QString>* _listMeasurments,const ControlTypes::Conditioner& _typeDetector, const QVector<int>* _border, QObject* parent = nullptr);
    virtual void slotChangeTypeValue(const QString &type) override;
    //virtual ~Temperature();

};

#endif // TEMPERATURE_H
