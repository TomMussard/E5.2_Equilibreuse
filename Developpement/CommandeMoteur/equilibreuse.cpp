#include "equilibreuse.h"
#include "capot.h"
#include "ui_equilibreuse.h"

Equilibreuse::Equilibreuse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Equilibreuse)
{
    ui->setupUi(this);
    leCapot = new capot(laCarte,0,this);
}

Equilibreuse::~Equilibreuse()
{
    delete ui;
}
