#ifndef DBTABLE_H
#define DBTABLE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QPushButton>
namespace Ui {
class dbtable;
}

class dbtable : public QWidget
{
    Q_OBJECT

public:
    explicit dbtable(QWidget *parent = nullptr);
    ~dbtable();

private:
    Ui::dbtable *ui;
};

#endif // DBTABLE_H
