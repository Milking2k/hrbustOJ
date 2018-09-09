/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QFrame *line;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *searchFlight;
    QPushButton *bookTicks;
    QPushButton *refund;
    QPushButton *addFlight;
    QPushButton *modifyFlight;
    QPushButton *quitSys;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(454, 348);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 50, 281, 51));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(50, 120, 351, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(70, 160, 291, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        searchFlight = new QPushButton(gridLayoutWidget);
        searchFlight->setObjectName(QStringLiteral("searchFlight"));

        gridLayout->addWidget(searchFlight, 0, 0, 1, 1);

        bookTicks = new QPushButton(gridLayoutWidget);
        bookTicks->setObjectName(QStringLiteral("bookTicks"));

        gridLayout->addWidget(bookTicks, 0, 1, 1, 1);

        refund = new QPushButton(gridLayoutWidget);
        refund->setObjectName(QStringLiteral("refund"));

        gridLayout->addWidget(refund, 0, 2, 1, 1);

        addFlight = new QPushButton(gridLayoutWidget);
        addFlight->setObjectName(QStringLiteral("addFlight"));

        gridLayout->addWidget(addFlight, 1, 0, 1, 1);

        modifyFlight = new QPushButton(gridLayoutWidget);
        modifyFlight->setObjectName(QStringLiteral("modifyFlight"));

        gridLayout->addWidget(modifyFlight, 1, 1, 1, 1);

        quitSys = new QPushButton(gridLayoutWidget);
        quitSys->setObjectName(QStringLiteral("quitSys"));

        gridLayout->addWidget(quitSys, 1, 2, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(330, 320, 111, 20));
        label_2->setStyleSheet(QLatin1String("font: italic 9pt \"Consolas\";\n"
"color: rgb(127, 127, 127);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 50, 51, 51));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/bottom_img);"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">\346\254\242\350\277\216\344\275\277\347\224\250\345\277\253\345\277\253\345\277\253\350\210\252\347\217\255\350\256\242\347\245\250\347\263\273\347\273\237</span></p></body></html>", 0));
        searchFlight->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\350\210\252\347\217\255", 0));
        bookTicks->setText(QApplication::translate("MainWindow", "\350\264\255\347\245\250", 0));
        refund->setText(QApplication::translate("MainWindow", "\346\237\245\347\245\250/\351\200\200\347\245\250", 0));
        addFlight->setText(QApplication::translate("MainWindow", "\345\242\236\345\212\240\350\210\252\347\217\255", 0));
        modifyFlight->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\350\210\252\347\217\255", 0));
        quitSys->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        label_2->setText(QApplication::translate("MainWindow", "@lichunjie v0.4", 0));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
