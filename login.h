#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtSql/QtSql>
#include <QSettings>
#include <qsettings.h>
#include <dialog.h>
#include <QMouseEvent>
#define MARGIN 20

namespace Ui {
class LogIn;
}

class LogIn : public QWidget
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = 0);
    ~LogIn();
    int countFlag(QPoint p, int row);
    //void setCursorType(int flag);
    int countRow(QPoint p);

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

    void on_pushButton_2_clicked();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
   // void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

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
    bool isLeftPressed;
    int curPos;
    QPoint pLast;



   void disconnect();
   void NumberWrong();
   void PasswordWrong();

};

#endif // LOGIN_H
