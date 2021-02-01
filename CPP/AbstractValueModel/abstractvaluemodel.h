#ifndef ABSTRACTVALUEMODEL_H
#define ABSTRACTVALUEMODEL_H

#include <QObject>
#include "global.h"

class AbstractValueModel : public QObject
{
    Q_OBJECT
public:
    explicit AbstractValueModel(const ControlTypes::Conditioner& _typeDetector, QObject *parent = nullptr);

    ControlTypes::Conditioner getTypeDetector() const;
    const int* getValue() const;

protected:
    ControlTypes::Conditioner m_typeDetector;
    int m_value;

signals:
    void signalChangeValue(const ControlTypes::Conditioner& type, const int value);

public slots:
    void slotSetValue(int value);
    void slotSetGUI(const ControlTypes::Conditioner& type, const int value);
};

#endif // ABSTRACTVALUEMODEL_H
