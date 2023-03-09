//
// Created by 93705 on 2022/3/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_myPushButton.h" resolved

#include "mypushbutton.h"
#include "ui_myPushButton.h"
#include <QDebug>
#include <QPropertyAnimation>


myPushButton::myPushButton(QWidget *parent) :
        QPushButton(parent), ui(new Ui::myPushButton) {
    ui->setupUi(this);
}

myPushButton::~myPushButton() {
    delete ui;
}

myPushButton::myPushButton(QString normalImg, QString pressImg) {
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pixmap;

    // 图片加载失败，将代码返回掉。
    bool ret = pixmap.load(normalImg);
    if (!ret) {
        qDebug() << "图片加载失败" << endl;
        return;
    }

    // 图片加载成功，设置相关属性。
    this->setFixedSize(pixmap.width(), pixmap.height());
    // 设置不规则图片的样式
    this->setStyleSheet("QPushButton{border:0px}");
    // 设置图标
    this->setIcon(pixmap);
    // 设置图标大小   --  必须添加上，不然显示的图片十分小
    this->setIconSize(pixmap.size());
}

void myPushButton::zoom_down() {

    // 创建一个动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    // 设置动画时间间隔
    animation->setDuration(200);

    // 起始位置
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));

    // 结束位置
    animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));

    // 设置弹跳曲线,弹跳类型为OutBounce(使用setEasingCurve搜索Qt文档即可)
    animation->setEasingCurve(QEasingCurve::OutBounce);

    // 执行动画
    animation->start();
}

void myPushButton::zoom_up() {
    // 创建一个动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    // 设置动画时间间隔
    animation->setDuration(100);

    // 起始位置
    animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));

    // 结束位置
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    // 设置弹跳曲线,弹跳类型为OutBounce(使用setEasingCurve搜索Qt文档即可)
    animation->setEasingCurve(QEasingCurve::OutBounce);

    // 执行动画
    animation->start();
}

void myPushButton::mousePressEvent(QMouseEvent *e) {
    // 传入的按下图片不为空，说明需要有按下状态，要进行切换图片
    if (this->pressImgPath != "") {
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if (!ret) {
            qDebug("图片加载失败");
            return;
        }
        // 图片加载成功，设置相关属性。
        this->setFixedSize(pix.width(), pix.height());
        // 设置不规则图片的样式
        this->setStyleSheet("QPushButton{border:0px}");
        // 设置图标
        this->setIcon(pix);
        // 设置图标大小   --  必须添加上，不然显示的图片十分小
        this->setIconSize(pix.size());
    }

    // 让父类执行其他内容 --- 这是必须的
    return QPushButton::mousePressEvent(e);
}

void myPushButton::mouseReleaseEvent(QMouseEvent *e) {

    // 传入的按下图片不为空，说明需要有按下状态，要进行切换图片
    if (this->pressImgPath != "") {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if (!ret) {
            qDebug("图片加载失败");
            return;
        }
        // 图片加载成功，设置相关属性。
        this->setFixedSize(pix.width(), pix.height());
        // 设置不规则图片的样式
        this->setStyleSheet("QPushButton{border:0px}");
        // 设置图标
        this->setIcon(pix);
        // 设置图标大小   --  必须添加上，不然显示的图片十分小
        this->setIconSize(pix.size());
    }

    // 让父类执行其他内容 --- 这是必须的
    return QPushButton::mouseReleaseEvent(e);
}

