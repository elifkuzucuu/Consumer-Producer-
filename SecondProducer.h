#ifndef SECONDPRODUCER_H
#define SECONDPRODUCER_H

#include <QObject>

class SecondProducer:  public QObject
{
    Q_OBJECT

public slots:
    void writeNumberToBuffer2(QList<int> &buffer);

};

#endif // SECONDPRODUCER_H
