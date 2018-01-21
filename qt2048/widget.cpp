#include "widget.h"
#include "ui_widget.h"
#include "position.h"
#include <QWaitCondition>
#include "data.h"
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_blocPosition = new position;
    blockShow(QString("start"));
    setWindowTitle(QString("2048"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    try{
        if(event->key() == Qt::Key_W)
        {
            blockShow(QString("up"));
        }
        if(event->key() == Qt::Key_A)
        {
            blockShow(QString("left"));
        }
        if(event->key() == Qt::Key_S)
        {
            blockShow(QString("down"));
        }
        if(event->key() == Qt::Key_D)
        {
            blockShow(QString("right"));
        }
    }
    catch(QString exception){
        QMessageBox::about(0,"Error",exception);
        this->close();
    }
}

void Widget::blockShow(QString type)
{
    foreach (auto item, m_vecLabel) {
        delete item;
    }
    m_vecLabel.clear();
    m_LabelPosition = m_blocPosition->getPositionInfo(type);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(m_LabelPosition->blockPosition[i][j] != 0)
            {
                m_vecLabel.append(new QLabel(QString::number(m_LabelPosition->blockPosition[i][j]),ui->widget));
                m_vecLabel.last()->setGeometry(100*j, 100*i, 100, 100);
                m_vecLabel.last()->setAlignment(Qt::AlignCenter);
                m_vecLabel.last()->setFont(QFont("Times", 25, QFont::Bold));

                m_vecLabel.last()->setStyleSheet(QString("QLabel{background-color: rgb(0, 255, 255);"
                                                         "color: red; border:5px solid yellow;}"));
            }
        }
    }
    foreach (auto item, m_vecLabel) {
        item->show();
    }
}

