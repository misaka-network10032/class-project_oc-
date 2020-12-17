#include "use.h"
#include "ui_use.h"

use::use(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::use)
{
    ui->setupUi(this);
    ui->piclabel->setStyleSheet("QLabel{border-image:url(:/new/prefix1/use.jpg);}");
    //ui->tablewidget->setStyleSheet("QTableWidget{border-image:url(:/new/prefix1/w1.jpg);}");
}

use::~use()
{
    delete ui;
}

void use::on_backbutton_clicked()
{
    emit display(0);
}
