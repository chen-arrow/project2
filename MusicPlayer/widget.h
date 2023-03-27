#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUrl>
#include <QMediaPlayer>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_3_clicked();
private:
    Ui::Widget *ui;
    QList<QUrl> playList;  //播放列表
    QAudioOutput * audioOutput;  //output对象
    QMediaPlayer * mediaPlayer;  //媒体播放对象
    int curPlayIndex = 0;
};
#endif // WIDGET_H
