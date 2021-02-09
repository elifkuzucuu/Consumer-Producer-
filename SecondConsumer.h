#ifndef SECONDCONSUMER_H
#define SECONDCONSUMER_H

#include <QObject>

class SecondConsumer : public QObject
{
    Q_OBJECT

public slots:
    void squareOfNumber(QList<int> &buffer);

};


#endif // SECONDCONSUMER_H
