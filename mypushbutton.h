#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    //explicit mypushbutton(QWidget *parent = nullptr);
    mypushbutton(QString normal,QString press = "");
    QString normalImgPath;//默认显示
    QString pressedImgPath;//按下显示

    //向下跳跃
    void zoom1();
    //向上跳跃
    void zoom2();

    //鼠标按下
    void mousePressEvent(QMouseEvent * e);
    //鼠标释放
    void mouseReleaseEvent(QMouseEvent * e);


signals:

public slots:
};

#endif // MYPUSHBUTTON_H
