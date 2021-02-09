#include <QDebug>
#include <QMutex>
#include <QThread>
#include <QObject>

#include "SecondConsumer.h"

void SecondConsumer::squareOfNumber(QList<int> &buffer)
{

    QMutex m_locker;

    while (1)
    {

        //qDebug() << buffer.count() << "second consumer";


        if (buffer.count() > 0)
        {
            QMutexLocker tLocker (&m_locker);
            qDebug() << "Second Consumer " << buffer[0] << " sayisini aldi. Karesi: " << buffer[0] * buffer[0] << endl;
            buffer.removeFirst();
        }

        QThread::sleep(5);
    }

}
