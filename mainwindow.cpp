#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->radioButton_2->click();


    db = new DataBase();
    db->connectToDataBase();


    this->setup_all_Model_diod();
    this->createUI(*model);

    this->setup_all_Model_resistor();
    this->createUIresistor(*model_resistor);


}

MainWindow::~MainWindow()
{
    delete ui;
}

//------------------------------------------------------DIOD_TABLE_---------------------------------------------------------//
void MainWindow::setup_all_Model_diod()
{
    model = new QSqlQueryModel(this);
    model->setQuery("SELECT " TABLE_model_diod  " FROM " TABLE_diod " ; ");
    if (model->lastError().isValid())
        qDebug() << model->lastError();

    model->setHeaderData(0,Qt::Horizontal,tr("Модель"));
}

void MainWindow::createUI(QSqlQueryModel &model)
{

    ui->tableView->setModel(&model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


}

void MainWindow::setupModeldiod(QString Qtemp)
{
    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
     * */
    modeldiod = new QSqlQueryModel();
    QString temp = Qtemp;
    modeldiod->setQuery("SELECT " TABLE_model_diod  " FROM " TABLE_diod " WHERE " TABLE_model_diod " LIKE \'" +Qtemp+ "%\'  ; ");
    if (modeldiod->lastError().isValid())
        qDebug() << modeldiod->lastError();

    modeldiod->setHeaderData(0,Qt::Horizontal,tr("Модель"));
}

void MainWindow::on_pushButton_clicked()
{

  QVariantList     data;

    data.append(ui->lineEdit_model->text());
    data.append(ui->lineEdit_U_obr_max->text().toInt());
    data.append(ui->lineEdit_I_pr_max->text().toInt());
    data.append(ui->lineEdit_I_prh->text().toDouble());
    data.append(ui->lineEdit_F_rab->text().toInt());
    data.append(ui->lineEdit_U_pr->text().toDouble());
    data.append(ui->lineEdit_I_pr->text().toDouble());
    data.append(ui->lineEdit_I_obr->text().toInt());
    data.append(ui->lineEdit_T_k_max->text().toInt());

    db_t->inserIntoTable(data);
    data.clear();
    MainWindow::diodbuttonclear();



    this->setup_all_Model_diod();
    this->createUI(*model);

}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
      QVariantList     data;
    MainWindow::diodbuttonclear();
    QString temp =index.data().toString();
    qDebug() << temp;

    db_t->select_all_values(data,temp);
     qDebug()<<data;
    ui->lineEdit_model->setText(QString("%1").arg(data.value(0).toString()));
    ui->lineEdit_U_obr_max->setText(QString("%1").arg(data.value(1).toInt()));
    ui->lineEdit_I_pr_max->setText(QString("%1").arg(data.value(2).toInt()));
    ui->lineEdit_I_prh->setText(QString("%1").arg(data.value(3).toDouble()));
    ui->lineEdit_F_rab->setText(QString("%1").arg(data.value(4).toInt()));
    ui->lineEdit_U_pr->setText(QString("%1").arg(data.value(5).toDouble()));
    ui->lineEdit_I_pr->setText(QString("%1").arg(data.value(6).toDouble()));
    ui->lineEdit_I_obr->setText(QString("%1").arg(data.value(7).toInt()));
    ui->lineEdit_T_k_max->setText(QString("%1").arg(data.value(8).toInt()));
     qDebug()<<data;

}

void MainWindow::on_lineEdit_model_textChanged(const QString &arg1)
{
    this->setupModeldiod(arg1);
    this->createUI(*modeldiod);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->statusBar->showMessage("...");
    if(questionQMB("Ви справді бажаєте видалити цей елемент?"))
    { db_t->DELET(ui->lineEdit_model->text());
        createUI(*model);
        MainWindow::diodbuttonclear();

    }

}

