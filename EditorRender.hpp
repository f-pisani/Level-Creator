#ifndef EDITORRENDER_HPP
#define EDITORRENDER_HPP

#include <vector>
#include <SFML/Graphics.hpp>

#include "Engine/Level.hpp"

struct DrawRenderTxHelper // SmartRenderTexture
{
    sf::RenderTexture tx;
    sf::Sprite sprite;
};


class EditorRender
{
    void updateGridLimits();

    // Level data
    Level& m_level;
    // Editor rendered
    sf::RenderTexture m_rendered;
    // Editor stuff (Grid, World limits, Current cell, Current selection, ...)
    DrawRenderTxHelper m_levelGridLimits;
    sf::RectangleShape m_currentCell;
    std::vector<sf::RectangleShape> m_selection;
    sf::Sprite m_asset;
    // Art Object
    bool m_artObjectRequireUpdate;
    std::vector<sf::Sprite> m_artObjectUpdateQueue;
    DrawRenderTxHelper m_artObject;

    public:
        EditorRender(Level& level);
        ~EditorRender();

        void displayGrid(sf::RenderTarget* target);
        void displayCurrentCell(sf::RenderTarget* target);
        void displaySelection(sf::RenderTarget* target);
        void displayAsset(sf::RenderTarget* target);

        void currentCell(unsigned int x, unsigned int y);
        void setSelection(std::vector<sf::Vector2u> selection);
        void setAsset(sf::Texture* tx);
        void setArtObject(Point position, sf::Texture* tx);
};

#endif // EDITORRENDER_HPP
