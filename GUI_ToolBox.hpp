#ifndef GUI_TOOLBOX_HPP
#define GUI_TOOLBOX_HPP

#include <iostream>
#include <QToolBox>
#include <QTableWidget>
#include <QLabel>
#include <QPixmap>

#include "Engine/Level.hpp"
#include "Editor/ToolID.hpp"

namespace Ui { class GUI_ToolBox; }

class GUI_ToolBox : public QToolBox
{
    Q_OBJECT
    Ui::GUI_ToolBox* m_ui;
    Level m_level;

    QPixmap assetThumbnailFromDat(DAT& dat, std::string asset, int max_width, int max_height);
    void updateAssetsPanel();

    public:
        GUI_ToolBox(QWidget* parent);
        ~GUI_ToolBox();

    private slots:
        void updateLevel(Level level);
        void updateToolID(Tool_ID tool);
        void assetsCellClicked(int currentRow, int currentColumn, int previousRow, int previousColumn);

    signals:
        void assetSelected(std::string);
};

#endif // GUI_TOOLBOX_HPP
