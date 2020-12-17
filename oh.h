#ifndef OH_H
#define OH_H

#include <QWidget>
#include <QLabel>
#include <QMovie>

namespace Ui {
class OH;
}

class OH : public QWidget
{
    Q_OBJECT

public:
    explicit OH(QWidget *parent = nullptr);
    ~OH();

private:
    Ui::OH *ui;
signals:
    void display(int number);
private slots:
    void on_changebutton_clicked();
    void on_exitbutton_clicked();
};

#endif // OH_H
