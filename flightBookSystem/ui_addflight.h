/********************************************************************************
** Form generated from reading UI file 'addflight.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFLIGHT_H
#define UI_ADDFLIGHT_H

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

class Ui_addflight
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *tEndh;
    QLineEdit *fare;
    QLineEdit *tStarth;
    QLineEdit *rebate;
    QLineEdit *tStartm;
    QLineEdit *plcEnd;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *fName;
    QLineEdit *plcStart;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *tEndm;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *addFlightButtom;

    void setupUi(QWidget *addflight)
    {
        if (addflight->objectName().isEmpty())
            addflight->setObjectName(QStringLiteral("addflight"));
        addflight->resize(379, 270);
        gridLayoutWidget = new QWidget(addflight);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 50, 254, 178));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        tEndh = new QLineEdit(gridLayoutWidget);
        tEndh->setObjectName(QStringLiteral("tEndh"));

        gridLayout->addWidget(tEndh, 3, 1, 1, 1);

        fare = new QLineEdit(gridLayoutWidget);
        fare->setObjectName(QStringLiteral("fare"));

        gridLayout->addWidget(fare, 5, 1, 1, 4);

        tStarth = new QLineEdit(gridLayoutWidget);
        tStarth->setObjectName(QStringLiteral("tStarth"));

        gridLayout->addWidget(tStarth, 1, 1, 1, 1);

        rebate = new QLineEdit(gridLayoutWidget);
        rebate->setObjectName(QStringLiteral("rebate"));

        gridLayout->addWidget(rebate, 6, 1, 1, 4);

        tStartm = new QLineEdit(gridLayoutWidget);
        tStartm->setObjectName(QStringLiteral("tStartm"));

        gridLayout->addWidget(tStartm, 1, 3, 1, 1);

        plcEnd = new QLineEdit(gridLayoutWidget);
        plcEnd->setObjectName(QStringLiteral("plcEnd"));

        gridLayout->addWidget(plcEnd, 4, 1, 1, 4);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        fName = new QLineEdit(gridLayoutWidget);
        fName->setObjectName(QStringLiteral("fName"));

        gridLayout->addWidget(fName, 0, 1, 1, 4);

        plcStart = new QLineEdit(gridLayoutWidget);
        plcStart->setObjectName(QStringLiteral("plcStart"));

        gridLayout->addWidget(plcStart, 2, 1, 1, 4);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 3, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 2, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 1, 4, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 3, 4, 1, 1);

        tEndm = new QLineEdit(gridLayoutWidget);
        tEndm->setObjectName(QStringLiteral("tEndm"));

        gridLayout->addWidget(tEndm, 3, 3, 1, 1);

        label_12 = new QLabel(addflight);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(260, 240, 111, 20));
        label_12->setStyleSheet(QLatin1String("color: rgb(158, 158, 158);\n"
"font: italic 10pt \"Consolas\";"));
        label_13 = new QLabel(addflight);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(60, 20, 61, 20));
        addFlightButtom = new QPushButton(addflight);
        addFlightButtom->setObjectName(QStringLiteral("addFlightButtom"));
        addFlightButtom->setGeometry(QRect(240, 20, 75, 20));

        retranslateUi(addflight);

        QMetaObject::connectSlotsByName(addflight);
    } // setupUi

    void retranslateUi(QWidget *addflight)
    {
        addflight->setWindowTitle(QApplication::translate("addflight", "Form", 0));
        label_2->setText(QApplication::translate("addflight", "<html><head/><body><p align=\"center\">\350\265\267\351\243\236\346\227\266\351\227\264</p></body></html>", 0));
        label_3->setText(QApplication::translate("addflight", "<html><head/><body><p align=\"center\">\350\265\267\351\243\236\345\234\260\347\202\271</p></body></html>", 0));
        label->setText(QApplication::translate("addflight", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\350\210\252\347\217\255\345\217\267(Fxxx)</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("addflight", "<html><head/><body><p align=\"center\">\345\210\260\350\276\276\345\234\260\347\202\271</p></body></html>", 0));
        label_5->setText(QApplication::translate("addflight", "<html><head/><body><p align=\"center\">\345\210\260\350\276\276\346\227\266\351\227\264</p></body></html>", 0));
        label_6->setText(QApplication::translate("addflight", "<html><head/><body><p align=\"center\">\347\245\250\344\273\267</p></body></html>", 0));
        label_7->setText(QApplication::translate("addflight", "<html><head/><body><p align=\"center\">\346\212\230\346\211\243</p></body></html>", 0));
        label_9->setText(QApplication::translate("addflight", "\346\227\266", 0));
        label_8->setText(QApplication::translate("addflight", "\346\227\266", 0));
        label_10->setText(QApplication::translate("addflight", "\345\210\206", 0));
        label_11->setText(QApplication::translate("addflight", "\345\210\206", 0));
        label_12->setText(QApplication::translate("addflight", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">@lichunjie v0.4</span></p></body></html>", 0));
        label_13->setText(QApplication::translate("addflight", "\350\257\267\350\276\223\345\205\245\344\277\241\346\201\257", 0));
        addFlightButtom->setText(QApplication::translate("addflight", "\347\241\256\350\256\244", 0));
    } // retranslateUi

};

namespace Ui {
    class addflight: public Ui_addflight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFLIGHT_H
