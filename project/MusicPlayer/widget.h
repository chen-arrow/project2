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
<<<<<<< HEAD

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

=======
    void on_pushButton_3_clicked();
>>>>>>> remotes/origin/zy
private:
    Ui::Widget *ui;
    QList<QUrl> playList;  //播放列表
    QAudioOutput * audioOutput;  //output对象
    QMediaPlayer * mediaPlayer;  //媒体播放对象
    int curPlayIndex = 0;
<<<<<<< HEAD
=======
    int ifplay=0;
>>>>>>> remotes/origin/zy
};
#endif // WIDGET_H
