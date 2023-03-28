#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QDir>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
   auto path= QFileDialog::getExistingDirectory(this,"请选择音乐目录","D://arrow");
   QDir dir(path);
    auto musicList = dir.entryList(QStringList()<<"*.mp3"<<"*.wav");
    qInfo()<<musicList;
    ui->listWidget->addItems(musicList);
}

