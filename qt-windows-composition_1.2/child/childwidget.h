#ifndef CHILDWIDGET_H
#define CHILDWIDGET_H

#include <QWidget>

namespace Ui {
class ChildWidget;
}

class ChildWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChildWidget(QWidget *parent = 0);
    ~ChildWidget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ChildWidget *ui;
};

#endif // CHILDWIDGET_H
