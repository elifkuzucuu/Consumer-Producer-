#include <QDebug>
#include <QList>
#include <QMutex>
#include <QThread>

#include "Producer.h"

QMutex producerMutex;

void Producer::write_Number_to_Buffer(QList<int> &buffer)
{
    int i,randomNumber,counter=0;

    while (1)
    {
        for (i = 0 ; i < 10 ; i++)
        {
            if (buffer[i] == -1)
                break;
            else
            {
                counter++;
            }
        }

        if (i == 10)
        {
            i--;
        }


        if (counter == 10)
        {
            qDebug() << "Buffer is full." << endl;

        }


        else
        {
            counter = 0;
            producerMutex.lock();
            randomNumber = qrand() % 50;
            buffer[i] = randomNumber;
            qDebug() << "Producer " << buffer[i] << " sayisini buffera yazdi." << endl;
        }

        producerMutex.unlock();
        QThread::sleep(2);
    }
}







