#include <QMutex>
#include <QDebug>
#include <QThread>

#include "FirstConsumer.h"

void FirstConsumer::multiplyByTwo(QList<int> &buffer)
{

    QMutex m_locker;

    while (1)
    {

        if (buffer.count() > 0)
        {
            QMutexLocker tLocker (&m_locker);
            qDebug() << "First Consumer " << buffer[0] << " sayisini aldi. 2 ile carpti: " << buffer[0] * 2 << endl;
            buffer.removeFirst();
        }

        QThread::sleep(4);
    }

}












