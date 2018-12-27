#-------------------------------------------------
#
# Project created by QtCreator 2018-04-28T10:17:42
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = SV-ASSIST
TEMPLATE = app

RC_FILE = icon.rc

QMAKE_LFLAGS += /MANIFESTUAC:"level='requireAdministrator'uiAccess='false'"

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#LIBS += J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/lib/CPULIB.lib

        #J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/lib/disk.lib \
        #J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/lib/EDIDDLL.lib \
        #J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/lib/GPUDLL.lib \
        #J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/lib/smbiosdll.lib \

#INCLUDEPATH += J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/libheaders

#here a blackspace have function!

SOURCES += \
        main.cpp \
        dialog.cpp \
    widget_maintab.cpp \
    widget_pushbutton.cpp \
    widget_sidetab.cpp \
    widget_sidetabgroup.cpp \
    widget_title.cpp \
    page_hard.cpp \
    page_soft.cpp \
    page_test.cpp \
    hard_zhxx.cpp \
    hard_board.cpp \
    hard_cpu.cpp \
    hard_memory.cpp \
    hard_pci.cpp \
    hard_storage.cpp \
    hard_gfx.cpp \
    hard_net.cpp \
    hard_other.cpp \
    soft_zhxx.cpp \
    soft_config.cpp \
    test_memory.cpp \
    test_storage.cpp \
    window_config.cpp \
    window_help.cpp \
    window_about.cpp \
    test_cpu.cpp \
    widget_treebrowser.cpp \
    window_iobase.cpp \
    window_ioindex.cpp \
    window_sio.cpp \
    window_memoryaddress.cpp \
    soft_service.cpp \
    soft_autoboot.cpp \
    soft_taskscheduler.cpp \
    soft_transmission.cpp \
    getdata.cpp \
    window_memorytest.cpp \
    myshadow.cpp

HEADERS += \
        dialog.h \
    widget_maintab.h \
    widget_pushbutton.h \
    widget_sidetab.h \
    widget_sidetabgroup.h \
    widget_title.h \
    widget_treebrowser.h \
    page_hard.h \
    page_soft.h \
    page_test.h \
    hard_zhxx.h \
    hard_board.h \
    hard_cpu.h \
    hard_memory.h \
    hard_pci.h \
    hard_storage.h \
    hard_gfx.h \
    hard_net.h \
    hard_other.h \
    soft_zhxx.h \
    soft_config.h \
    soft_service.h \
    soft_autoboot.h \
    soft_taskscheduler.h \
    soft_transmission.h \
    test_memory.h \
    test_storage.h \
    test_cpu.h \
    window_about.h \
    window_config.h \
    window_help.h \
    window_iobase.h \
    window_ioindex.h \
    window_sio.h \
    window_memoryaddress.h \
    driverheaders/Driverdll.h \
    driverheaders/Ring0Defination.h \
    libheaders/ACPI_Defination.h\
    libheaders/ACPI.h\
    libheaders/CAudio.h \
    libheaders/CPU.h \
    libheaders/CPUlibdefination.h \
    libheaders/defination.h \
    libheaders/diskdefination.h \
    libheaders/EDID.h \
    libheaders/EDIDdefination.h \
    libheaders/gpu.h \
    libheaders/Igpu.h \
    libheaders/Iusb.h \
    libheaders/NetworkLib.h \
    libheaders/smbioslib.h \
    libheaders/Softwaredefination.h \
    libheaders/SV-SoftWare.h \
    libheaders/SV_Hardware.h\
    libheaders/UsbDefination.h \
    getdata.h \
    window_memorytest.h \
    myshadow.h


RESOURCES += \
    resource.qrc

win32: LIBS += -L$$PWD/lib/ -lsv-assistant

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/lib/sv-assistant.lib
#else:win32-g++: PRE_TARGETDEPS += $$PWD/lib/libsv-assistant.a

win32: LIBS += -L$$PWD/lib/ -lSV-SoftWare

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/lib/SV-SoftWare.lib
#else:win32-g++: PRE_TARGETDEPS += $$PWD/lib/libSV-SoftWare.a
