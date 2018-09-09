/********************************************************************************
** Form generated from reading UI file 'searchflight.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHFLIGHT_H
#define UI_SEARCHFLIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchFlight
{
public:
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *flightName;
    QPushButton *searchFlightBottom;
    QFrame *line;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *tStart;
    QLabel *plcStart;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *tEnd;
    QLabel *plcEnd;
    QLabel *duration;
    QLabel *rebate;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_16;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_11;
    QFrame *line_12;
    QFrame *line_13;
    QFrame *line_14;
    QFrame *line_5;
    QFrame *line_2;
    QLabel *fare;
    QLabel *label_2;

    void setupUi(QWidget *searchFlight)
    {
        if (searchFlight->objectName().isEmpty())
            searchFlight->setObjectName(QStringLiteral("searchFlight"));
        searchFlight->resize(461, 303);
        label = new QLabel(searchFlight);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 20, 191, 21));
        horizontalLayoutWidget = new QWidget(searchFlight);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(130, 40, 191, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        flightName = new QLineEdit(horizontalLayoutWidget);
        flightName->setObjectName(QStringLiteral("flightName"));

        horizontalLayout->addWidget(flightName);

        searchFlightBottom = new QPushButton(horizontalLayoutWidget);
        searchFlightBottom->setObjectName(QStringLiteral("searchFlightBottom"));
        searchFlightBottom->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(searchFlightBottom);

        line = new QFrame(searchFlight);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(40, 90, 381, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        gridLayoutWidget = new QWidget(searchFlight);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 130, 401, 88));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tStart = new QLabel(gridLayoutWidget);
        tStart->setObjectName(QStringLiteral("tStart"));

        gridLayout->addWidget(tStart, 1, 5, 1, 1);

        plcStart = new QLabel(gridLayoutWidget);
        plcStart->setObjectName(QStringLiteral("plcStart"));

        gridLayout->addWidget(plcStart, 1, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 13, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 11, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("border-color: rgb(0, 255, 157);"));

        gridLayout->addWidget(label_5, 0, 7, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 9, 1, 1);

        tEnd = new QLabel(gridLayoutWidget);
        tEnd->setObjectName(QStringLiteral("tEnd"));

        gridLayout->addWidget(tEnd, 1, 7, 1, 1);

        plcEnd = new QLabel(gridLayoutWidget);
        plcEnd->setObjectName(QStringLiteral("plcEnd"));

        gridLayout->addWidget(plcEnd, 1, 3, 1, 1);

        duration = new QLabel(gridLayoutWidget);
        duration->setObjectName(QStringLiteral("duration"));

        gridLayout->addWidget(duration, 1, 13, 1, 1);

        rebate = new QLabel(gridLayoutWidget);
        rebate->setObjectName(QStringLiteral("rebate"));

        gridLayout->addWidget(rebate, 1, 11, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 5, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 0, 1, 1, 1);

        line_3 = new QFrame(gridLayoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 0, 2, 2, 1);

        line_4 = new QFrame(gridLayoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 0, 4, 2, 1);

        line_11 = new QFrame(gridLayoutWidget);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_11, 0, 6, 2, 1);

        line_12 = new QFrame(gridLayoutWidget);
        line_12->setObjectName(QStringLiteral("line_12"));
        line_12->setFrameShape(QFrame::VLine);
        line_12->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_12, 0, 8, 2, 1);

        line_13 = new QFrame(gridLayoutWidget);
        line_13->setObjectName(QStringLiteral("line_13"));
        line_13->setFrameShape(QFrame::VLine);
        line_13->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_13, 0, 10, 2, 1);

        line_14 = new QFrame(gridLayoutWidget);
        line_14->setObjectName(QStringLiteral("line_14"));
        line_14->setFrameShape(QFrame::VLine);
        line_14->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_14, 0, 12, 2, 1);

        line_5 = new QFrame(gridLayoutWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 0, 14, 2, 1);

        line_2 = new QFrame(gridLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 0, 2, 1);

        fare = new QLabel(gridLayoutWidget);
        fare->setObjectName(QStringLiteral("fare"));

        gridLayout->addWidget(fare, 1, 9, 1, 1);

        label_2 = new QLabel(searchFlight);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 280, 101, 20));
        label_2->setStyleSheet(QLatin1String("font: italic 8pt \"Consolas\";\n"
"color: rgb(115, 115, 115);"));

        retranslateUi(searchFlight);

        QMetaObject::connectSlotsByName(searchFlight);
    } // setupUi

    void retranslateUi(QWidget *searchFlight)
    {
        searchFlight->setWindowTitle(QApplication::translate("searchFlight", "Form", 0));
        label->setText(QApplication::translate("searchFlight", "\350\257\267\350\276\223\345\205\245\350\246\201\346\237\245\350\257\242\347\232\204\350\210\252\347\217\255\345\217\267(\346\240\274\345\274\217\344\270\272Fxxx)", 0));
        searchFlightBottom->setText(QApplication::translate("searchFlight", "\347\241\256\350\256\244", 0));
        tStart->setText(QApplication::translate("searchFlight", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        plcStart->setText(QApplication::translate("searchFlight", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        label_9->setText(QApplication::translate("searchFlight", "<html><head/><body><p align=\"center\">\345\216\206\346\227\266</p></body></html>", 0));
        label_8->setText(QApplication::translate("searchFlight", "<html><head/><body><p align=\"center\">\346\212\230\346\211\243</p></body></html>", 0));
        label_5->setText(QApplication::translate("searchFlight", "<html><head/><body><p align=\"center\">\350\220\275\345\234\260\346\227\266\351\227\264</p></body></html>", 0));
        label_7->setText(QApplication::translate("searchFlight", "<html><head/><body><p align=\"center\">\347\245\250\344\273\267</p></body></html>", 0));
        tEnd->setText(QApplication::translate("searchFlight", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        plcEnd->setText(QApplication::translate("searchFlight", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        duration->setText(QApplication::translate("searchFlight", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        rebate->setText(QApplication::translate("searchFlight", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        label_3->setText(QApplication::translate("searchFlight", "<html><head/><body><p align=\"center\">\351\231\215\350\220\275\345\234\260\347\202\271</p></body></html>", 0));
        label_4->setText(QApplication::translate("searchFlight", "<html><head/><body><p align=\"center\">\350\265\267\351\243\236\346\227\266\351\227\264</p></body></html>", 0));
        label_16->setText(QApplication::translate("searchFlight", "<html><head/><body><p align=\"center\">\350\265\267\351\243\236\345\234\260\347\202\271</p></body></html>", 0));
        fare->setText(QApplication::translate("searchFlight", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        label_2->setText(QApplication::translate("searchFlight", "@lichunjie v0.4", 0));
    } // retranslateUi

};

namespace Ui {
    class searchFlight: public Ui_searchFlight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHFLIGHT_H
