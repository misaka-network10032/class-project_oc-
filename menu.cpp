#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    ui->tablewidget->setStyleSheet("QTableWidget{border-image:url(:/new/prefix1/w1.jpg);}");
    menubuttongroup=new QButtonGroup;
    menubuttongroup->addButton(ui->cet4button,0);
    menubuttongroup->addButton(ui->GREbutton,1);
    ui->tablewidget->setColumnCount(3);
    QStringList headerLabels;
    headerLabels<<tr("用户名")<<tr("cet完成度")<<tr("gre完成度");
    ui->tablewidget->setHorizontalHeaderLabels(headerLabels);
    ui->tablewidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    setui();
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_startbutton_clicked()
{
    QString name=ui->namelineEdit->text();
    int flag=0;
    int s=ui->numlineEdit->text().toInt();
    ui->numlineEdit->clear();
    if(name=="")
    {
        QMessageBox::about(NULL,"反馈","用户名不能为空！");
        return;
    }
    QFile file("user.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(file.isOpen()==false)
    {
        QMessageBox::about(NULL,"反馈","文件打开失败！");
        return;
    }
    QTextStream inp(&file);
    while(inp.atEnd()==false)
    {
        QString tname;
        inp>>tname;
        if(name==tname)  flag=1;
    }
    if(flag==0)
    {
         QMessageBox::about(NULL,"反馈","用户不存在");
         return;
    }
    file.close();
    QString tname=name+"temp.txt";
    int tag=-1;
    tag=menubuttongroup->checkedId();
    QVector<QString> temp;
    if(tag==0)
    {
        QFile ck("cet4.txt");
        ck.open(QIODevice::ReadOnly|QIODevice::Text);
        if(ck.isOpen()==false)
        {
            QMessageBox::about(NULL, "反馈", "文件打开失败");
            return;
        }
        QTextStream inr(&ck);
        while(inr.atEnd()==false)
        {
            int tflag=0;
            QString x;
            inr>>x;
            if(x=="")  continue;
            QString k_name="k"+name+".txt";
            QFile kw(k_name);
            kw.open(QIODevice::ReadOnly|QIODevice::Text);
            if(kw.isOpen()==false)
            {
                QMessageBox::about(NULL, "反馈", "文件打开失败");
                return;
            }
            QTextStream kin(&kw);
            while(kin.atEnd()==false)
            {
                QString y;
                kin>>y;
                if(y==x)
                {
                    tflag=1;
                    break;
                }
            }
            kw.close();
            if(tflag==1)  continue;
            temp.push_back(x);
        }
        ck.close();
    }
    else if(tag==1)
    {
        QFile ck("gre.txt");
        ck.open(QIODevice::ReadOnly|QIODevice::Text);
        if(ck.isOpen()==false)
        {
            QMessageBox::about(NULL, "反馈", "文件打开失败");
            return;
        }
        QTextStream inr(&ck);
        while(inr.atEnd()==false)
        {
            int tflag=0;
            QString x;
            inr>>x;
            if(x=="")  continue;
            QString k_name="k"+name+".txt";
            QFile kw(k_name);
            kw.open(QIODevice::ReadOnly|QIODevice::Text);
            if(kw.isOpen()==false)
            {
                QMessageBox::about(NULL, "反馈", "文件打开失败");
                return;
            }
            QTextStream kin(&kw);
            while(kin.atEnd()==false)
            {
                QString y;
                kin>>y;
                if(y==x)
                {
                    tflag=1;
                    break;
                }
            }
            kw.close();
            if(tflag==1)  continue;
            temp.push_back(x);
        }
        ck.close();
    }
    else
    {
        QMessageBox::about(NULL,"反馈","请选择词库！");
        return;
    }
    QString ttname=name+".txt";
    QFile mem(ttname);
    mem.open(QIODevice::ReadOnly|QIODevice::Text);
    if(mem.isOpen()==false)
    {
        QMessageBox::about(NULL, "反馈", "文件打开失败");
        return;
    }
    QTextStream inw(&mem);
    while(inw.atEnd()==false)
    {
        int tflag=0;
        QString x;
        inw>>x;
        if(x=="") continue;
       for(int i=0;i<temp.size();i++)
        {
            QString y;
            y=temp[i];
            if(y==x)
            {
                tflag=1;
                break;
            }
        }
       QString k_name="k"+name+".txt";
       QFile kw(k_name);
       kw.open(QIODevice::ReadOnly|QIODevice::Text);
       if(kw.isOpen()==false)
       {
           QMessageBox::about(NULL, "反馈", "文件打开失败");
           return;
       }
       QTextStream kin(&kw);
       while(kin.atEnd()==false)
       {
           QString y;
           kin>>y;
           if(y==x)
           {
               tflag=1;
               break;
           }
       }
       kw.close();
        if(tflag==1)  continue;
        temp.push_back(x);
    }
    mem.close();
    if(temp.size()==0)
    {
        QMessageBox::about(NULL, "反馈", "太棒了，你已经掌握了词库的所有单词");
        emit display(3);
        return;
    }
    QFile n_file(tname);
    n_file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
    if(n_file.isOpen()==false)
    {
        QMessageBox::about(NULL, "反馈", "文件打开失败");
        return;
    }
    QTextStream ine(&n_file);
    for(int i=0;i<temp.size();i++)
    {
        QString x=temp[i]+" ";
        ine<<x;
    }
    n_file.close();
    QFile num("num.txt");
    num.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
    if(s==0)
    {
        QMessageBox::about(NULL, "反馈", "单词数量不可以为0！");
        return;
    }
    else if(s<0)
    {
        QMessageBox::about(NULL, "反馈", "单词数量不可以为负数！");
        return;
    }
    else if(s>temp.size())
    {
        QMessageBox::about(NULL,"反馈","太贪心了，没有这么多单词要记忆了~");
        return;
    }
    QTextStream inq(&num);
    inq<<s<<endl;
    inq<<name;
    num.close();
    QMessageBox::about(NULL,"反馈","设置保存成功！");
    emit display(1);
}

void Menu::on_newbutton_clicked()
{
    QString name=ui->namelineEdit->text();
    int flag=0;
    if(name=="")
    {
        QMessageBox::about(NULL,"反馈","用户名不能为空！");
        return;
    }
    QFile file("user.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(file.isOpen()==false)
    {
        QMessageBox::about(NULL,"反馈","文件打开失败！");
        return;
    }
    QTextStream inp(&file);
    while(inp.atEnd()==false)
    {
        QString tname;
        inp>>tname;
        if(name==tname)  flag=1;
    }
    if(flag==1)
    {
        QMessageBox::about(NULL,"反馈","用户已存在，不能重复建立同名用户");
        return;
    }
    file.close();
    QFile n_file("user.txt");
    n_file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    if(n_file.isOpen()==false)
    {
        QMessageBox::about(NULL,"反馈","文件打开失败");
        return;
    }
    QTextStream out(&n_file);
    out<<name<<" ";
    n_file.close();
    QString fname=name+".txt";
    QFile file_n(fname);
    file_n.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    if(file_n.isOpen()==false)
    {
        QMessageBox::about(NULL,"反馈","文件打开失败");
        return;
    }
    file_n.close();
    QString kname="k"+name+".txt";
    QFile kfile(kname);
    kfile.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    if(kfile.isOpen()==false)
    {
        QMessageBox::about(NULL,"反馈","文件打开失败");
        return;
    }
    kfile.close();
    QString tname=name+"temp.txt";
    QFile tfile(tname);
    tfile.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    if(tfile.isOpen()==false)
    {
        QMessageBox::about(NULL,"反馈","文件打开失败");
        return;
    }
    tfile.close();
    QMessageBox::about(NULL,"反馈","新建成功");
    setui();
}

void Menu::on_endbutton_clicked()
{
    QApplication::exit();
}


void Menu::on_rebutton_clicked()
{
    setui();
    QMessageBox::about(NULL,"反馈","刷新成功！");
}


void Menu::on_betubutton_clicked()
{
    emit display(2);
}