void MainWindow::diodbuttonclear()
{
    ui->lineEdit_model->clear();
    ui->lineEdit_U_obr_max->clear();
    ui->lineEdit_I_pr_max->clear();
    ui->lineEdit_I_prh->clear();
    ui->lineEdit_F_rab->clear();
    ui->lineEdit_U_pr->clear();
    ui->lineEdit_I_pr->clear();
    ui->lineEdit_I_obr->clear();
    ui->lineEdit_T_k_max->clear();

}

//------------------------------------------------------DIOD_TABLE_---------------------------------------------------------//

//------------------------------------------------------RESISTOR_TABLE_---------------------------------------------------------//
void MainWindow::setup_all_Model_resistor()
{
    model_resistor = new QSqlQueryModel(this);
    model_resistor->setQuery("SELECT " TABLE_model_resistor  " FROM " TABLE_resistor " ; ");
    if (model_resistor->lastError().isValid())
        qDebug() << model_resistor->lastError();

    model_resistor->setHeaderData(0,Qt::Horizontal,tr("Модель"));

}

void MainWindow::createUIresistor(QSqlQueryModel &model)
{
    ui->tableView_3->setModel(&model);
    ui->tableView_3->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->tableView_3->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_3->resizeColumnsToContents();
    ui->tableView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_3->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::setupModelresistor(QString Qtemp)
{

    modelr = new QSqlQueryModel();
    QString temp = Qtemp;
    modelr->setQuery("SELECT " TABLE_model_resistor  " FROM " TABLE_resistor " WHERE " TABLE_model_resistor " LIKE \'" +Qtemp+ "%\'  ; ");
    if (modelr->lastError().isValid())
        qDebug() << modelr->lastError();

    modelr->setHeaderData(0,Qt::Horizontal,tr("Модель"));
}

void MainWindow::on_pushButton_4_clicked()
{
      QVariantList     data;

    data.append(ui->lineEdit_r_model->text());
    data.append(ui->lineEdit_r_s->text().toDouble());
    data.append(ui->lineEdit_r_pover->text().toDouble());
    data.append(ui->lineEdit_r_dopusk->text().toInt());
    data.append(ui->lineEdit_r_korpus->text());

    db_r->inserIntoTable(data);
    this->resistorbuttonclear();




};

void MainWindow::on_tableView_3_doubleClicked(const QModelIndex &index)
{
    this->resistorbuttonclear();
  QVariantList     data;
    QString i=index.data().toString();
    qDebug() << i;
    db_r->select_all_values(data,i);
    qDebug()<<data.value(0);
    ui->lineEdit_r_model->setText(QString("%1").arg(i));
    ui->lineEdit_r_s->setText(QString("%1").arg(data.value(0).toDouble()));
    ui->lineEdit_r_pover->setText(QString("%1").arg(data.value(1).toDouble()));
    ui->lineEdit_r_dopusk->setText(QString("+-%1%").arg(data.value(2).toInt()));
    ui->lineEdit_r_korpus->setText(QString("%1").arg(data.value(3).toString()));
    qDebug()<<data;

}

void MainWindow::on_lineEdit_r_model_textChanged(const QString &arg1)
{
    this->setupModelresistor(arg1);
    this->createUIresistor(*modelr);

}

void MainWindow::on_pushButton_5_clicked()
{
    ui->statusBar->showMessage("...");
    if(questionQMB("Ви справді бажаєте видалити цей елемент?"))
    { db_r->DELET(ui->lineEdit_r_model->text());
        this->resistorbuttonclear();
    }
}

void MainWindow::resistorbuttonclear()
{
    ui->lineEdit_r_model->clear();
    ui->lineEdit_r_s->clear();
    ui->lineEdit_r_pover->clear();
    ui->lineEdit_r_dopusk->clear();
    ui->lineEdit_r_korpus->clear();
}
//------------------------------------------------------RESISTOR_TABLE_---------------------------------------------------------//




void MainWindow::on_pushButton_6_clicked()
{
    ui->statusBar->showMessage("...");
    if(this->questionQMB("Вийти?"))
      {  this->close();
        db->closeDataBase();
    }
}




void MainWindow::on_radioButton_2_toggled(bool checked)
{
    ui->lineEdit_model->clear();
    ui->lineEdit_U_obr_max->clear();
    ui->lineEdit_I_pr_max->clear();
    ui->lineEdit_I_prh->clear();
    ui->lineEdit_F_rab->clear();
    ui->lineEdit_U_pr->clear();
    ui->lineEdit_I_pr->clear();
    ui->lineEdit_I_obr->clear();
    ui->lineEdit_T_k_max->clear();


    ui->lineEdit_r_model->clear();
    ui->lineEdit_r_s->clear();
    ui->lineEdit_r_pover->clear();
    ui->lineEdit_r_dopusk->clear();
    ui->lineEdit_r_korpus->clear();


    if(checked){


        //""""""""""""""""""""""Diod"""""""""""""""""""
        ui->lineEdit_model->setReadOnly(false);
        ui->lineEdit_U_obr_max->setReadOnly(true);
        ui->lineEdit_I_pr_max->setReadOnly(true);
        ui->lineEdit_I_prh->setReadOnly(true);
        ui->lineEdit_F_rab->setReadOnly(true);
        ui->lineEdit_U_pr->setReadOnly(true);
        ui->lineEdit_I_pr->setReadOnly(true);
        ui->lineEdit_I_obr->setReadOnly(true);
        ui->lineEdit_T_k_max->setReadOnly(true);


        ui->pushButton->setHidden(true);
        ui->pushButton_3->setHidden(true);

        //"""""""""""""""""""""resistor"""""""""""""""""""""""""
        ui->lineEdit_r_model->setReadOnly(false);
        ui->lineEdit_r_s->setReadOnly(true);
        ui->lineEdit_r_pover->setReadOnly(true);
        ui->lineEdit_r_dopusk->setReadOnly(true);
        ui->lineEdit_r_korpus->setReadOnly(true);


        ui->pushButton_4->setHidden(true);
        ui->pushButton_5->setHidden(true);
    }
}

bool MainWindow::questionQMB(QString massege)
{
    ui->statusBar->showMessage("...");
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"",massege,QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        return 1;
    } else {
        return 0;
    }
}


