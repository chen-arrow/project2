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

    //默认音量值
    audioOutput->setVolume(0.5);
    ui->Slider_volume->setValue(50);

    //默认列表循环播放
    ui->pushButton_6->setIcon(QIcon(":/picture/playlist repeat.png"));
    connect(mediaPlayer,&QMediaPlayer::mediaStatusChanged,[=](QMediaPlayer::MediaStatus status){
        if(status==6)
        {
            curPlayIndex=(curPlayIndex+1)%playList.size();
            ui->listWidget->setCurrentRow(curPlayIndex);
            mediaPlayer->setSource(playList[curPlayIndex]);
            mediaPlayer->play();
        }
    });

    m_pTimer=new QTimer();
    m_pTimer->setInterval(25);
        connect(m_pTimer,&QTimer::timeout,this,&Widget::upDateRote);

    s_pTimer=new QTimer(this);
    s_pTimer->setInterval(15);
    connect(s_pTimer,&QTimer::timeout,this,&Widget::upDateStylusIn);

    //按钮移动，还原
    connect(ui->pushButton,&QPushButton::pressed,this,&Widget::btnmove);
    connect(ui->pushButton,&QPushButton::released,this,&Widget::btnmoveback);
    connect(ui->pushButton_2,&QPushButton::pressed,this,&Widget::btnmove);
    connect(ui->pushButton_2,&QPushButton::released,this,&Widget::btnmoveback);
    connect(ui->pushButton_3,&QPushButton::pressed,this,&Widget::btnmove);
    connect(ui->pushButton_3,&QPushButton::released,this,&Widget::btnmoveback);
    connect(ui->pushButton_4,&QPushButton::pressed,this,&Widget::btnmove);
    connect(ui->pushButton_4,&QPushButton::released,this,&Widget::btnmoveback);
    connect(ui->pushButton_5,&QPushButton::pressed,this,&Widget::btnmove);
    connect(ui->pushButton_5,&QPushButton::released,this,&Widget::btnmoveback);
    connect(ui->pushButton_6,&QPushButton::pressed,this,&Widget::btnmove);
    connect(ui->pushButton_6,&QPushButton::released,this,&Widget::btnmoveback);


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
    if(playList.empty())
    {
        return;
    }
    curPlayIndex=(curPlayIndex-1)%playList.size();
    ui->listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setSource(playList[curPlayIndex]);
    mediaPlayer->play();
}

//下一首
void Widget::on_pushButton_4_clicked()
{
    if(playList.empty())
    {
        return;
    }
    curPlayIndex=(curPlayIndex+1)%playList.size();
    ui->listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setSource(playList[curPlayIndex]);
    mediaPlayer->play();
}

//播放
void Widget::on_pushButton_3_clicked()
{
    if(playList.empty())
    {
        return;
    }

    switch(mediaPlayer->playbackState())
    {
        case QMediaPlayer::PlaybackState::StoppedState: //停止状态
        {
            //如果没有播放，那就播放当前选中的音乐
            //获取选中的行号
            curPlayIndex = ui->listWidget->currentRow();
            //播放对应下标的音乐
            mediaPlayer->setSource(playList[curPlayIndex]);
            mediaPlayer->play();
            ui->pushButton_3->setStyleSheet("border-image: url(:/picture/playing.png);");
            break;
        }
        case QMediaPlayer::PlaybackState::PlayingState: //播放状态
            //如果现在正在播放就暂停音乐
            mediaPlayer->pause();
            m_pTimer->stop();
            upDateStylusOut();
            ui->pushButton_3->setStyleSheet("border-image: url(:/picture/play.png);");
            break;
        case QMediaPlayer::PlaybackState::PausedState: //暂停状态
             //如果现在是暂停就继续播放
            m_pTimer->start(100);
            upDateStylusIn();
            ui->pushButton_3->setStyleSheet("border-image: url(:/picture/playing.png);");
            mediaPlayer->play();
            break;
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

//文件按钮
void Widget::on_pushButton_clicked()
{
    auto path = QFileDialog::getExistingDirectory(this,"请选择音乐所在的目录", "C:\\Users\\dc\\Desktop");

    QDir dir(path);
    auto musicList = dir.entryList(QStringList()<< "*.wav" << "*.mp3");

    ui->listWidget->addItems(musicList);
    ui->listWidget->setCurrentRow(0);

    for(auto file : musicList)
            playList.append(QUrl::fromLocalFile(path + "/" +file));
}

//双击播放列表，播放音乐
void Widget::on_listWidget_doubleClicked(const QModelIndex &index)
{
    curPlayIndex = index.row();
    //播放对应下标的音乐
    mediaPlayer->setSource(playList[curPlayIndex]);
    mediaPlayer->play();
}

//列表循环播放和单曲循环播放
void Widget::on_pushButton_6_clicked(bool checked)
{
    if(checked)
    {
        ui->pushButton_6->setIcon(QIcon(":/picture/Repeat once1.png"));
        mediaPlayer->setLoops(-1);
    }
    else
    {
        ui->pushButton_6->setIcon(QIcon(":/picture/playlist repeat.png"));
        mediaPlayer->setLoops(1);
    }
}

//按钮移动
void Widget::btnmove()
{
    QPushButton *btn = qobject_cast<QPushButton*>(QObject::sender());
    btn->move(btn->geometry().x() + 1, btn->geometry().y() + 1);
}
//按钮移动还原
void Widget::btnmoveback()
{
    QPushButton *btn = qobject_cast<QPushButton*>(QObject::sender());
    btn->move(btn->geometry().x() - 1, btn->geometry().y() - 1);
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


    painter.drawPixmap(rect(),QPixmap(":/picture/background1.png"),QRect());

    QPixmap pixMap3(":/picture/cdCover");
    painter.save();
    painter.translate(85/1.5,110/1.5);
    painter.translate(195/1.5,195/1.5);
    painter.rotate(2*cd_Rote);
    painter.translate(-75/1.5,-75/1.5);
    painter.drawPixmap(0,0,150/1.5,150/1.5,pixMap3);
    painter.restore();

    QPixmap pixMap1(":/picture/record");
    painter.save();
    painter.translate(85/1.5,110/1.5);//move to rect left_top
    painter.translate(195/1.5,195/1.5);
    painter.rotate(2*cd_Rote);
    painter.translate(-195/1.5,-195/1.5);
    painter.drawPixmap(0,0,390/1.5,390/1.5,pixMap1);
    painter.restore();

    QPixmap pixMap2(":/picture/stylus");

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

