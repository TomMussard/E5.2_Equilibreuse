#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "capot.h"
#include "moteur.h"
#include "mcculdaq.h"
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onCapot_EtatCapotChange(bool _etat);

private slots:
    void on_dial_ConsigneVitesse_valueChanged(int value);
    void on_pushButton_Lancer_clicked();
    void on_pushButton_Arreter_clicked();

private:
    Ui::MainWindow *ui;
    Moteur *leMoteur;
    MccUldaq laCarte;
    QLabel labelEtatCapot;
    Capot *leCapot;
};
#endif // MAINWINDOW_H
