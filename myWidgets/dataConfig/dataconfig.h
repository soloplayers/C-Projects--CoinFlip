//
// Created by 93705 on 2022/4/8.
//

#ifndef COINFLIP_DATACONFIG_H
#define COINFLIP_DATACONFIG_H

#include <QObject>
#include <QMap>
#include <QVector>

class dataConfig : public QObject {
Q_OBJECT

public:
    explicit dataConfig(QObject *parent = nullptr);

    ~dataConfig() override;

    QMap<int, QVector<QVector<int>>> mData;

private:

};


#endif //COINFLIP_DATACONFIG_H
