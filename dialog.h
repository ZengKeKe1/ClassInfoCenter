#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <login.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT   

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
        void on_MathPB_clicked();

        void on_EnglishPB_clicked();

private:
    Ui::Dialog *ui;
    QSqlDatabase database;
    QString srv;
    void ShowScores(int a);
   // void ShowEScores();

    QString Scores(QString order);
    QString select_Name="select name from admin where number=";
    QString select_Mtest1 = "select test1 from MScores where number=";
    QString select_Mtest2 = "select test2 from MScores where number=";
    QString select_Mtest3 = "select test3 from MScores where number=";
    QString select_Mtest4 = "select test4 from MScores where number=";
    QString select_Mtest5 = "select test5 from MScores where number=";
    QString select_Mtest6 = "select testC from MScores where number=";

    QString select_Etest1 = "select test1 from EScores where number=";
    QString select_Etest2 = "select test2 from EScores where number=";
    QString select_Etest3 = "select test3 from EScores where number=";
    QString select_Etest4 = "select test4 from EScores where number=";
    QString select_Etest5 = "select test5 from EScores where number=";
    QString select_Etest6 = "select testC from EScores where number=";
};

#endif // DIALOG_H
