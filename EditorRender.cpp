#include "EditorRender.hpp"

/***************************************************************************************************
 * PUBLIC METHODS
 */
EditorRender::EditorRender(Level& level) :
    m_level(level),
    m_rendered(),
    m_levelGridLimits(),
    m_currentCell(),
    m_selection(),
    m_asset()
{
    // Level : Grid and limits
    m_levelGridLimits.tx.create(m_level.levelData().width+1, m_level.levelData().height+1);
    m_levelGridLimits.tx.setSmooth(true);
    m_levelGridLimits.tx.clear(sf::Color(20, 20, 40, 0));

    updateGridLimits();

    // Level : Current cell
    m_currentCell.setSize(sf::Vector2f(m_level.levelData().grid_width+1.f, m_level.levelData().grid_height+1.f));
    m_currentCell.setFillColor(sf::Color(100, 100, 255, 75));
    m_currentCell.setOutlineColor(sf::Color::Blue);
    m_currentCell.setOutlineThickness(1.5f);

    // Level : ArtObject
    m_artObject.tx.create(m_level.levelData().width+1, m_level.levelData().height+1);
    m_artObject.tx.clear(sf::Color(20, 20, 40, 0));
}


EditorRender::~EditorRender()
{

}


void EditorRender::displayGrid(sf::RenderTarget *target)
{
    target->draw(m_artObject.sprite);
    target->draw(m_levelGridLimits.sprite);
}


void EditorRender::displayCurrentCell(sf::RenderTarget *target)
{
    target->draw(m_currentCell);
}


void EditorRender::displaySelection(sf::RenderTarget *target)
{
    for(size_t i=0; i<m_selection.size(); ++i)
        target->draw(m_selection[i]);
}


void EditorRender::displayAsset(sf::RenderTarget* target)
{
    target->draw(m_asset);
}


void EditorRender::currentCell(unsigned int x, unsigned int y)
{
    m_currentCell.setPosition(x*m_level.levelData().grid_width,
                              y*m_level.levelData().grid_height);

    m_asset.setPosition(x*m_level.levelData().grid_width,
                        y*m_level.levelData().grid_height);
}


void EditorRender::setSelection(std::vector<sf::Vector2u> selection)
{
    m_selection.clear();

    for(size_t i=0; i<selection.size(); ++i)
    {
        sf::RectangleShape shape;
        shape.setSize(sf::Vector2f(m_level.levelData().grid_width+1.f, m_level.levelData().grid_height+1.f));
        shape.setFillColor(sf::Color(100, 100, 255, 75));
        shape.setPosition(selection[i].x*m_level.levelData().grid_width,
                          selection[i].y*m_level.levelData().grid_height);

        m_selection.push_back(shape);
    }
}


void EditorRender::setAsset(sf::Texture *tx)
{
    m_asset.setTexture(*tx, true);
}


void EditorRender::setArtObject(Point position, sf::Texture *tx)
{
    sf::Sprite art;
    art.setTexture(*tx, true);
    art.setPosition(position.x(), position.y());

    m_artObject.tx.draw(art);
    m_artObject.tx.display();

    m_artObject.sprite.setTexture(m_artObject.tx.getTexture(), true);
}


/***************************************************************************************************
 * PRIVATE METHODS
 */
void EditorRender::updateGridLimits()
{
    // Level : Grid
    if(m_level.levelData().width != 0 && m_level.levelData().height != 0 &&
       m_level.levelData().grid_width != 0 && m_level.levelData().grid_height != 0)
    {
        sf::VertexArray line(sf::PrimitiveType::Lines, 2);
        line[0].color = sf::Color(50, 140, 80);
        line[1].color = sf::Color(50, 140, 80);

        unsigned int cols_count = (m_level.levelData().width/m_level.levelData().grid_width);

        unsigned int rows_count = (m_level.levelData().height/m_level.levelData().grid_height);

        for(unsigned int x=0; x<=cols_count; ++x)
        {
            line[0].position = sf::Vector2f(x*m_level.levelData().grid_width+0.5f, 0.5f);
            line[1].position = sf::Vector2f(x*m_level.levelData().grid_width+0.5f, m_level.levelData().height+0.5f);

            m_levelGridLimits.tx.draw(line);
        }

        for(unsigned int y=0; y<=rows_count; ++y)
        {
            line[0].position = sf::Vector2f(0.5f, y*m_level.levelData().grid_height+0.5f);
            line[1].position = sf::Vector2f(m_level.levelData().width+0.5f, y*m_level.levelData().grid_height+0.5f);

            m_levelGridLimits.tx.draw(line);
        }

        // Level : Limits
        sf::VertexArray levelLimits(sf::PrimitiveType::LinesStrip, 5);
        levelLimits[0].color = sf::Color(250, 50, 50);
        levelLimits[1].color = sf::Color(250, 50, 50);
        levelLimits[2].color = sf::Color(250, 50, 50);
        levelLimits[3].color = sf::Color(250, 50, 50);
        levelLimits[4].color = sf::Color(250, 50, 50);

        levelLimits[0].position = sf::Vector2f(0.5f, 0.5f);
        levelLimits[1].position = sf::Vector2f(m_level.levelData().width+0.5f, 0.5f);
        levelLimits[2].position = sf::Vector2f(m_level.levelData().width+0.5f, m_level.levelData().height+0.5f);
        levelLimits[3].position = sf::Vector2f(0.5f, m_level.levelData().height+0.5f);
        levelLimits[4].position = levelLimits[0].position;

        m_levelGridLimits.tx.draw(levelLimits);
    }

    m_levelGridLimits.tx.display();
    m_levelGridLimits.sprite.setTexture(m_levelGridLimits.tx.getTexture(), true);
    m_levelGridLimits.sprite.setPosition(0.f, 0.f);
}
