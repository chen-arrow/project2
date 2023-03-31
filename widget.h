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

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_toggled(bool checked);

    void on_Slider_volume_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QList<QUrl> playList;  //播放列表
    QAudioOutput * audioOutput;  //output对象
    QMediaPlayer * mediaPlayer;  //媒体播放对象
    int curPlayIndex = 0;

    int ifplay = 0; // 暂停播放按钮

};
#endif // WIDGET_H
