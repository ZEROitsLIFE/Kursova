#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

/* Методы для подключения к базе данных
 * */
void DataBase::connectToDataBase()
{
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
    if(!QFile(DATABASE_NAME).exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();


    }
}

/* Методы восстановления базы данных
 * */
bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createTable() || !this->createTabel2()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
    return false;
}

/* Метод для открытия базы данных
 * */
bool DataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

/* Методы закрытия базы данных
 * */
void DataBase::closeDataBase()
{
    db.close();
}

/* Метод для создания таблицы в базе данных
 * */
bool DataBase::createTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
         * с последующим его выполнением.
         * */
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " TABLE_diod " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    TABLE_model_diod    " VARCHAR(20)        NOT NULL,"
                    TABLE_U_obr_max" INTEGER            NOT NULL,"
                    TABLE_I_pr_max " INTEGER            NOT NULL,"
                    TABLE_I_prh    " DOUBLE(10,1)               ,"
                    TABLE_F_rab    " INTEGER                    ,"
                    TABLE_U_pr     " DOUBLE(10,1)       NOT NULL,"
                    TABLE_I_pr     " DOUBLE(10,1)       NOT NULL,"
                    TABLE_I_obr    " INTEGER            NOT NULL,"
                    TABLE_T_k_max  " INTEGER            NOT NULL"
                    " );"
                    )){
        qDebug() << "DataBase: error of create  " << TABLE_diod;
        qDebug() << query.lastError().text();





        return false;
    } else {
        return true;
    }
    return false;

}

bool DataBase::createTabel2()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " TABLE_resistor " ("
                                                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   TABLE_model_resistor    " VARCHAR(30)        NOT NULL, "
                   TABLE_Soprotivleniye    " DOUBLE(10,2)            NOT NULL, "
                   TABLE_Moshchnost        " DOUBLE(10,2)            NOT NULL, "
                   TABLE_Dopusk            " INTEGER               NOT NULL, "
                   TABLE_korpus            " VARCHAR(50)                    "
                                   " );"
                   )){
        qDebug() << "DataBase: error of create  " << TABLE_resistor;
        qDebug() << query.lastError().text();

        return false;
    } else {
        return true;
    }
    return false;
}


