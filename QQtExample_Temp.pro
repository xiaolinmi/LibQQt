##-----------------------------------------------------------------
##LibQQt样例工程入口
##不能随便编译，初始设置要求比较严格，请按照规程设置完整。
##Example要编译，必须先编译完LibQQt
##本Library基于Multi-link技术，Example也是
##Example工程也就是App工程和Library工程不能放在一起编译，否则会引发 first time bug (add_deploy_library_on_mac).
##Library工程组和App工程组分开编译，不会引发这个bug。
##-----------------------------------------------------------------
TEMPLATE = subdirs

SUBDIRS =

#need vlcQt libvlc library
#SUBDIRS += test/qqtliveplayer
#need ffmpeg library
#SUBDIRS += test/qqtffmpegplayer

#need webkit webkitwidgets - WebSupport
#webengine
#ignored
#lessThan(QT_MAJOR_VERSION , 5):SUBDIRS += test/qqtwebkittest
#lessThan(QT_MAJOR_VERSION , 5):SUBDIRS += test/qqtwebclient

#need OpenCV
#
SUBDIRS += examples/QQtOpenCVExample

#这是一对，用于测试Multi-link对其他的lib的链接能力
#SUBDIRS += test/QQtMultiLinkTest

#need winSDK
#SUBDIRS += examples/QQtOpenSceneGraphExample

#need Qwt
#SUBDIRS += test/QQtQwtTest