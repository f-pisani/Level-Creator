#include "GUI_StatusBar.hpp"

/***************************************************************************************************
 * PUBLIC METHODS
 */
GUI_StatusBar::GUI_StatusBar(QWidget* parent) :
    QStatusBar(parent),
    m_fps(new QLabel),
    m_tool(new QLabel),
    m_viewPosition(new QLabel),
    m_viewZoom(new QLabel),
    m_cell(new QLabel)
{
    updateFPS(0);
    m_fps->setTextFormat(Qt::RichText);
    m_fps->setToolTip("Editor FPS.");
    addPermanentWidget(m_fps);
    addSeparator();
    
    updateTool("None");
    m_tool->setTextFormat(Qt::RichText);
    m_tool->setToolTip("Active tool.");
    addPermanentWidget(m_tool);
    addSeparator();
    
    updateViewPosition(0, 0);
    m_viewPosition->setTextFormat(Qt::RichText);
    m_viewPosition->setToolTip("Editor view position.");
    addPermanentWidget(m_viewPosition);
    addSeparator();
    
    updateViewZoom(100);
    m_viewZoom->setTextFormat(Qt::RichText);
    m_viewZoom->setToolTip("Editor zoom value.");
    addPermanentWidget(m_viewZoom);
    addSeparator();
    
    updateCell(0, 0);
    m_cell->setTextFormat(Qt::RichText);
    m_cell->setToolTip("Cell coordinate.");
    addPermanentWidget(m_cell);
}


GUI_StatusBar::~GUI_StatusBar()
{

}


/***************************************************************************************************
 * PRIVATE METHODS
 */
void GUI_StatusBar::addSeparator(int width)
{
    m_separator.push_back(new QFrame);
    QFrame* separator = m_separator.at(m_separator.size()-1);
    separator->setFrameShape(QFrame::VLine);
    separator->setLineWidth(width);
    
    addPermanentWidget(separator);
}


/***************************************************************************************************
 * PRIVATE SLOTS
 */
void GUI_StatusBar::updateFPS(unsigned int fps)
{
    m_fps->setText("<b>FPS:</b> "+QString::number(fps));
}


void GUI_StatusBar::updateTool(QString tool_name)
{
    m_tool->setText("<b>Tool:</b> "+tool_name);
}


void GUI_StatusBar::updateViewPosition(int x, int y)
{
    m_viewPosition->setText("<b>View:</b> ("+QString::number(x)+","+QString::number(y)+")");
}


void GUI_StatusBar::updateViewZoom(unsigned int zoom)
{
    m_viewZoom->setText("<b>Zoom:</b> "+QString::number(zoom)+"%");
}


void GUI_StatusBar::updateCell(int x, int y)
{
    m_cell->setText("<b>Cell:</b> ("+QString::number(x)+","+QString::number(y)+")");
}
