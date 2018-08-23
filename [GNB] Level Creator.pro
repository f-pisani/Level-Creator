#-------------------------------------------------
#
# Project created by QtCreator 2015-07-06T03:35:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "[GNB] Level Creator"
TEMPLATE = app

SOURCES +=  main.cpp\
            Editor.cpp \
            EditorRender.cpp \
            GUI.cpp \
            GUI_StatusBar.cpp \
            GUI_ToolBar.cpp \
            GUI_ToolBox.cpp \
            GUI_LevelSettings.cpp \
            GUI_AssetsManager.cpp \
            Dat/DAT.cpp \
            QSFML/QSFML.cpp \
            Engine/Binarizable.cpp \
            Engine/Point.cpp \
            Engine/Size.cpp \
            Engine/ArtObject.cpp \
            Engine/Collider.cpp \
            Engine/Marker.cpp \
            Engine/Trigger.cpp \
            Engine/Level.cpp


HEADERS +=  Editor.hpp \
            EditorRender.hpp \
            GUI.hpp \
            GUI_StatusBar.hpp \
            GUI_ToolBar.hpp \
            GUI_ToolBox.hpp \
            GUI_LevelSettings.hpp \
            GUI_AssetsManager.hpp \
            Dat/DAT.hpp \
            QSFML/QSFML.hpp \
            Editor/ToolID.hpp \
            Engine/Binarizable.hpp \
            Engine/Point.hpp \
            Engine/Size.hpp \
            Engine/ArtObject.hpp \
            Engine/Collider.hpp \
            Engine/Marker.hpp \
            Engine/Trigger.hpp \
            Engine/Level.hpp


FORMS   +=  GUI.ui \
            GUI_ToolBox.ui \
            GUI_LevelSettings.ui \
            GUI_AssetsManager.ui
            


LIBS    +=  -LI:/SFML-2.3/lib

CONFIG  +=  C++11
CONFIG(release, debug|release): LIBS    +=  -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS      +=  -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += I:/SFML-2.3/include
DEPENDPATH  += I:/SFML-2.3/include
