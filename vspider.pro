TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++1y
QMAKE_LFLAGS += -pthread -std=c++1y

SOURCES += \
    src/main.cc \
    src/spider_host.cc \
    src/components/args/url_info.cc \
    src/components/downloader.cc \
    src/components/args/raw_document_info.cc \
    src/util/ilogger.cc \
    src/components/args/arg.cc \
    src/components/url_queue.cc

HEADERS += \
    src/main.h \
    src/spider_host.h \
    src/common.h \
    src/components/downloader.h \
    src/components/analyzer.h \
    src/components/components.h \
    src/components/spider_component.h \
    src/components/url_queue.h \
    src/components/args/arg.h \
    src/components/args/url_info.h \
    src/components/args/raw_document_info.h \
    src/util/ilogger.h \
    src/components/url_queue.h

unix {
    DEFINES += PLATFORM_UNIX

#    INCLUDEPATH +=

    LIBS += -L/usr/local/lib \
            -lPocoFoundation \
            -lPocoNet
}

OTHER_FILES += \
    README.md
