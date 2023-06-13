#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fileeditor.cpp"
#include <QString>
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


void MainWindow::on_pushButton_clicked()
{
    QString path2 = ui->path->text();

    FileEditor obj1(path2.toStdString());
    QString OUT;
    QString EDIT;
    EditChecker z1;
    ExsistingChecker x;
    obj1.Attach(&z1);
    obj1.Attach(&x);
    obj1.Write("A");
        OUT = x.FEx;
    EDIT = z1.FEd;
    OUT = OUT + " " + EDIT;
    QMessageBox::information(this,"Редактирование",OUT);

}

void MainWindow::on_pushButton_2_clicked()
{
    QString path2 = ui->path->text();

      FileEditor obj1(path2.toStdString());
    QString OUT;
    EditChecker z1;
    ExsistingChecker x;
    obj1.Attach(&z1);
    obj1.Attach(&x);
    obj1.Write("");
    OUT = x.FEx;
    QMessageBox::information(this,"Проверка на существование",OUT);
}
