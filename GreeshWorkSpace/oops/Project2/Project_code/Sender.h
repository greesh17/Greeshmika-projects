#ifndef SENDER_H
#define SENDER_H

#include <QThread>
#include <QList>
#include "Message.h"


class Sender:public QThread
{
    Q_OBJECT
public:
    explicit Sender(QObject *parent = 0);
private:
    void run();
    enum {SENDER,RECEIVER};
    QList<Message> msgList;
signals:
    void FinishSender();
};

#endif // SENDER_H
