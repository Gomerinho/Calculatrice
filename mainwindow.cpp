#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_plus_moins, SIGNAL(released()),this,SLOT(operation_pressed()));
    connect(ui->pushButton_pourcent, SIGNAL(released()),this,SLOT(operation_pressed()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    double nombreLabel;
    QString nouveauLabel;
    nombreLabel = (ui->label->text() + button->text()).toDouble();

    nouveauLabel = QString::number(nombreLabel, 'g', 15);
    ui->label->setText(nouveauLabel);
}

void MainWindow::on_pushButton_point_released()
{
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();
    double nombreLabel;
    QString nouveauLabel;
    if (button->text() == "+/-") {
        nombreLabel = ui->label->text().toDouble() ;
        nombreLabel = nombreLabel * -1;
        nouveauLabel = QString::number(nombreLabel, 'g', 15);
        ui->label->setText(nouveauLabel);
    }

    if (button->text() == "%") {
        nombreLabel = ui->label->text().toDouble() ;
        nombreLabel = nombreLabel * 0.01;
        nouveauLabel = QString::number(nombreLabel, 'g', 15);
        ui->label->setText(nouveauLabel);
    }
}

void MainWindow::on_pushButton_clear_released()
{

}

void MainWindow::on_pushButton_egale_released()
{

}
