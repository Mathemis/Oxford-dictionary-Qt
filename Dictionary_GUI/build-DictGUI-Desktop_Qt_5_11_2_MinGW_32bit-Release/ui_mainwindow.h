/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_0;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_1;
    QPushButton *pushButton_0;
    QLabel *label_1;
    QWidget *page_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_4;
    QPushButton *pushButton_1;
    QLabel *label_5;
    QWidget *page_2;
    QLabel *label_7;
    QPushButton *pushButton_6;
    QTextEdit *textEdit_1;
    QLabel *label_8;
    QLabel *label_6;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit_2;
    QWidget *page_3;
    QPushButton *pushButton_8;
    QTextEdit *textEdit_2;
    QLabel *label_10;
    QLineEdit *lineEdit_3;
    QLabel *label_9;
    QLabel *label_11;
    QPushButton *pushButton_9;
    QWidget *page_4;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QLineEdit *lineEdit_4;
    QLabel *label_14;
    QLabel *label_12;
    QLabel *label_13;
    QTextEdit *textEdit_3;
    QWidget *page_5;
    QPushButton *pushButton_12;
    QTextEdit *textEdit_4;
    QLabel *label_16;
    QPushButton *pushButton_14;
    QLineEdit *lineEdit_5;
    QLabel *label_15;
    QLabel *label_17;
    QPushButton *pushButton_13;
    QWidget *page_6;
    QLabel *label_18;
    QPushButton *pushButton_15;
    QLineEdit *lineEdit_6;
    QLabel *label_19;
    QPushButton *pushButton_16;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(620, 515);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 621, 481));
        page_0 = new QWidget();
        page_0->setObjectName(QStringLiteral("page_0"));
        label_2 = new QLabel(page_0);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 280, 131, 61));
        QFont font;
        font.setFamily(QStringLiteral("Palatino Linotype"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        label_3 = new QLabel(page_0);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 340, 271, 31));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        lineEdit_1 = new QLineEdit(page_0);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));
        lineEdit_1->setGeometry(QRect(10, 380, 601, 41));
        QFont font2;
        font2.setPointSize(11);
        lineEdit_1->setFont(font2);
        pushButton_0 = new QPushButton(page_0);
        pushButton_0->setObjectName(QStringLiteral("pushButton_0"));
        pushButton_0->setGeometry(QRect(530, 430, 81, 31));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_0->setFont(font3);
        label_1 = new QLabel(page_0);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(70, 20, 481, 251));
        label_1->setPixmap(QPixmap(QString::fromUtf8(":/oed_sharing.png")));
        stackedWidget->addWidget(page_0);
        page_1 = new QWidget();
        page_1->setObjectName(QStringLiteral("page_1"));
        pushButton_2 = new QPushButton(page_1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 230, 211, 61));
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(true);
        font4.setWeight(75);
        pushButton_2->setFont(font4);
        pushButton_2->setStyleSheet(QStringLiteral("color: rgb(156, 78, 0);"));
        pushButton_2->setFlat(false);
        pushButton_3 = new QPushButton(page_1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(80, 320, 211, 61));
        pushButton_3->setFont(font4);
        pushButton_3->setStyleSheet(QLatin1String("color: rgb(156, 78, 0);\n"
""));
        pushButton_4 = new QPushButton(page_1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(330, 230, 211, 61));
        pushButton_4->setFont(font4);
        pushButton_4->setStyleSheet(QLatin1String("color: rgb(156, 78, 0);\n"
""));
        pushButton_5 = new QPushButton(page_1);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(330, 320, 211, 61));
        QFont font5;
        font5.setPointSize(13);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        pushButton_5->setFont(font5);
        pushButton_5->setStyleSheet(QLatin1String("\n"
"color: rgb(156, 78, 0);"));
        label_4 = new QLabel(page_1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 160, 101, 41));
        QFont font6;
        font6.setFamily(QStringLiteral("OCR A Extended"));
        font6.setPointSize(29);
        font6.setBold(true);
        font6.setWeight(75);
        label_4->setFont(font6);
        label_4->setStyleSheet(QLatin1String("color: rgb(0, 194, 0);\n"
"\n"
""));
        pushButton_1 = new QPushButton(page_1);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(80, 420, 461, 51));
        pushButton_1->setFont(font4);
        pushButton_1->setStyleSheet(QLatin1String("color: rgb(67, 67, 67);\n"
""));
        label_5 = new QLabel(page_1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 601, 151));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/oxford.png")));
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 50, 131, 31));
        label_7->setFont(font1);
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(540, 140, 61, 31));
        pushButton_6->setFont(font2);
        textEdit_1 = new QTextEdit(page_2);
        textEdit_1->setObjectName(QStringLiteral("textEdit_1"));
        textEdit_1->setGeometry(QRect(20, 200, 581, 231));
        textEdit_1->setFont(font2);
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 160, 131, 31));
        QFont font7;
        font7.setPointSize(12);
        font7.setBold(true);
        font7.setItalic(false);
        font7.setUnderline(false);
        font7.setWeight(75);
        font7.setStrikeOut(false);
        label_8->setFont(font7);
        label_8->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(260, 0, 101, 41));
        QFont font8;
        font8.setFamily(QStringLiteral("Segoe UI Black"));
        font8.setPointSize(18);
        font8.setBold(false);
        font8.setItalic(false);
        font8.setWeight(50);
        label_6->setFont(font8);
        label_6->setStyleSheet(QStringLiteral(""));
        pushButton_7 = new QPushButton(page_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(0, 450, 51, 31));
        QFont font9;
        font9.setPointSize(10);
        pushButton_7->setFont(font9);
        lineEdit_2 = new QLineEdit(page_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 90, 581, 41));
        lineEdit_2->setFont(font2);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        pushButton_8 = new QPushButton(page_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(530, 400, 71, 31));
        QFont font10;
        font10.setFamily(QStringLiteral("Segoe UI Historic"));
        font10.setPointSize(11);
        font10.setBold(false);
        font10.setItalic(false);
        font10.setWeight(50);
        pushButton_8->setFont(font10);
        textEdit_2 = new QTextEdit(page_3);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(20, 200, 581, 181));
        textEdit_2->setFont(font2);
        label_10 = new QLabel(page_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 50, 131, 31));
        label_10->setFont(font1);
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        lineEdit_3 = new QLineEdit(page_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 90, 581, 41));
        lineEdit_3->setFont(font2);
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(260, 0, 91, 41));
        label_9->setFont(font8);
        label_9->setStyleSheet(QStringLiteral(""));
        label_11 = new QLabel(page_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 160, 141, 31));
        label_11->setFont(font7);
        label_11->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        pushButton_9 = new QPushButton(page_3);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(0, 450, 51, 31));
        QFont font11;
        font11.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font11.setPointSize(10);
        font11.setBold(false);
        font11.setItalic(false);
        font11.setWeight(50);
        pushButton_9->setFont(font11);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        pushButton_11 = new QPushButton(page_4);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(0, 450, 51, 31));
        pushButton_11->setFont(font11);
        pushButton_10 = new QPushButton(page_4);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(530, 400, 71, 31));
        pushButton_10->setFont(font10);
        lineEdit_4 = new QLineEdit(page_4);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(20, 90, 581, 41));
        lineEdit_4->setFont(font2);
        label_14 = new QLabel(page_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 160, 141, 31));
        label_14->setFont(font7);
        label_14->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        label_12 = new QLabel(page_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(260, 0, 101, 41));
        label_12->setFont(font8);
        label_12->setStyleSheet(QStringLiteral(""));
        label_13 = new QLabel(page_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 50, 131, 31));
        label_13->setFont(font1);
        label_13->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        textEdit_3 = new QTextEdit(page_4);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(20, 200, 581, 181));
        textEdit_3->setFont(font2);
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        pushButton_12 = new QPushButton(page_5);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(550, 140, 51, 21));
        pushButton_12->setFont(font2);
        textEdit_4 = new QTextEdit(page_5);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(20, 200, 581, 171));
        textEdit_4->setFont(font2);
        label_16 = new QLabel(page_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 50, 131, 31));
        label_16->setFont(font1);
        label_16->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        pushButton_14 = new QPushButton(page_5);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(0, 450, 51, 31));
        pushButton_14->setFont(font9);
        lineEdit_5 = new QLineEdit(page_5);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(20, 90, 581, 41));
        lineEdit_5->setFont(font2);
        label_15 = new QLabel(page_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(260, 0, 111, 41));
        label_15->setFont(font8);
        label_15->setStyleSheet(QStringLiteral(""));
        label_17 = new QLabel(page_5);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 160, 131, 31));
        label_17->setFont(font7);
        label_17->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        pushButton_13 = new QPushButton(page_5);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(410, 390, 191, 31));
        pushButton_13->setFont(font2);
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        label_18 = new QLabel(page_6);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(280, 0, 71, 41));
        label_18->setFont(font8);
        label_18->setStyleSheet(QStringLiteral(""));
        pushButton_15 = new QPushButton(page_6);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(540, 180, 61, 31));
        pushButton_15->setFont(font2);
        lineEdit_6 = new QLineEdit(page_6);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(20, 110, 581, 41));
        lineEdit_6->setFont(font2);
        label_19 = new QLabel(page_6);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 70, 151, 31));
        label_19->setFont(font1);
        label_19->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        pushButton_16 = new QPushButton(page_6);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(0, 450, 51, 31));
        pushButton_16->setFont(font9);
        stackedWidget->addWidget(page_6);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OED Project - 1712475", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "WELCOME!", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "First, please input data file location:", nullptr));
        pushButton_0->setText(QApplication::translate("MainWindow", "Import", nullptr));
        label_1->setText(QString());
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("MainWindow", "SEARCH", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "MODIFY", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "INSERT", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "REMOVE", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "MENU", nullptr));
        pushButton_1->setText(QApplication::translate("MainWindow", "SAVE CURRENT DICTIONARY DATA", nullptr));
        label_5->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "Input word:", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "OK", nullptr));
        textEdit_1->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Definiton:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "SEARCH", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "Back", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "OK", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Input word:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "INSERT", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Input definiton:", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "Back", nullptr));
        pushButton_11->setText(QApplication::translate("MainWindow", "Back", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "OK", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Input definiton:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "MODIFY", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Input word:", nullptr));
        pushButton_12->setText(QApplication::translate("MainWindow", "OK", nullptr));
        textEdit_4->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Input word:", nullptr));
        pushButton_14->setText(QApplication::translate("MainWindow", "Back", nullptr));
        lineEdit_5->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "REMOVE", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "Definiton:", nullptr));
        pushButton_13->setText(QApplication::translate("MainWindow", "Delete this word from OED", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "SAVE", nullptr));
        pushButton_15->setText(QApplication::translate("MainWindow", "OK", nullptr));
        lineEdit_6->setText(QString());
        label_19->setText(QApplication::translate("MainWindow", "Input file location:", nullptr));
        pushButton_16->setText(QApplication::translate("MainWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
