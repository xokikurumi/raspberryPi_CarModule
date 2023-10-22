#ifndef DISPLAYVIEWTHREAD_H
#define DISPLAYVIEWTHREAD_H
#include<QThread>


class DisplayViewThread: public QThread
{
public:
    DisplayViewThread(QObject* parent=0);

protected:
    void run();

private:
    void timerHit();
};

#endif // DISPLAYVIEWTHREAD_H
