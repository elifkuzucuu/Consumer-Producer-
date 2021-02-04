#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>

class Consumer : public QObject
{
    Q_OBJECT

public slots:
    void getNumberFromBuffer(QList<int> &buffer);

};

#endif // CONSUMER_H
