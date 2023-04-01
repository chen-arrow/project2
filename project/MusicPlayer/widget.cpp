#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>
#include <QPainterPath>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //加载模块multimedia
    //new一个output对象
    audioOutput = new QAudioOutput(this);
    //new一个媒体播放对象
    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setAudioOutput(audioOutput);

    //获取总媒体时长
    connect(mediaPlayer,&QMediaPlayer::durationChanged, this, [=](qint64 duration)
    {
        ui->totalLabel->setText(QString("%1:%2").arg(duration/1000/60,2,10,QChar('0'))
                                .arg(duration/1000%60,2,10,QChar('0')));
        ui->playCourseSlider->setRange(0, duration);
    });

    //获取当前时长
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, [=](qint64 pos)
    {
         ui->curLabel->setText(QString("%1:%2").arg(pos/1000/60,2,10,QChar('0'))
                                .arg(pos/1000%60,2,10,QChar('0')));
         ui->playCourseSlider->setValue(pos);
    });

    //滑动音乐进度条，使音乐进度改变
    connect(ui->playCourseSlider, &QSlider::sliderMoved, mediaPlayer, &QMediaPlayer::setPosition);

    m_pTimer=new QTimer();
    m_pTimer->setInterval(25);
        connect(m_pTimer,&QTimer::timeout,this,&Widget::upDateRote);

    s_pTimer=new QTimer(this);
    s_pTimer->setInterval(15);
    connect(s_pTimer,&QTimer::timeout,this,&Widget::upDateStylusIn);
}

void Widget::on_pushButton_3_clicked()
{
    if(ifplay==0)//判断是否为播放状态
    {
        mediaPlayer->play();//播放
        m_pTimer->start(100);

        upDateStylusIn();
//        s_pTimer->start(10);
        ifplay=1;
    }
    else
    {
        mediaPlayer->pause();//暂停
        m_pTimer->stop();
        upDateStylusOut();
        ifplay=0;
    }
}

void Widget::on_pushButton_Theme_clicked()
{

    if(iftheme==0){
        LoadQss::loadQss(":/qss/style.qss");
        iftheme++;
    }
    else{
        LoadQss::loadQss(":/qss/origin.qss");
        iftheme--;
    }
}

Widget::~Widget()
{
    delete ui;
    delete audioOutput;
    delete mediaPlayer;
}
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
//    painter.setPen(QPen(QColor(0, 0, 0, 150)));
//    QPainterPath painterPath;
//    painterPath.addRect(40,40,300,300);
////    painterPath.addEllipse(80,80,220,220);
//    painter.setClipPath(painterPath);

//    painter.drawPath(painterPath);


    QPixmap pixMap3(":/images/cdCover");
    painter.save();
    painter.translate(85/1.5,110/1.5);
    painter.translate(195/1.5,195/1.5);
    painter.rotate(2*cd_Rote);
    painter.translate(-75/1.5,-75/1.5);
    painter.drawPixmap(0,0,150/1.5,150/1.5,pixMap3);
    painter.restore();

    QPixmap pixMap1(":/images/record");
    painter.save();
    painter.translate(85/1.5,110/1.5);//move to rect left_top
    painter.translate(195/1.5,195/1.5);
    painter.rotate(2*cd_Rote);
    painter.translate(-195/1.5,-195/1.5);
    painter.drawPixmap(0,0,390/1.5,390/1.5,pixMap1);
    painter.restore();

    QPixmap pixMap2(":/images/stylus");

    painter.save();
    painter.translate(30/1.5,-200/1.5);
    painter.translate(250/1.5,250/1.5);
    painter.rotate(s_Rote);
    painter.translate(-250/1.5,-250/1.5);
    painter.drawPixmap(0,0,500/1.5,500/1.5,pixMap2);
    painter.restore();

}

void Widget::upDateRote()
{
    cd_Rote=cd_Rote+1;
    if(cd_Rote==180)
    {
        cd_Rote=0;
    }
    update();
}

void Widget::onStartorStopRote()
{
    m_bStart=!m_bStart;
    if(m_bStart)
    {
        m_pTimer->start(100);
        s_pTimer->start(300);
    }
    else
    {
        m_pTimer->stop();
        s_pTimer->stop();
    }
}
void Widget::upDateStylusIn()
{
    s_pTimer->start(10);
    s_Rote += 1;
    if(s_Rote > 30)
    {
        s_pTimer->stop();
    }
    update();
}
void Widget::upDateStylusOut()
{
    s_Rote =0;

    update();
}