void MainWindow::on_radioButton_toggled(bool checked)
{
    ui->lineEdit_model->clear();
    ui->lineEdit_U_obr_max->clear();
    ui->lineEdit_I_pr_max->clear();
    ui->lineEdit_I_prh->clear();
    ui->lineEdit_F_rab->clear();
    ui->lineEdit_U_pr->clear();
    ui->lineEdit_I_pr->clear();
    ui->lineEdit_I_obr->clear();
    ui->lineEdit_T_k_max->clear();


    ui->lineEdit_r_model->clear();
    ui->lineEdit_r_s->clear();
    ui->lineEdit_r_pover->clear();
    ui->lineEdit_r_dopusk->clear();
    ui->lineEdit_r_korpus->clear();


    if(checked){

        //""""""""""""""""""""""Diod"""""""""""""""""""
        ui->lineEdit_model->setReadOnly(false);
        ui->lineEdit_U_obr_max->setReadOnly(false);
        ui->lineEdit_I_pr_max->setReadOnly(false);
        ui->lineEdit_I_prh->setReadOnly(false);
        ui->lineEdit_F_rab->setReadOnly(false);
        ui->lineEdit_U_pr->setReadOnly(false);
        ui->lineEdit_I_pr->setReadOnly(false);
        ui->lineEdit_I_obr->setReadOnly(false);
        ui->lineEdit_T_k_max->setReadOnly(false);


        ui->pushButton->setHidden(false);
        ui->pushButton_3->setHidden(false);

        //"""""""""""""""""""""resistor"""""""""""""""""""""""""
        ui->lineEdit_r_model->setReadOnly(false);
        ui->lineEdit_r_s->setReadOnly(false);
        ui->lineEdit_r_pover->setReadOnly(false);
        ui->lineEdit_r_dopusk->setReadOnly(false);
        ui->lineEdit_r_korpus->setReadOnly(false);

        ui->pushButton_4->setHidden(false);
        ui->pushButton_5->setHidden(false);
    }
}
