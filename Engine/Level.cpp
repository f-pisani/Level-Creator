#include "Level.hpp"

/***************************************************************************************************
 * PUBLIC METHODS
 */
Level::Level() :
    m_levelData()
{
}


Level::Level(const Level& level) :
    m_levelData(level.m_levelData)
{ 
}


Level::Level(LevelData levelData) :
    m_levelData(levelData)
{
}


Level& Level::operator=(const Level& level)
{
    clear();
    m_levelData = level.m_levelData;
    
    return *this;
}


Level& Level::operator=(LevelData levelData)
{
    clear();
    m_levelData = levelData;
    
    return *this;
}


Level::~Level()
{
}


bool Level::saveToFile(std::string path)
{
    std::fstream file(path.c_str(), std::fstream::out | std::fstream::trunc | std::fstream::binary);
    
    if(file.is_open())
    {
        LevelHelper levelHelper(m_levelData.helper());
        
        file.write(reinterpret_cast<char*>(&m_levelData.width), sizeof(m_levelData.width));
        file.write(reinterpret_cast<char*>(&m_levelData.height), sizeof(m_levelData.height));
        file.write(reinterpret_cast<char*>(&m_levelData.grid_width), sizeof(m_levelData.grid_width));
        file.write(reinterpret_cast<char*>(&m_levelData.grid_height), sizeof(m_levelData.grid_height));
        // DAT
        std::string dat_str(m_levelData.assets.saveToStream());
        unsigned int dat_size(dat_str.size());
        file.write(reinterpret_cast<char*>(&dat_size), sizeof(dat_size));
        file.write(dat_str.c_str(), sizeof(char)*dat_size);
        
        // Art Object
        file.write(reinterpret_cast<char*>(&levelHelper.artObject_count), sizeof(levelHelper.artObject_count));
        for(unsigned int i=0; i<m_levelData.artObject.size(); ++i)
        {
            std::string binary(m_levelData.artObject[i].writeToBinary());
            unsigned int binarySize(binary.size());
            
            file.write(reinterpret_cast<char*>(&binarySize), sizeof(binarySize));
            file.write(binary.c_str(), sizeof(char)*binarySize);
        }
        
        // Collider
        // Marker
        // Trigger
        
        file.close();
        return true;
    }
    else
        return false;
}


bool Level::loadFromFile(std::string path)
{
    std::fstream file(path.c_str(), std::fstream::in | std::fstream::binary);
    
    if(file.is_open())
    {
        clear();
        LevelHelper levelHelper;
        
        file.read(reinterpret_cast<char*>(&m_levelData.width), sizeof(m_levelData.width));
        file.read(reinterpret_cast<char*>(&m_levelData.height), sizeof(m_levelData.height));
        file.read(reinterpret_cast<char*>(&m_levelData.grid_width), sizeof(m_levelData.grid_width));
        file.read(reinterpret_cast<char*>(&m_levelData.grid_height), sizeof(m_levelData.grid_height));
        // DAT
        std::string dat_str("");
        unsigned int dat_size(0);
        file.read(reinterpret_cast<char*>(&dat_size), sizeof(dat_size));
        for(unsigned int i=0; i<dat_size; ++i)
            dat_str += file.get();
        m_levelData.assets.loadFromStream(dat_str);
        
        // Art Object
        file.read(reinterpret_cast<char*>(&levelHelper.artObject_count), sizeof(levelHelper.artObject_count));
        for(unsigned int i=0; i<levelHelper.artObject_count; ++i)
        {
            ArtObject art;
            std::string binary("");
            unsigned int binarySize(0);
            
            file.read(reinterpret_cast<char*>(&binarySize), sizeof(binarySize));
            for(unsigned int r=0; r<binarySize; ++r)
                binary += file.get();
            
            art.loadFromBinary(binary);
            
            m_levelData.artObject.push_back(art);
        }
        
        // Collider
        // Marker
        // Trigger
        
        file.close();
        return true;
    }
    else
        return false;    
}


/***************************************************************************************************
 * PRIVATE METHODS
 */
void Level::clear()
{
    m_levelData = LevelData();
}
