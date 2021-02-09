#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QObject>
#include <QList>

#include "FirstConsumer.h"
#include "FirstProducer.h"
#include "SecondConsumer.h"
#include "SecondProducer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);


    QThread threadFirstProducer;
    QThread threadFirstConsumer;
    QThread threadSecondProducer;
    QThread threadSecondConsumer;

    QList <int> buffer;

    QObject::connect(&threadFirstConsumer, &QThread::started, [&](){
        FirstConsumer tConsumer;
        tConsumer.multiplyByTwo(buffer);
    });



    QObject::connect(&threadFirstProducer, &QThread::started, [&](){
        FirstProducer tProducer;
        tProducer.writeNumberToBuffer(buffer);

    });

    QObject::connect(&threadSecondConsumer, &QThread::started, [&](){
        SecondConsumer tConsumer2;
        tConsumer2.squareOfNumber(buffer);

    });

    QObject::connect(&threadSecondProducer, &QThread::started, [&](){
        SecondProducer tProducer2;
        tProducer2.writeNumberToBuffer2(buffer);

    });



    threadFirstProducer.start();
    threadFirstConsumer.start();
    threadSecondProducer.start();
    threadSecondConsumer.start();



    //    threadFirstConsumer.setObjectName("ConsumerThread");
    //    threadFirstProducer.setObjectName("ProducerThread");


    //    qDebug() << threadConsumer.thread()->currentThreadId();
    //    qDebug() << threadProducer.thread()->currentThreadId();


    return a.exec();
}
