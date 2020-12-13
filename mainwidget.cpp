#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    menuwidget=new Menu;
    wordwidget=new word;
    stacklayout=new QStackedLayout;
    stacklayout->addWidget(menuwidget);
    stacklayout->addWidget(wordwidget);
    setLayout(stacklayout);
    connect(menuwidget,&Menu::display,stacklayout,&QStackedLayout::setCurrentIndex);
    connect(wordwidget,&word::display,stacklayout,&QStackedLayout::setCurrentIndex);
}

MainWidget::~MainWidget()
{
    delete ui;
}
