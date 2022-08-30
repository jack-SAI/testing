#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <workingplane.h>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()|Qt::WindowMaximizeButtonHint);
    setWindowFlags(windowFlags()|Qt::WindowMinMaxButtonsHint);
    setWindowFlags(windowFlags()|Qt::WindowCloseButtonHint);
    workingPlane *wk = new workingPlane();
    //db=new dbtable();
    //wk->setParent(this);
    //wk->show();
    connect(ui->templogin,&QPushButton::clicked,wk,&QWidget::show);
    connect(this,&MainWindow::acception,wk,&QWidget::show);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug()<<"click templogin";
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->usrLineEdit->text()=='1' && ui->pwdLineEdit->text()=='1'){
        acception();
    }
    else{
        qDebug()<<"name or password wrong";
    }
}
