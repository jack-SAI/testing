#include "dbtable.h"
#include "ui_dbtable.h"

dbtable::dbtable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dbtable)
{
    ui->setupUi(this);
    qDebug()<<"@@@@@@@";

    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName("testing.db");
    if(!db1.open()){
        qDebug()<<"open db error";
    }

//多列模式
    QSqlQuery qsq;
    if(!qsq.exec("select * from wordbox")){
        qDebug()<<"open table error";
    }
    //多列模式
    QStandardItemModel *model = new QStandardItemModel(10,3);
  //  model->setHeaderData(0,Qt::Horizontal,tr("id"));
    model->setHeaderData(1,Qt::Horizontal,tr("English"));
    model->setHeaderData(2,Qt::Horizontal,tr("chinese"));

  //  QStringList idData;
    QStringList EnglishData;
    QStringList ChineseData;

    while (qsq.next()) {
        model->insertRow(1);
       // model->setData(model->index(1,0),qsq.value("id").toInt());
        model->setData(model->index(1,1),qsq.value("English").toString());
        model->setData(model->index(1,2),qsq.value("Chinese").toDouble());
    }

    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
//ui->
    ui->tableView->setModel(model);

}

dbtable::~dbtable()
{
    delete ui;
}
