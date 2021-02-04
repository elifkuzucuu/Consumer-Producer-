#include <QDebug>
#include <QList>
#include <QMutex>
#include <QThread>

#include "Producer.h"



void Producer::writeNumberToBuffer(QList<int> &buffer)
{
    int i , randomNumber;
    QMutex m_locker;
    while (1)
    {
        QMutexLocker tLocker (&m_locker);

        randomNumber = qrand() % 50;
        buffer << randomNumber;
        qDebug() << "Producer " << randomNumber << " sayisini buffera yazdi." << endl;

        if (buffer.count() == 10)
        {
            qDebug() << "Buffer is full." << endl;

        }

        QThread::sleep(2);

    }
}














