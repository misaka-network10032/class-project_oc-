#include "word.h"
#include "ui_word.h"

word::word(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::word)
{
    ui->setupUi(this);
    ui->wordlabel->setText("");
}

word::~word()
{
    delete ui;
}

void word::on_startbutton_clicked()
{
    wordlist.resize(0);
    onceword.resize(0);
    QFile file("num.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(file.isOpen()==false)
    {
        QMessageBox::about(NULL,"反馈","文件打开失败！");
        return;
    }
    QTextStream inp(&file);
    while(inp.atEnd()==false)
    {
       QString x;
       inp>>x>>name;
       number=x.toInt();
    }
    file.close();
    QString tname=name+"temp.txt";
    QFile ifile(tname);
    ifile.open(QIODevice::ReadOnly|QIODevice::Text);
    if(ifile.isOpen()==false)
    {
        QMessageBox::about(NULL,"反馈","文件打开失败！");
        return;
    }
    QTextStream iinp(&ifile);
    while(iinp.atEnd()==false)
    {
        QString x;
        iinp>>x;
        wordlist.push_back(x);
    }
    ifile.close();
    wordlist.pop_back();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int size=wordlist.size();
    if(size==0)   return;
    QVector<int> rand;
    for(int i=0;i<number;i++)
    {
        int flag=0;
        int temp=qrand()%size;
        for(int j=0;j<rand.size();j++)
        {
            if(temp==rand[j])
            {
                i--;
                flag=1;
                break;
            }
        }
        if(flag==1)  continue;
        rand.push_back(temp);
        onceword.push_back(wordlist[temp]);
    }
    int tsize=onceword.size()-1;
    ui->wordlabel->setText(onceword[tsize]);
}

void word::on_knowpushButton_clicked()
{
    int num=getnumber();
    if(num==0)
    {
        QMessageBox::about(NULL,"反馈","没有单词了~");
        return;
    }
    QFile file("k"+getname()+".txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    if(file.isOpen()==false)
    {
        QMessageBox::about(NULL,"反馈","文件打开失败");
        return;
    }
    QTextStream out(&file);
    out<<ui->wordlabel->text()<<" ";
    setnumber(num-1);
    if(getnumber()==0)
    {
        ui->wordlabel->setText("");
        QMessageBox::about(NULL,"反馈","没有单词了~");
        return;
    }
    ui->wordlabel->setText(getword(getnumber()-1));
}

void word::on_unknownbutton_clicked()
{
    int num=getnumber();
    if(num==0)
    {
        QMessageBox::about(NULL,"反馈","没有单词了~");
        return;
    }
    QFile file(getname()+".txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    if(file.isOpen()==false)
    {
        QMessageBox::about(NULL,"反馈","文件打开失败");
        return;
    }
    QTextStream out(&file);
    out<<ui->wordlabel->text()<<" ";
    setnumber(num-1);
    if(getnumber()==0)
    {
        ui->wordlabel->setText("");
        QMessageBox::about(NULL,"反馈","没有单词了~");
        return;
    }
    ui->wordlabel->setText(getword(getnumber()-1));
}


void word::on_skipbutton_clicked()
{
    int num=getnumber();
    if(num==0)
    {
        QMessageBox::about(NULL,"反馈","没有单词了~");
        return;
    }
    QFile file(getname()+".txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    if(file.isOpen()==false)
    {
        QMessageBox::about(NULL,"反馈","文件打开失败");
        return;
    }
    QTextStream out(&file);
    out<<ui->wordlabel->text()<<" ";
    setnumber(num-1);
    if(getnumber()==0)
    {
        ui->wordlabel->setText("");
        QMessageBox::about(NULL,"反馈","没有单词了~");
        return;
    }
    ui->wordlabel->setText(getword(getnumber()-1));
}

void word::on_returnbutton_clicked()
{
    emit display(0);
}
