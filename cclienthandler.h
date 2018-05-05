#ifndef CCLIENTHANDLER_H
#define CCLIENTHANDLER_H
#include<QString>
#include<QDebug>

class CClientHandler
{
private:
    const char* message;
public:
    CClientHandler();
    void handleCommand(QString str);
    const char* getMessage();
};

#endif // CCLIENTHANDLER_H
