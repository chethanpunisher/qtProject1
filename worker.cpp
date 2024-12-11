#include "worker.h"
#include <QDebug>

Worker::Worker() = default;

Worker::~Worker() = default;

void Worker::doWork() {
    qDebug() << "Worker: Doing work in thread:" << QThread::currentThread();
    // Simulate a time-consuming task
    QThread::sleep(1);
    emit workFinished();
}
