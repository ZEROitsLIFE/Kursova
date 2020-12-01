#ifndef RESISTOR_TABLE_H
#define RESISTOR_TABLE_H


#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>


#define TABLE_resistor                   "resistor"
#define TABLE_model_resistor             "model"
#define TABLE_Soprotivleniye             "Sp"
#define TABLE_Moshchnost                 "Mosh"
#define TABLE_Dopusk                     "Dop"
#define TABLE_korpus                     "Korpus"


class resistor_table
{
public:
    resistor_table();
    ~resistor_table();
    bool inserIntoTable(const QVariantList &data);
    void select_all_values (QVariantList &data,QString temp);
    bool DELET(QString temp);


};

#endif // RESISTOR_TABLE_H
