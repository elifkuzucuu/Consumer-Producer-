#include <QDebug>
#include <QList>
#include <QMutex>
#include <QThread>
#include <QObject>

#include "SecondProducer.h"


void SecondProducer :: writeNumberToBuffer2(QList<int> &buffer)
{
    int randomNumber;
    QMutex m_locker;
    QMutexLocker tLocker (&m_locker);
    while (1)
    {


        randomNumber = (qrand() % 900 )+ 100;
        buffer << randomNumber;
        qDebug() << "Second Producer " << randomNumber << " sayisini buffera yazdi." << endl;

        if (buffer.count() == 10)
        {
            qDebug() << "Buffer is full." << endl;

        }

        QThread::sleep(3);

    }
}
