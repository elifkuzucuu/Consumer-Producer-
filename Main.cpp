#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QObject>

#include "Consumer.h"
#include "Producer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);


    QThread threadProducer;
    QThread threadConsumer;
    QList <int> buffer = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};


    QObject::connect(&threadConsumer, &QThread::started, [&](){
        Consumer tConsumer;
        tConsumer.get_Number(buffer);
    });



    QObject::connect(&threadProducer, &QThread::started, [&](){
        Producer tProducer;
        tProducer.write_Number_to_Buffer(buffer);

    });

    threadProducer.start();
    threadConsumer.start();


    threadConsumer.setObjectName("ConsumerThread");
    threadProducer.setObjectName("ProducerThread");


    qDebug() << threadConsumer.thread()->currentThreadId();
    qDebug() << threadProducer.thread()->currentThreadId();


    return a.exec();
}
