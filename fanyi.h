#ifndef FANYI_H
#define FANYI_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkRequest>
#include <QNetworkReply>

namespace Ui {
class Fanyi;
}

class Fanyi : public QDialog
{
    Q_OBJECT

public:
    explicit Fanyi(QWidget *parent = 0);
    ~Fanyi();

private slots:
    void on_pushButton_clicked();
    void slotfanyijieguo();
    void slotbutton();

private:
    Ui::Fanyi *ui;
    QNetworkReply *reply;
};

#endif // FANYI_H
