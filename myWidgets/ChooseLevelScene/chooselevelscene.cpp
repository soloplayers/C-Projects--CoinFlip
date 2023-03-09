//
// Created by 93705 on 2022/3/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ChooseLevelScene.h" resolved

#include "chooselevelscene.h"
#include "ui_ChooseLevelScene.h"
#include "myWidgets/myPushButton/mypushbutton.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QSound>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::ChooseLevelScene) {
    ui->setupUi(this);

    // 配置基础信息
    setWindowIcon(QPixmap(":/res/Coin0001.png"));
    setWindowTitle("翻金币");
    setFixedSize(400, 600);

    // 创建菜单栏
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *startMenu = bar->addMenu("开始");
    QAction *exitAction = startMenu->addAction("退出");

    // 点击退出，实现退出游戏
    connect(exitAction, &QAction::triggered, [=]() {
        this->close();
    });

    // 选择关卡音效
    QSound *chooseSound = new QSound(":/res/TapButtonSound.wav", this);
    QSound *backSound = new QSound(":/res/BackButtonSound.wav", this);

    // 返回按钮
    myPushButton *backBtn = new myPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    // 放在最右下角
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    connect(backBtn, &myPushButton::clicked, [=]() {

        // 播放按钮音效
        backSound->play();

        // 告诉主场景，我要返回了。主场景监听ChooseLevelScene的返回按钮
        emit chooseSceneBack();
    });


    // 创建选择关卡的按钮
    for (int i = 0; i < 20; ++i) {
        myPushButton *menuBtn = new myPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(60 + i % 4 * 70, 130 + i / 4 * 70);

        // 监听每个按钮的事件
        connect(menuBtn, &myPushButton::clicked, [=]() {

            // 播放选择关卡的音效
            chooseSound->play();

            this->hide();
            play = new playScene(i + 1);
            // 进入到游戏场景,并设置游戏场景的初始位置
            play->setGeometry(this->geometry());

            play->show();
            connect(play, &playScene::chooseSceneBack, [=]() {
                this->setGeometry(play->geometry());
                this->show();
                delete play;
                play = nullptr;
            });
        });

        QLabel *label = new QLabel;
        label->setParent(menuBtn);  // 将label的父类设置为menuBtn，这样相对好定位
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i + 1));

        // 设置label上的文字对齐方式setAlignment,Qt::AlignCenter等于Qt::AlignHCenter | Qt::AlignVCenter
        label->setAlignment(Qt::AlignCenter);
    }
}

ChooseLevelScene::~ChooseLevelScene() {
    delete ui;
}

void ChooseLevelScene::paintEvent(QPaintEvent *e) {

    // 实例化一个画家对象
    QPainter painter(this);
    QPixmap pix;

    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);


    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width()) / 2, 30, pix.width(), pix.height(), pix);
}

