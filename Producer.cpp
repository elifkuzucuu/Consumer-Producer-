#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>

class Producer :  public QObject
{
    Q_OBJECT

public slots:
    void writeNumberToBuffer(QList<int> &buffer);

};

#endif // PRODUCER_H
