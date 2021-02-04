#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QObject>
#include <QList>

#include "Consumer.h"
#include "Producer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);


    QThread threadProducer;
    QThread threadConsumer;
    QList <int> buffer;

    QObject::connect(&threadConsumer, &QThread::started, [&](){
        Consumer tConsumer;
        tConsumer.getNumberFromBuffer(buffer);
    });



    QObject::connect(&threadProducer, &QThread::started, [&](){
        Producer tProducer;
        tProducer.writeNumberToBuffer(buffer);

    });

    threadProducer.start();
    threadConsumer.start();


    threadConsumer.setObjectName("ConsumerThread");
    threadProducer.setObjectName("ProducerThread");


//    qDebug() << threadConsumer.thread()->currentThreadId();
//    qDebug() << threadProducer.thread()->currentThreadId();


    return a.exec();
}
