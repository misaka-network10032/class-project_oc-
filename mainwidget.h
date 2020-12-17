#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStackedLayout>
#include "menu.h"
#include "word.h"
#include "use.h"
#include "oh.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    Menu *menuwidget;
    word *wordwidget;
    use  *usewidget;
    OH   *ohwidget;
    QStackedLayout *stacklayout;
};

#endif // MAINWIDGET_H
