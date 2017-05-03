//详细成绩查询窗口
#ifndef GPA_H
#define GPA_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPalette>

namespace Ui {
class GPA;
}

class GPA : public QDialog
{
    Q_OBJECT

public:
    explicit GPA(QWidget *parent = 0);
    ~GPA();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GPA *ui;
    void SHOW();
    void shengchenggpa();//生成平均绩点和排名
    void shengchenggegechengji();//生成各科成绩
};

#endif // GPA_H
