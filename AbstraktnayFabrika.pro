QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        classunit.cpp \
        cppclassunit.cpp \
        cppfactory.cpp \
        cppmethodunit.cpp \
        cppprintoperatorunit.cpp \
        csclassunit.cpp \
        csfactory.cpp \
        csmethodunit.cpp \
        csprintoperatorunit.cpp \
        factory.cpp \
        javaclassunit.cpp \
        javafactory.cpp \
        javamethodunit.cpp \
        javaprintoperatorunit.cpp \
        main.cpp \
        methodunit.cpp \
        printoperatorunit.cpp \
        unit.cpp

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
