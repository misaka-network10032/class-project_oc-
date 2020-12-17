#include "oh.h"
#include "ui_oh.h"

OH::OH(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OH)
{
    ui->setupUi(this);
    QMovie *movie=new QMovie(":/new/prefix1/Oh.gif");
    ui->ohlabel->setMovie(movie);
    movie->start();
}

OH::~OH()
{
    delete ui;
}

void OH::on_changebutton_clicked()
{
    emit display(0);
}

void OH::on_exitbutton_clicked()
{
    QApplication::exit();
}
