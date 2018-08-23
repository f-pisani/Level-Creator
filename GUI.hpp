#ifndef GUI_HPP
#define GUI_HPP

#include <iostream>
#include <map>

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFileDialog>

#include "GUI_LevelSettings.hpp"
#include "GUI_AssetsManager.hpp"

#include "Engine/Level.hpp"

#include "Editor.hpp"
#include "Editor/ToolID.hpp"

namespace Ui { class GUI; }

class GUI : public QMainWindow
{
    Q_OBJECT
    void closeEvent(QCloseEvent *event);
    void initSignalsAndSlots();

    Ui::GUI* m_ui;
    Editor* m_editor;
    std::string m_levelFilePath;
    Level m_level;
        
    public:
        explicit GUI(QWidget *parent = 0);
        ~GUI();
        void setupEditor(Editor* editor);
        QWidget* getEditorFrame();

     
    private slots:
        // Menu bar
        void updateMenuBar(bool levelLoaded);
        /// File
        void on_actionFileNew_triggered();
        void on_actionFileOpen_triggered();
        void on_actionFileSave_triggered();
        void on_actionFileSave_As_triggered();
        void on_actionFileClose_triggered();
        void on_actionFileQuit_triggered();
        /// Level
        void on_actionLevelSettings_triggered();
        void on_actionLevelAssetsManager_triggered();
        /// View
        void on_actionViewZoom25_triggered();
        void on_actionViewZoom50_triggered();
        void on_actionViewZoom100_triggered();
        void on_actionViewZoom125_triggered();
        void on_actionViewZoom150_triggered();
        void on_actionViewZoom175_triggered();
        void on_actionViewReset_triggered();
        
    signals:
        void fileLoaded(bool);
        void fileLoaded(Level);
};

#endif // GUI_HPP
