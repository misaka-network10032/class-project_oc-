#ifndef USE_H
#define USE_H

#include <QWidget>

namespace Ui {
class use;
}

class use : public QWidget
{
    Q_OBJECT

public:
    explicit use(QWidget *parent = nullptr);
    ~use();

private:
    Ui::use *ui;
signals:
    void display(int number);
private slots:
    void on_backbutton_clicked();
};

#endif // USE_H
