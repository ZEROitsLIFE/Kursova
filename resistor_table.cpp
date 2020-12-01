#include "resistor_table.h"

resistor_table::resistor_table()
{

}

bool resistor_table::inserIntoTable(const QVariantList &data)
{
    QSqlQuery query;
    /* В начале SQL запрос формируется с ключами,
         * которые потом связываются методом bindValue
         * для подстановки данных из QVariantList
         * */
    query.prepare("INSERT INTO " TABLE_resistor " ( " TABLE_model_resistor        " , "
                  TABLE_Soprotivleniye    " , "
                  TABLE_Moshchnost     " , "
                  TABLE_Dopusk        " , "
                  TABLE_korpus    " ) "
                                     "VALUES (:model, :S, :M, :D, :K );");
    query.bindValue(":model",        data[0].toString());
    query.bindValue(":S",          data[1].toDouble());
    query.bindValue(":M",          data[2].toDouble());
    query.bindValue(":D",           data[3].toInt());
    query.bindValue(":K",           data[4].toString());
    // После чего выполняется запросом методом exec()
    if(!query.exec()){
        qDebug() << "error insert into " << TABLE_resistor;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;

}

void resistor_table::select_all_values(QVariantList &data, QString i)
{


    QSqlQuery query1;
    if(query1.prepare("SELECT " TABLE_Soprotivleniye " , " TABLE_Moshchnost " , " TABLE_Dopusk  " , "
                    TABLE_korpus " FROM " TABLE_resistor " WHERE " TABLE_model_resistor " = \'"+i+"\' ;"))
    {} else {
            qDebug() << " error SELECT " << TABLE_resistor;
            qDebug() << query1.lastError().text();
    }
           data.append(query1.value(0).toDouble());
           data.append(query1.value(1).toDouble());
           data.append(query1.value(2).toInt());
           data.append(query1.value(3).toString());



}



bool resistor_table::DELET(QString temp)
{
    QSqlQuery query;
        query.prepare("DELETE FROM " TABLE_resistor " WHERE " TABLE_model_resistor "= \'" +temp+ "\' ;");
        if (query.exec())
           return 1;
        else
            return 0;
}
