#include "fanyi.h"
#include "ui_fanyi.h"

QNetworkAccessManager *manger;

Fanyi::Fanyi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fanyi)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
    manger=new QNetworkAccessManager(this);
    QObject::connect(ui->lineEdit,SIGNAL(textChanged(
                                             QString)),SLOT(slotbutton()));
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);//隐藏问号
    QObject::connect(manger,SIGNAL(finished(QNetworkReply*)),SLOT(slotfanyijieguo()));
}

Fanyi::~Fanyi()
{
    delete ui;
}

void Fanyi::on_pushButton_clicked()
{
    QNetworkRequest *request=new QNetworkRequest();
    request->setUrl(QUrl("http://fanyi.baidu.com/v2transapi"));
    QByteArray postData;
    QByteArray ssport=ui->lineEdit->text().toUtf8();
    if(ui->comboBox->currentIndex()==0)
    {
        postData.append("from=en&to=zh&query=").append(ssport);
        reply=manger->post(*request,postData);
    }
    else if(ui->comboBox->currentIndex()==1)
    {
        postData.append("from=zh&to=en&query=").append(ssport);
        reply=manger->post(*request,postData);
    }
}

void Fanyi::slotfanyijieguo()
{
    if(reply->error()==QNetworkReply::NoError)
    {
        QByteArray bytes=reply->readAll();
        QString string=QString::fromLocal8Bit(bytes);
        int i=90;
        QString string1;
        while(string.at(i)!='"')
        {
            string1+=string.at(i);
            i++;
        }
        if(ui->comboBox->currentIndex()==0)
        {
            do{
                int idx=string1.indexOf("\\u");
                QString strHex=string1.mid(idx,6);
                strHex=strHex.replace("\\u",QString());
                int nHex=strHex.toInt(0,16);
                string1.replace(idx,6,QChar(nHex));
            } while(string1.indexOf("\\u")!=-1);
            ui->textBrowser->setText(string1);
        }
        else if(ui->comboBox->currentIndex()==1)
        {
            ui->textBrowser->setText(string1);
        }
    }
    else {
        qDebug()<<"handle errors here";
        QVariant statusCodeV=reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        qDebug("found error ... codec: %d %d\n",statusCodeV.toInt(),(int)reply->error());
    }
    reply->deleteLater();
}

void Fanyi::slotbutton()
{
    if(ui->lineEdit->text()>=1)
        ui->pushButton->setEnabled(true);
}
