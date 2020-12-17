#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    setWindowTitle("记忆大师");
    QFont font;
    font.setFamily("KaiTi");
    qApp->setFont(font);
    menuwidget=new Menu;
    wordwidget=new word;
    usewidget=new use;
    ohwidget=new OH;
    stacklayout=new QStackedLayout;
    stacklayout->addWidget(menuwidget);
    stacklayout->addWidget(wordwidget);
    stacklayout->addWidget(usewidget);
    stacklayout->addWidget(ohwidget);
    setLayout(stacklayout);
    connect(menuwidget,&Menu::display,stacklayout,&QStackedLayout::setCurrentIndex);
    connect(wordwidget,&word::display,stacklayout,&QStackedLayout::setCurrentIndex);
    connect(usewidget,&use::display,stacklayout,&QStackedLayout::setCurrentIndex);
    connect(ohwidget,&OH::display,stacklayout,&QStackedLayout::setCurrentIndex);
}

MainWidget::~MainWidget()
{
    delete ui;
}
