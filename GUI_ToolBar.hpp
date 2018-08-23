#ifndef GUITOOLBAR_HPP
#define GUITOOLBAR_HPP

#include <QToolBar>
#include <QToolButton>

#include <QIcon>
#include <QMenu>
#include <QAction>
#include <QActionGroup>

#include "Editor/ToolID.hpp"

class GUI_ToolBar : public QToolBar
{
    Q_OBJECT
    QToolButton* m_toolButton_object;
    QToolButton* m_toolButton_collider;
    QToolButton* m_toolButton_marker;
    QToolButton* m_toolButton_trigger;
        
    public:
        GUI_ToolBar(QWidget* parent);
        ~GUI_ToolBar();
         
    private slots:
        void toolButtonTriggered(QAction* action);

    signals:
        void toolSelected(Tool_ID);
        void toolSelected(QString);
};

#endif // GUITOOLBAR_HPP
