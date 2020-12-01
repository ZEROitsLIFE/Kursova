#ifndef DIOD_TABLE_H
#define DIOD_TABLE_H


#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>


#define TABLE_diod                   "doid"
#define TABLE_model_diod             "model"
#define TABLE_U_obr_max         "U_obr_max"
#define TABLE_I_pr_max          "I_pr_max"
#define TABLE_I_prh             "I_prh"
#define TABLE_F_rab             "F_rab"
#define TABLE_U_pr              "U_pr"
#define TABLE_I_pr              "I_pr"
#define TABLE_I_obr             "I_obr"
#define TABLE_T_k_max           "T_k_max"

class diod_table
{
public:
    diod_table();
    ~diod_table();
    bool inserIntoTable(const QVariantList &data);
    void select_all_values(QVariantList &data,QString);
    bool DELET(QString temp);


private:






};

#endif // DIOD_TABLE_H
