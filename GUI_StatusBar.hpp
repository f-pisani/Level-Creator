#ifndef GUISTATUSBAR_HPP
#define GUISTATUSBAR_HPP

#include <vector>
#include <QLabel>
#include <QStatusBar>

class GUI_StatusBar : public QStatusBar
{
    Q_OBJECT
    void addSeparator(int width=1);
    
    std::vector<QFrame*> m_separator;
    QLabel* m_fps;
    QLabel* m_tool;
    QLabel* m_viewPosition;
    QLabel* m_viewZoom;
    QLabel* m_cell;
    
    public:
        GUI_StatusBar(QWidget* parent);
        ~GUI_StatusBar();
        
    private slots:
        void updateFPS(unsigned int fps);
        void updateTool(QString tool_name);
        void updateViewPosition(int x, int y);
        void updateViewZoom(unsigned int zoom);
        void updateCell(int x, int y);        
};

#endif // GUISTATUSBAR_HPP
