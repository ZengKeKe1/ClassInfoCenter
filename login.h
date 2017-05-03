#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtSql/QtSql>
#include <QSettings>
#include <qsettings.h>
#include <dialog.h>

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
    void getUserInfo(QString number);
    //void GetServer(QString name);
    void RemeberPd_clicked();
    void savecfg();
    void loadcfg();

    void on_pushButton_clicked();

private:
    Ui::LogIn *ui;
    Fanyi *loginfanyi;
    Dialog *cw;
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
