#ifndef POSITION_H
#define POSITION_H

#include <QObject>
#include "data.h"
#include <QPair>
#include <QVector>


class position
{
public:
    position();
    blockInfo* getPositionInfo(QString type);

private:
    int getNum(int base);
    void createNewBlock();
private:
    blockInfo *m_block;
    QVector<QPair<int, int>> m_veCcoordinate;
};

#endif // POSITION_H
