# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = Material-XML
DESTDIR = ./release
QT += core xml gui widgets
CONFIG += release
DEFINES += _WINDOWS _UNICODE WIN64 QT_DEPRECATED_WARNINGS QT_WIDGETS_LIB QT_XML_LIB
INCLUDEPATH += ./GeneratedFiles/$(ConfigurationName) \
    ./GeneratedFiles \
    . \
    ./release \
    $(QTDIR)/mkspecs/win32-msvc
LIBS += -L"../../../../../../utils/my_sql/my_sql/lib" \
    -L"../../../../../../utils/postgresql/pgsql/lib" \
    -lshell32
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += release
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(Material-XML.pri)
