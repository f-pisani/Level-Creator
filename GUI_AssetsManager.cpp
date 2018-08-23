#include "GUI_AssetsManager.hpp"
#include "ui_GUI_AssetsManager.h"


/***************************************************************************************************
 * PUBLIC METHODS
 */
GUI_AssetsManager::GUI_AssetsManager(QWidget* parent, DAT* dat) :
    QDialog(parent),
    m_ui(new Ui::GUI_AssetsManager),
    m_dat(dat)
{
    m_ui->setupUi(this);
    setWindowTitle(parent->windowTitle()+" > Assets Manager");
    
    for(unsigned int i=0; i<m_dat->count(); ++i)
        m_ui->listWidget->addItem(QString(m_dat->fileNameByIndex(i).c_str()));
    
    on_listWidget_itemSelectionChanged();
}


GUI_AssetsManager::~GUI_AssetsManager()
{
    delete m_ui;
}


/***************************************************************************************************
 * PRIVATE SLOTS
 */
////////////////////////////////////////////////////////////////////////////////////////////////////
/// QListWidget
void GUI_AssetsManager::on_listWidget_itemSelectionChanged()
{
    if(m_ui->listWidget->selectedItems().size() >= 1)
    {
        if(m_ui->listWidget->selectedItems().size() == m_ui->listWidget->count())
            m_ui->selectAllButton->setEnabled(false);
        else
            m_ui->selectAllButton->setEnabled(true);
        
        m_ui->toggleSelectionButton->setEnabled(true);
        m_ui->unselectAllButton->setEnabled(true);
        
        m_ui->removeButton->setEnabled(true);
        m_ui->renameButton->setEnabled(true);
        
        m_ui->listWidget->setMouseTracking(false);
    }
    else
    {
        m_ui->selectAllButton->setEnabled(true);
        m_ui->toggleSelectionButton->setEnabled(false);
        m_ui->unselectAllButton->setEnabled(false);
        
        m_ui->removeButton->setEnabled(false);
        m_ui->renameButton->setEnabled(false);
        
        m_ui->listWidget->setMouseTracking(true);
    }
}


void GUI_AssetsManager::on_listWidget_itemEntered(QListWidgetItem *item)
{
    std::string key_name(item->data(Qt::DisplayRole).toString().toStdString());
    std::string data(m_dat->file(key_name));
    uchar pixmapData[data.size()];
    for(unsigned int i=0; i<data.size(); ++i)
        pixmapData[i] = data[i];
    
    QPixmap pixmap;
    pixmap.loadFromData(pixmapData, data.size());
    
    if(pixmap.size().width() > 200 || pixmap.size().height() > 200)
        m_ui->preview->setPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    else
        m_ui->preview->setPixmap(pixmap);
}


