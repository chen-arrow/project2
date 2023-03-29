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
        connect(m_pTimer,&QTimer::timeout,this,&Widget::upDateRote);
}

void Widget::on_pushButton_3_clicked()
{
    if(ifplay==0)//判断是否为播放状态
    {
        mediaPlayer->play();//播放
        m_pTimer->start(100);
        ifplay=1;
    }
    else
    {
        mediaPlayer->pause();//暂停
        m_pTimer->stop();
        ifplay=0;
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
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPainterPath painterPath;
    painterPath.addEllipse(80,80,220,220);
    painter.setClipPath(painterPath);
    painter.drawPath(painterPath);

    QPixmap pixMap("C:/Users/USER/Downloads/second-project-warehouse-master/project/MusicPlayer/images/Turntable/record");

    QTransform transform;
    transform.translate(190,190);
    painter.setTransform(transform);


    painter.save();
    painter.rotate(2*m_Rote);
    painter.drawPixmap(-110,-110,220,220,pixMap);
    painter.restore();


}

void Widget::upDateRote()
{
    m_Rote=m_Rote+1;
    if(m_Rote==180)
    {
        m_Rote=0;
    }
    update();
}

void Widget::onStartorStopRote()
{
    m_bStart=!m_bStart;
    if(m_bStart)
    {
        m_pTimer->start(100);
        m_pbtn->setText(tr("Stop"));
    }
    else
    {
        m_pTimer->stop();
        m_pbtn->setText(tr("Start"));
    }
}
