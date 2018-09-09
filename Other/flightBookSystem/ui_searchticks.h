/********************************************************************************
** Form generated from reading UI file 'searchticks.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHTICKS_H
#define UI_SEARCHTICKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchTicks
{
public:
    QLabel *label_12;
    QLabel *label_13;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_19;
    QLineEdit *tEndm;
    QLabel *label_20;
    QLineEdit *rebate;
    QLineEdit *tEndh;
    QLineEdit *fare;
    QLineEdit *tStarth;
    QLineEdit *plcEnd;
    QLineEdit *tStartm;
    QLabel *label_6;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_14;
    QLineEdit *plcStart;
    QLabel *label_15;
    QLabel *label_18;
    QLabel *label_17;
    QLabel *label_2;
    QPushButton *addFlightButtom;
    QLineEdit *searchFlight;
    QPushButton *checkModify;

    void setupUi(QWidget *searchTicks)
    {
        if (searchTicks->objectName().isEmpty())
            searchTicks->setObjectName(QStringLiteral("searchTicks"));
        searchTicks->resize(318, 320);
        label_12 = new QLabel(searchTicks);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(210, 300, 111, 20));
        label_12->setStyleSheet(QLatin1String("color: rgb(158, 158, 158);\n"
"font: italic 10pt \"Consolas\";"));
        label_13 = new QLabel(searchTicks);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 20, 131, 20));
        gridLayoutWidget = new QWidget(searchTicks);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 80, 254, 178));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(gridLayoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_2->addWidget(label_19, 0, 4, 1, 1);

        tEndm = new QLineEdit(gridLayoutWidget);
        tEndm->setObjectName(QStringLiteral("tEndm"));

        gridLayout_2->addWidget(tEndm, 2, 3, 1, 1);

        label_20 = new QLabel(gridLayoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_2->addWidget(label_20, 2, 4, 1, 1);

        rebate = new QLineEdit(gridLayoutWidget);
        rebate->setObjectName(QStringLiteral("rebate"));

        gridLayout_2->addWidget(rebate, 5, 1, 1, 4);

        tEndh = new QLineEdit(gridLayoutWidget);
        tEndh->setObjectName(QStringLiteral("tEndh"));

        gridLayout_2->addWidget(tEndh, 2, 1, 1, 1);

        fare = new QLineEdit(gridLayoutWidget);
        fare->setObjectName(QStringLiteral("fare"));

        gridLayout_2->addWidget(fare, 4, 1, 1, 4);

        tStarth = new QLineEdit(gridLayoutWidget);
        tStarth->setObjectName(QStringLiteral("tStarth"));

        gridLayout_2->addWidget(tStarth, 0, 1, 1, 1);

        plcEnd = new QLineEdit(gridLayoutWidget);
        plcEnd->setObjectName(QStringLiteral("plcEnd"));

        gridLayout_2->addWidget(plcEnd, 3, 1, 1, 4);

        tStartm = new QLineEdit(gridLayoutWidget);
        tStartm->setObjectName(QStringLiteral("tStartm"));

        gridLayout_2->addWidget(tStartm, 0, 3, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 2, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 3, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_2->addWidget(label_14, 4, 0, 1, 1);

        plcStart = new QLineEdit(gridLayoutWidget);
        plcStart->setObjectName(QStringLiteral("plcStart"));

        gridLayout_2->addWidget(plcStart, 1, 1, 1, 4);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_2->addWidget(label_15, 5, 0, 1, 1);

        label_18 = new QLabel(gridLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_2->addWidget(label_18, 0, 2, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_2->addWidget(label_17, 2, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        addFlightButtom = new QPushButton(searchTicks);
        addFlightButtom->setObjectName(QStringLiteral("addFlightButtom"));
        addFlightButtom->setGeometry(QRect(210, 50, 75, 20));
        searchFlight = new QLineEdit(searchTicks);
        searchFlight->setObjectName(QStringLiteral("searchFlight"));
        searchFlight->setGeometry(QRect(30, 50, 161, 20));
        checkModify = new QPushButton(searchTicks);
        checkModify->setObjectName(QStringLiteral("checkModify"));
        checkModify->setGeometry(QRect(30, 280, 75, 23));

        retranslateUi(searchTicks);

        QMetaObject::connectSlotsByName(searchTicks);
    } // setupUi

    void retranslateUi(QWidget *searchTicks)
    {
        searchTicks->setWindowTitle(QApplication::translate("searchTicks", "Form", 0));
        label_12->setText(QApplication::translate("searchTicks", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">@lichunjie v0.4</span></p></body></html>", 0));
        label_13->setText(QApplication::translate("searchTicks", "\350\257\267\350\276\223\345\205\245\344\277\241\346\201\257\350\210\252\347\217\255\345\217\267(Fxxx)", 0));
        label_19->setText(QApplication::translate("searchTicks", "\345\210\206", 0));
        label_20->setText(QApplication::translate("searchTicks", "\345\210\206", 0));
        label_6->setText(QApplication::translate("searchTicks", "<html><head/><body><p align=\"center\">\350\265\267\351\243\236\345\234\260\347\202\271</p></body></html>", 0));
        label_11->setText(QApplication::translate("searchTicks", "<html><head/><body><p align=\"center\">\345\210\260\350\276\276\346\227\266\351\227\264</p></body></html>", 0));
        label_10->setText(QApplication::translate("searchTicks", "<html><head/><body><p align=\"center\">\345\210\260\350\276\276\345\234\260\347\202\271</p></body></html>", 0));
        label_14->setText(QApplication::translate("searchTicks", "<html><head/><body><p align=\"center\">\347\245\250\344\273\267</p></body></html>", 0));
        label_15->setText(QApplication::translate("searchTicks", "<html><head/><body><p align=\"center\">\346\212\230\346\211\243</p></body></html>", 0));
        label_18->setText(QApplication::translate("searchTicks", "\346\227\266", 0));
        label_17->setText(QApplication::translate("searchTicks", "\346\227\266", 0));
        label_2->setText(QApplication::translate("searchTicks", "<html><head/><body><p align=\"center\">\350\265\267\351\243\236\346\227\266\351\227\264</p></body></html>", 0));
        addFlightButtom->setText(QApplication::translate("searchTicks", "\347\241\256\350\256\244", 0));
        checkModify->setText(QApplication::translate("searchTicks", "\347\241\256\350\256\244\344\277\256\346\224\271", 0));
    } // retranslateUi

};

namespace Ui {
    class searchTicks: public Ui_searchTicks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHTICKS_H
