#ifndef ABSTACTVALUEMODEL_H
#define ABSTACTVALUEMODEL_H

#include <QObject>
#include

class AbstactValueModel : public QObject
{
    Q_OBJECT
public:
    explicit AbstactValueModel(QObject *parent = nullptr);

    ControlTypes::Conditioner getTypeDetector() const;

signals:

public slots:
};

#endif // ABSTACTVALUEMODEL_H
