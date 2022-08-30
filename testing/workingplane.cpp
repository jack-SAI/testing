#include "workingplane.h"
#include "ui_workingplane.h"
#include<QTextBrowser>
#include<workingplane.h>
#include <iostream>
#include <QDebug>


workingPlane::workingPlane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workingPlane)
{
    ui->setupUi(this);

     db=new dbtable();
    connect(ui->search,&QPushButton::clicked,ui->textBrowser,[=]()
    {
        ui->textBrowser->insertPlainText("this is a text msg");

    });

//    出问题了，好像是参数个数不匹配
//    connect(ui->search,&QPushButton::clicked,ui->textBrowser,&workingPlane::on_pushButton_clicked);
//    也有问题，signal里面没有click的函数事件
//    QObject::connect(ui->search,SIGNAL())


    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(getT(QString)));



}

workingPlane::~workingPlane()
{
    delete ui;
}

void workingPlane::on_pushButton_clicked()
{
    ui->textBrowser->insertPlainText("this is a text msg");
}

void workingPlane::on_dbButton_clicked()
{
    db->show();
}

void workingPlane::getT(QString str)
{
     qDebug()<<"jieshou\n";
   qDebug() << str;
}


void workingPlane::on_search_clicked()//获取搜索数据
{

}
