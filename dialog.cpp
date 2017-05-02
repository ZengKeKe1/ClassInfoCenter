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
    QString b="0";
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
    if(ui->SubChoose->currentIndex()==3)
    {
       if(Scores(select_DHomework1)==b)
          a++;
       if(Scores(select_DHomework2)==b)
          a++;
       if(Scores(select_DHomework3)==b)
          a++;
       if(Scores(select_DHomework4)==b)
          a++;
       if(Scores(select_DHomework5)==b)
          a++;
       if(Scores(select_DHomework6)==b)
          a++;
    }
    if(ui->SubChoose->currentIndex()==4)
    {
       if(Scores(select_PHomework1)==b)
          a++;
       if(Scores(select_PHomework2)==b)
          a++;
       if(Scores(select_PHomework3)==b)
          a++;
       if(Scores(select_PHomework4)==b)
          a++;
       if(Scores(select_PHomework5)==b)
          a++;
       if(Scores(select_PHomework6)==b)
          a++;
    }
    if(ui->SubChoose->currentIndex()==5)
    {
       if(Scores(select_LHomework1)==b)
          a++;
       if(Scores(select_LHomework2)==b)
          a++;
       if(Scores(select_LHomework3)==b)
          a++;
       if(Scores(select_LHomework4)==b)
          a++;
       if(Scores(select_LHomework5)==b)
          a++;
       if(Scores(select_LHomework6)==b)
          a++;
    }
   QString s = QString::number(a, 10);
    ui->HWtotal->setText(s);
}

