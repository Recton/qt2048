#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVector>
#include <QKeyEvent>

struct blockInfo;
class position;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void keyPressEvent(QKeyEvent *event);

private:
    void blockShow(QString);

private:
    Ui::Widget *ui;
    position* m_blocPosition;
    blockInfo *m_LabelPosition;
    QVector<QLabel*> m_vecLabel;
};

#endif // WIDGET_H
