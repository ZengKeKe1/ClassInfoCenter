#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDate>
#include "translate.h"
#include "gpa.h"
#include <globle.h>
#include <QDesktopWidget>

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

        void on_pushButton_clicked();

        void on_pushButton_2_clicked();

        void on_pushButton_3_clicked();

private:
    Ui::Dialog *ui;
    QSqlDatabase database;
    QString srv;
    void ShowScores(int a);
    void ShowTime();
    void ShowName();
    void Show();
    void HomeworkT();
   // Fanyi *dialogfanyi;
    GPA *gpa;//详细成绩查询窗口
    void ShowEScores();
    void showhomework();

    QString Scores(QString order);
    QString Scores1(QString order);
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

   QString select_EHomework1 = "select HW1 from EHomework where number=";
   QString select_EHomework2 = "select HW2 from EHomework where number=";
   QString select_EHomework3 = "select HW3 from EHomework where number=";
   QString select_EHomework4 = "select HW4 from EHomework where number=";
   QString select_EHomework5 = "select HW5 from EHomework where number=";
   QString select_EHomework6 = "select HW6 from EHomework where number=";
   QString select_EHomework7 = "select HW7 from EHomework where number=";
   QString select_EHomework8 = "select HW8 from EHomework where number=";

   QString select_MHomework1 = "select HW1 from MHomework where number=";
   QString select_MHomework2 = "select HW2 from MHomework where number=";
   QString select_MHomework3 = "select HW3 from MHomework where number=";
   QString select_MHomework4 = "select HW4 from MHomework where number=";
   QString select_MHomework5 = "select HW5 from MHomework where number=";
   QString select_MHomework6 = "select HW6 from MHomework where number=";
   QString select_MHomework7 = "select HW7 from MHomework where number=";
   QString select_MHomework8 = "select HW8 from MHomework where number=";

   QString select_DHomework1 = "select HW1 from DHomework where number=";
   QString select_DHomework2 = "select HW2 from DHomework where number=";
   QString select_DHomework3 = "select HW3 from DHomework where number=";
   QString select_DHomework4 = "select HW4 from DHomework where number=";
   QString select_DHomework5 = "select HW5 from DHomework where number=";
   QString select_DHomework6 = "select HW6 from DHomework where number=";
   QString select_DHomework7 = "select HW7 from DHomework where number=";
   QString select_DHomework8 = "select HW8 from DHomework where number=";


   QString select_PHomework1 = "select HW1 from PHomework where number=";
   QString select_PHomework2 = "select HW2 from PHomework where number=";
   QString select_PHomework3 = "select HW3 from PHomework where number=";
   QString select_PHomework4 = "select HW4 from PHomework where number=";
   QString select_PHomework5 = "select HW5 from PHomework where number=";
   QString select_PHomework6 = "select HW6 from PHomework where number=";
   QString select_PHomework7 = "select HW7 from PHomework where number=";
   QString select_PHomework8 = "select HW8 from PHomework where number=";

   QString select_LHomework1 = "select HW1 from LHomework where number=";
   QString select_LHomework2 = "select HW2 from LHomework where number=";
   QString select_LHomework3 = "select HW3 from LHomework where number=";
   QString select_LHomework4 = "select HW4 from LHomework where number=";
   QString select_LHomework5 = "select HW5 from LHomework where number=";
   QString select_LHomework6 = "select HW6 from LHomework where number=";
   QString select_LHomework7 = "select HW7 from LHomework where number=";
   QString select_LHomework8 = "select HW8 from LHomework where number=";

   QString select_EHomework11 = "select English from Homework where id=1";
   QString select_EHomework22 = "select English from Homework where id=2";
   QString select_EHomework33 = "select English from Homework where id=3";
   QString select_EHomework44 = "select English from Homework where id=4";
   QString select_EHomework55 = "select English from Homework where id=5";
   QString select_EHomework66 = "select English from Homework where id=6";
   QString select_EHomework77 = "select English from Homework where id=7";
   QString select_EHomework88 = "select English from Homework where id=8";

   QString select_MHomework11 = "select Math from Homework where id=1";
   QString select_MHomework22 = "select Math from Homework where id=2";
   QString select_MHomework33 = "select Math from Homework where id=3";
   QString select_MHomework44 = "select Math from Homework where id=4";
   QString select_MHomework55 = "select Math from Homework where id=5";
   QString select_MHomework66 = "select Math from Homework where id=6";
   QString select_MHomework77 = "select Math from Homework where id=7";
   QString select_MHomework88 = "select Math from Homework where id=8";

   QString select_DHomework11 = "select ElectricandElectronicTechnique from Homework where id=1";
   QString select_DHomework22 = "select ElectricandElectronicTechnique from Homework where id=2";
   QString select_DHomework33 = "select ElectricandElectronicTechnique from Homework where id=3";
   QString select_DHomework44 = "select ElectricandElectronicTechnique from Homework where id=4";
   QString select_DHomework55 = "select ElectricandElectronicTechnique from Homework where id=5";
   QString select_DHomework66 = "select ElectricandElectronicTechnique from Homework where id=6";
   QString select_DHomework77 = "select ElectricandElectronicTechnique from Homework where id=7";
   QString select_DHomework88 = "select ElectricandElectronicTechnique from Homework where id=8";

   QString select_PHomework11 = "select physical from Homework where id=1";
   QString select_PHomework22 = "select physical from Homework where id=2";
   QString select_PHomework33 = "select physical from Homework where id=3";
   QString select_PHomework44 = "select physical from Homework where id=4";
   QString select_PHomework55 = "select physical from Homework where id=5";
   QString select_PHomework66 = "select physical from Homework where id=6";
   QString select_PHomework77 = "select physical from Homework where id=7";
   QString select_PHomework88 = "select physical from Homework where id=8";

   QString select_LHomework11 = "select DiscreteMathematics from Homework where id=1";
   QString select_LHomework22 = "select DiscreteMathematics from Homework where id=2";
   QString select_LHomework33 = "select DiscreteMathematics from Homework where id=3";
   QString select_LHomework44 = "select DiscreteMathematics from Homework where id=4";
   QString select_LHomework55 = "select DiscreteMathematics from Homework where id=5";
   QString select_LHomework66 = "select DiscreteMathematics from Homework where id=6";
   QString select_LHomework77 = "select DiscreteMathematics from Homework where id=7";
   QString select_LHomework88 = "select DiscreteMathematics from Homework where id=8";

};

#endif // DIALOG_H
