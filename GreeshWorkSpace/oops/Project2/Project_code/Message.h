#ifndef MESSAGE_H
#define MESSAGE_H

#include <QHash>

struct Data{
    int a = 0;
    int b = 0;
    int sum = 0;
};

class Message
{
public:
    Message();
    ~Message();
    void setData(Data data){packet = data;}
    void setId(int i){Receiver_id = i;}
    int getId(){return Receiver_id;}
    Data getData(){return packet;}
private:
    int Receiver_id;
    Data packet;
};

#endif // MESSAGE_H
