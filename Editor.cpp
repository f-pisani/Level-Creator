#include "Editor.hpp"

/***************************************************************************************************
 * PUBLIC METHODS
 */
Editor::Editor(QWidget* parent) :
    QSFML(parent, QPoint(0,0), parent->size()),
    m_level(Level()),
    m_assets(),
    m_selectedAsset(),
    m_tool(Tool_ID::None),
    m_currentCell(0, 0),
    m_selection(),
    m_editorRender(new EditorRender(m_level)),
    m_view(),
    m_viewZoom(100)
{ 
}


Editor::~Editor()
{
}


///
/// \brief Move the center of the Editor view.
/// \param x
/// \param y
///
void Editor::setView(float x, float y)
{
    m_view.setCenter(x, y);
    
    emit viewPositionChanged(x, y);
}


///
/// \brief Reset the center of the editor view. (By default: the middle of the level)
///
void Editor::resetView()
{
    setView(m_level.levelData().width/2,
            m_level.levelData().height/2);
}


///
/// \brief Set the zoom for the Editor view.
/// \param zoom Set the zoom in percentage. (Min: 50% Max: 150%)
///
void Editor::setZoom(unsigned int zoom)
{
    if(zoom >= 50 && zoom <= 150)
    {
        m_viewZoom = zoom;
        float factor = 1.f+(1.f-(m_viewZoom/100.f));

        m_view.setSize(getSize().x*factor,
                       getSize().y*factor);
        
        emit viewZoomChanged(m_viewZoom);
    }
}


///
/// \brief Reset the zoom of the Editor view. (By default: 100%)
///
void Editor::resetZoom()
{
    setZoom(100);
}


/***************************************************************************************************
 * PRIVATE METHODS
 */
///
/// \brief Generate an unique ID for a pair of coordinate
/// \param x X offset
/// \param y Y offset
/// \return Cell unique ID
/// \note This function is based on the grid. If multiple coordinate are inside the same grid cell
/// it will be only one ID for all of them.
///
int Editor::uniqueIDFromCell(float x, float y)
{
    if(x > m_level.levelData().width || y > m_level.levelData().height)
        return -1;

    int cell_X = x/m_level.levelData().grid_width;
    int cell_Y = y/m_level.levelData().grid_height;
    int row_width = m_level.levelData().width/m_level.levelData().grid_width;

    return (cell_Y * row_width + cell_X);
}


///
/// \brief Reverse Editor::uniqueIDFromCell
/// \param cell_id Unique ID of a cell
/// \return Cell coordonate
/// \note This function is based on the grid. To get the reel position you need to multiply cell.x by the grid width,
/// same for cell.y: you need to multiply by the grid height.
///
sf::Vector2f Editor::cellFromUniqueID(int cell_id)
{
    sf::Vector2f cell(-1.f, -1.f);
    int row_width = m_level.levelData().width/m_level.levelData().grid_width;

    cell.x = cell_id%row_width;
    cell.y = cell_id/row_width;

    return cell;
}


///
/// \brief Function called right after sf::RenderWindow::create
///
void Editor::OnInit()
{
    m_view = sf::View(sf::Vector2f(getSize().x/2, getSize().y/2), sf::Vector2f(getSize().x, getSize().y));
}


///
/// \brief Function called each time the window is refresh. (Event Loop)
///
void Editor::OnUpdate()
{   
    emit fpsChanged(FPS());
    
    clear(sf::Color(20, 20, 40, 0));
    OnUpdateView();
    OnUpdateZoom();
    OnUpdateCurrentCell();
    OnUpdateToolAction();

    QSFML::setView(m_view);
    m_editorRender->displayGrid(this);
    if(m_tool == Tool_ID::Object_Create)
        m_editorRender->displayAsset(this);
    m_editorRender->displayCurrentCell(this);
    m_editorRender->displaySelection(this);
}


