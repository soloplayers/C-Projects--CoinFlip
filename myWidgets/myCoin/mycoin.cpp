//
// Created by 93705 on 2022/4/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_myCoin.h" resolved

#include "mycoin.h"
#include "ui_myCoin.h"
#include <QDebug>
#include <QMessageBox>

myCoin::~myCoin() {
    delete ui;
}

myCoin::myCoin(QString btnImg) : ui(new Ui::myCoin) {
    ui->setupUi(this);
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if (!ret) {
        qDebug("图片加载失败");
        return;
    }
    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:none}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));


    // 监听金币翻转的事件，不用再changFlag里面监听，不然每次点击都会connect，效率低，耗内存

    // 监听正面翻到反面，并且实现翻转金币
    connect(timer1, &QTimer::timeout, [=]() {
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:none}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        // 判断，如果翻完了，将Min重置为1;
        if (this->min > this->max) {
            this->min = 1;
            // 停止定时器
            isAnimation = false;//停止做动画
            timer1->stop();
        }
    });

    // 监听反面翻到正面，并且实现翻转金币
    connect(timer2, &QTimer::timeout, [=]() {
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:none}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        // 判断，如果翻完了，将Min重置为1;
        if (this->min > this->max) {
            this->max = 8;
            // 停止定时器
            isAnimation = false;//停止做动画
            timer2->stop();

        }
    });
}

void myCoin::changFlag() {
    // 如果是正面
    if (this->flag) {
        // 开始正面翻反面的定时器
        timer1->start(30);
        isAnimation = true;//开始做动画
        this->flag = false;

    } else {
        timer2->start(30);
        isAnimation = true;//开始做动画
        this->flag = true;
    }
}

void myCoin::mousePressEvent(QMouseEvent *e) {
    if (this->isAnimation || this->isGoldenCoin) {
        return;
    } else {
        QPushButton::mousePressEvent(e);
    }
}


