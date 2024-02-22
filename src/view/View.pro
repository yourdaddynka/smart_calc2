QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../modules/ModelCalculator.cc \
    ../modules/ModelCredit.cc \
    ../modules/ModelDeposit.cc \
    creditcalcus.cc \
    depositcalcus.cc \
    graphsbuild.cc \
    main.cc \
    mainwindow.cc \
    qcustomplot.cpp

HEADERS += \
    ../controllers/ControllerCalculator.h \
    ../controllers/ControllerCredit.h \
    ../controllers/ControllerDeposit.h \
    creditcalcus.h \
    depositcalcus.h \
    graphsbuild.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    creditcalcus.ui \
    depositcalcus.ui \
    graphsbuild.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    View.pro.user
