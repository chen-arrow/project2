#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>

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

    //音量控件默认隐藏
    ui->frame_volume->setVisible(false);

}

Widget::~Widget()
{
    delete ui;
    delete audioOutput;
    delete mediaPlayer;
}
//上一首
void Widget::on_pushButton_2_clicked()
{
    if(curPlayIndex==0)
    {
        curPlayIndex=playList.size()-1;
    }
    else
    {
        curPlayIndex=(curPlayIndex-1)%playList.size();
    }
    ui->listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setSource(playList[curPlayIndex]);
    mediaPlayer->play();
}

//下一首
void Widget::on_pushButton_4_clicked()
{
    curPlayIndex=(curPlayIndex+1)%playList.size();
    ui->listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setSource(playList[curPlayIndex]);
    mediaPlayer->play();
}

//播放
void Widget::on_pushButton_3_clicked()
{
    if (ifplay == 0) // 判断是否为播放状态
    {
        mediaPlayer->play(); // 播放
        ifplay = 1;
    }
    else
    {
        mediaPlayer->pause(); // 暂停
        ifplay = 0;
    }
}
//音量控件显示和关闭
void Widget::on_pushButton_5_toggled(bool checked)
{
    if(checked)
    {

        ui->frame_volume->setVisible(true);
    }
    else
    {
        ui->frame_volume->setVisible(false);
    }
}

//调节音量大小
void Widget::on_Slider_volume_valueChanged(int value)
{
    audioOutput->volumeChanged((float)value/100);
}

