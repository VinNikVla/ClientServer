#ifndef HUMADITY_H
#define HUMADITY_H
//#include "valuemodel.h"
#include "ValueModel/valuemodel.h"

class Humadity:public ValueModel
{
public:
    Humadity(const QVector<QString>* _listMeasurments,const ControlTypes::Conditioner& _typeDetector, const QVector<int>* _border, QObject* parent = nullptr);
    virtual void slotChangeTypeValue(const QString &type) override;
};

#endif // HUMADITY_H
