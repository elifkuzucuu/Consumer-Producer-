#include <QMutex>
#include <QDebug>
#include <QThread>

#include "Consumer.h"

QMutex consumerMutex;

void Consumer::get_Number(QList<int> &buffer)
{
    int i , j;

    while (1)
    {
        consumerMutex.lock();
        for (i = 0 ; i < 10 ; i++)
        {
            if (buffer[i] != -1)
            {
                qDebug() << "Consumer class " << buffer[i] << " sayisini aldi. 2 ile carpti: " << buffer[i]*2 << endl;
                buffer[i] = -1;

                for (j = i+1 ; j < 10 ; j++)
                {
                    buffer[i] = buffer[j];
                    i++;
                    buffer[j] = -1;
                }
                break;
            }
        }
        consumerMutex.unlock();
        QThread::sleep(6);
    }
}