void GUI_AssetsManager::on_listWidget_itemClicked(QListWidgetItem *item)
{
    on_listWidget_itemEntered(item); 
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// SELECTION BUTTONS
void GUI_AssetsManager::on_selectAllButton_clicked()
{
    for(int i=0; i<m_ui->listWidget->count(); ++i)
    {
        QListWidgetItem* item(m_ui->listWidget->item(i));
        item->setSelected(true);
    }
}


void GUI_AssetsManager::on_unselectAllButton_clicked()
{
    for(int i=0; i<m_ui->listWidget->count(); ++i)
    {
        QListWidgetItem* item(m_ui->listWidget->item(i));
        item->setSelected(false);
    }    
}


void GUI_AssetsManager::on_toggleSelectionButton_clicked()
{
    for(int i=0; i<m_ui->listWidget->count(); ++i)
    {
        QListWidgetItem* item(m_ui->listWidget->item(i));
        if(item->isSelected())
            item->setSelected(false);
        else
            item->setSelected(true);
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// MANAGEMENT BUTTON
void GUI_AssetsManager::on_addButton_clicked()
{
    QStringList addFileNames(QFileDialog::getOpenFileNames(this, windowTitle()+" > Add file(s)...",
                                                           "", "Images (*.bmp *.png *.tga *.jpg *.gif)"));
    
    for(int i=0; i<addFileNames.size(); ++i)
    {
        if(!m_dat->exists(DAT::fileName(addFileNames.at(i).toStdString())))
        {
            if(!m_dat->add(addFileNames.at(i).toStdString()))
                QMessageBox::warning(this, windowTitle()+" > Adding error",
                                     "Unable to open file: "+addFileNames.at(i)+" !");
            else
                m_ui->listWidget->addItem(QString(DAT::fileName(addFileNames.at(i).toStdString()).c_str()));
        }
        else
            QMessageBox::warning(this, windowTitle()+" > Error while adding",
                                 "File: "+addFileNames.at(i)+"\nCan't be added. A file with this name already exists.");
    }
}


void GUI_AssetsManager::on_renameButton_clicked()
{
    QList<QListWidgetItem*> selectedItems(m_ui->listWidget->selectedItems());
    
    for(int i=0; i<selectedItems.size(); ++i)
    {
        bool ok(false);
        QString new_name(QInputDialog::getText(this, windowTitle()+" > Rename file",
                                               "New file name: ", QLineEdit::Normal,
                                               selectedItems.at(i)->data(Qt::DisplayRole).toString(), &ok));
        
        if(!new_name.isEmpty() && ok)
        {
            if(m_dat->rename(selectedItems.at(i)->data(Qt::DisplayRole).toString().toStdString(),
                             new_name.toStdString()))
            {
                m_ui->listWidget->removeItemWidget(selectedItems.at(i));
                delete selectedItems.at(i);
                
                m_ui->listWidget->addItem(new_name);
            }
            else
                QMessageBox::warning(this, windowTitle()+" > Error while renaming",
                                     "File with this name already exists !");
        }
    }
}


void GUI_AssetsManager::on_removeButton_clicked()
{
    QList<QListWidgetItem*> selectedItems(m_ui->listWidget->selectedItems());
    
    int user_select(QMessageBox::question(this, windowTitle()+" > Remove selected file(s) ?",
                                          QString::number(selectedItems.size())+ " file(s).\n"+
                                          "Do you want to remove all selected file(s) from the level ?"));
    
    if(user_select == QMessageBox::Yes)
    {
        for(int i=0; i<selectedItems.size(); ++i)
        {
            QString filename = selectedItems.at(i)->data(Qt::DisplayRole).toString();
            
            if(m_dat->remove(filename.toStdString()))
            {
                m_ui->listWidget->removeItemWidget(selectedItems.at(i));
                delete selectedItems.at(i);   
            }
            else
                QMessageBox::warning(this, windowTitle()+" > Error while removing",
                                     "Error while trying to remove: "+filename+" !\nTry again or reload the level.");
        }        
    }
}


void GUI_AssetsManager::on_removeAllButton_clicked()
{
    int user_select = QMessageBox::question(this, windowTitle()+" > Remove all file(s) ?",
                                            "Do you want to remove all file(s) from the level ?");
    
    if(user_select == QMessageBox::Yes)
    {
        m_dat->clear();
        
        while(m_ui->listWidget->count()>0)
        {
            QListWidgetItem* item(m_ui->listWidget->takeItem(0));
            delete item;
        }
    }
}


void GUI_AssetsManager::on_exportDatButton_clicked()
{
    QString selectedFilter("DAT (*.dat)");
    QString path(QFileDialog::getSaveFileName(this, windowTitle()+" > Export to DAT", "",
                                              "All (*.*);;DAT (*.dat)", &selectedFilter));
    
    if(!path.isEmpty())
    {
        if(m_dat->saveToFile(path.toStdString()))
            QMessageBox::information(this, windowTitle()+" > DAT Export",
                                     "Export to file: "+path+"\nSuccess !");
        else
            QMessageBox::warning(this, windowTitle()+" > Error while exporting",
                                 "Unable to create file: "+path+" !");
    }
}


void GUI_AssetsManager::on_importDatButton_clicked()
{
    QString selectedFilter("DAT (*.dat)");
    QString path(QFileDialog::getOpenFileName(this, windowTitle()+" > Import from DAT", "",
                                              "All (*.*);;DAT (*.dat)", &selectedFilter));
    
    if(!path.isEmpty())
    {
        DAT dat;
        if(dat.loadFromFile(path.toStdString()))
        {
            for(unsigned int i=0; i<dat.count(); ++i)
            {
                std::string name(dat.fileNameByIndex(i));
                std::string data(dat.file(name));
           
                if(!m_dat->exists(name))
                {
                    m_dat->add(name, data);
                    m_ui->listWidget->addItem(QString(name.c_str()));
                }
                else
                    QMessageBox::warning(this, windowTitle()+" > Error while importing",
                                         "Unable to add file: "+QString(name.c_str())+"\nFile already exists !");
            }
        }
        else
           QMessageBox::warning(this, windowTitle()+" > Error while importing",
                                "Unable to load file: "+path+" !");
    }
}
