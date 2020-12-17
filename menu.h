#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QVector>
#include "word.h"
#include "ui_menu.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
    void setui()
    {
        QFile file("user.txt");
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        QTextStream inp(&file);
        if(file.isOpen()==false)
        {
            QMessageBox::about(NULL,"反馈","文件打开失败!");
            return;
        }
        QVector<QString> user;
        while(inp.atEnd()==false)
        {
            QString name;
            inp>>name;
            if(name=="") continue;
            user.push_back(name);
        }
        file.close();
        usernum=user.size();
        ui->tablewidget->setRowCount(usernum);
        int cet4num=0;
        QFile cet("cet4.txt");
        cet.open(QIODevice::ReadOnly|QIODevice::Text);
        QTextStream cinp(&cet);
        if(cet.isOpen()==false)
        {
            QMessageBox::about(NULL,"反馈","文件打开失败！");
            return;
        }
        while(cinp.atEnd()==false)
        {
            QString x;
            cinp>>x;
            if(x=="")  continue;
            cet4num++;
        }
        cet.close();
        QVector<int> cetk;
        int temp1;
        for(int i=0;i<user.size();i++)
        {
            temp1=0;
            QFile kcet("k"+user[i]+".txt");
            kcet.open(QIODevice::ReadOnly|QIODevice::Text);
            QTextStream ccinp(&kcet);
            if(kcet.isOpen()==false)
            {
                QMessageBox::about(NULL,"反馈","文件打开失败！");
                return;
            }
            while(ccinp.atEnd()==false)
            {
                QString x;
                ccinp>>x;
                if(x=="")   continue;
                QFile ccet("cet4.txt");
                ccet.open(QIODevice::ReadOnly|QIODevice::Text);
                QTextStream tccinp(&ccet);
                if(ccet.isOpen()==false)
                {
                    QMessageBox::about(NULL,"反馈","文件打开失败！");
                    return;
                }
                while(tccinp.atEnd()==false)
                {
                    QString y;
                    tccinp>>y;
                    if(x==y)   temp1++;
                }
            }
            cetk.push_back(temp1);
        }
        int grenum=0;
        QFile gre("gre.txt");
        gre.open(QIODevice::ReadOnly|QIODevice::Text);
        QTextStream gcinp(&gre);
        if(gre.isOpen()==false)
        {
            QMessageBox::about(NULL,"反馈","文件打开失败！");
            return;
        }
        while(gcinp.atEnd()==false)
        {
            QString x;
            gcinp>>x;
            if(x=="")  continue;
            grenum++;
        }
        gre.close();
        QVector<int> grek;
        int temp2;
        for(int i=0;i<user.size();i++)
        {
            temp2=0;
            QFile kgre("k"+user[i]+".txt");
            kgre.open(QIODevice::ReadOnly|QIODevice::Text);
            QTextStream cccinp(&kgre);
            if(kgre.isOpen()==false)
            {
                QMessageBox::about(NULL,"反馈","文件打开失败！");
                return;
            }
            while(cccinp.atEnd()==false)
            {
                QString x;
                cccinp>>x;
                if(x=="")   continue;
                QFile cgre("gre.txt");
                cgre.open(QIODevice::ReadOnly|QIODevice::Text);
                QTextStream tccinp(&cgre);
                if(cgre.isOpen()==false)
                {
                    QMessageBox::about(NULL,"反馈","文件打开失败！");
                    return;
                }
                while(tccinp.atEnd()==false)
                {
                    QString y;
                    tccinp>>y;
                    if(x==y)   temp2++;
                }
            }
            grek.push_back(temp2);
        }
        for(int i=0;i<user.size();i++)
        {
           double x1=double(cetk[i]);
           double y1=double(cet4num);
           double x2=double(grek[i]);
           double y2=double(grenum);
           int z1=(x1/y1)*100;
           int z2=(x2/y2)*100;
           Menu::ui->tablewidget->setItem(i,0,new QTableWidgetItem(user[i]));
           Menu::ui->tablewidget->setItem(i,1,new QTableWidgetItem(QString::number(z1)+"%"));
           Menu::ui->tablewidget->setItem(i,2,new QTableWidgetItem(QString::number(z2)+"%"));
        }
    }
private:
    Ui::Menu *ui;
    QButtonGroup *menubuttongroup;
    int usernum;
signals:
    void display(int number);
private slots:
    void on_newbutton_clicked();
    void on_endbutton_clicked();
    void on_startbutton_clicked();
    void on_rebutton_clicked();
    void on_betubutton_clicked();
};

#endif // MENU_H
