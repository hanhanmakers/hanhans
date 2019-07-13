#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
//mypushbutton::mypushbutton(QWidget *parent) : QPushButton(parent)
//{

//}
mypushbutton::mypushbutton(QString normal,QString press)
{
    //保存 正常显示路径 和 选中后显示路径
    this->normalImgPath = normal;
    this->pressedImgPath = press;

    QPixmap pix;
    bool ret = pix.load(this->normalImgPath);
    if(!ret)
    {
        QString str = QString("%1 图片加载失败").arg(this->normalImgPath);
        qDebug()<<str;
        return;
    }
    //设定图片大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px}");
    //设置图片
    this->setIcon(pix);
    //设置图片大小
    this->setIconSize(QSize(pix.width(),pix.height()));





}
//向下跳跃
void mypushbutton::zoom1()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设定时间间隔
    animation->setDuration(200);
    //设置动态对象起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置动画结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}
//向上跳跃
void mypushbutton::zoom2()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设定时间间隔
    animation->setDuration(200);
    //设置动态对象起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置动画结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

//鼠标按下
void mypushbutton::mousePressEvent(QMouseEvent * e)
{
    if(this->pressedImgPath!="")//不为空切换
    {
        QPixmap pix;
        bool ret = pix.load(this->pressedImgPath);
        if(!ret)
        {
            qDebug()<<"图片加载失败";
            return;
        }
        //设定图片大小
        //this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图片
        this->setIcon(pix);
        //设置图片大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    //其他事情交给父类
    QPushButton::mousePressEvent(e);



}
//鼠标释放
void mypushbutton::mouseReleaseEvent(QMouseEvent * e)
{
    if(this->pressedImgPath!="")//不为空切换
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if(!ret)
        {
            qDebug()<<"图片加载失败";
            return;
        }
        //设定图片大小
        //this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图片
        this->setIcon(pix);
        //设置图片大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    //其他事情交给父类
    QPushButton::mouseReleaseEvent(e);


}





