#include "GUI_LevelSettings.hpp"

/***************************************************************************************************
 * PUBLIC METHODS
 */
GUI_LevelSettings::GUI_LevelSettings(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    setWindowTitle(parent->windowTitle()+" > Create new level");
}


GUI_LevelSettings::GUI_LevelSettings(QWidget *parent, QString path, Level level) :
    QDialog(parent)
{
    setupUi(this);
    setWindowTitle(parent->windowTitle()+" > Level Settings");
    
    pathLineEdit->setText(path);
    levelWidth_spinBox->setValue(level.levelData().width);
    emit levelWidth_spinBox->editingFinished();
    levelHeight_spinBox->setValue(level.levelData().height);
    emit levelHeight_spinBox->editingFinished();
    gridWidth_spinBox->setValue(level.levelData().grid_width);
    gridHeight_spinBox->setValue(level.levelData().grid_height);

    selectPathBtn->setEnabled(false);
}


/***************************************************************************************************
 * PRIVATE METHODS (SLOTS)
 */
////////////////////////////////////////////////////////////////////////////////////////////////////
/// CONFIRMATION BUTTONS
void GUI_LevelSettings::on_confirmation_Button_accepted()
{
    if(!pathLineEdit->text().isEmpty())
        accept();
    else
        QMessageBox::warning(this, windowTitle()+" > Incomplete project path",
                             "You must select a file to create the level.");
}


void GUI_LevelSettings::on_confirmation_Button_rejected()
{
    reject();
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// PATH SELECTION
void GUI_LevelSettings::on_selectPathBtn_clicked()
{
    QString defaultFilter("Level (*.level)");
    QString path(QFileDialog::getSaveFileName(this, windowTitle()+" > Select file", "",
                                              "All (*.*);;Level (*.level)",
                                              &defaultFilter));
    
    if(!path.isEmpty())
        pathLineEdit->setText(path);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// GRID LIMITS (Grid Width <= Level Width/2 && Grid Height <= Level Height/2)
void GUI_LevelSettings::on_levelWidth_spinBox_editingFinished()
{
    int levelWidth = levelWidth_spinBox->value();
    if(levelWidth/2 > 256)
        gridWidth_spinBox->setMaximum(256);
    else
        gridWidth_spinBox->setMaximum(levelWidth/2);
    
    int gridWidth = gridWidth_spinBox->value();
    if(gridWidth > gridWidth_spinBox->maximum())
        gridWidth_spinBox->setValue(gridWidth_spinBox->maximum());
}


void GUI_LevelSettings::on_levelHeight_spinBox_editingFinished()
{
    int levelHeight = levelHeight_spinBox->value();
    if(levelHeight/2 > 256)
        gridHeight_spinBox->setMaximum(256);
    else
        gridHeight_spinBox->setMaximum(levelHeight/2);
    
    
    int gridHeight = gridHeight_spinBox->value();
    if(gridHeight > gridHeight_spinBox->maximum())
        gridHeight_spinBox->setValue(gridHeight_spinBox->maximum());
}

