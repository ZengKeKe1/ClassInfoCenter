#include "login.h"
#include "ui_login.h"
#include "dialog.h"
#include <QApplication>
#include <qsettings.h>


LogIn::LogIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    loadcfg();

    connect(ui->loginBtn,SIGNAL(clicked(bool)),this,SLOT(login_clicked()));
    connect(ui->NumberLE,SIGNAL(textEdited(QString)),this,SLOT(getUserInfo(QString)));
    connect(ui->Service, SIGNAL(textChanged(QString)), this, SLOT(GetServer(QString)));

    tableFlag=false;

            //QSqlDatabase db;




}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::login_clicked()
{

    GetServer(ui->Service->text());
    getUserInfo(ui->NumberLE->text());
    if(matchFlag==false)
    {
        //用户名错误
        qDebug()<<"name invalid";
        if (database.open())
        NumberWrong();
    }
    else
    {
        if(usr_passwd!=ui->PasswordLE->text())
        {
            //密码错误
            qDebug()<<"passwd not match";
            PasswordWrong();
        }
        else
        {
                  //用户名和密码均正确
            if(remeberPassword==true)
            savecfg();
            Dialog cw(this);
            this->hide();
            cw.show();
            cw.exec();    
            cw.move ((QApplication::desktop()->width() - cw.width())/2,(QApplication::desktop()->height() - cw.height())/2);
            this->close();
        }
    }
}

void LogIn::getUserInfo(QString number)
{
        //database = (QSqlDatabase::addDatabase("QMYSQL"));
           QSqlDatabase database=QSqlDatabase::addDatabase("QMYSQL");
           database.setHostName(this->srv);
           database.setDatabaseName("Scores");
           database.setUserName("usr1");
           database.setPassword("zengkeke1");

           if (database.open())

                        qDebug() << "succeed!";
           else
           {

                        qDebug() << "Failed to connect to root mysql admin";
                        disconnect();

           }

    QSqlQuery sql_query;        //改变量必须在成功打开数据库后定义才有效

    //查询部分数据(name)

    QString tempstring="select * from admin where number='"+number+"'";
    qDebug()<<tempstring;
    if(!sql_query.exec(tempstring))
    {
        qDebug()<<sql_query.lastError();
        matchFlag=false;
    }
    else
    {
        while(sql_query.next())
        {
           // usr_id = sql_query.value(2).toInt();
            usr_passwd = sql_query.value(1).toString();
            usr_name = sql_query.value(0).toString();
          //  usr_email = sql_query.value(3).toString();
          //  usr_history = sql_query.value(4).toInt();

            qDebug()<<QString("账号=%2     密码=%1").arg(usr_passwd).arg(usr_name);

        }
        if(usr_name==number)
         {
            globel::Usr_name=number;
            matchFlag=true;
        }
        else                matchFlag=false;
    }

    qDebug()<<matchFlag;


}

void LogIn::GetServer(QString srv)
{
    qDebug() << srv;
    this->srv = srv;
    globel::Srv = srv;
}

void LogIn::RemeberPd_clicked()
{
    if(ui->RememberPd->isChecked())
    {
           remeberPassword=true;
    }
    else
    {ui->PasswordLE->clear();
        remeberPassword=false;}
}

void LogIn::savecfg()
{
    QSettings cfg("fzconfig.ini",QSettings::IniFormat);
    //cfg.setValue("服务器",ui->Service->text());
    cfg.setValue("user",ui->NumberLE->text());
    cfg.setValue("password",ui->PasswordLE->text());
    cfg.setValue("remeber", ui->RememberPd->isChecked());
   // usr_name=ui->NumberLE->text();
   // usr_passwd=ui->PasswordLE->text();
    cfg.sync();
}

void LogIn::loadcfg()
{
    QSettings cfg("fzconfig.ini",QSettings::IniFormat);
    ui->RememberPd->setChecked(cfg.value("remeber").toBool());
    if(ui->RememberPd->isChecked())
    {    ui->NumberLE->setText(cfg.value("user").toString());
         ui->PasswordLE->setText(cfg.value("password").toString());
        // ui->Service->setText(cfg.value("服务器").toString());
       //  ui->PasswordLE->setText(usr_passwd);
   }

     //if(RemeberPassword=="true")
   // {
   //     qDebug()<<true;
   //     ui->RememberPd->setChecked(true);
  //  }
  //  qDebug()<<false;
}
void LogIn::disconnect()
{
    QLabel *Dialog = new QLabel;
    Dialog->setWindowTitle("微冷");
    Dialog->setText("连接服务器失败,请修改服务器地址");
    Dialog->setMaximumHeight(50);
    Dialog->setMaximumWidth(230);
    Dialog->setMinimumHeight(50);
    Dialog->setMinimumWidth(230);
    Dialog->setAlignment(Qt::AlignCenter);
    Dialog->setWindowModality(Qt::ApplicationModal);
    Dialog->show();
    Dialog->move ((QApplication::desktop()->width() - Dialog->width())/2,(QApplication::desktop()->height() - Dialog->height())/2);
}
void LogIn::NumberWrong()
{
    QLabel *Dialog = new QLabel;
    Dialog->setWindowTitle("微冷");
    Dialog->setText("学号错误,请检查学号");
    Dialog->setMaximumHeight(50);
    Dialog->setMaximumWidth(230);
    Dialog->setMinimumHeight(50);
    Dialog->setMinimumWidth(230);
    //Dialog->setParent(this);
    Dialog->setAlignment(Qt::AlignCenter);
    Dialog->setWindowModality(Qt::ApplicationModal);
    Dialog->show();
    Dialog->move ((QApplication::desktop()->width() - Dialog->width())/2,(QApplication::desktop()->height() - Dialog->height())/2);
}
void LogIn::PasswordWrong()
{
    QLabel *Dialog = new QLabel;
   // QLabel *Label = new QLabel(Dialog);
    Dialog->setWindowTitle("微冷");
    Dialog->setText("密码错误，请重新输入");
    Dialog->setMaximumHeight(50);
    Dialog->setMaximumWidth(230);
    Dialog->setMinimumHeight(50);
    Dialog->setMinimumWidth(230);
    Dialog->setAlignment(Qt::AlignCenter);
    Dialog->setWindowModality(Qt::ApplicationModal);
    //Label->setParent(Dialog);
    //Dialog->setParent(this);
    Dialog->show();
    Dialog->move ((QApplication::desktop()->width() - Dialog->width())/2,(QApplication::desktop()->height() - Dialog->height())/2);
}
