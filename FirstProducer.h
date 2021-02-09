#ifndef FIRSTPRODUCER_H
#define FIRSTPRODUCER_H

#include <QObject>

class FirstProducer :  public QObject
{
    Q_OBJECT

public slots:
    void writeNumberToBuffer(QList<int> &buffer);

};

#endif // FIRSTPRODUCER_H
