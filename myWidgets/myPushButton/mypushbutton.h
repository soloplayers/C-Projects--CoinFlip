//
// Created by 93705 on 2022/3/17.
//

#ifndef COINFLIP_MYPUSHBUTTON_H
#define COINFLIP_MYPUSHBUTTON_H

#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class myPushButton; }
QT_END_NAMESPACE

class myPushButton : public QPushButton {
Q_OBJECT

    explicit myPushButton(QWidget *parent = nullptr);


public:
//    explicit myPushButton(QWidget *parent = nullptr);

    // 重写 myPushButton构造函数,两个参数都是图片路径。设置第二个参数是为了项目中使用到量词myPushButton而作的考虑,
    explicit myPushButton(QString normalImg="", QString pressImg = "");

    // 成员属性，保存用户传入的默认显示路径，以及按下后显示的图片路径。
    QString normalImgPath;
    QString pressImgPath;

    // 弹跳特效 --  这两个函数可以封装成一个函数，设置不同参数即可，避免代码冗余
    void zoom_down();   // 向下跳
    void zoom_up();     // 向上跳

    // 重写按钮的 按下和释放事件  --以修改返回按钮的特效图片
    // 配合构造函数的第二个参数pressImg值判断是否需要切图片。
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;

    ~myPushButton() override;

private:
    Ui::myPushButton *ui{};
};


#endif //COINFLIP_MYPUSHBUTTON_H
