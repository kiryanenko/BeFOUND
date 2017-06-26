#ifndef QUERY_H
#define QUERY_H

#include <QObject>
#include <QList>
#include "globals.h"


enum RequestType {
    GetOnlineUsers = 0,
    GetAllUsers
};

enum answerType {
    OK = 0,
    Error
};


// Абстрактный класс запроса
class Query : public QObject
{
    Q_OBJECT

public:
    explicit Query();
    virtual ~Query() {}

    virtual QByteArray execute() = 0;
    virtual void onAnswer(QByteArray answer) = 0;

signals:
    void signalError(QString msg);
};


class QueryGetOnlineUsers : public Query
{
    Q_OBJECT

public:
    explicit QueryGetOnlineUsers();
    ~QueryGetOnlineUsers();

    QByteArray execute();
    void onAnswer(QByteArray answer);

signals:
    void signalError(QString msg);
    void onlineUsers(QList<Globals::User> users);
};


class QueryGetAllUsers : public Query
{
    Q_OBJECT

public:
    explicit QueryGetAllUsers();
    ~QueryGetAllUsers();

    QByteArray execute();
    void onAnswer(QByteArray answer);

signals:
    void signalError(QString msg);
    void allUsers(QList<Globals::User> users);
};


#endif // QUERY_H