#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_0_clicked()
{
    string s = ui->lineEdit_1->text().toStdString();
    bool check = dict.ReadFile(s);
    if (check == false)
        QMessageBox::critical(this,"Message", "Can not find the data file!");
    else{
        QMessageBox::about(this,"Message", "Import data successfull!");
        ui->stackedWidget->setCurrentIndex(1);
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_lineEdit_2_editingFinished()
{}


// Search
void MainWindow::on_pushButton_6_clicked()
{
    string s = ui->lineEdit_2->text().toStdString();
    string check = dict.Search(s);
    if (check == "")
        QMessageBox::critical(this,"Message", "Can not find the word!");
    else{
        QString qs = QString::fromLocal8Bit(check.c_str());
        ui->textEdit_1->setText(qs);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit_2->clear();
    ui->textEdit_1->clear();
    ui->stackedWidget->setCurrentIndex(1);
}
//


// Insert
void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_8_clicked()
{
    string k = ui->lineEdit_3->text().toStdString();
    string v = ui->textEdit_2->toPlainText().toStdString();
    dict.Insert(k, v);
    QMessageBox::about(this,"Message", "Insert word successfully!");
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->lineEdit_3->clear();
    ui->textEdit_2->clear();
    ui->stackedWidget->setCurrentIndex(1);
}
//

// Modify
void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_10_clicked()
{
    string k = ui->lineEdit_4->text().toStdString();
    string v = ui->textEdit_3->toPlainText().toStdString();
    bool check = dict.Modify(k, v);
    if (check) QMessageBox::about(this,"Message", "Edit successfully!");
    else QMessageBox::critical(this,"Message", "Can not find the word!");
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->lineEdit_4->clear();
    ui->textEdit_3->clear();
    ui->stackedWidget->setCurrentIndex(1);
}
//

// Remove
void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_12_clicked()
{
    string s = ui->lineEdit_5->text().toStdString();
    string check = dict.Search(s);
    if (check == "")
        QMessageBox::critical(this,"Message", "This word does not exist!");
    else{
        QString qs = QString::fromLocal8Bit(check.c_str());
        ui->textEdit_4->setText(qs);
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    string s = ui->lineEdit_5->text().toStdString();
    dict.Remove(s);
    QMessageBox::about(this,"Message", "Remove word successfully!");
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->lineEdit_5->clear();
    ui->textEdit_4->clear();
    ui->stackedWidget->setCurrentIndex(1);
}


// Save
void MainWindow::on_pushButton_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_15_clicked()
{
    string s = ui->lineEdit_6->text().toStdString();
    bool check = dict.Save(s);
    if (check) QMessageBox::about(this,"Message", "Saved successfully!");
    else QMessageBox::critical(this,"Message", "Can not make file!");
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->lineEdit_6->clear();
    ui->stackedWidget->setCurrentIndex(1);
}
