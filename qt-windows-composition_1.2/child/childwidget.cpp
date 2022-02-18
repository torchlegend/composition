#include "childwidget.h"
#include "ui_childwidget.h"

#include <QDebug>
#include <QSettings>


ChildWidget::ChildWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChildWidget)
{
    ui->setupUi(this);
    QSettings* settings = new QSettings("C:/Users/13060/Desktop/ID.ini",QSettings::IniFormat);
    //settings->beginGroup("child");
    settings->setValue("child1winID",this->winId());
    //settings->endGroup();
    //this->winId()
    settings->sync();
    qDebug() << "ChildWidget winId:" << this->winId();
    //this->setWindowFlags(Qt::FramelessWindowHint);

    long a = this->winId();//句柄
    QString s = QString::number(a, 10);
    ui->pushButton_3->setText(s);
}

ChildWidget::~ChildWidget()
{
    delete ui;
}

void ChildWidget::on_pushButton_clicked()
{
    ui->pushButton_4->setText("当前状态：状态一");
}

void ChildWidget::on_pushButton_2_clicked()
{
    ui->pushButton_4->setText("当前状态：状态二");
}
