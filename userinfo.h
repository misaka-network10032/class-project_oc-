#ifndef USERINFO_H
#define USERINFO_H
#include <QWidget>
#include <QVector>


class userinfo
{
private:
    QString id;
public:
    userinfo();
    userinfo(QString tid)
    {
        id=tid;
    }
};

#endif // USERINFO_H
