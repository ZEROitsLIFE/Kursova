#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QTableView>
#include <QLineEdit>
#include <QRadioButton>
#include <QMessageBox>
#include <QDebug>


/* Подключаем заголовочный файл для работы с информацией, которая помещена в базу данных */
#include "database.h"
#include "diod_table.h"
#include "resistor_table.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_lineEdit_model_textChanged(const QString &arg1);
    void on_pushButton_3_clicked();
    void diodbuttonclear();



    void on_pushButton_4_clicked();
    void on_tableView_3_doubleClicked(const QModelIndex &index);
    void on_lineEdit_r_model_textChanged(const QString &arg1);
    void on_pushButton_6_clicked();
    void resistorbuttonclear();



    void on_radioButton_toggled(bool checked);

    void on_pushButton_5_clicked();

    void on_radioButton_2_toggled(bool checked);

private:
    Ui::MainWindow  *ui;
    /* В проекте используются объекты для взаимодействия с информацией в базе данных
     * и моделью представления таблицы базы данных
     * */
    DataBase        *db;
    diod_table      *db_t;
    resistor_table  *db_r;
    QSqlQueryModel  *model,*modeldiod;
    QSqlQueryModel  *model_resistor,*modelr;


private:

    void setup_all_Model_diod();
    void createUI(QSqlQueryModel &model);
    void setupModeldiod(QString Qtemp);

    void setup_all_Model_resistor();
    void createUIresistor(QSqlQueryModel &model);
    void setupModelresistor(QString Qtemp);




    bool questionQMB(QString massege);

};

#endif // MAINWINDOW_H
