﻿#ifndef WORKINGPLANE_H
#define WORKINGPLANE_H

#include <QWidget>
#include<dbtable.h>

namespace Ui {
class workingPlane;
}

class workingPlane : public QWidget
{
    Q_OBJECT

public:
    explicit workingPlane(QWidget *parent = nullptr);
    ~workingPlane();

private slots:
    void on_pushButton_clicked();

    void on_dbButton_clicked();

private:
    Ui::workingPlane *ui;
dbtable *db = nullptr;
};

#endif // WORKINGPLANE_H
