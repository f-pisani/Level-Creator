#ifndef DRAGANDDROP_HPP
#define DRAGANDDROP_HPP

#include <vector>
#include <SFML/Graphics.hpp>

struct DragAndDrop
{
    sf::Vector2i start;
    sf::Vector2i stop;
    
    std::vector<sf::Vector2i> getCells()
    {
        std::vector<sf::Vector2i> cells;
        for(int x=start.x; x<stop.x; ++x)
        {
            for(int y=start.y; y<stop.y; ++y)
                cells.push_back(sf::Vector2i(x, y));
        }
        
        return cells;
    }
};

#endif // DRAGANDDROP_HPP

