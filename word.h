#ifndef WORD_H
#define WORD_H

#include <QWidget>
#include <QFile>
#include <QButtonGroup>
#include <QMessageBox>
#include <QDebug>
#include <QTime>
#include <QtGlobal>
#include "menu.h"
#include "ui_menu.h"

namespace Ui {
class word;
}

class word : public QWidget
{
    Q_OBJECT
public:
    explicit word(QWidget *parent = nullptr);
    ~word();
    int getnumber()
    {
        return number;
    }
    void setnumber(int num)
    {
        number=num;
    }
    QString getname()
    {
        return name;
    }
    void setname(QString n)
    {
        name=n;
    }
    QString getword(int number)
    {
        return onceword[number];
    }
    void setword(QString w,int number)
    {
        onceword[number]=w;
    }
    QString getwordlist(int number)
    {
        return wordlist[number];
    }
    void setwordlist(QString w,int number)
    {
        wordlist[number]=w;
    }
private:
    Ui::word *ui;
    int number;
    QString name;
    QVector<QString> wordlist;
    QVector<QString> onceword;
signals:
    void display(int number);
private slots:
    void on_startbutton_clicked();
    void on_knowpushButton_clicked();
    void on_unknownbutton_clicked();
    void on_skipbutton_clicked();
    void on_returnbutton_clicked();
};

#endif // WORD_H
