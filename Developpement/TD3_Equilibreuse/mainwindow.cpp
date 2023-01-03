#include "mainwindow.h"
#include "capot.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    leMoteur = new Moteur(laCarte,0,4 );
    leCapot = new Capot(laCarte,0,this);
    connect(leCapot,&Capot::EtatCapotChange,this,&MainWindow::onCapot_EtatCapotChange);
    onCapot_EtatCapotChange(leCapot -> getEtatCapot());

    ui->statusbar->addPermanentWidget(&labelEtatCapot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCapot_EtatCapotChange(bool _etat)
{
    QPalette palette;
    labelEtatCapot.setAutoFillBackground(true);
    if(_etat)
    {
        palette.setColor(QPalette::WindowText,Qt::black);
        labelEtatCapot.setPalette(palette);
        labelEtatCapot.setText("| Capot fermé|");
    }
    else
    {
        palette.setColor(QPalette::WindowText,Qt::red);
        labelEtatCapot.setPalette(palette);
        labelEtatCapot.setText("| Capot ouvert |");
        on_pushButton_Arreter_clicked();
    }
}

void MainWindow::on_dial_ConsigneVitesse_valueChanged(int value)
{
    ui -> lcdNumber_consigne -> display(value);
}


void MainWindow::on_pushButton_Lancer_clicked()
{
    if(ui->pushButton_Lancer->text()=="Moteur Lancer")
    {
        ui->pushButton_Lancer->setText("Fixer consigne");
    }
    leMoteur->FixerConsigneVitesse(ui->dial_ConsigneVitesse->value());
}


void MainWindow::on_pushButton_Arreter_clicked()
{
    ui->pushButton_Lancer->setText("Moteur Lancer");
    leMoteur->FixerConsigneVitesse(0);
    ui->dial_ConsigneVitesse->setValue(0);
}

