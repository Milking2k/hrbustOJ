/********************************************************************************
** Form generated from reading UI file 'refund.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFUND_H
#define UI_REFUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_refund
{
public:
    QPushButton *checkOrder;
    QLabel *label_12;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *deleteSubmit;
    QLabel *label_11;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_10;
    QFrame *line_2;
    QLabel *label_2;
    QLabel *IDcard;
    QLabel *bookNum;
    QLabel *state;
    QLabel *orderNum;
    QLabel *fName;
    QLabel *Name;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *searchOrder;
    QFrame *line;

    void setupUi(QWidget *refund)
    {
        if (refund->objectName().isEmpty())
            refund->setObjectName(QStringLiteral("refund"));
        refund->resize(389, 229);
        checkOrder = new QPushButton(refund);
        checkOrder->setObjectName(QStringLiteral("checkOrder"));
        checkOrder->setGeometry(QRect(270, 140, 71, 31));
        label_12 = new QLabel(refund);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(280, 210, 111, 20));
        label_12->setStyleSheet(QLatin1String("color: rgb(158, 158, 158);\n"
"font: italic 10pt \"Consolas\";"));
        gridLayoutWidget = new QWidget(refund);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 20, 206, 201));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        deleteSubmit = new QPushButton(gridLayoutWidget);
        deleteSubmit->setObjectName(QStringLiteral("deleteSubmit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deleteSubmit->sizePolicy().hasHeightForWidth());
        deleteSubmit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(deleteSubmit, 0, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 6, 0, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 5, 0, 1, 1);

        line_2 = new QFrame(gridLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 1, 7, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        IDcard = new QLabel(gridLayoutWidget);
        IDcard->setObjectName(QStringLiteral("IDcard"));
        IDcard->setMinimumSize(QSize(114, 0));

        gridLayout->addWidget(IDcard, 4, 2, 1, 1);

        bookNum = new QLabel(gridLayoutWidget);
        bookNum->setObjectName(QStringLiteral("bookNum"));

        gridLayout->addWidget(bookNum, 5, 2, 1, 1);

        state = new QLabel(gridLayoutWidget);
        state->setObjectName(QStringLiteral("state"));

        gridLayout->addWidget(state, 6, 2, 1, 1);

        orderNum = new QLabel(gridLayoutWidget);
        orderNum->setObjectName(QStringLiteral("orderNum"));

        gridLayout->addWidget(orderNum, 1, 2, 1, 1);

        fName = new QLabel(gridLayoutWidget);
        fName->setObjectName(QStringLiteral("fName"));

        gridLayout->addWidget(fName, 2, 2, 1, 1);

        Name = new QLabel(gridLayoutWidget);
        Name->setObjectName(QStringLiteral("Name"));

        gridLayout->addWidget(Name, 3, 2, 1, 1);

        verticalLayoutWidget = new QWidget(refund);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(220, 40, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        searchOrder = new QLineEdit(verticalLayoutWidget);
        searchOrder->setObjectName(QStringLiteral("searchOrder"));

        verticalLayout->addWidget(searchOrder);

        line = new QFrame(refund);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(210, 20, 16, 201));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(refund);

        QMetaObject::connectSlotsByName(refund);
    } // setupUi

    void retranslateUi(QWidget *refund)
    {
        refund->setWindowTitle(QApplication::translate("refund", "Form", 0));
        checkOrder->setText(QApplication::translate("refund", "\346\237\245\350\257\242", 0));
        label_12->setText(QApplication::translate("refund", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">@lichunjie v0.4</span></p></body></html>", 0));
        deleteSubmit->setText(QApplication::translate("refund", "\351\200\200\347\245\250", 0));
        label_11->setText(QApplication::translate("refund", "<html><head/><body><p align=\"right\">\350\210\252\347\217\255\347\212\266\346\200\201</p></body></html>", 0));
        label_9->setText(QApplication::translate("refund", "<html><head/><body><p align=\"right\">\350\272\253\344\273\275\350\257\201\345\217\267</p></body></html>", 0));
        label_8->setText(QApplication::translate("refund", "<html><head/><body><p align=\"right\">\345\247\223\345\220\215</p></body></html>", 0));
        label_6->setText(QApplication::translate("refund", "<html><head/><body><p align=\"right\">\350\256\242\345\215\225\345\217\267</p></body></html>", 0));
        label_7->setText(QApplication::translate("refund", "<html><head/><body><p align=\"right\">\350\210\252\347\217\255\345\217\267</p></body></html>", 0));
        label_10->setText(QApplication::translate("refund", "<html><head/><body><p align=\"right\">\350\256\242\345\215\225\346\225\260\351\207\217</p></body></html>", 0));
        label_2->setText(QApplication::translate("refund", "<html><head/><body><p align=\"center\">\350\256\242\345\215\225\350\257\246\346\203\205</p></body></html>", 0));
        IDcard->setText(QString());
        bookNum->setText(QString());
        state->setText(QString());
        orderNum->setText(QString());
        fName->setText(QString());
        Name->setText(QString());
        label->setText(QApplication::translate("refund", "<html><head/><body><p align=\"center\">\350\257\267\350\276\223\345\205\245\346\202\250\351\234\200\350\246\201\346\237\245\350\257\242\347\232\204</p></body></html>", 0));
        label_3->setText(QApplication::translate("refund", "<html><head/><body><p align=\"center\">\350\256\242\345\215\225\347\274\226\345\217\267(\346\240\274\345\274\217\344\270\272Sxxx)</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class refund: public Ui_refund {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFUND_H
