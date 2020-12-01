#include "diod_table.h"

diod_table::diod_table()
{

}


bool diod_table::inserIntoTable(const QVariantList &data)
{
    QSqlQuery query;
    /* В начале SQL запрос формируется с ключами,
         * которые потом связываются методом bindValue
         * для подстановки данных из QVariantList
         * */
    query.prepare("INSERT INTO " TABLE_diod " ( " TABLE_model_diod        " , "
                  TABLE_U_obr_max    " , "
                  TABLE_I_pr_max     " , "
                  TABLE_I_prh        " , "
                  TABLE_F_rab        " , "
                  TABLE_U_pr         " , "
                  TABLE_I_pr         " , "
                  TABLE_I_obr        " , "
                  TABLE_T_k_max      " ) "
                                     "VALUES (:model, :Uom, :Ipm, :Ip, :Fr, :Upr, :Ipr, :To, :Tkm );");
    query.bindValue(":model",        data[0].toString());
    query.bindValue(":Uom",          data[1].toInt());
    query.bindValue(":Ipm",          data[2].toInt());
    query.bindValue(":Ip",           data[3].toDouble());
    query.bindValue(":Fr",           data[4].toInt());
    query.bindValue(":Upr",          data[5].toDouble());
    query.bindValue(":Ipr",          data[6].toDouble());
    query.bindValue(":To",           data[7].toInt());
    query.bindValue(":Tkm",          data[8].toInt());
    // После чего выполняется запросом методом exec()
    if(!query.exec()){
        qDebug() << "error insert into " << TABLE_diod;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}



void diod_table::select_all_values(QVariantList &data,QString temp)
{

    QSqlQuery query;
    if(!query.prepare("SELECT " TABLE_model_diod " , " TABLE_U_obr_max " , " TABLE_I_pr_max " , " TABLE_I_prh " , " TABLE_F_rab  " , "
                      TABLE_U_pr " , " TABLE_I_pr  " , " TABLE_I_obr " , " TABLE_T_k_max  " FROM " TABLE_diod " WHERE " TABLE_model_diod" = \'" +temp+ "\' ;"))
    {
        qDebug() << "SELECT error" << TABLE_diod;
        qDebug() << query.lastError().text();
    }
    else {

        data.append(query.value(0).toString());
        data.append(query.value(1).toInt());
        data.append(query.value(2).toInt());
        data.append(query.value(3).toDouble());
        data.append(query.value(4).toInt());
        data.append(query.value(5).toDouble());
        data.append(query.value(6).toDouble());
        data.append(query.value(7).toInt());
        data.append(query.value(8).toInt());




}
}

bool diod_table::DELET(QString temp)
{

    QSqlQuery query;
    query.prepare("DELETE FROM " TABLE_diod " WHERE " TABLE_model_diod "= \'" +temp+ "\' ;");
    if (query.exec())
        return 1;
    else
        return 0;

}
