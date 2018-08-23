#include <QApplication>
#include <QSplashScreen>

#include "GUI.hpp"
#include "Editor.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion");

    GUI gui;
    gui.show();

    Editor editor(gui.getEditorFrame());
    editor.show();
    gui.setupEditor(&editor);

    return a.exec();
}
