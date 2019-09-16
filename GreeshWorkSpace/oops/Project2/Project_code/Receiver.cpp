#include "Receiver.h"
#include "global.h"
#include <QMutex>
#include <QDebug>

Receiver::Receiver(QObject *parent):
    QThread (parent)
{
}

void Receiver::run()
{
    for (int i = 0; i < 5; i++) {
        QMutex mutex;
        mutex.lock();
        Message m = sharedData.value(i);
        int id = m.getId();
        if (id != RECEIVER)
            return;
        Data d = m.getData();
        d.sum = d.a + d.b;
        m.setData(d);
        sharedData.insert(i,m);
        mutex.unlock();
    }
    emit FinishReceiver();
}
