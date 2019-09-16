#include "Sender.h"
#include <QMutex>
#include "global.h"

Sender::Sender(QObject *parent):
    QThread (parent)
{
    for(int i = 0 ; i < 5 ; i++) {
        Data temp;
        temp.a = i;
        temp.b = i + 1;
        Message msg;
        msg.setData(temp);
        msg.setId(RECEIVER);
        msgList.append(msg);
    }
}

void Sender::run()
{
    int i = 0;
    foreach(Message m , msgList){
        QMutex mutex;
        mutex.lock();
        sharedData.insert(i , m);
        i++;
        mutex.unlock();
    }
}
