#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <iostream>
#include <fstream>
//#include <sstream>
#include <vector>

#include "../Dat/DAT.hpp"

#include "Point.hpp"
#include "Size.hpp"
#include "ArtObject.hpp"
#include "Collider.hpp"
#include "Marker.hpp"
#include "Trigger.hpp"

struct LevelHelper
{
    unsigned int artObject_count;
    unsigned int collider_count;
    unsigned int marker_count;
    unsigned int trigger_count;
};


struct LevelData
{
    DAT assets;
    std::vector<ArtObject> artObject;
    std::vector<Collider> collider;
    std::vector<Marker> marker;
    std::vector<Trigger> trigger;
    unsigned int width;
    unsigned int height;
    unsigned int grid_width;
    unsigned int grid_height;
    
    LevelData() :
        assets(),
        artObject(),
        collider(),
        marker(),
        trigger(),
        width(0),
        height(0),
        grid_width(0),
        grid_height(0)
    {
    }
    
    LevelHelper helper()
    {
        LevelHelper h;
        h.artObject_count = artObject.size();
        h.collider_count = collider.size();
        h.marker_count = marker.size();
        h.trigger_count = trigger.size();
        
        return h;
    }
};

class Level
{
    public:
        Level();
        Level(const Level& level);
        Level(LevelData levelData);
        Level& operator=(const Level& level);
        Level& operator=(LevelData levelData);
        ~Level();
        
        void clear();
        
        bool saveToFile(std::string path);
        //std::string saveToStream();
        bool loadFromFile(std::string path);
        //bool loadFromStream(std::string str);
        
        inline LevelData& levelData(){ return m_levelData; }
        inline void setLevelData(LevelData levelData){ m_levelData = levelData; }
        
    private:
        LevelData m_levelData;
};

#endif // LEVEL_HPP

