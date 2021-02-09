#ifndef FIRSTCONSUMER_H
#define FIRSTCONSUMER_H

#include <QObject>

class FirstConsumer : public QObject
{
    Q_OBJECT

public slots:
    void multiplyByTwo(QList<int> &buffer);

};

#endif // FIRSTCONSUMER_H
