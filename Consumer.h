#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>

class Consumer : public QObject
{
    Q_OBJECT

public slots:
    void get_Number(QList<int> &buffer);

};

#endif // CONSUMER_H