void Dialog::showhomework()
{    if(ui->SubChoose->currentIndex()==1)
      {
      if(Scores(select_EHomework1)=="0")
      ui->HomeworkLB1->setText(Scores1(select_EHomework11));
      else  ui->HomeworkLB1->setText("完成");
      if(Scores(select_EHomework2)=="0")
      ui->HomeworkLB2->setText(Scores1(select_EHomework22));
      else  ui->HomeworkLB2->setText("完成");
      if(Scores(select_EHomework3)=="0")
      ui->HomeworkLB3->setText(Scores1(select_EHomework33));
      else  ui->HomeworkLB3->setText("完成");
      if(Scores(select_EHomework4)=="0")
      ui->HomeworkLB4->setText(Scores1(select_EHomework44));
      else  ui->HomeworkLB4->setText("完成");
      if(Scores(select_EHomework5)=="0")
      ui->HomeworkLB5->setText(Scores1(select_EHomework55));
      else  ui->HomeworkLB5->setText("完成");
      if(Scores(select_EHomework6)=="0")
      ui->HomeworkLB6->setText(Scores1(select_EHomework66));
      else  ui->HomeworkLB6->setText("完成");
   //   if(Scores(select_EHomework7)=="0")
   //   ui->HomeworkLB7->setText(Scores(select_EHomework77));
      }

    if(ui->SubChoose->currentIndex()==2)
        {
        if(Scores(select_MHomework1)=="0")
        ui->HomeworkLB1->setText(Scores1(select_MHomework11));
        else  ui->HomeworkLB1->setText("完成");
        if(Scores(select_MHomework2)=="0")
        ui->HomeworkLB2->setText(Scores1(select_MHomework22));
        else  ui->HomeworkLB2->setText("完成");
        if(Scores(select_MHomework3)=="0")
        ui->HomeworkLB3->setText(Scores1(select_MHomework33));
        else  ui->HomeworkLB3->setText("完成");
        if(Scores(select_MHomework4)=="0")
        ui->HomeworkLB4->setText(Scores1(select_MHomework44));
        else  ui->HomeworkLB4->setText("完成");
        if(Scores(select_MHomework5)=="0")
        ui->HomeworkLB5->setText(Scores1(select_MHomework55));
        else  ui->HomeworkLB5->setText("完成");
        if(Scores(select_MHomework6)=="0")
        ui->HomeworkLB6->setText(Scores1(select_MHomework66));
        else  ui->HomeworkLB6->setText("完成");
     //   if(Scores(select_MHomework7)=="0")
     //   ui->HomeworkLB7->setText(Scores(select_MHomework77));
        }

    if(ui->SubChoose->currentIndex()==3)
        {
        if(Scores(select_DHomework1)=="0")
        ui->HomeworkLB1->setText(Scores1(select_DHomework11));
        else  ui->HomeworkLB1->setText("完成");
        if(Scores(select_DHomework2)=="0")
        ui->HomeworkLB2->setText(Scores1(select_DHomework22));
        else  ui->HomeworkLB2->setText("完成");
        if(Scores(select_DHomework3)=="0")
        ui->HomeworkLB3->setText(Scores1(select_DHomework33));
        else  ui->HomeworkLB3->setText("完成");
        if(Scores(select_DHomework4)=="0")
        ui->HomeworkLB4->setText(Scores1(select_DHomework44));
        else  ui->HomeworkLB4->setText("完成");
        if(Scores(select_DHomework5)=="0")
        ui->HomeworkLB5->setText(Scores1(select_DHomework55));
        else  ui->HomeworkLB5->setText("完成");
        if(Scores(select_DHomework6)=="0")
        ui->HomeworkLB6->setText(Scores1(select_DHomework66));
        else  ui->HomeworkLB6->setText("完成");
    //    if(Scores(select_DHomework7)=="0")
    //    ui->HomeworkLB7->setText(Scores(select_DHomework77));
        }

    if(ui->SubChoose->currentIndex()==4)
        {
        if(Scores(select_PHomework1)=="0")
        ui->HomeworkLB1->setText(Scores1(select_PHomework11));
        else  ui->HomeworkLB1->setText("完成");
        if(Scores(select_PHomework2)=="0")
        ui->HomeworkLB2->setText(Scores1(select_PHomework22));
        else  ui->HomeworkLB2->setText("完成");
        if(Scores(select_PHomework3)=="0")
        ui->HomeworkLB3->setText(Scores1(select_PHomework33));
        else  ui->HomeworkLB3->setText("完成");
        if(Scores(select_PHomework4)=="0")
        ui->HomeworkLB4->setText(Scores1(select_PHomework44));
        else  ui->HomeworkLB4->setText("完成");
        if(Scores(select_PHomework5)=="0")
        ui->HomeworkLB5->setText(Scores1(select_PHomework55));
        else  ui->HomeworkLB5->setText("完成");
        if(Scores(select_PHomework6)=="0")
        ui->HomeworkLB6->setText(Scores1(select_PHomework66));
        else  ui->HomeworkLB6->setText("完成");
    //    if(Scores(select_PHomework7)=="0")
    //    ui->HomeworkLB7->setText(Scores1(select_PHomework77));
        }

    if(ui->SubChoose->currentIndex()==5)
        {
        if(Scores(select_LHomework1)=="0")
        ui->HomeworkLB1->setText(Scores1(select_LHomework11));
        else  ui->HomeworkLB1->setText("完成");
        if(Scores(select_LHomework2)=="0")
        ui->HomeworkLB2->setText(Scores1(select_LHomework22));
        else  ui->HomeworkLB2->setText("完成");
        if(Scores(select_LHomework3)=="0")
        ui->HomeworkLB3->setText(Scores1(select_LHomework33));
        else  ui->HomeworkLB3->setText("完成");
        if(Scores(select_LHomework4)=="0")
        ui->HomeworkLB4->setText(Scores1(select_LHomework44));
        else  ui->HomeworkLB4->setText("完成");
        if(Scores(select_LHomework5)=="0")
        ui->HomeworkLB5->setText(Scores1(select_LHomework55));
        else  ui->HomeworkLB5->setText("完成");
        if(Scores(select_LHomework6)=="0")
        ui->HomeworkLB6->setText(Scores1(select_LHomework66));
        else  ui->HomeworkLB6->setText("完成");
    //    if(Scores(select_LHomework7)=="0")
    //    ui->HomeworkLB7->setText(Scores1(select_LHomework77));
        }
}
QString Dialog::Scores1(QString order)
{
    QString Mtest;
    QSqlQuery sql_query;
    QString tempstring= order;
    qDebug()<<tempstring;
    qDebug()<<globel::Usr_name;
    sql_query.exec(tempstring);
    if(sql_query.next())
    Mtest=sql_query.value(0).toString();
    qDebug()<<Mtest;
    return Mtest;
}


void Dialog::on_pushButton_2_clicked()
{
     HomeworkT();
     showhomework();
}
