/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QListWidget *listWidget;
    QSlider *playCourseSlider;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *curLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *totalLabel;
    QFrame *frame_volume;
    QHBoxLayout *horizontalLayout_5;
    QSlider *Slider_volume;
    QPushButton *pushButton_6;
    QPushButton *pushButton_Theme;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1024, 580);
        Widget->setStyleSheet(QString::fromUtf8("*{\n"
" bord er:none\n"
"  \n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	\n"
"	background-color: rgb(255, 239, 233);\n"
"}\n"
"\n"
""));
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 510, 351, 64));
        widget->setMinimumSize(QSize(0, 64));
        widget->setMaximumSize(QSize(16777215, 64));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(32, 32));
        pushButton->setMaximumSize(QSize(32, 32));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/folder.png);"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(32, 32));
        pushButton_2->setMaximumSize(QSize(32, 32));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/rewind.png);"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(32, 32));
        pushButton_3->setMaximumSize(QSize(32, 32));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/play.png);"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(32, 32));
        pushButton_4->setMaximumSize(QSize(32, 32));
        pushButton_4->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/forward.png);"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(32, 32));
        pushButton_5->setMaximumSize(QSize(32, 32));
        pushButton_5->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/picture/volume-up.png);"));
        pushButton_5->setCheckable(true);

        horizontalLayout->addWidget(pushButton_5);

        listWidget = new QListWidget(Widget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(630, 10, 331, 441));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0.5);"));
        playCourseSlider = new QSlider(Widget);
        playCourseSlider->setObjectName("playCourseSlider");
        playCourseSlider->setGeometry(QRect(20, 470, 331, 18));
        playCourseSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 0px solid #bbb;\n"
"}\n"
"\n"
"/*1.\346\273\221\345\212\250\350\277\207\347\232\204\346\247\275\350\256\276\350\256\241\345\217\202\346\225\260*/\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(16, 181, 140, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-radius: 2px;\n"
"margin-top:8px;\n"
"margin-bottom:8px;\n"
"}\n"
"\n"
"/*2.\346\234\252\346\273\221\345\212\250\350\277\207\347\232\204\346\247\275\350\256\276\350\256\241\345\217\202\346\225\260*/\n"
"QSlider::add-page:horizontal {\n"
"background: rgb(255,255, 255);\n"
"border: 0px solid #777;\n"
"border-radius: 2px;\n"
"margin-top:9px;\n"
"margin-bottom:9px;\n"
"}\n"
" \n"
"/*3.\345\271\263\346\227\266\346\273\221\345\212\250\347\232\204\346\273\221\345\235\227\350\256\276\350\256\241\345\217\202\346\225\260*/\n"
"QSlider::handle:horizontal {\n"
"/*\346\273\221\345\235\227\351\242\234\350\211\262*/\n"
"background:qlineargradient(spread:pad, x1:0, y"
                        "1:0, x2:1, y2:1, stop:0 rgba(0, 191, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"/*\346\273\221\345\235\227\347\232\204\345\256\275\345\272\246*/\n"
"width: 5px;\n"
"border: 1px solid rgb(193,204,208);\n"
"border-radius: 2px; \n"
"\n"
"margin-top:4px;\n"
"\n"
"margin-bottom:4px;\n"
"}\n"
"\n"
"/*4.\346\211\213\345\212\250\346\213\211\345\212\250\346\227\266\346\230\276\347\244\272\347\232\204\346\273\221\345\235\227\350\256\276\350\256\241\345\217\202\346\225\260*/\n"
"QSlider::handle:horizontal:hover {\n"
"\n"
"background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 191, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"width: 10px;\n"
"border: 1px solid rgb(193,204,208);\n"
"border-radius: 5px; \n"
"margin-top:2px;\n"
"margin-bottom:2px;\n"
"}"));
        playCourseSlider->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 440, 361, 41));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        curLabel = new QLabel(layoutWidget);
        curLabel->setObjectName("curLabel");

        horizontalLayout_2->addWidget(curLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        totalLabel = new QLabel(layoutWidget);
        totalLabel->setObjectName("totalLabel");

        horizontalLayout_4->addWidget(totalLabel);

        frame_volume = new QFrame(Widget);
        frame_volume->setObjectName("frame_volume");
        frame_volume->setGeometry(QRect(290, 430, 31, 91));
        frame_volume->setFrameShape(QFrame::NoFrame);
        frame_volume->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_volume);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        Slider_volume = new QSlider(frame_volume);
        Slider_volume->setObjectName("Slider_volume");
        Slider_volume->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {\n"
"border: 0px solid #bbb;\n"
"\n"
"}\n"
"\n"
"QSlider::sub-page:vertical {\n"
"background:  rgb(255, 255, 255);\n"
"\n"
"border-radius: 0px;/*\346\225\264\344\275\223\345\234\206\350\247\222*/\n"
"border-top-left-radius:10px;/*\345\267\246\344\270\212\345\234\206\350\247\222*/\n"
"border-bottom-left-radius:10px;/*\345\267\246\344\270\213\345\234\206\350\247\222*/\n"
"margin-top:0px;/*\344\270\212\350\267\235\347\246\273*/\n"
"margin-bottom:0px;/*\344\270\213\350\267\235\347\246\273*/\n"
"}\n"
"\n"
"QSlider::add-page:vertical {\n"
"background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(16, 181, 140, 255), stop:1 rgba(255, 255, 255, 255));/*\350\203\214\346\231\257\350\211\262*/\n"
"border-radius: 0px;/*\346\225\264\344\275\223\345\234\206\350\247\222*/\n"
"border-top-right-radius:10px;/*\345\217\263\344\270\212\345\234\206\350\247\222*/\n"
"border-bottom-right-radius:10px;/*\345\217\263\344\270\213\345\234\206\350\247\222*/\n"
"margin-top:0px;/*\344\270\212\350\267"
                        "\235\347\246\273*/\n"
"margin-bottom:0px;/*\344\270\213\350\267\235\347\246\273*/\n"
"}\n"
"/*\346\213\226\346\213\275\351\224\256\346\240\267\345\274\217*/\n"
"QSlider::handle:vertical {\n"
"background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 191, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border: 0px solid rgb(255,153,102);\n"
"width: 14px;\n"
"height:10px;\n"
"border-radius: 7px;\n"
"margin-top:0px;\n"
"margin-bottom:0px;\n"
"}\n"
"\n"
"QSlider::sub-page:vertical:disabled {\n"
" \n"
"}\n"
"\n"
"QSlider::add-page:vertical:disabled {\n"
" \n"
"}\n"
"QSlider::handle:vertical:disabled {\n"
" \n"
"}"));
        Slider_volume->setOrientation(Qt::Vertical);

        horizontalLayout_5->addWidget(Slider_volume);

        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(340, 490, 32, 32));
        pushButton_6->setMinimumSize(QSize(32, 32));
        pushButton_6->setMaximumSize(QSize(32, 32));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);"));
        pushButton_6->setIconSize(QSize(25, 25));
        pushButton_6->setCheckable(true);
        pushButton_Theme = new QPushButton(Widget);
        pushButton_Theme->setObjectName("pushButton_Theme");
        pushButton_Theme->setGeometry(QRect(390, 530, 92, 29));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "MusicPlayer", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        curLabel->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
        totalLabel->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
        pushButton_6->setText(QString());
        pushButton_Theme->setText(QCoreApplication::translate("Widget", "\346\233\264\346\224\271\344\270\273\351\242\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
