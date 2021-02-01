#ifndef CLIENTCONDITIONER_H
#define CLIENTCONDITIONER_H

#include <QObject>
#include "AbstractConditioner/abstractconditioner.h"
#include "global.h"
#include "Settings/settings.h"
#include "AbstractUDP/udpserver.h"

class ClientConditioner:public AbstractConditioner
{
    Q_OBJECT
public:
    ClientConditioner(Settings* _set, QObject* parent = nullptr);

private:
    Settings* m_set;
    UDPclient* m_client;


signals:
    void signalChangeComplexState(const DeviceState& state);
public slots:
    void slotChangeState();
private:
    void connectSettings();

};

#endif // CLIENTCONDITIONER_H
