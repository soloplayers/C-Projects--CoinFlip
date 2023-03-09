//
// Created by 93705 on 2022/4/3.
//

#ifndef COINFLIP_PLAYSCENE_H
#define COINFLIP_PLAYSCENE_H

#include <QMainWindow>
#include "myWidgets/myCoin/mycoin.h"


QT_BEGIN_NAMESPACE
namespace Ui { class playScene; }
QT_END_NAMESPACE

class playScene : public QMainWindow {
Q_OBJECT

public:
//    explicit playScene(QWidget *parent = nullptr);
    explicit playScene(int levelNum);

    int levelIndex; //内部成员属性，记录所选的关卡

    // 重写paintEvent事件 绘制背景图
    void paintEvent(QPaintEvent *) override;

    int gameArr[4][4];  // 二维数组，维护每个关卡的具体数据
    myCoin *coinBtn[4][4];  // 保存数组地图中的金币信息

    // 游戏是否胜利的标志,默认是胜利状态，只要执行翻金币，不是全金币，游戏判定便不会赢
    bool isWin;

    ~playScene() override;

signals:
    void chooseSceneBack();

private:
    Ui::playScene *ui;
};


#endif //COINFLIP_PLAYSCENE_H
