#include "position.h"
#include <QDateTime>
#include <QDebug>

position::position()
{
    m_block = new blockInfo;
    //memset(m_block->blockPosition,0,sizeof(m_block->blockPosition));
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            m_block->blockPosition[i][j] = 0;
        }
    }
    m_block->blockPosition[getNum(3)][getNum(3)] = 2;
}

int position::getNum(int base)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int test =qrand()%base;
    return test;
}

void position::createNewBlock()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(m_block->blockPosition[i][j] == 0)
            {
                QPair<int, int> pair(i,j);
                m_veCcoordinate.append(pair);
            }
        }
    }
    if(m_veCcoordinate.count() == 0)
        throw QString("Game Over"); ;

    int count = getNum(m_veCcoordinate.count());
    m_block->blockPosition[m_veCcoordinate.at(count).first][m_veCcoordinate.at(count).second] = 2;
    m_veCcoordinate.clear();
}

blockInfo *position::getPositionInfo(QString type)
{
    bool move;
    qDebug()<<m_block->blockPosition[0][0]<<m_block->blockPosition[0][1]<<m_block->blockPosition[0][2]<<m_block->blockPosition[0][3];
    qDebug()<<m_block->blockPosition[1][0]<<m_block->blockPosition[1][1]<<m_block->blockPosition[1][2]<<m_block->blockPosition[1][3];
    qDebug()<<m_block->blockPosition[2][0]<<m_block->blockPosition[2][1]<<m_block->blockPosition[2][2]<<m_block->blockPosition[2][3];
    qDebug()<<m_block->blockPosition[3][0]<<m_block->blockPosition[3][1]<<m_block->blockPosition[3][2]<<m_block->blockPosition[3][3];
    qDebug()<<type<<endl;

    if(type == QString("left"))
    {
        for(int i = 0; i < 4; i++)
        {
            int numPos = 0;
            for(int j = 0; j < 4; j++)
            {
                if(m_block->blockPosition[i][j] == 0)
                    continue;
                else
                {
                    if(numPos == j)
                    {
                        numPos++;
                        continue;
                    }
                    else
                    {
                        m_block->blockPosition[i][numPos] = m_block->blockPosition[i][j];
                        m_block->blockPosition[i][j] = 0;
                        numPos++;
                        move = true;
                    }
                }
            }
        }
        for(int i = 0; i < 4; i++)
        {
            int pos = 0;
            for(int j = 0; j < 4; j++)
            {
                if(m_block->blockPosition[i][j] != 0)
                {
                    if(j == 3)
                    {
                        int value = m_block->blockPosition[i][j];
                        m_block->blockPosition[i][j] = 0;
                        m_block->blockPosition[i][pos] = value;
                    }
                    else if(m_block->blockPosition[i][j] == m_block->blockPosition[i][j+1])
                    {
                        m_block->blockPosition[i][j] = 0;
                        m_block->blockPosition[i][pos] = m_block->blockPosition[i][j+1]*2;
                        m_block->blockPosition[i][j+1] = 0;
                        move = true;
                    }
                    else
                    {
                        int value = m_block->blockPosition[i][j];
                        m_block->blockPosition[i][j] = 0;
                        m_block->blockPosition[i][pos] = value;
                    }
                    pos++;
                }
            }
        }
    }
    else if(type == QString("right"))
    {
        for(int i = 0; i < 4; i++)
        {
            int numPos = 3;
            for(int j = 3; j >= 0; j--)
            {
                if(m_block->blockPosition[i][j] == 0)
                    continue;
                else
                {
                    if(numPos == j)
                    {
                        numPos--;
                        continue;
                    }
                    else
                    {
                        m_block->blockPosition[i][numPos] = m_block->blockPosition[i][j];
                        m_block->blockPosition[i][j] = 0;
                        numPos--;
                        move = true;
                    }
                }
            }
        }
        for(int i = 0; i < 4; i++)
        {
            int pos = 3;
            for(int j = 3; j >= 0; j--)
            {
                if(m_block->blockPosition[i][j] != 0)
                {
                    if(j == 0)
                    {
                        int value = m_block->blockPosition[i][j];
                        m_block->blockPosition[i][j] = 0;
                        m_block->blockPosition[i][pos] = value;
                    }
                    else if(m_block->blockPosition[i][j] == m_block->blockPosition[i][j-1])
                    {
                        m_block->blockPosition[i][j] = 0;
                        m_block->blockPosition[i][pos] = m_block->blockPosition[i][j-1]*2;
                        m_block->blockPosition[i][j-1] = 0;
                        move = true;
                    }
                    else
                    {
                        int value = m_block->blockPosition[i][j];
                        m_block->blockPosition[i][j] = 0;
                        m_block->blockPosition[i][pos] = value;

                    }
                    pos--;
                }
            }
        }
    }
    else if(type == QString("up"))
    {
        for(int i = 0; i < 4; i++)
        {
            int numPos = 0;
            for(int j = 0; j < 4; j++)
            {
                if(m_block->blockPosition[j][i] == 0)
                    continue;
                else
                {
                    if(numPos == j)
                    {
                        numPos++;
                        continue;
                    }
                    else
                    {
                        m_block->blockPosition[numPos][i] = m_block->blockPosition[j][i];
                        m_block->blockPosition[j][i] = 0;
                        numPos++;
                        move = true;
                    }
                }
            }
        }
        for(int i = 0; i < 4; i++)
        {
            int pos = 0;
            for(int j = 0; j < 4; j++)
            {
                if(m_block->blockPosition[j][i] != 0)
                {
                    if(j == 3)
                    {
                        int value = m_block->blockPosition[j][i];
                        m_block->blockPosition[j][i] = 0;
                        m_block->blockPosition[pos][i] = value;
                    }
                    else if(m_block->blockPosition[j][i] == m_block->blockPosition[j+1][i])
                    {
                        m_block->blockPosition[j][i] = 0;
                        m_block->blockPosition[pos][i] = m_block->blockPosition[j+1][i]*2;
                        m_block->blockPosition[j+1][i] = 0;
                        move = true;
                    }
                    else
                    {
                        int value = m_block->blockPosition[j][i];
                        m_block->blockPosition[j][i] = 0;
                        m_block->blockPosition[pos][i] = value;
                    }
                    pos++;
                }
            }
        }
    }
    else if(type == QString("down"))
    {
        for(int i = 0; i < 4; i++)
        {
            int numPos = 3;
            for(int j = 3; j >= 0; j--)
            {
                if(m_block->blockPosition[j][i] == 0)
                    continue;
                else
                {
                    if(numPos == j)
                    {
                        numPos--;
                        continue;
                    }
                    else
                    {
                        m_block->blockPosition[numPos][i] = m_block->blockPosition[j][i];
                        m_block->blockPosition[j][i] = 0;
                        numPos--;
                        move = true;
                    }
                }
            }
        }
        for(int i = 0; i < 4; i++)
        {
            int pos = 3;
            for(int j = 3; j >= 0; j--)
            {
                if(m_block->blockPosition[j][i] != 0)
                {
                    if(j == 0)
                    {
                        int value = m_block->blockPosition[j][i];
                        m_block->blockPosition[j][i] = 0;
                        m_block->blockPosition[pos][i] = value;
                    }
                    else if(m_block->blockPosition[j][i] == m_block->blockPosition[j-1][i])
                    {
                        m_block->blockPosition[j][i] = 0;
                        m_block->blockPosition[pos][i] = m_block->blockPosition[j-1][i]*2;
                        m_block->blockPosition[j-1][i] = 0;
                        move = true;
                    }
                    else
                    {
                        int value = m_block->blockPosition[j][i];
                        m_block->blockPosition[j][i] = 0;
                        m_block->blockPosition[pos][i]= value;
                    }
                    pos--;
                }
            }
        }
    }
    if(type == "start" || move == true)
        createNewBlock();
    return m_block;
}
