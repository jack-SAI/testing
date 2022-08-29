/********************************************************************************
** Form generated from reading UI file 'workingplane.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKINGPLANE_H
#define UI_WORKINGPLANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_workingPlane
{
public:
    QLineEdit *lineEdit;
    QPushButton *search;
    QTextBrowser *textBrowser;
    QPushButton *dbButton;

    void setupUi(QWidget *workingPlane)
    {
        if (workingPlane->objectName().isEmpty())
            workingPlane->setObjectName(QStringLiteral("workingPlane"));
        workingPlane->resize(773, 471);
        lineEdit = new QLineEdit(workingPlane);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 40, 281, 31));
        search = new QPushButton(workingPlane);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(410, 40, 93, 28));
        textBrowser = new QTextBrowser(workingPlane);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(100, 100, 411, 192));
        dbButton = new QPushButton(workingPlane);
        dbButton->setObjectName(QStringLiteral("dbButton"));
        dbButton->setGeometry(QRect(680, 440, 93, 28));

        retranslateUi(workingPlane);

        QMetaObject::connectSlotsByName(workingPlane);
    } // setupUi

    void retranslateUi(QWidget *workingPlane)
    {
        workingPlane->setWindowTitle(QApplication::translate("workingPlane", "Form", Q_NULLPTR));
        search->setText(QApplication::translate("workingPlane", "\346\237\245\350\257\242", Q_NULLPTR));
        dbButton->setText(QApplication::translate("workingPlane", "\346\225\260\346\215\256\345\272\223", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class workingPlane: public Ui_workingPlane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKINGPLANE_H
