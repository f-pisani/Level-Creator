#ifndef ARTOBJECT_HPP
#define ARTOBJECT_HPP

#include <sstream>

#include "Binarizable.hpp"
#include "Point.hpp"

class ArtObject : public Binarizable
{
    Point m_pos;
    std::string m_asset;
    
    public:
        ArtObject();
        ArtObject(Point p);
        ArtObject(Point p, std::string asset);
        ArtObject(const ArtObject& obj);
        ArtObject& operator=(const ArtObject& obj);
        ~ArtObject();
        
        std::string writeToBinary();
        bool loadFromBinary(std::string str);
        
        inline Point position(){ return m_pos; }
        inline std::string asset(){ return m_asset; }
        inline void setPosition(Point p){ m_pos = p; }
        inline void setAsset(std::string asset){ m_asset = asset; }
};

#endif // ARTOBJECT_HPP
