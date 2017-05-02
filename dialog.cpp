#include "dialog.h"
#include "ui_dialog.h"
#include "translate.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);//隐藏问号
   // connect(ui->SubChoose,SIGNAL(currentIndexChanged(QString)),this,SLOT(Dialog::HomeworkT(QString)));
    Show();
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::Scores(QString order)
{
    QString Mtest;
    QSqlQuery sql_query;
    QString tempstring= order+globel::Usr_name;
    qDebug()<<tempstring;
    qDebug()<<globel::Usr_name;
    sql_query.exec(tempstring);
    if(sql_query.next())
    Mtest=sql_query.value(0).toString();
    qDebug()<<Mtest;
    return Mtest;
}

void Dialog::ShowScores(int a)
{
  if(a==1)
  {
    ui->Mtest1LE->setText(Scores(select_Mtest1));
    ui->Mtest2LE->setText(Scores(select_Mtest2));
    ui->Mtest3LE->setText(Scores(select_Mtest3));
    ui->Mtest4LE->setText(Scores(select_Mtest4));
    ui->Mtest5LE->setText(Scores(select_Mtest5));
    ui->Mtest6LE->setText(Scores(select_Mtest6));

    ui->ScoreLB1->setText("第一次成绩:");
    ui->ScoreLB2->setText("第二次成绩:");
    ui->ScoreLB3->setText("第三次成绩:");
    ui->ScoreLB4->setText("第四次成绩:");
    ui->ScoreLB5->setText("第五次成绩:");
    ui->ScoreLB6->setText("平时成绩:");
  }
//}
//void Dialog::showEScores()
//{
   if(a==2)
 {
    ui->Mtest1LE->setText(Scores(select_Etest1));
    ui->Mtest2LE->setText(Scores(select_Etest2));
    ui->Mtest3LE->setText(Scores(select_Etest3));
    ui->Mtest4LE->setText(Scores(select_Etest4));
    ui->Mtest5LE->setText(Scores(select_Etest5));
    ui->Mtest6LE->setText(Scores(select_Etest6));

    ui->ScoreLB1->setText("第一次听写:");
    ui->ScoreLB2->setText("期中小测:");
    ui->ScoreLB3->setText("第三次成绩:");
    ui->ScoreLB4->setText("第四次成绩:");
    ui->ScoreLB5->setText("第五次成绩:");
    ui->ScoreLB6->setText("平时成绩:");
 }
}
/*  if(Scores(select_Mtest1)==NULL)
      ui->Mtest1LE->hide();
  if(Scores(select_Mtest2)==NULL)
      ui->Mtest2LE->hide();
  if(Scores(select_Mtest3)==NULL)
      ui->Mtest3LE->hide();
  if(Scores(select_Mtest4)==NULL)
      ui->Mtest4LE->hide();
  if(Scores(select_Mtest5)==NULL)
      ui->Mtest5LE->hide();
  if(Scores(select_Mtest6)==NULL)
      ui->Mtest6LE->hide();
*/



void Dialog::on_MathPB_clicked()
{
    ShowScores(1);
}

void Dialog::on_EnglishPB_clicked()
{
    ShowScores(2);
}

void Dialog::ShowTime()
{
    QDate time = QDate::currentDate();
    QString Days = time.toString("yyyy-MM-dd");
    QDate time1,time2,time3,time4;
    time1.setDate(2017,02,17);
    time2.setDate(2017,07,02);
    time3.setDate(2016,9,02);
    time4.setDate(2020,07,01);
    qint64 days1 = time1.daysTo(time);
    qint64 days2 = time.daysTo(time2);
    qint64 days3 = time3.daysTo(time);
    qint64 days4 = time.daysTo(time4);
    QString Days1 = QString::number(days1);
    QString Days2 = QString::number(days2);
    QString Days3 = QString::number(days3);
    QString Days4 = QString::number(days4);
   // QDateTime now = QDateTime::currentDateTime();
    ui->Time->setWordWrap(true);
    ui->Time->setText("Hi,今天是"+Days+",这是本学期的第"+Days1+"天，距离本学期结束还有"+Days2+"这是您大学生活的第"+Days3+"天,离毕业还有"+Days4+"天，祝您心情愉快");
   //connect(ui->ObjectC,SIGNAL(currentTextChanged(QString)),this,SLOT(ShowMScores(QString a)));
   // if(ui->Search->clicked())
   //    QString a;
   //ui->ObjectC->currentTextChanged(QString);
   // ShowMScores(ui->ObjectC->currentTextChanged(QString).toString());

}
void Dialog::ShowName()
{
    ui->Name->setText(Scores(select_Name)+"同学");
    qDebug()<<globel::Usr_name;

}

void Dialog::on_pushButton_clicked()
{
    dialogfanyi=new Fanyi();
    dialogfanyi->show();
}

void Dialog::Show()
{
    ShowTime();
    ShowName();
}

void Dialog::HomeworkT()
{
    int a=0;
    QString b=NULL;
   if(ui->SubChoose->currentIndex()==1)
  {
      if(Scores(select_EHomework1)==b)
        a++;
      if(Scores(select_EHomework2)==b)
        a++;
      if(Scores(select_EHomework3)==b)
        a++;
      if(Scores(select_EHomework4)==b)
        a++;
      if(Scores(select_EHomework5)==b)
        a++;
      if(Scores(select_EHomework6)==b)
        a++;
    }
    if(ui->SubChoose->currentIndex()==2)
    {
       if(Scores(select_MHomework1)==b)
          a++;
       if(Scores(select_MHomework2)==b)
          a++;
       if(Scores(select_MHomework3)==b)
          a++;
       if(Scores(select_MHomework4)==b)
          a++;
       if(Scores(select_MHomework5)==b)
          a++;
       if(Scores(select_MHomework6)==b)
          a++;
    }

   QString s = QString::number(a, 10);
    ui->HWtotal->setText(s);
}


void Dialog::on_pushButton_2_clicked()
{
     HomeworkT();
}