///
/// \brief Update Editor view position.
///
void Editor::OnUpdateView()
{
    sf::Vector2f viewPositionTarget(m_view.getCenter().x,
                                    m_view.getCenter().y);
    float factor = 1.f+(1.f-(m_viewZoom/100.f));

    // Horizontal movements
    if(isKeyPressed(Qt::Key_Left))
        viewPositionTarget.x += -1.f*factor;
    else if(isKeyPressed(Qt::Key_Right))
        viewPositionTarget.x += 1.f*factor;

    // Vertical movements
    if(isKeyPressed(Qt::Key_Up))
        viewPositionTarget.y += -1.f*factor;
    else if(isKeyPressed(Qt::Key_Down))
        viewPositionTarget.y += 1.f*factor;

    // Check for changes
    if(viewPositionTarget.x != m_view.getCenter().x ||
       viewPositionTarget.y != m_view.getCenter().y)
        setView(viewPositionTarget.x, viewPositionTarget.y);
}


///
/// \brief Update Editor view zoom.
///
void Editor::OnUpdateZoom()
{
    if(isMouseWheelForward())
        setZoom(m_viewZoom+10);
    else if(isMouseWheelBackward())
        setZoom(m_viewZoom-10);
}


///
/// \brief Update the current cell. (Mouse over)
///
void Editor::OnUpdateCurrentCell()
{
    sf::Vector2i mousePos(sf::Mouse::getPosition(*this));
    sf::Vector2f worldPos = mapPixelToCoords(mousePos, m_view);

    if((mousePos.x>0 && mousePos.x<static_cast<int>(getSize().x)) &&
       (mousePos.y>0 && mousePos.y<static_cast<int>(getSize().y)) &&
       (worldPos.x>0 && worldPos.x<static_cast<int>(m_level.levelData().width)) &&
       (worldPos.y>0 && worldPos.y<static_cast<int>(m_level.levelData().height)))
    {
        m_currentCell = sf::Vector2u(worldPos.x/m_level.levelData().grid_width,
                                     worldPos.y/m_level.levelData().grid_height);
        m_editorRender->currentCell(m_currentCell.x, m_currentCell.y);
        emit cellHoverChanged(m_currentCell.x, m_currentCell.y);
    }
}


///
/// \brief Call the function associate with the current selected Tool.
///
void Editor::OnUpdateToolAction()
{
    switch(m_tool)
    {
        case Tool_ID::Object_Select: Selection(SelectionMode::ArtObject); break;

        default: ;
    }
}


///
/// \brief Select tiles
/// \param mode Set the SelectionMode.
///
void Editor::Selection(SelectionMode mode)
{
    static bool dragAndDropActif(false);
    static sf::Vector2u initialDrag(0, 0);
    static sf::Vector2u initialDrop(0, 0);

    // Right-Click : Remove selection (or remove only the selected cell if clicked)
    if(isMouseButtonReleased(Qt::MouseButton::RightButton))
    {
        auto it = std::find(m_selection.begin(), m_selection.end(), m_currentCell);

        if(it == m_selection.end())
            m_selection.clear();
        else
            m_selection.erase(it);

        // EditorRender: Update selection !
        m_editorRender->setSelection(m_selection);
    }

    // Left-Click Pressed : Drag
    if(isMouseButtonPressed(Qt::MouseButton::LeftButton))
    {
        if(!dragAndDropActif)
        {
            dragAndDropActif = true;
            initialDrag = m_currentCell;
            initialDrop = sf::Vector2u(0, 0);
        }
        else
            m_selection.clear();

        initialDrop = m_currentCell;
        if(initialDrag.x == initialDrop.x)
        {
            sf::Vector2u restoreInitialDrag = initialDrag;
            // Vertical selection
            if(initialDrag.y > initialDrop.y)
            {
                sf::Vector2u tmp = initialDrag;
                initialDrag = initialDrop;
                initialDrop = tmp;
            }

            for(unsigned int y=initialDrag.y; y<=initialDrop.y; ++y)
                m_selection.push_back(sf::Vector2u(initialDrag.x, y));

            initialDrag = restoreInitialDrag;
        }
        else if(initialDrag.y == initialDrop.y)
        {
            sf::Vector2u restoreInitialDrag = initialDrag;
            // Horizontal selection
            if(initialDrag.x > initialDrop.x)
            {
                sf::Vector2u tmp = initialDrag;
                initialDrag = initialDrop;
                initialDrop = tmp;
            }

            for(unsigned int x=initialDrag.x; x<=initialDrop.x; ++x)
                m_selection.push_back(sf::Vector2u(x, initialDrag.y));

            initialDrag = restoreInitialDrag;
        }
        else
        {
            sf::Vector2u restoreInitialDrag = initialDrag;
            // Area selection
            if(initialDrag.x > initialDrop.x && initialDrag.y > initialDrop.y)
            {
                sf::Vector2u tmp = initialDrag;
                initialDrag = initialDrop;
                initialDrop = tmp;
            }
            else if(initialDrag.x < initialDrop.x && initialDrag.y > initialDrop.y)
            {
                unsigned int tmp(initialDrag.y);
                initialDrag.y = initialDrop.y;
                initialDrop.y = tmp;
            }
            else if(initialDrag.x > initialDrop.x && initialDrag.y < initialDrop.y)
            {
                unsigned int tmp(initialDrag.x);
                initialDrag.x = initialDrop.x;
                initialDrop.x = tmp;
            }

            for(unsigned int x=initialDrag.x; x<=initialDrop.x; ++x)
            {
                for(unsigned int y=initialDrag.y; y<=initialDrop.y; ++y)
                    m_selection.push_back(sf::Vector2u(x, y));
            }
            initialDrag = restoreInitialDrag;
        }

        // EditorRender: Update selection !
        m_editorRender->setSelection(m_selection);
    }

    // Left-Click Released : Drop
    if(isMouseButtonReleased(Qt::MouseButton::LeftButton))
    {
        if(dragAndDropActif)
        {
            dragAndDropActif = false;
            initialDrag = sf::Vector2u(0, 0);
            initialDrop = sf::Vector2u(0, 0);
        }
    }
}


