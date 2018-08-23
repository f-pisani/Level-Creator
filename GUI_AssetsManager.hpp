#ifndef GUIASSETSMANAGER_HPP
#define GUIASSETSMANAGER_HPP

#include <iostream>
#include <QDialog>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QListWidgetItem>

#include "Engine/Level.hpp"
#include "DAT/DAT.hpp"

namespace Ui { class GUI_AssetsManager; }

class GUI_AssetsManager : public QDialog
{
    Q_OBJECT
    
    public:
        explicit GUI_AssetsManager(QWidget* parent, DAT* dat);
        ~GUI_AssetsManager();
        
    private slots:
        // QListWidget
        void on_listWidget_itemSelectionChanged();
        void on_listWidget_itemEntered(QListWidgetItem *item);
        void on_listWidget_itemClicked(QListWidgetItem *item);
        // Selection
        void on_selectAllButton_clicked();
        void on_unselectAllButton_clicked();
        void on_toggleSelectionButton_clicked();
        // Manage
        void on_addButton_clicked();
        void on_renameButton_clicked();
        void on_removeButton_clicked();
        void on_removeAllButton_clicked();
        void on_exportDatButton_clicked();
        void on_importDatButton_clicked();
        
    private:
        Ui::GUI_AssetsManager* m_ui;
        DAT* m_dat;
};

#endif // GUIASSETSMANAGER_HPP
