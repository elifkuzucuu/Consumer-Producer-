#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>

class Producer :  public QObject
{
    Q_OBJECT

public slots:
    void write_Number_to_Buffer(QList<int> &buffer);

};

#endif // PRODUCER_H
