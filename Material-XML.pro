#-------------------------------------------------
#
# Project created by QtCreator 2018-04-11T16:54:44
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Material-XML
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32:RC_ICONS += icon.ico

SOURCES += \
    src/main.cpp \
    src/material.cpp \
    src/searchsettings.cpp \
    gui/mainwindow.cpp \
    gui/SettingsWindow.cpp

HEADERS += \
    src/material.h \
    src/searchsettings.h \
    gui/mainwindow.h \
    gui/SettingsWindow.h

FORMS += \
    gui/mainwindow.ui \
    gui/settingswindow.ui

SOURCE_PATH = $$shell_path($$clean_path("$$PWD\\Sm4shMaterials.db"))
DEST_PATH_DEBUG = $$shell_path($$clean_path("$$OUT_PWD\\debug\\Sm4shMaterials.db"))
DEST_PATH_RELEASE = $$shell_path($$clean_path("$$OUT_PWD\\release\\Sm4shMaterials.db"))

#Create a command, using the 'cmd' command line and Window's 'xcopy', to copy our shaders folder
#into the Game/Bin/Shaders/ directory.
CopyFiles.commands = $$quote(cmd /c copy /Y $${SOURCE_PATH} $${DEST_PATH_DEBUG})
CopyFiles.commands = $$quote(cmd /c copy /Y $${SOURCE_PATH} $${DEST_PATH_RELEASE})

#Add the command to Qt.
QMAKE_EXTRA_TARGETS += CopyFiles
POST_TARGETDEPS += CopyFiles
