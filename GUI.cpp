#include "GUI.hpp"
#include "ui_GUI.h"

/***************************************************************************************************
 * PUBLIC METHODS
 */
GUI::GUI(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::GUI),
    m_editor(nullptr),
    m_levelFilePath(""),
    m_level(Level())
{
    m_ui->setupUi(this);
}


GUI::~GUI()
{
    delete m_ui;
}


void GUI::setupEditor(Editor* editor)
{
    m_editor = editor;

    initSignalsAndSlots();
}


QWidget* GUI::getEditorFrame()
{
    return m_ui->editorFrame;
}


/***************************************************************************************************
 * PRIVATE METHODS
 */
void GUI::closeEvent(QCloseEvent* e)
{
    if(!m_levelFilePath.empty())
    {
        int user_select(QMessageBox::question(this, windowTitle()+" > Quit ?",
                                              "Do you realy want to quit ? All unsaved changes will be lost.",
                                              QMessageBox::Yes | QMessageBox::Abort));

        if(user_select == QMessageBox::Abort)
            e->ignore();
    }
}


void GUI::initSignalsAndSlots()
{
    // QMenuBar
    connect(this, SIGNAL(fileLoaded(bool)), this, SLOT(updateMenuBar(bool)));
    // QToolBar
    connect(this, SIGNAL(fileLoaded(bool)), m_ui->toolBar, SLOT(setEnabled(bool)));
    // QToolBox: Information
    connect(this, SIGNAL(fileLoaded(Level)), m_ui->toolBox, SLOT(updateLevel(Level)));
    connect(m_ui->toolBox, SIGNAL(assetSelected(std::string)), m_editor, SLOT(updateSelectedAsset(std::string)));
    connect(m_ui->toolBar, SIGNAL(toolSelected(Tool_ID)), m_ui->toolBox, SLOT(updateToolID(Tool_ID)));
     /* Unique cell id
     */
    // QSFML
    connect(this, SIGNAL(fileLoaded(bool)), m_editor, SLOT(setVisible(bool)));
    connect(this, SIGNAL(fileLoaded(Level)), m_editor, SLOT(updateLevel(Level)));
    connect(m_ui->toolBar, SIGNAL(toolSelected(Tool_ID)), m_editor, SLOT(updateToolID(Tool_ID)));
    // QStatusBar
    connect(m_ui->toolBar, SIGNAL(toolSelected(QString)), m_ui->statusBar, SLOT(updateTool(QString)));
    connect(m_editor, SIGNAL(fpsChanged(uint)), m_ui->statusBar, SLOT(updateFPS(uint)));
    connect(m_editor, SIGNAL(viewPositionChanged(int,int)), m_ui->statusBar, SLOT(updateViewPosition(int,int)));
    connect(m_editor, SIGNAL(viewZoomChanged(uint)), m_ui->statusBar, SLOT(updateViewZoom(uint)));
    connect(m_editor, SIGNAL(cellHoverChanged(int,int)), m_ui->statusBar, SLOT(updateCell(int,int)));
}


/***************************************************************************************************
 * PRIVATE SLOTS (Menu Bar)
 */
