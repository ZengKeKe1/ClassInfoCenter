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
    setWindowIcon(QIcon(QStringLiteral(":/Sources/class.ico")));
    setWindowFlags(Qt::FramelessWindowHint);
    this->setMouseTracking(true);
        //设置在不按鼠标的情况下也触发鼠标移动事件，注意QMainWindow的情况:centralWidget()->setMouseTracking(true);
        isLeftPressed=false;
        curPos=0;//标记鼠标左击时的位置
        this->setMinimumSize(400,300);//设置最小尺寸
        QCursor cursor;
        cursor.setShape(Qt::ArrowCursor);//设置鼠标为箭头形状
       // ui->pushButton->setCursor(cursor);//当放在按钮上时，为箭头
       // cursor.setShape(Qt::OpenHandCursor);
        QWidget::setCursor(cursor);//当放在主窗口上时，为手形
        qDebug()<<"h="<<this->height();
        setWindowFlags(Qt::FramelessWindowHint);//设置主窗口无边框
        qDebug()<<this->minimumHeight();
   //this->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/Sources/829658.png").scaled(this->size())));
   this->setPalette(palette);
    loadcfg();

    ui->PasswordLE->setEchoMode(QLineEdit::Password);
    connect(ui->loginBtn,SIGNAL(clicked(bool)),this,SLOT(getUserInfo()));
    connect(ui->loginBtn,SIGNAL(clicked(bool)),this,SLOT(login_clicked()));
    //connect(ui->NumberLE,SIGNAL(textEdited(QString)),this,SLOT(getUserInfo(QString)));
    //connect(ui->Service, SIGNAL(textChanged(QString)), this, SLOT(GetServer(QString)));  
    connect(ui->PasswordLE,SIGNAL(returnPressed()),this,SLOT(login_clicked()));
    connect(ui->NumberLE,SIGNAL(returnPressed()),this,SLOT(login_clicked()));

    tableFlag=false;

            //QSqlDatabase db;




}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::login_clicked()
{

    //GetServer(ui->Service->text());
    getUserInfo(ui->NumberLE->text());
    if(matchFlag==false)
    {
        //用户名错误
        qDebug()<<"name invalid";
        //if (database.open())
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
            //Dialog cw(this);
            cw = new Dialog();
            this->hide();
            cw->show();
            cw->exec();
            this->close();
            //cw.move ((QApplication::desktop()->width() - cw.width())/2,(QApplication::desktop()->height() - cw.height())/2);
            //this->close();
        }
    }
}

void LogIn::getUserInfo(QString number)
{
           number=ui->NumberLE->text();
        //database = (QSqlDatabase::addDatabase("QMYSQL"));
           QSqlDatabase database=QSqlDatabase::addDatabase("QMYSQL");
           database.setHostName("119.29.206.109");
           database.setDatabaseName("Scores");
           database.setUserName("guanli1");
           database.setPassword("zengkeke1");

           if (!database.open())
           {
               qDebug() << "Failed to connect to root mysql admin";
                  disconnect();
           }

           else
           {
                  qDebug() << "succeed!";
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
        if(usr_name==number&&usr_name!=NULL)
         {
            globel::Usr_name=number;
            matchFlag=true;
        }
        else                matchFlag=false;
    }

    qDebug()<<matchFlag;


}

/*void LogIn::GetServer(QString srv)
{
    qDebug() << srv;
    this->srv = srv;
    globel::Srv = srv;
}
*/
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
    Dialog->setText("连接服务器失败,请检查您的网络");
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

void LogIn::on_pushButton_clicked()
{
   /* loginfanyi=new*/Fanyi aw(this);
    aw.show();
    aw.exec();
  //  aw.move ((QApplication::desktop()->width() - aw.width())/2,(QApplication::desktop()->height() - aw.height())/2);
}


void LogIn::on_pushButton_2_clicked()
{
    this->close();
}
void LogIn::mousePressEvent(QMouseEvent *event)//鼠标按下事件
{
    if(event->button()==Qt::LeftButton)
    {
        this->isLeftPressed=true;
        QPoint temp=event->globalPos();
        pLast=temp;
        curPos=countFlag(event->pos(),countRow(event->pos()));
        event->ignore();
    }
}

void LogIn::mouseReleaseEvent(QMouseEvent *event)//鼠标释放事件
{
    if(isLeftPressed)
        isLeftPressed=false;
    //QApplication::restoreOverrideCursor();//恢复鼠标指针性状
    event->ignore();
}

/*void LogIn::mouseDoubleClickEvent(QMouseEvent *event)//鼠标双击 全屏
{
    if(event->button()==Qt::LeftButton)
    {
        if(windowState()!=Qt::WindowFullScreen)
            setWindowState(Qt::WindowFullScreen);
        else setWindowState(Qt::WindowNoState);//恢复正常模式
    }
    event->ignore();
}
*/

void LogIn::mouseMoveEvent(QMouseEvent *event)//鼠标移动事件
{

   // int poss=countFlag(event->pos(),countRow(event->pos()));
    //setCursorType(poss);
    if(isLeftPressed)//是否左击
    {
        QPoint ptemp=event->globalPos();
        ptemp=ptemp-pLast;
        if(curPos==22)//移动窗口
        {
            ptemp=ptemp+pos();
            move(ptemp);
        }
        else
        {
          /*  QRect wid=geometry();

            switch(curPos)//改变窗口的大小
            {

            case 11:wid.setTopLeft(wid.topLeft()+ptemp);break;//左上角
            case 13:wid.setTopRight(wid.topRight()+ptemp);break;//右上角
            case 31:wid.setBottomLeft(wid.bottomLeft()+ptemp);break;//左下角
            case 33:wid.setBottomRight(wid.bottomRight()+ptemp);break;//右下角
            case 12:wid.setTop(wid.top()+ptemp.y());break;//中上角
            case 21:wid.setLeft(wid.left()+ptemp.x());break;//中左角
            case 23:wid.setRight(wid.right()+ptemp.x());break;//中右角
            case 32:wid.setBottom(wid.bottom()+ptemp.y());break;//中下角
            }
            setGeometry(wid);
       */}


        pLast=event->globalPos();//更新位置
    }
    event->ignore();
}



int LogIn::countFlag(QPoint p,int row)//计算鼠标在哪一列和哪一行
{
    if(p.y()<MARGIN)
        return 10+row;
    else if(p.y()>this->height()-MARGIN)
        return 30+row;
    else
        return 20+row;
}

/*void LogIn::setCursorType(int flag)//根据鼠标所在位置改变鼠标指针形状
{
    Qt::CursorShape cursor;
    switch(flag)
    {
    case 11:
    case 33:
        cursor=Qt::SizeFDiagCursor;break;
    case 13:
    case 31:
        cursor=Qt::SizeBDiagCursor;break;
    case 21:
    case 23:
        cursor=Qt::SizeHorCursor;break;
    case 12:
    case 32:
        cursor=Qt::SizeVerCursor;break;
    case 22:
        cursor=Qt::OpenHandCursor;break;
    default:
        QApplication::restoreOverrideCursor();//恢复鼠标指针性状
         break;

    }
    setCursor(cursor);
}
*/
int LogIn::countRow(QPoint p)//计算在哪一列
{
    return (p.x()<MARGIN)?1:(p.x()>(this->width()-MARGIN)?3:2);
}
