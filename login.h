#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtSql/QtSql>
#include "dialog.h"
#include <QSettings>
#include <QDesktopWidget>
#include <globle.h>

namespace Ui {
class LogIn;
}

class LogIn : public QWidget
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = 0);
    ~LogIn();

signals:
    void TransmitDb(QSqlDatabase database);

private slots:
    void login_clicked();
    void getUserInfo(QString name);
    void GetServer(QString name);
    void RemeberPd_clicked();
    void savecfg();
    void loadcfg();

private:
    Ui::LogIn *ui;
    QSqlDatabase database;
    QString usr_passwd;
    bool tableFlag;
    bool matchFlag;
    QString RemeberPassword;
    bool remeberPassword;
    QString usr_name;
    QString srv;
    int usr_id;



   void disconnect();
   void NumberWrong();
   void PasswordWrong();
};

#endif // LOGIN_H
