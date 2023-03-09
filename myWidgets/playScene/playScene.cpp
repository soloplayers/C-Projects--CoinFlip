//
// Created by 93705 on 2022/4/3.
//

// You may need to build the project (run Qt uic code generator) to get "ui_playScene.h" resolved

#include "playScene.h"
#include "ui_playScene.h"
#include <qdebug.h>
#include "qmenu.h"
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include "myWidgets/myPushButton/mypushbutton.h"
#include "myWidgets/myCoin/mycoin.h"
#include <QIcon>
#include <QPropertyAnimation>
#include <QSound>
#include "myWidgets/dataConfig/dataconfig.h"

playScene::playScene(int levelNum) :
        ui(new Ui::playScene) {
    ui->setupUi(this);
    levelIndex = levelNum;

    // 初始化游戏场景
//    设置固定大小
    this->setFixedSize(400, 600);
    setWindowIcon(QPixmap(":/res/Coin0001.png"));
//    设置标题
    this->setWindowTitle(QString("第%1关").arg(this->levelIndex));
    // 创建菜单栏
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *startMenu = bar->addMenu("开始");
    QAction *exitAction = startMenu->addAction("退出");

    // 点击退出，实现退出游戏
    connect(exitAction, &QAction::triggered, [=]() {
        this->close();
    });

    // 添加音效资源
    QSound *flipSound = new QSound(":/res/CoinFlipSound.wav", this);
    QSound *winSound = new QSound(":/res/LevelWinSound.wav", this);
    QSound *backSound = new QSound(":/res/BackButtonSound.wav", this);

    // 返回按钮
    myPushButton *backBtn = new myPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    // 放在最右下角
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    connect(backBtn, &myPushButton::clicked, [=]() {
        // 播放返回按钮音效
        backSound->play();
        emit this->chooseSceneBack();
    });

    // 显示当前的关卡、
    QLabel *levelLabel = new QLabel;
    levelLabel->setParent(this);
    levelLabel->setStyleSheet("border:1px solid red");
    levelLabel->setText(QString("Level:%1").arg(this->levelIndex));
    levelLabel->setGeometry(30, this->height() - 50, 180, 50);
    levelLabel->setFont(QFont(QString("kaiTi"), 24, 1));

    // 写入配置到的地图数据来进行初始化
    dataConfig data;
    // 初始化每个关卡的二维数组
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            this->gameArr[i][j] = data.mData[this->levelIndex][i][j];
        }
    }

    // 胜利图片的显示
    QLabel *winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0, 0, tmpPix.width(), tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move((this->width() - tmpPix.width()) / 2, -tmpPix.height());

    // 显示金币的背景图案
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            QLabel *label = new QLabel;
            QPixmap pix = QPixmap(":/res/BoardNode.png");
            label->setGeometry(0, 0, pix.width(), pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            // 按设计的比例自适应位置，水平要右移1/4,垂直要下移1/3
            label->move(this->width() / 4 + i * pix.width(), this->height() / 3 + j * pix.height());

            // 创建金币
            QString coinPath;
            if (gameArr[i][j] == 1) {
                // 显示金币
                coinPath = QString(":/res/Coin0001.png");
            } else {
                // 显示银币
                coinPath = QString(":/res/Coin0008.png");
            }
            myCoin *coin = new myCoin(coinPath);
            // 设置父结点
            coin->setParent(label);
            // 设置居中
            coin->move((label->width() - coin->width()) / 2, (label->width() - coin->height()) / 2);

            // 给金币属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = gameArr[i][j];   // 1是正面（金币） 0是反面（银币）

            // 将金币放入到金币的二维数组中，以便后期的维护
            coinBtn[i][j] = coin;

            // 点击金币 进行翻转
            connect(coin, &myCoin::clicked, [=]() {

                // 播放翻金币的音效
                flipSound->play();

                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        coinBtn[i][j]->isGoldenCoin = true;
                    }
                }
                coin->changFlag();
                this->gameArr[i][j] = this->gameArr[i][j] ? 0 : 1;

                // 进行翻转周围的金币和更新地图的数据,周围的金币要进行延时翻转
                // 先进性越界判断

                // 进行延时处理
                QTimer::singleShot(400, [=]() {
                    // 右侧
                    if (coin->posX + 1 <= 3) {
                        coinBtn[coin->posX + 1][coin->posY]->changFlag();
                        this->gameArr[coin->posX + 1][coin->posY] = this->gameArr[coin->posX + 1][coin->posY] ? 0 : 1;
                    }

                    // 左侧
                    if (coin->posX - 1 >= 0) {
                        coinBtn[coin->posX - 1][coin->posY]->changFlag();
                        this->gameArr[coin->posX - 1][coin->posY] = this->gameArr[coin->posX - 1][coin->posY] ? 0 : 1;
                    }

                    // 上侧
                    if (coin->posY - 1 >= 0) {
                        coinBtn[coin->posX][coin->posY - 1]->changFlag();
                        this->gameArr[coin->posX][coin->posY - 1] = this->gameArr[coin->posX][coin->posY - 1] ? 0 : 1;
                    }

                    // 下侧
                    if (coin->posY + 1 <= 3) {
                        coinBtn[coin->posX][coin->posY + 1]->changFlag();
                        this->gameArr[coin->posX][coin->posY + 1] = this->gameArr[coin->posX][coin->posY + 1] ? 0 : 1;
                    }
                    for (int i = 0; i < 4; ++i) {
                        for (int j = 0; j < 4; ++j) {
                            coinBtn[i][j]->isGoldenCoin = false;
                        }
                    }
                    // 判断是否胜利
                    this->isWin = true;
                    for (int i = 0; i < 4; ++i) {
                        for (int j = 0; j < 4; ++j) {
                            if (!coinBtn[i][j]->flag) {
                                this->isWin = false;
                                break;
                            }
                        }
                    }
                    if (this->isWin) {

                        // 游戏胜利的音效
                        winSound->play();

                        // 游戏胜利后将所有金币的isWin改为true，并在金币按钮的按下事件中return掉
                        // 相当于用户点击每一个按钮时，都会被return掉，因为每个金币的isWin都是true了
                        for (int i = 0; i < 4; ++i) {
                            for (int j = 0; j < 4; ++j) {
                                coinBtn[i][j]->isGoldenCoin = true;
                            }
                        }
                        // 将胜利的图片砸下来
                        QPropertyAnimation *imgMove = new QPropertyAnimation(winLabel, "geometry");
                        // 设置时间间隔
                        imgMove->setDuration(1000);
                        // 设置开始时间
                        imgMove->setStartValue(
                                QRect(winLabel->x(), winLabel->y(), winLabel->width(), winLabel->height()));

                        // 设置结束位置
                        imgMove->setEndValue(
                                QRect(winLabel->x(), winLabel->y() + 114, winLabel->width(), winLabel->height()));

                        // 设置缓和曲线--跳一下的效果来自这里
                        imgMove->setEasingCurve(QEasingCurve::OutBounce);

                        // 执行动画
                        imgMove->start();

                    }

                });

            });
        }
    }
}

playScene::~playScene() {
    delete ui;
}

void playScene::paintEvent(QPaintEvent *) {
    // 实例化一个画家对象
    QPainter painter(this);
    QPixmap pix;

    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width()) / 2, 30, pix.width(), pix.height(), pix);

}

