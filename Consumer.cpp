#include <QMutex>
#include <QDebug>
#include <QThread>

#include "Consumer.h"

void Consumer::getNumberFromBuffer(QList<int> &buffer)
{
    int i , j;
    QMutex m_locker;

    while (1)
    {

        QMutexLocker tLocker (&m_locker);
        qDebug() << buffer.count();
        if (buffer.count() > 0)
        {

            qDebug() << "Consumer class " << buffer[0] << " sayisini aldi. 2 ile carpti: " << buffer[0] * 2 << endl;
            buffer.removeFirst();
        }

        QThread::sleep(4);
    }

}












