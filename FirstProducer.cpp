#include <QDebug>
#include <QList>
#include <QMutex>
#include <QThread>

#include "FirstProducer.h"



void FirstProducer::writeNumberToBuffer(QList<int> &buffer)
{
    int randomNumber;
    QMutex m_locker;
    QMutexLocker tLocker (&m_locker);
    while (1)
    {


        randomNumber = qrand() % 50;
        buffer << randomNumber;
        qDebug() << "First Producer " << randomNumber << " sayisini buffera yazdi." << endl;

        if (buffer.count() == 10)
        {
            qDebug() << "Buffer is full." << endl;

        }

        QThread::sleep(2);

    }
}














