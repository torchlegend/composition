#include "parentwidget.h"
#include "ui_parentwidget.h"

#include <QWindow>
#include<windows.h>
#include<QDebug>
#include <QFileInfo>

ParentWidget::ParentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParentWidget),
    childWidget(NULL)
{
    ui->setupUi(this);




    //connect(ui->integrateWidgetBtn, SIGNAL(clicked(bool)), this, SLOT(integrate()));
}

ParentWidget::~ParentWidget()
{
    delete ui;
}

void ParentWidget::integrate()
{
    //    int childWidgetWinId = 592804; //get from debug output

    //    QWindow *childWindow = QWindow::fromWinId( childWidgetWinId );

    //    childWidget = QWidget::createWindowContainer(childWindow, this, Qt::Widget );

    //    ui->childWidgetLayout->addWidget(childWidget);


}


//void ParentWidget::on_integrateWidgetBtn_clicked()
//{
//    integrate();
//}


//清空布局
void ParentWidget::clearLayout(QLayout* layout)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (QWidget* widget = item->widget())
            widget->deleteLater();

        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout);

        if (QSpacerItem* spaerItem = item->spacerItem())
            layout->removeItem(spaerItem);

        delete item;
    }
}

void ParentWidget::on_integrateWidgetBtn_clicked()
{
    clearLayout(ui->childWidgetLayout);
    int childWidgetWinId;
    QProcess* caller = new QProcess(this);//创建对象

/*判断是否有child进程运行*/
    QProcess process;
    process.start("tasklist");
    process.waitForFinished();
    QByteArray result = process.readAllStandardOutput();
    QString str = result;
    if(str.contains("child.exe")){
        qDebug() << "hello world";
        caller->start("child.exe");
        Sleep(1000); //这个只能更大，不能更小，不然无法获得子串口句柄，应该和机器性能有关
        QSettings* settings = new QSettings("C:/Users/13060/Desktop/ID.ini",QSettings::IniFormat);
        childWidgetWinId = settings->value("child1winID").toInt();; //get from debug output
        qDebug() << childWidgetWinId << endl;
    }
    else{
        caller->start("C:/Users/13060/Desktop/qt-windows-composition-example-master/qt-windows-composition-example-master/Debug/child/debug/child.exe");//程序路径
        Sleep(1000); //这个只能更大，不能更小，不然无法获得子串口句柄，应该和机器性能有关
        //QString cfgFile = "C:/Users/13060/Desktop/ID.ini";
        QSettings* settings = new QSettings("C:/Users/13060/Desktop/ID.ini",QSettings::IniFormat);
        childWidgetWinId = settings->value("child1winID").toInt();; //get from debug output
        qDebug() << childWidgetWinId << endl;
    }




    //QFileInfo fi("C:/Users/13060/Desktop/ID.ini");
    //    if(fi.exists()){
    //        Sleep(1000); //这个只能更大，不能更小，不然无法获得子串口句柄，应该和机器性能有关
    //        QSettings* settings = new QSettings("C:/Users/13060/Desktop/ID.ini",QSettings::IniFormat);
    //        childWidgetWinId = settings->value("child1winID").toInt();; //get from debug output
    //        qDebug() << childWidgetWinId << endl;
    //    }
    //    else{
    //        caller->start("C:/Users/13060/Desktop/qt-windows-composition-example-master/qt-windows-composition-example-master/Debug/child/debug/child.exe");//程序路径
    //        Sleep(1000); //这个只能更大，不能更小，不然无法获得子串口句柄，应该和机器性能有关
    //        //QString cfgFile = "C:/Users/13060/Desktop/ID.ini";
    //        QSettings* settings = new QSettings("C:/Users/13060/Desktop/ID.ini",QSettings::IniFormat);
    //        childWidgetWinId = settings->value("child1winID").toInt();; //get from debug output
    //        qDebug() << childWidgetWinId << endl;
    //    }


//    caller->start("C:/Users/13060/Desktop/qt-windows-composition-example-master/qt-windows-composition-example-master/Debug/child/debug/child.exe");//程序路径
//    Sleep(1000); //这个只能更大，不能更小，不然无法获得子串口句柄，应该和机器性能有关
//    QSettings* settings = new QSettings("C:/Users/13060/Desktop/ID.ini",QSettings::IniFormat);
//    childWidgetWinId = settings->value("child1winID").toInt();; //get from debug output
//    qDebug() << childWidgetWinId << endl;

    QWindow *childWindow = QWindow::fromWinId(childWidgetWinId);
    childWidget = QWidget::createWindowContainer(childWindow, this, Qt::Widget );
    //childWidget->setMinimumSize(800,600);
    ui->childWidgetLayout->addWidget(childWidget);
    childWidget->setMinimumSize(476,460);
}

void ParentWidget::on_pushButton_clicked()
{
    clearLayout(ui->childWidgetLayout);

    QPushButton *a = new QPushButton();
    a->setText("设备二，hello world");
    ui->childWidgetLayout->addWidget(a);
}
