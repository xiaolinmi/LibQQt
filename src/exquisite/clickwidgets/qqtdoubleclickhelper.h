#ifndef QQTDOUBLECLICKHELPER_H
#define QQTDOUBLECLICKHELPER_H

#include <QTimer>

#include <qqtevent.h>
#include <qqtlongclickhelper.h>

#include <qqt-local.h>
#include <qqtcore.h>

/**
 * @brief The QQtDoubleClickHelper class
 *
 * 支持
 * click
 * longClick
 * doubleClick
 *
 * 原理
 * release开始检测.
 * 发现longClick只发送longClick.
 * 发现click只发送click.
 * 发现doubleClick只发送doubleClick.包括Qt的和内部的检测都管用.
 * 以最新click为准
 *
 * 行为
 * releaseEvent是核心.
 * 仅仅接收到release,就可以发生单击和双击检测,击发其中一个.
 * 必须被press击发,才会检测发生长击,长击到点,如果没有release也不会发射信号.
 * 仅仅使用pressEvent,不会发生任何情况.
 * 仅仅使用DoubleClickEvent,不会发生任何情况.
 *
 * DoubleClick检测是独立于系统的,用户可以在页面里实现多套独立的按键时延检测,一个widget一个时延系统也没问题.
 */
class QQTSHARED_EXPORT QQtDoubleClickHelper : public QQtLongClickHelper
{
    Q_OBJECT

public:
    explicit QQtDoubleClickHelper ( QObject* parent = 0 );
    virtual ~QQtDoubleClickHelper();

    //调用于userWidget相对应的Event里
    //允许重写
public:
    virtual void mousePressEvent ( QMouseEvent* event, QWidget* userWidget = 0 ) override;
    virtual void mouseReleaseEvent ( QMouseEvent* event, QWidget* userWidget = 0 ) override;
    virtual void mouseDoubleClickEvent ( QMouseEvent* event, QWidget* userWidget = 0 ) override;

signals:
    void doubleClick();

signals:
    void doubleClickWithPoint ( QPoint point );

signals:
    void doubleClickWithPointF ( QPointF point );

    //optional
public:
    //设置双击检测时延 default: doubleClickInterval ms
    //不会影响系统默认时延
    void setDoubleClickInterval ( int millSecond = doubleClickInterval ) {
        mDoubleClickInterval = millSecond;
    }
    int getDoubleClickInterval() const {
        return mDoubleClickInterval;
    }

    inline const quint32 doubleClickNum() const { return nDoubleClickNum; }
    inline const quint32 doubleClickNumWithCancel() const { return nDoubleClickNumWithCancel; }

    /**
     * 以下用于内部
     */
public:

public slots:
    void slotClickTimeout();
    void slotLongClickTimeout();
    void slotDoubleClickTimeout();

protected:
    //这个语法比较难,只有整型有特权.
    static const int doubleClickInterval = 260;

    //clickTimer
    QTimer* m_click_timer;
    //longClickTimer
    QTimer* m_long_click_timer;
    //doubleClickTimer
    QTimer* m_double_click_timer;


    //双击200ms. 这个比较符合双击舒适度.Qt内部的Timer慢一些,可能是计算了比较完整的时间.
    //在这个范围内的都 才 是双击
    int mDoubleClickInterval;

    //click 检测使用
    QTime startClickTime;

    //double click检测用
    QTime prev_doubleclick;
    QTime now_doubleclick;

    //long click用
    QTime prev_release;
    QTime now_release_initial;

    //click 用
    QWidget* mUserWidget;
    QQtMouseEvent* mMouseEvent;

    //click num
    virtual void checkClickNum ( QQtClickType type ) override;
    virtual void checkClickNumWithCancel() override;

    quint32 nDoubleClickNum;
    quint32 nDoubleClickNumWithCancel;
};

#endif // QQTDOUBLECLICKHELPER_H
