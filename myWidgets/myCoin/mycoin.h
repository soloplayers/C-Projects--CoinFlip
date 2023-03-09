//
// Created by 93705 on 2022/4/8.
//

#ifndef COINFLIP_MYCOIN_H
#define COINFLIP_MYCOIN_H

#include <QPushButton>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class myCoin; }
QT_END_NAMESPACE

class myCoin : public QPushButton {
Q_OBJECT

public:
    // 参数代表传入的金币路径 ， 还是银币路径
    explicit myCoin(QString btnImg);

    ~myCoin() override;

    // 加上一些金币的属性，便于实现金币翻转的特效
    int posX;   // x坐标位置
    int posY;   // y坐标位置
    bool flag;  // 正反标志 ，金币 = true = 正面，银币 = false = 反面

    // 正反标志的改变函数
    void changFlag();

    // 必须要进行初始化，不然会异常退出报错
    QTimer *timer1 = new QTimer;  // 正面翻到反面的定时器
    QTimer *timer2 = new QTimer;  // 反面翻到正面的定时器

    // 表示资源图片里面1~8张图片，这8张图片是静态动画！
    int min = 1;
    int max = 8;

    // 执行动画的标志--节流阀（用户狂点，金币会狂转，效果不好）--搭配点击事件来控制开关
    bool isAnimation = false;

    // 重写按下事件
    void mousePressEvent(QMouseEvent *) override;

    // 是否胜利的标志
    bool isGoldenCoin = false;

private:
    Ui::myCoin *ui;
};


#endif //COINFLIP_MYCOIN_H
