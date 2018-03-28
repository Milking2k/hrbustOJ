/********************************************************************************
** Form generated from reading UI file 'bookticks.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKTICKS_H
#define UI_BOOKTICKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bookticks
{
public:
    QLabel *label_12;
    QTableWidget *tableWidget;
    QPushButton *addTicket;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *plcEnd;
    QLineEdit *plcStart;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_3;
    QPushButton *bookButton;
    QFrame *line;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout;
    QLineEdit *IDcard;
    QLineEdit *Name;
    QLabel *label_4;
    QLineEdit *bookNum;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QComboBox *fName;

    void setupUi(QWidget *bookticks)
    {
        if (bookticks->objectName().isEmpty())
            bookticks->setObjectName(QStringLiteral("bookticks"));
        bookticks->resize(701, 349);
        bookticks->setWindowOpacity(1);
        label_12 = new QLabel(bookticks);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(590, 320, 111, 20));
        label_12->setStyleSheet(QLatin1String("color: rgb(158, 158, 158);\n"
"font: italic 10pt \"Consolas\";"));
        tableWidget = new QTableWidget(bookticks);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 50, 465, 280));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setAutoScroll(false);
        tableWidget->setRowCount(0);
        tableWidget->horizontalHeader()->setDefaultSectionSize(56);
        tableWidget->horizontalHeader()->setMinimumSectionSize(56);
        tableWidget->verticalHeader()->setDefaultSectionSize(23);
        tableWidget->verticalHeader()->setMinimumSectionSize(23);
        addTicket = new QPushButton(bookticks);
        addTicket->setObjectName(QStringLiteral("addTicket"));
        addTicket->setGeometry(QRect(420, 12, 61, 26));
        gridLayoutWidget = new QWidget(bookticks);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(11, 10, 401, 30));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        plcEnd = new QLineEdit(gridLayoutWidget);
        plcEnd->setObjectName(QStringLiteral("plcEnd"));

        gridLayout_2->addWidget(plcEnd, 0, 5, 1, 1);

        plcStart = new QLineEdit(gridLayoutWidget);
        plcStart->setObjectName(QStringLiteral("plcStart"));

        gridLayout_2->addWidget(plcStart, 0, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 4, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(30, 0));

        gridLayout_2->addWidget(label_7, 0, 3, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        bookButton = new QPushButton(bookticks);
        bookButton->setObjectName(QStringLiteral("bookButton"));
        bookButton->setGeometry(QRect(560, 170, 61, 31));
        line = new QFrame(bookticks);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(480, 60, 20, 241));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        gridLayoutWidget_2 = new QWidget(bookticks);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(500, 60, 181, 101));
        gridLayout = new QGridLayout(gridLayoutWidget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        IDcard = new QLineEdit(gridLayoutWidget_2);
        IDcard->setObjectName(QStringLiteral("IDcard"));

        gridLayout->addWidget(IDcard, 2, 1, 1, 1);

        Name = new QLineEdit(gridLayoutWidget_2);
        Name->setObjectName(QStringLiteral("Name"));

        gridLayout->addWidget(Name, 1, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        bookNum = new QLineEdit(gridLayoutWidget_2);
        bookNum->setObjectName(QStringLiteral("bookNum"));

        gridLayout->addWidget(bookNum, 3, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        fName = new QComboBox(gridLayoutWidget_2);
        fName->setObjectName(QStringLiteral("fName"));

        gridLayout->addWidget(fName, 0, 1, 1, 1);


        retranslateUi(bookticks);

        QMetaObject::connectSlotsByName(bookticks);
    } // setupUi

    void retranslateUi(QWidget *bookticks)
    {
        bookticks->setWindowTitle(QApplication::translate("bookticks", "Form", 0));
        label_12->setText(QApplication::translate("bookticks", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">@lichunjie v0.4</span></p></body></html>", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("bookticks", "\350\210\252\347\217\255\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("bookticks", "\345\207\272\345\217\221\345\234\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("bookticks", "\347\233\256\347\232\204\345\234\260", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("bookticks", "\345\207\272\345\217\221\346\227\266\351\227\264", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("bookticks", "\345\210\260\350\276\276\346\227\266\351\227\264", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("bookticks", "\347\245\250\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("bookticks", "\346\212\230\346\211\243", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("bookticks", "\345\216\206\346\227\266", 0));
        addTicket->setText(QApplication::translate("bookticks", "\346\237\245\350\257\242", 0));
        label_2->setText(QApplication::translate("bookticks", "<html><head/><body><p align=\"center\">\347\233\256\347\232\204\345\234\260</p></body></html>", 0));
        label_7->setText(QApplication::translate("bookticks", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        label->setText(QApplication::translate("bookticks", "<html><head/><body><p align=\"center\">\345\207\272\345\217\221\345\234\260</p></body></html>", 0));
        label_3->setText(QApplication::translate("bookticks", "\350\257\267\350\276\223\345\205\245\345\207\272\345\217\221\345\234\260\345\222\214\347\233\256\347\232\204\345\234\260", 0));
        bookButton->setText(QApplication::translate("bookticks", "\350\256\242\347\245\250", 0));
        label_4->setText(QApplication::translate("bookticks", "<html><head/><body><p align=\"center\">\345\247\223\345\220\215</p></body></html>", 0));
        label_5->setText(QApplication::translate("bookticks", "<html><head/><body><p align=\"center\">\350\272\253\344\273\275\350\257\201</p></body></html>", 0));
        label_6->setText(QApplication::translate("bookticks", "<html><head/><body><p align=\"center\">\350\256\242\345\215\225\346\225\260\351\207\217</p></body></html>", 0));
        label_8->setText(QApplication::translate("bookticks", "<html><head/><body><p align=\"center\">\350\210\252\347\217\255\345\217\267</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class bookticks: public Ui_bookticks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKTICKS_H