void GUI::updateMenuBar(bool levelLoaded)
{
    if(levelLoaded)
    {
        m_ui->actionFileSave->setEnabled(true);
        m_ui->actionFileSave_As->setEnabled(true);
        m_ui->actionFileClose->setEnabled(true);
        
        m_ui->menuLevel->setEnabled(true);
        m_ui->menuView->setEnabled(true);
    }
    else
    {
        m_ui->actionFileSave->setEnabled(false);
        m_ui->actionFileSave_As->setEnabled(false);
        m_ui->actionFileClose->setEnabled(false);
        
        m_ui->menuLevel->setEnabled(false);
        m_ui->menuView->setEnabled(false);
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// Menu: File
void GUI::on_actionFileNew_triggered()
{
    if(!m_levelFilePath.empty())
        on_actionFileClose_triggered();

    if(m_levelFilePath.empty())
    {
        GUI_LevelSettings settings(this);

        if(settings.exec() == QDialog::Accepted)
        {
            if(m_level.saveToFile(settings.pathLineEdit->text().toStdString()))
            {
                m_levelFilePath = settings.pathLineEdit->text().toStdString();
                m_level.levelData().width = settings.levelWidth_spinBox->value();
                m_level.levelData().height = settings.levelHeight_spinBox->value();
                m_level.levelData().grid_width = settings.gridWidth_spinBox->value();
                m_level.levelData().grid_height = settings.gridHeight_spinBox->value();
                
                emit fileLoaded(true);
                emit fileLoaded(m_level);
            }
            else  
                QMessageBox::warning(this, windowTitle()+" > Error while creating level",
                                     "Error ! Unable to create file: "+settings.pathLineEdit->text());
        }
    }
}


void GUI::on_actionFileOpen_triggered()
{
    if(!m_levelFilePath.empty())
        on_actionFileClose_triggered();

    if(m_levelFilePath.empty())
    {
        QString defaultFilter("Level (*.level)");
        QString path(QFileDialog::getOpenFileName(this, windowTitle()+" > Load level", "",
                                                  "All (*.*);;Level (*.level)", &defaultFilter));

        if(!path.isEmpty())
        {
            m_levelFilePath = path.toStdString();
            if(m_level.loadFromFile(path.toStdString()))
            {
                emit fileLoaded(true);
                emit fileLoaded(m_level);
            }
            else
                QMessageBox::warning(this, windowTitle()+" > Error while loading level",
                                     "Unable to load file: "+path);
        }
    }
}


void GUI::on_actionFileSave_triggered()
{
    m_level = m_editor->level();
    
    if(m_level.saveToFile(m_levelFilePath))
        QMessageBox::information(this, windowTitle()+" > Level saved",
                                 "File: "+QString(m_levelFilePath.c_str())+" saved !");
    else
        QMessageBox::warning(this, windowTitle()+" > Error while saving level",
                             "Unable to save file: "+QString(m_levelFilePath.c_str()));
}


void GUI::on_actionFileSave_As_triggered()
{
    QString defaultFilter("Level (*.level)");
    QString path(QFileDialog::getSaveFileName(this, "Select project directory.", "",
                                              "All (*.*);;Level (*.level)", &defaultFilter));

    if(!path.isEmpty())
    {
        m_level = m_editor->level();
        
        if(m_level.saveToFile(path.toStdString()))
            QMessageBox::information(this, windowTitle()+" > Level saved",
                                     "File: "+QString(m_levelFilePath.c_str())+" saved !");
        else
            QMessageBox::warning(this, windowTitle()+" > Error while saving level",
                                 "Unable to save file: "+QString(m_levelFilePath.c_str()));
    }
}


void GUI::on_actionFileClose_triggered()
{
    int close_confirmation = QMessageBox::question(this, windowTitle()+" > Close level",
                                                   "Do you want to save the level ?",
                                                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,
                                                   QMessageBox::Save);

    if(close_confirmation == QMessageBox::Save)
    {
        if(!m_level.saveToFile(m_levelFilePath))
        {
            QMessageBox::warning(this, windowTitle()+" > Error while saving level",
                                 "Unable to save file: "+QString(m_levelFilePath.c_str()));
            
            close_confirmation = QMessageBox::Cancel;
        }
    }

    if(close_confirmation != QMessageBox::Cancel)
    {
        m_levelFilePath = "";
        m_level.clear();

        emit fileLoaded(false);
        emit fileLoaded(Level());
    }
}


void GUI::on_actionFileQuit_triggered()
{
    close();
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// Menu: Level
void GUI::on_actionLevelSettings_triggered()
{
    GUI_LevelSettings settings(this, QString(m_levelFilePath.c_str()), m_level);

    if(settings.exec() == QDialog::Accepted)
    {
        m_level.levelData().width = settings.levelWidth_spinBox->value();
        m_level.levelData().height = settings.levelHeight_spinBox->value();
        m_level.levelData().grid_width = settings.gridWidth_spinBox->value();
        m_level.levelData().grid_height = settings.gridHeight_spinBox->value();
        
        emit fileLoaded(m_level);
    }
}


void GUI::on_actionLevelAssetsManager_triggered()
{
    GUI_AssetsManager assetManager(this, &m_level.levelData().assets);
    
    assetManager.exec();

    emit fileLoaded(m_level);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// Menu: View
void GUI::on_actionViewZoom25_triggered(){ m_editor->setZoom(25); }
void GUI::on_actionViewZoom50_triggered(){ m_editor->setZoom(50); }
void GUI::on_actionViewZoom100_triggered(){ m_editor->setZoom(100); }
void GUI::on_actionViewZoom125_triggered(){ m_editor->setZoom(125); }
void GUI::on_actionViewZoom150_triggered(){ m_editor->setZoom(150); }
void GUI::on_actionViewZoom175_triggered(){ m_editor->setZoom(175); }
void GUI::on_actionViewReset_triggered()
{
    m_editor->setZoom(100);
    m_editor->resetView();
}
