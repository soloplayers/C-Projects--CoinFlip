#include "Mainwindow.h"
#include "./ui_mainscene.h"
#include "myWidgets/myPushButton/mypushbutton.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QSound>
#include <QPalette>

MainScene::MainScene(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainScene) {
    ui->setupUi(this);

    // 设置主场景
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("翻金币");
    setFixedSize(400, 600);

    // 设置样式表
    ui->menubar->setStyleSheet("background-color:rgb(218, 227, 240)");

    // 退出按钮实现
    connect(ui->action, &QAction::triggered, [=]() {
        this->close();
    });

    // 准备开始按钮的音效
    QSound *startSound = new QSound(":/res/TapButtonSound.wav", this);
//    startSound->setLoops(-1); 设置音乐循环次数。-1表示无限循环
//    startSound->play();

    // 开始按钮
    myPushButton *startBtn = new myPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    // 将图片放在中间下方（百分比自动适配）
    startBtn->move(this->width() / 2 - startBtn->width() / 2, this->height() * 3 / 4);

    // 实例化一个关卡界面，不要指明父对象，不然会报错
    chooseScene = new ChooseLevelScene;

    // 监听该按钮的按下事件以设置样式
    connect(startBtn, &myPushButton::clicked, [=]() {
        //播放开始音效资源
        startSound->play();

        // 做一个点击按钮后的特效 -->  做弹起特效
        startBtn->zoom_down();  // 使用向下弹跳的函数
        startBtn->zoom_up();    // 使用向上弹跳的函数

        // 延时进入到选择关卡界面(自身隐藏hide，选择界面出现show)
        QTimer::singleShot(500, [=]() {

            // 设置场景的位置（继承上一个场景的位置）
            chooseScene->setGeometry(this->geometry());

            // 自身隐藏
            this->hide();
            // 关卡选择界面出现

            chooseScene->show();
        });

    });


    // 信号和槽的链接，一次连接就行了，不然会浪费内存
    // 在这里监听选择关卡的信号
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, [=]() {
        QTimer::singleShot(500, [=]() {
            this->setGeometry(chooseScene->geometry());
            this->show();
            chooseScene->hide();
        });
    });
}

MainScene::~MainScene() {
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *) {

    // 利用画家类画背景图
    QPainter painter(this);

    QPixmap pixmap;

    // 设置为this(当前屏幕)的宽高-----画背景图
    pixmap.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pixmap);

    // 画背景图标Title图片
    pixmap.load(":/res/Title.png");
    pixmap = pixmap.scaled(pixmap.width() / 2,
                           pixmap.height() / 2);  // scaled()函数进行缩放,参数是缩放的结果，一般配合原来的图片乘上响应的比例。该函数返回改变后的Pixmap
    painter.drawPixmap(10, 30, pixmap);
}

