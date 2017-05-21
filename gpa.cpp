#include "gpa.h"
#include "ui_gpa.h"
#include "globle.h"

GPA::GPA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GPA)
{
    ui->setupUi(this);
    setWindowTitle(tr("前程命运游中寻，万代江山戏里绣"));
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);//隐藏问号

}

GPA::~GPA()
{
    delete ui;
}

void GPA::shengchenggpa()  //生成平均绩点和排名
{
    QSqlQuery gpaquery;
    gpaquery.prepare("select * from GPA where number=:d");
    gpaquery.bindValue(":d",globel::Usr_name);
    gpaquery.exec();
    if(gpaquery.next())
        ui->JidianLE->setText(gpaquery.value(12).toString());//得到平均绩点
        ui->PaimingLE->setText(gpaquery.value(13).toString());//得到绩点排名
   // ui->JidianLE->setEnabled(false); //设置平均绩点编辑条不可编辑
   // ui->PaimingLE->setEnabled(false);//设置排名编辑条不可编辑
}


void GPA::shengchenggegechengji() //生成各科成绩
{
    QPalette palyouxiu;
    palyouxiu.setColor(QPalette::Text,Qt::green);//优秀成绩设置为绿色 优秀为大于80
    QPalette palyiban;
    palyiban.setColor(QPalette::Text,Qt::darkYellow);//一般成绩设置为暗黄色 一般为小于80大于等于60
    QPalette palbujige;
    palbujige.setColor(QPalette::Text,Qt::red); //不及格成绩设置为红色，不及格为小于60

    QSqlQuery gekechengjiquery;
    gekechengjiquery.prepare("select * from GPA where number=:d");
    gekechengjiquery.bindValue(":d",globel::Usr_name);
    gekechengjiquery.exec();
    gekechengjiquery.next();

    //高数成绩
    if(gekechengjiquery.value(25).toString().toInt()>=80)
        ui->gaoshuLE->setPalette(palyouxiu);
    else if(gekechengjiquery.value(25).toString().toInt()>=60)
        ui->gaoshuLE->setPalette(palyiban);
    else ui->gaoshuLE->setPalette(palbujige);
    ui->gaoshuLE->setText(gekechengjiquery.value(25).toString());
  //  ui->gaoshuLE->setEnabled(false);

    //线性代数成绩
    if(gekechengjiquery.value(23).toString().toInt()>=80)
        ui->xianxingdaishuLE->setPalette(palyouxiu);
    else if(gekechengjiquery.value(23).toString().toInt()>=60)
        ui->xianxingdaishuLE->setPalette(palyiban);
    else ui->xianxingdaishuLE->setPalette(palbujige);
    ui->xianxingdaishuLE->setText(gekechengjiquery.value(23).toString());
  //  ui->xianxingdaishuLE->setEnabled(false);

    //职业规划成绩
    if(gekechengjiquery.value(21).toString().toInt()>=80)
        ui->zhiyeguihuaLE->setPalette(palyouxiu);
    else if(gekechengjiquery.value(21).toString().toInt()>=60)
        ui->zhiyeguihuaLE->setPalette(palyiban);
    else ui->zhiyeguihuaLE->setPalette(palbujige);
    ui->zhiyeguihuaLE->setText(gekechengjiquery.value(21).toString());
  //  ui->zhiyeguihuaLE->setEnabled(false);

    //英语成绩
    if(gekechengjiquery.value(20).toString().toInt()>=80)
        ui->yingyuLE->setPalette(palyouxiu);
    else if(gekechengjiquery.value(20).toString().toInt()>=60)
        ui->yingyuLE->setPalette(palyiban);
    else ui->yingyuLE->setPalette(palbujige);
    ui->yingyuLE->setText(gekechengjiquery.value(20).toString());
   // ui->yingyuLE->setEnabled(false);

    //心理健康成绩
    if(gekechengjiquery.value(19).toString().toInt()>=80)
        ui->xinlijiankangLE->setPalette(palyouxiu);
    else if(gekechengjiquery.value(19).toString().toInt()>=60)
        ui->xinlijiankangLE->setPalette(palyiban);
    else ui->xinlijiankangLE->setPalette(palbujige);
    ui->xinlijiankangLE->setText(gekechengjiquery.value(19).toString());
  //  ui->xinlijiankangLE->setEnabled(false);

    //近现代史成绩
    if(gekechengjiquery.value(18).toString().toInt()>=80)
        ui->jinxiandaishiLE->setPalette(palyouxiu);
    else if(gekechengjiquery.value(18).toString().toInt()>=60)
        ui->jinxiandaishiLE->setPalette(palyiban);
    else ui->jinxiandaishiLE->setPalette(palbujige);
    ui->jinxiandaishiLE->setText(gekechengjiquery.value(18).toString());
  //  ui->jinxiandaishiLE->setEnabled(false);

    //军事理论成绩
    if(gekechengjiquery.value(26).toString().toInt()>=80)
        ui->junshililunLE->setPalette(palyouxiu);
    else if(gekechengjiquery.value(26).toString().toInt()>=60)
        ui->junshililunLE->setPalette(palyiban);
    else ui->junshililunLE->setPalette(palbujige);
    ui->junshililunLE->setText(gekechengjiquery.value(26).toString());
  //  ui->junshililunLE->setEnabled(false);

    //军训成绩
    if(gekechengjiquery.value(27).toString()=="优秀")
        ui->junxunLE->setPalette(palyouxiu);
    else
        ui->junxunLE->setPalette(palyiban);
    ui->junxunLE->setText(gekechengjiquery.value(27).toString());
   // ui->junxunLE->setEnabled(false);

    //程序设计成绩
    if(gekechengjiquery.value(28).toString().toInt()>=80)
        ui->chengxudesignLE->setPalette(palyouxiu);
    else if(gekechengjiquery.value(28).toString().toInt()>=60)
        ui->chengxudesignLE->setPalette(palyiban);
    else ui->chengxudesignLE->setPalette(palbujige);
    ui->chengxudesignLE->setText(gekechengjiquery.value(28).toString());
  //  ui->chengxudesignLE->setEnabled(false);

    //计算机导论成绩
    if(gekechengjiquery.value(29).toString().toInt()>=80)
        ui->jisuanjiLE->setPalette(palyouxiu);
    else if(gekechengjiquery.value(29).toString().toInt()>=60)
        ui->jisuanjiLE->setPalette(palyiban);
    else ui->jisuanjiLE->setPalette(palbujige);
    ui->jisuanjiLE->setText(gekechengjiquery.value(29).toString());
  //  ui->jisuanjiLE->setEnabled(false);

    //程序设计实验成绩
    if(gekechengjiquery.value(30).toString()=="优秀")
        ui->chengxushiyanLE->setPalette(palyouxiu);
    else
        ui->chengxushiyanLE->setPalette(palyiban);
    ui->chengxushiyanLE->setText(gekechengjiquery.value(30).toString());
   // ui->chengxushiyanLE->setEnabled(false);
}
void GPA::SHOW()
{
    if(ui->SubChoose->currentIndex()==1)
    {
     shengchenggpa();
     shengchenggegechengji();
    }
}
void GPA::on_pushButton_clicked()
{
    SHOW();
}
