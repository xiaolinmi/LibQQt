#ifndef QQTDOUBLECLICKSOUNDLABEL_H
#define QQTDOUBLECLICKSOUNDLABEL_H

#include <qqtlabel.h>
#include <qqtdoubleclicksoundhelper.h>

#include <qqt-local.h>
#include <qqtcore.h>

/**
 * 这个是个虚类
 * 提供安装ClickHelper的能力
 */
class QQTSHARED_EXPORT QQtDoubleClickSoundLabel : public QQtLabel
{
public:
    explicit QQtDoubleClickSoundLabel ( QWidget* parent = 0 ) :
        QQtLabel ( parent ) {
        mClickHelper = 0;
        mClickHelper = new QQtDoubleClickSoundHelper ( this );
        installClickHelper ( mClickHelper );
    }
    virtual ~QQtDoubleClickSoundLabel() {}

    /**
     * 提供给App用信号
     * 界面层内部直接处理
     */
signals:
    void click();
    void longClick();
    void doubleClick();

signals:
    void clickWithPoint ( QPoint point );
    void longClickWithPoint ( QPoint point );
    void doubleClickWithPoint ( QPoint point );

    /**
     * 用户可选使用
     */
public:
    inline void installClickHelper ( QQtDoubleClickSoundHelper* helper ) {
        unConnectClickHelper();
        mClickHelper = helper;
        if ( !mClickHelper )
            return;
        connectClickHelper();
    }
    inline QQtDoubleClickSoundHelper* clickHelper() const {
        return mClickHelper;
    }

    /**
     * 子类重写这两个函数,实现丰富的click能力
     */
    // QQtWidget interface
protected:
    virtual void connectClickHelper() {
        if ( !mClickHelper )
            return;

        connect ( mClickHelper, SIGNAL ( click() ), this, SIGNAL ( click() ) );
        connect ( mClickHelper, SIGNAL ( longClick() ), this, SIGNAL ( longClick() ) );
        connect ( mClickHelper, SIGNAL ( doubleClick() ), this, SIGNAL ( doubleClick() ) );
        connect ( mClickHelper, SIGNAL ( clickWithPoint ( QPoint ) ), this, SIGNAL ( clickWithPoint ( QPoint ) ) );
        connect ( mClickHelper, SIGNAL ( longClickWithPoint ( QPoint ) ), this, SIGNAL ( longClickWithPoint ( QPoint ) ) );
        connect ( mClickHelper, SIGNAL ( doubleClickWithPoint ( QPoint ) ), this, SIGNAL ( doubleClickWithPoint ( QPoint ) ) );
    }

    virtual void unConnectClickHelper() {
        if ( !mClickHelper )
            return;

        disconnect ( mClickHelper, SIGNAL ( click() ), this, SIGNAL ( click() ) );
        disconnect ( mClickHelper, SIGNAL ( longClick() ), this, SIGNAL ( longClick() ) );
        disconnect ( mClickHelper, SIGNAL ( doubleClick() ), this, SIGNAL ( doubleClick() ) );
        disconnect ( mClickHelper, SIGNAL ( clickWithPoint ( QPoint ) ), this, SIGNAL ( clickWithPoint ( QPoint ) ) );
        disconnect ( mClickHelper, SIGNAL ( longClickWithPoint ( QPoint ) ), this, SIGNAL ( longClickWithPoint ( QPoint ) ) );
        disconnect ( mClickHelper, SIGNAL ( doubleClickWithPoint ( QPoint ) ), this,
                     SIGNAL ( doubleClickWithPoint ( QPoint ) ) );
    }

private:
    QQtDoubleClickSoundHelper* mClickHelper;

    /**
     * 子类不必重写MouseEvent函数,
     * 这里实现对clickHelper的响应能力
     */
    // QWidget interface
protected:
    virtual void mousePressEvent ( QMouseEvent* event ) {
        if ( mClickHelper )
            mClickHelper->mousePressEvent ( event, this );
        return QQtLabel::mousePressEvent ( event );
    }

    virtual void mouseReleaseEvent ( QMouseEvent* event ) {
        if ( mClickHelper )
            mClickHelper->mouseReleaseEvent ( event, this );
        return QQtLabel::mouseReleaseEvent ( event );
    }

    virtual void mouseDoubleClickEvent ( QMouseEvent* event ) {
        if ( mClickHelper )
            mClickHelper->mouseDoubleClickEvent ( event, this );
        return QQtLabel::mouseDoubleClickEvent ( event );
    }
};

#endif // QQTDOUBLECLICKSOUNDLABEL_H