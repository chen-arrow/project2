#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUrl>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_3_clicked();

    void upDateRote();
    void onStartorStopRote();

private:
    Ui::Widget *ui;
    QList<QUrl> playList;  //播放列表
    QAudioOutput * audioOutput;  //output对象
    QMediaPlayer * mediaPlayer;  //媒体播放对象
    int curPlayIndex = 0;
    int ifplay=0;

    QTimer *m_pTimer;

    int m_Rote=0;

    QPushButton *m_pbtn=nullptr;
    bool m_bStart=false;
};
#endif // WIDGET_H
