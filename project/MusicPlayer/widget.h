#ifndef WIDGET_H
#define WIDGET_H
#ifndef LOADQSS_H
#define LOADQSS_H

#include <QFile>
#include <QApplication>
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

class LoadQss
{
public:
    static void loadQss(const QString &path)
    {
        QFile qss(path);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};

#endif // LOADQSS_H

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *event);

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_toggled(bool checked);

    void on_Slider_volume_valueChanged(int value);

    void on_pushButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_6_clicked(bool checked);

    void btnmove();

    void btnmoveback();

    void upDateRote();

    void onStartorStopRote();

    void upDateStylusIn();

    void upDateStylusOut();

    void on_pushButton_Theme_clicked();
private:
    Ui::Widget *ui;
    QList<QUrl> playList;  //播放列表
    QAudioOutput * audioOutput;  //output对象
    QMediaPlayer * mediaPlayer;  //媒体播放对象
    int curPlayIndex = 0;

    int ifplay = 0; // 暂停播放按钮
    int iftheme=0;
    QTimer *m_pTimer;
    QTimer *s_pTimer;
    int cd_Rote=0;
    int s_Rote=0;

    QPushButton *m_pbtn=nullptr;
    bool m_bStart=false;

};
#endif // WIDGET_H

