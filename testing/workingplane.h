#ifndef WORKINGPLANE_H
#define WORKINGPLANE_H

#include <QWidget>

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

private:
    Ui::workingPlane *ui;

};

#endif // WORKINGPLANE_H
