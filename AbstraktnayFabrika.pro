QT = core

CONFIG += c++11 console
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    classunit.h \
    cppclassunit.h \
    cppfactory.h \
    cppmethodunit.h \
    cppprintoperatorunit.h \
    csclassunit.h \
    csfactory.h \
    csmethodunit.h \
    csprintoperatorunit.h \
    factory.h \
    javaclassunit.h \
    javafactory.h \
    javamethodunit.h \
    javaprintoperatorunit.h \
    methodunit.h \
    printoperatorunit.h \
    unit.h
