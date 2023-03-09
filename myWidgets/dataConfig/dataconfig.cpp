//
// Created by 93705 on 2022/4/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_dataConfig.h" resolved

#include "dataconfig.h"
#include <QDebug>
#include <QVector>


dataConfig::dataConfig(QObject *parent) :
        QObject(parent) {
    // 地图数据arr1~~arr20，模拟金银币：1为金币，0为银币
    // arr1:第一关
    int arr1[4][4] = {
            {1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 0, 0, 0},
            {1, 1, 0, 1},
    };

    // arr2：第2关
    int arr2[4][4]={
            {1,0,1,1},
            {0,0,1,1},
            {1,1,0,0},
            {1,1,0,1}
    };

    // arr3：第3关
    int arr3[4][4]={
            {0,0,0,0},
            {0,1,1,0},
            {0,1,1,0},
            {0,0,0,0}
    };

    // arr4：第4关
    int arr4[4][4]={
            {0, 1, 1, 1},
            {1, 0, 0, 1},
            {1, 0, 1, 1},
            {1, 1, 1, 1}
    };

    // arr5：第5关
    int arr5[4][4]={
            {1, 0, 0, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 0, 0, 1}
    };

    // arr6：第6关
    int arr6[4][4]={
            {1, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {1, 0, 0, 1}
    };

    // arr7：第7关
    int arr7[4][4]={
            {0, 1, 1, 1},
            {1, 0, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 0}
    };

    // arr8：第8关
    int arr8[4][4]={
            {0, 1, 0, 1},
            {1, 0, 0, 0},
            {0, 0, 0, 1},
            {1, 0, 1, 0}
    };

    // arr9：第9关
    int arr9[4][4]={
            {1, 0, 1, 0},
            {1, 0, 1, 0},
            {0, 0, 1, 0},
            {1, 0, 0, 1}
    };

    // arr10：第10关
    int arr10[4][4]={
            {1, 0, 1, 1},
            {1, 1, 0, 0},
            {0, 0, 1, 1},
            {1, 1, 0, 1}
    };

    // arr11：第11关
    int arr11[4][4]={
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {0, 1, 1, 0}
    };

    // arr12：第12关
    int arr12[4][4]={
            {0, 1, 1, 0},
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0}
    };

    // arr13：第13关
    int arr13[4][4]={
            {0, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 1, 1, 0}
    };

    // arr14：第14关
    int arr14[4][4]={
            {1, 0, 1, 1},
            {0, 1, 0, 1},
            {1, 0, 1, 0},
            {1, 1, 0, 1}
    };

    // arr15：第15关
    int arr15[4][4]={
            {0, 1, 0, 1},
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {0, 1, 0, 1}
    };

    // arr16：第16关
    int arr16[4][4]={
            {0, 1, 1, 0},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {0, 1, 1, 0}
    };

    // arr17：第17关
    int arr17[4][4]={
            {0, 1, 1, 1},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {1, 1, 1, 0}
    };

    // arr18：第18关
    int arr18[4][4]={
            {0, 0, 0, 1},
            {0, 0, 1, 0},
            {0, 1, 0, 0},
            {1, 0, 0, 0}
    };

    // arr19：第19关
    int arr19[4][4]={
            {0, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 1, 1},
            {0, 0, 0, 0}
    };

    // arr20：第20关
    int arr20[4][4]={
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0}
    };

    QVector<QVector<int>> v;// 二维容器 临时变量存储地图数据

    // 录入第1关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr1[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(1, v);
    v.clear();

    // 录入第2关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr2[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(2, v);
    v.clear();

    // 录入第3关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr3[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(3, v);
    v.clear();

    // 录入第4关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr4[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(4, v);
    v.clear();

    // 录入第5关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr5[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(5, v);
    v.clear();

    // 录入第6关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr6[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(6, v);
    v.clear();

    // 录入第7关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr7[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(7, v);
    v.clear();

    // 录入第8关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr8[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(8, v);
    v.clear();

    // 录入第9关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr9[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(9, v);
    v.clear();

    // 录入第10关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr10[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(10, v);
    v.clear();

    // 录入第11关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr11[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(11, v);
    v.clear();

    // 录入第12关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr12[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(12, v);
    v.clear();

    // 录入第13关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr13[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(13, v);
    v.clear();

    // 录入第14关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr14[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(14, v);
    v.clear();

    // 录入第15关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr15[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(15, v);
    v.clear();

    // 录入第16关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr16[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(16, v);
    v.clear();

    // 录入第17关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr17[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(17, v);
    v.clear();

    // 录入第18关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr18[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(18, v);
    v.clear();

    // 录入第19关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr19[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(19, v);
    v.clear();

    // 录入第20关数据
    for (int i = 0; i < 4; ++i) {
        QVector<int> v1;
        for (int j = 0; j < 4; ++j) {
            v1.push_back(arr20[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(20, v);
    v.clear();
}

dataConfig::~dataConfig() {

}


