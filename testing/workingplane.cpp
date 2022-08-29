#include "workingplane.h"
#include "ui_workingplane.h"
#include<QTextBrowser>
#include<workingplane.h>

workingPlane::workingPlane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workingPlane)
{
    ui->setupUi(this);
//    connect(ui->search,&QPushButton::clicked,ui->textBrowser,[=](){
     //   ui->textBrowser->insertPlainText("this is a text msg");
   // });

    Connection();

//    出问题了，好像是参数个数不匹配
//    connect(ui->search,&QPushButton::clicked,ui->textBrowser,&workingPlane::on_pushButton_clicked);
//    也有问题，signal里面没有click的函数事件
//    QObject::connect(ui->search,SIGNAL())


}

workingPlane::~workingPlane()
{
    delete ui;
}

//void workingPlane::on_pushButton_clicked()
//{
//    ui->textBrowser->insertPlainText("this is a text msg");
//}


void workingPlane::Connection()   //创建一个数据库来存储单词本
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//添加数据库的连接，连接名默认
    db.setDatabaseName("testing.db");
    if(!db.open()){
        QMessageBox::warning(this,"错误","不能连接到数据库！",QMessageBox::Yes);
    }
    else{
        qDebug("open is OK");
    }

    QSqlQuery qsq;
    qsq.exec("select * from stardict order by id limit 10");
    QStandardItemModel *model = new QStandardItemModel(10,3);


    model->setHeaderData(0,Qt::Horizontal,tr("id"));
    model->setHeaderData(1,Qt::Horizontal,tr("英文"));
    model->setHeaderData(2,Qt::Horizontal,tr("中文"));

    QStringList midData;
    QStringList mnameData;
    QStringList mpriceData;

    while (qsq.next()) {
        model->insertRow(1);
        model->setData(model->index(1,0),qsq.value("id").toInt());
        model->setData(model->index(1,1),qsq.value("sw").toString());
        model->setData(model->index(1,2),qsq.value("translation").toString());
    }

    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableView->setModel(model);
}

