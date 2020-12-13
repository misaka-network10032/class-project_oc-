#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include <QDebug>
#include <QFile>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private:
    Ui::Menu *ui;
    QButtonGroup *menubuttongroup;
signals:
    void display(int number);
private slots:
    void on_newbutton_clicked();
    void on_endbutton_clicked();
    void on_startbutton_clicked();
};

#endif // MENU_H
