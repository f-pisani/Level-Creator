#include "GUI_ToolBox.hpp"
#include "ui_GUI_ToolBox.h"

/***************************************************************************************************
 * PUBLIC METHODS
 */
GUI_ToolBox::GUI_ToolBox(QWidget* parent) :
    QToolBox(parent), m_ui(new Ui::GUI_ToolBox)
{
    m_ui->setupUi(this);

    // Assets
    connect(m_ui->assetsTable, SIGNAL(currentCellChanged(int,int,int,int)), this, SLOT(assetsCellClicked(int,int,int,int)));
}


GUI_ToolBox::~GUI_ToolBox()
{
    
}


/***************************************************************************************************
 * PRIVATE METHODS
 */
QPixmap GUI_ToolBox::assetThumbnailFromDat(DAT& dat, std::string asset, int max_width, int max_height)
{
    QPixmap pixmap;
    std::string assetData(dat.file(asset));

    if(!assetData.empty())
    {
        // Convert into uchar array
        uchar pixmapData[assetData.size()];
        for(unsigned int i=0; i<assetData.size(); ++i)
            pixmapData[i] = assetData[i];

        pixmap.loadFromData(pixmapData, assetData.size());
        if(pixmap.size().width() > max_width && pixmap.size().height() > max_height)
            pixmap = pixmap.scaled(max_width, max_height, Qt::KeepAspectRatio, Qt::SmoothTransformation); // Width & Height overflow
        else if(pixmap.size().width() > max_width)
            pixmap = pixmap.scaled(max_width, pixmap.size().height(), Qt::KeepAspectRatio, Qt::SmoothTransformation); // Width overflow
        else if(pixmap.size().height() > max_height)
            pixmap = pixmap.scaled(pixmap.size().width(), max_height, Qt::KeepAspectRatio, Qt::SmoothTransformation); // Height overflow
    }

    return pixmap;
}


void GUI_ToolBox::updateAssetsPanel()
{
    DAT& dat = m_level.levelData().assets; // Referencing level assets
    m_ui->assetsTable->clear();
    m_ui->assetsTable->setColumnCount(3);
    m_ui->assetsTable->setRowCount(dat.count()/3+1);

    for(unsigned int i=0; i<dat.count(); ++i)
    {
        QPixmap pixmap(assetThumbnailFromDat(dat, dat.fileNameByIndex(i), 64, 64));
        int currentRow = i/m_ui->assetsTable->columnCount();
        int currentColumn = i%m_ui->assetsTable->columnCount();

        QLabel* label(new QLabel());
        label->setAlignment(Qt::AlignCenter);
        label->setPixmap(pixmap);

        m_ui->assetsTable->setCellWidget(currentRow, currentColumn, label);
    }
}


/***************************************************************************************************
 * PRIVATE SLOTS
 */
void GUI_ToolBox::updateLevel(Level level)
{
    m_level = level;

    updateAssetsPanel();
}


void GUI_ToolBox::updateToolID(Tool_ID tool)
{
    switch(tool)
    {
        case Tool_ID::Object_Create: setCurrentIndex(indexOf(m_ui->Assets)); break;

        default: setCurrentIndex(indexOf(m_ui->Information));
    }

    for(int i=1; i<count(); ++i)
    {
        if(i != currentIndex())
            setItemEnabled(i, false);
    }
}


void GUI_ToolBox::assetsCellClicked(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    DAT& dat(m_level.levelData().assets);

    int currentIndex(currentRow*3+currentColumn);
    if(dat.fileNameByIndex(currentIndex) != "")
    {
        // Current Cell
        QPixmap currentPixmap(assetThumbnailFromDat(dat, dat.fileNameByIndex(currentIndex), 64, 64));

        QLabel* currentLabel(new QLabel());
        currentLabel->setStyleSheet("QLabel { background-color : blue; }");
        currentLabel->setAlignment(Qt::AlignCenter);
        currentLabel->setPixmap(currentPixmap);

        m_ui->assetsTable->setCellWidget(currentRow, currentColumn, currentLabel);

        // Previous Cell
        int previousIndex(previousRow*3+previousColumn);
        QPixmap previousPixmap(assetThumbnailFromDat(dat, dat.fileNameByIndex(previousIndex), 64, 64));

        QLabel* previousLabel(new QLabel());
        previousLabel->setAlignment(Qt::AlignCenter);
        previousLabel->setPixmap(previousPixmap);

        m_ui->assetsTable->setCellWidget(previousRow, previousColumn, previousLabel);

        emit assetSelected(dat.fileNameByIndex(currentIndex));
    }
}
