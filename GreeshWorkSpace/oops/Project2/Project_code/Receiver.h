#ifndef RECEIVER_H
#define RECEIVER_H

#include <QThread>

class Receiver:public QThread
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = 0);
private:
    void run();
    enum {SENDER,RECEIVER};
signals:
    void FinishReceiver();
};

#endif // RECEIVER_H
