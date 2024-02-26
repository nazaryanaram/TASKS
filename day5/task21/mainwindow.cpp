#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submit_clicked()
{
    //QListWidgetItem* item = new QListWidgetItem(ui->lineEdit->text(), ui->listWidget);

    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::critical(this, "Zgushacum", "lineEdit is empty!!");
    }else{
           QListWidgetItem* item = new QListWidgetItem(ui->lineEdit->text(), ui->listWidget);
           ui->listWidget->addItem(item);
           ui->lineEdit->clear();
           ui->lineEdit->setFocus();
    }
}

