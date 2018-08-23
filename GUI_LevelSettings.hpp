#ifndef GUILEVELSETTINGS_HPP
#define GUILEVELSETTINGS_HPP

#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>

#include "Engine/Level.hpp"

#include "ui_GUI_LevelSettings.h"

class GUI_LevelSettings : public QDialog, public Ui::GUI_LevelSettings
{
    Q_OBJECT
        
    public:
        explicit GUI_LevelSettings(QWidget *parent);
        GUI_LevelSettings(QWidget *parent, QString path, Level level);

    private slots:
        void on_confirmation_Button_accepted();
        void on_confirmation_Button_rejected();
        void on_selectPathBtn_clicked();
        void on_levelWidth_spinBox_editingFinished();
        void on_levelHeight_spinBox_editingFinished();
};

#endif // GUILEVELSETTINGS_HPP
