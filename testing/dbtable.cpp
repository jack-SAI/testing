#include "dbtable.h"
#include "ui_dbtable.h"

dbtable::dbtable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dbtable)
{

    qDebug()<<"@@@@@@@";

    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName("testing.db");
    if(!db1.open()){
        qDebug()<<"open db error";
    }


    QSqlQuery qsq;
    if(!qsq.exec("select * from wordbox")){
        qDebug()<<"open table error";
    }
    while(qsq.next()){
        QString ret =QString("id:%1,Enlish:%9,Chinese:%9")
                .arg(qsq.value("id").toInt())
                .arg(qsq.value("English").toString())
                .arg(qsq.value("Chinese").toString())
              ;
        qDebug()<<ret;

    }
    ui->setupUi(this);
}

dbtable::~dbtable()
{
    delete ui;
}
