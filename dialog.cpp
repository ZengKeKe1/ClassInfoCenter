#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->Name->setText(Scores(select_Name)+"同学");
    qDebug()<<globel::Usr_name;

setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);//隐藏问号
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm ddd");
   // QDateTime now = QDateTime::currentDateTime();
    ui->Time->setText("Hi,现在是"+str+"这是您大学生活的第");
   //connect(ui->ObjectC,SIGNAL(currentTextChanged(QString)),this,SLOT(ShowMScores(QString a)));
   // if(ui->Search->clicked())
   //    QString a;
   //ui->ObjectC->currentTextChanged(QString);
   // ShowMScores(ui->ObjectC->currentTextChanged(QString).toString());

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
