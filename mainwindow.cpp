#include "mainwindow.h"
#include "ui_mainwindow.h"

double premierNum;
bool utilisateurSecondNombre;

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

    connect(ui->pushButton_addition, SIGNAL(released()),this,SLOT(operation_binaire_pressed()));
    connect(ui->pushButton_division, SIGNAL(released()),this,SLOT(operation_binaire_pressed()));
    connect(ui->pushButton_soustraction, SIGNAL(released()),this,SLOT(operation_binaire_pressed()));
    connect(ui->pushButton_multiplication, SIGNAL(released()),this,SLOT(operation_binaire_pressed()));


    ui->pushButton_addition->setCheckable(true);
    ui->pushButton_soustraction->setCheckable(true);
    ui->pushButton_division->setCheckable(true);
    ui->pushButton_multiplication->setCheckable(true);

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

    if ((ui->pushButton_addition->isChecked() || ui->pushButton_soustraction->isChecked() || ui->pushButton_multiplication->isChecked() || ui->pushButton_division->isChecked()) && (!utilisateurSecondNombre)) {
        nombreLabel = button->text().toDouble();
        utilisateurSecondNombre = true;
        nouveauLabel = QString::number(nombreLabel, 'g', 15);
    }
    else {
        if (ui->label->text().contains('.') && button->text()=="0") {
            nouveauLabel = ui->label->text() + button->text();
        }else{
            nombreLabel = (ui->label->text() + button->text()).toDouble();
            nouveauLabel = QString::number(nombreLabel, 'g', 15);
        }
    }


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
    ui->pushButton_addition->setChecked(false);
    ui->pushButton_multiplication->setChecked(false);
    ui->pushButton_division->setChecked(false);
    ui->pushButton_soustraction->setChecked(false);

    utilisateurSecondNombre = false;

    ui->label->setText("0");
}

void MainWindow::on_pushButton_egale_released()
{
    double labelNumber, secondNum;

    QString nouveauLabel;

    secondNum = ui->label->text().toDouble();

    if (ui->pushButton_addition->isChecked()) {
        labelNumber = premierNum + secondNum;
        nouveauLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(nouveauLabel);
        ui->pushButton_addition->setChecked(false);
    }
    else if (ui->pushButton_soustraction->isChecked()) {
        labelNumber = premierNum - secondNum;
        nouveauLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(nouveauLabel);
        ui->pushButton_soustraction->setChecked(false);
    }
    else if (ui->pushButton_multiplication->isChecked()) {
        labelNumber = premierNum * secondNum;
        nouveauLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(nouveauLabel);
        ui->pushButton_multiplication->setChecked(false);
    }
    else if (ui->pushButton_division->isChecked()) {
        labelNumber = premierNum / secondNum;
        nouveauLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(nouveauLabel);
        ui->pushButton_division->setChecked(false);
    }

    utilisateurSecondNombre = false;
}

void MainWindow::operation_binaire_pressed()
{
    QPushButton * button = (QPushButton *) sender();

    premierNum = ui->label->text().toDouble();

    button->setChecked(true);
}

