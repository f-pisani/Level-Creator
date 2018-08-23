#ifndef Editor_HPP
#define Editor_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include <SFML/Graphics.hpp>

#include "QSFML/QSFML.hpp"
#include "Editor/ToolID.hpp"
#include "Engine/Level.hpp"
#include "Engine/ArtObject.hpp"

#include "EditorRender.hpp"

enum class SelectionMode
{
    None = 0,
    ArtObject = 1,
    Collider = 2,
    Marker = 3,
    Trigger = 4
};

class Editor : public QSFML
{
    Q_OBJECT
    int uniqueIDFromCell(float x, float y);
    sf::Vector2f cellFromUniqueID(int id);
    void OnInit();
    void OnUpdate();
    void OnUpdateView();
    void OnUpdateZoom();
    void OnUpdateCurrentCell();
    void OnUpdateToolAction();
    void Selection(SelectionMode mode);
        
    Level m_level;
    std::unordered_map<std::string, sf::Texture> m_assets;
    std::string m_selectedAsset;
    Tool_ID m_tool;
    sf::Vector2u m_currentCell;
    std::vector<sf::Vector2u> m_selection;
    EditorRender* m_editorRender;
    sf::View m_view;
    unsigned int m_viewZoom;
        
    public:
        Editor(QWidget* parent=0);
        ~Editor();
        
        void setView(float x, float y);
        void resetView();
        void setZoom(unsigned int zoom);
        void resetZoom();
        
        inline Level level(){ return m_level; }
        
    private slots:
        void updateToolID(Tool_ID id);
        void updateLevel(Level level);
        void updateSelectedAsset(std::string str);
        
    signals:
        void fpsChanged(unsigned int);
        void viewPositionChanged(int, int);
        void viewZoomChanged(unsigned int);
        void cellHoverChanged(int, int);
};

#endif // Editor_HPP
