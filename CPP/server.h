#ifndef SERVER_H
#define SERVER_H

#include "ValueModel/valuemodel.h"
class Server:public ValueModel
{
public:
    Server(const QVector<QString>* _listMeasurments,const ControlTypes::Conditioner& _typeDetector, const QVector<int>* _border, QObject* parent = nullptr);
    virtual void slotChangeTypeValue(const QString &type) override;

};

#endif // SERVER_H
