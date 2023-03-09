//
// Created by 93705 on 2022/3/17.
//

#ifndef COINFLIP_CHOOSELEVELSCENE_H
#define COINFLIP_CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "../playScene/playScene.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ChooseLevelScene; }
QT_END_NAMESPACE

class ChooseLevelScene : public QMainWindow {
Q_OBJECT

public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    // 重写paintEvent事件---目的是绘制背景图
    void paintEvent(QPaintEvent *) override;

    // 声明一个游戏对象指针
    playScene *play = nullptr;

    ~ChooseLevelScene() override;

signals:

    // 写一个自定义信号，告诉主场景。点击了返回按钮，以此将隐藏的主场景再次显示出来
//    自定义信号只需要声明，并不一定需要实现。
    void chooseSceneBack();

private:
    Ui::ChooseLevelScene *ui;
};


#endif //COINFLIP_CHOOSELEVELSCENE_H