/***************************************************************************************************
 * PRIVATE SLOTS
 */
///
/// \brief Update tool ID
/// \param id New active tool
///
void Editor::updateToolID(Tool_ID id)
{
    m_tool = id;
}


///
/// \brief Update level
/// \param level New active level
///
void Editor::updateLevel(Level level)
{
    m_level = level;
    
    // Create Editor Render
    delete m_editorRender;
    m_editorRender = new EditorRender(m_level);

    resetZoom();
    resetView();

    // Load assets
    DAT &dat(m_level.levelData().assets);

    m_assets.clear();
    for(unsigned int i=0; i<dat.count(); ++i)
    {
        std::string data_string(dat.file(dat.fileNameByIndex(i)));
        unsigned int data_size(data_string.size());
        char data[data_size];
        for(unsigned int s=0; s<data_size; ++s)
            data[s] = data_string[s];

        sf::Texture tx;
        tx.loadFromMemory(reinterpret_cast<void*>(&data), data_size);

        m_assets[dat.fileNameByIndex(i)] = tx;
    }

    // Load ArtObject
    m_level.levelData().artObject.push_back(ArtObject(Point(0.f, 0.f), "tiles__0000_Calque-1.png"));
    for(unsigned int i=0; i<m_level.levelData().artObject.size(); ++i)
    {
        bool load(true);
        ArtObject art(m_level.levelData().artObject.at(i));

        if(m_assets.count(art.asset()) == 0)
        {
            std::cout << "ArtObject #" << i << ": Invalid asset !" << std::endl;
            std::cout << "\tAsset: " << art.asset() << std::endl;
            load = false;
        }

        if((art.position().x() > m_level.levelData().width || art.position().x() < 0.f) ||
            (art.position().y() > m_level.levelData().height || art.position().y() < 0.f))
        {
            std::cout << "ArtObject #" << i << ": Invalid position !" << std::endl;
            std::cout << "\tPosition: " << art.position().x() << ", " << art.position().y() << std::endl;
            std::cout << "\tLevel: "  << m_level.levelData().width << ", " << m_level.levelData().height << std::endl;
            load = false;
        }

        if(load)
            m_editorRender->setArtObject(art.position(), &m_assets[art.asset()]);
    }
}


void Editor::updateSelectedAsset(std::string str)
{
    m_selectedAsset = str;

    m_editorRender->setAsset(&m_assets[str]);
}
