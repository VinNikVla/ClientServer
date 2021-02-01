#ifndef CLIENTCONDITIONER_H
#define CLIENTCONDITIONER_H

#include "AbstractConditioner/abstractconditioner.h"
#include "AbstractValueModel/ChangeStateModel/ChangeMeasurmentsModel/changemeasurment.h"
#include "global.h"
#include "AbstractUDP/udpclient.h"

class ServerConditioner:public AbstractConditioner
{
public:
    ServerConditioner(QObject* parent = nullptr);
    const QMap<ControlTypes::Conditioner, AbstractValueModel*>* getPointerToMap();

private slots:
    void requestParameters(const ControlTypes::Conditioner& type, const int value);
private:
    UDPCLient* m_server;

};

#endif // CLIENTCONDITIONER_H
