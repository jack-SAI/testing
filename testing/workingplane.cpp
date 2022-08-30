﻿#include "workingplane.h"
#include "ui_workingplane.h"
#include<QTextBrowser>
#include<workingplane.h>

workingPlane::workingPlane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workingPlane)
{
    ui->setupUi(this);
    models = new QSqlQueryModel(ui->tableView);//QSqlTableModel为读写模型,QSqlQueryModel为用来查询的只读模型
    Connection();

}

workingPlane::~workingPlane()
{
    delete ui;
}


void workingPlane::Connection()
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
    qsq.exec("select * from stardict limit 10  ");//搜索stardict表的前10项纪录

    QStandardItemModel *model = new QStandardItemModel(10,2);//类QStandardItemModel负责保存数据
    //model->setHeaderData(0,Qt::Horizontal,tr("id"));//设置tableview的表头
    model->setHeaderData(0,Qt::Horizontal,tr("英文"));
    model->setHeaderData(1,Qt::Horizontal,tr("中文"));


    while (qsq.next()) {
        model->insertRow(1);
       // model->setData(model->index(1,0),qsq.value("id").toInt());
        model->setData(model->index(1,0),qsq.value("sw").toString());
        model->setData(model->index(1,1),qsq.value("translation").toString());
    }

    ui->tableView->setModel(model); //Qt中用model/view模式来显示数据，将tableView与存储数据的model关联后才有显示的内容
    ui->tableView->horizontalHeader()->setVisible(true);// 显示表头
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选中时为整行选中
    ui->tableView->setColumnWidth(0,100);                             //设置第二列的宽度
    ui->tableView->setColumnWidth(1,500);                            //设置第三列的宽度




}


void workingPlane::show_table()
{
    qDebug("show is OK");

    models->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));  //设置tableview的表头
    models->setHeaderData(1,Qt::Horizontal,QObject::tr("单词"));
    models->setHeaderData(2,Qt::Horizontal,QObject::tr("词性"));

    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选中时为整行选中

    ui->tableView->setModel(models);
/*
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));  //设置tableview的表头
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("单词"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("词性"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("释义"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("例句"));
    ui->tableView->setModel(model);         //Qt中用model/view模式来显示数据，将tableView与存储数据的model关联后才有显示的内容
    ui->tableView->verticalHeader()->setVisible(false);                //隐藏表格的行号
    ui->tableView->hideColumn(0);                                     //隐藏第一列，即id
    ui->tableView->hideColumn(4);                                    //隐藏第四列，即例句
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);   //设置选中时为整行选中
    ui->tableView->setColumnWidth(1,100);                             //设置第二列的宽度
    ui->tableView->setColumnWidth(2,100);                            //设置第三列的宽度
    ui->tableView->horizontalHeader()->setStretchLastSection(true); //最后一列自动填充满空间
    //ui->tableView->resizeRowsToContents();                       //所有行根据内容自动调整行高
    */
}


void workingPlane::on_search_clicked()
{
    QString input = ui->lineEdit->text();
    if(input.isEmpty())      //判断是否有输入查询内容
    {
        QMessageBox::warning(this,"查询失败","请输入要查询的单词！",QMessageBox::Yes);
        return;
    }
    QSqlQuery query;
    query.prepare("select * from stardict where sw LIKE :sw order by sw asc");//搜索以:word开头的所有单词，全字匹配是where word = :word
    query.bindValue(":sw",ui->lineEdit->text()+"%");//参考http://www.qtdebug.com/qtbook-db-common/
    query.exec();
    if(!query.next())
    {
        QMessageBox::warning(this,"查询失败","没有查找到该单词！",QMessageBox::Yes);
        return;
    }
    models->setQuery(query);   //重新设置model的内容
    show_table();

}


