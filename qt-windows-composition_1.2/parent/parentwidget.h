#ifndef PARENTWIDGET_H
#define PARENTWIDGET_H

#include <QWidget>
#include <QWindow>
#include <QSettings>
#include <QProcess>

namespace Ui {
class ParentWidget;
}

class ParentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ParentWidget(QWidget *parent = 0);
    ~ParentWidget();
    void clearLayout(QLayout* layout);

private:
    Ui::ParentWidget *ui;
    QWidget *childWidget;

private slots:
    void integrate();

    //void on_integrateWidgetBtn_clicked();

    void on_integrateWidgetBtn_clicked();
    void on_pushButton_clicked();
};

#endif // PARENTWIDGET_H
