#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include "myWidgets/ChooseLevelScene/chooselevelscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow {
Q_OBJECT

public:
    explicit MainScene(QWidget *parent = nullptr);

    // 重写paintEvent事件（设置背景图片）
    void paintEvent(QPaintEvent *) override;

    ChooseLevelScene *chooseScene = nullptr;

    ~MainScene() override;

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
