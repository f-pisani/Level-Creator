#include "Marker.hpp"

/***************************************************************************************************
 * PUBLIC METHODS
 */
Marker::Marker() :
    m_name(""), m_pos(Point(0.f, 0.f))
{
}


Marker::Marker(std::string name, Point p) :
    m_name(name), m_pos(p)
    
{ 
}


Marker::Marker(const Marker& marker) :
    m_name(marker.m_name), m_pos(marker.m_pos)
{
}


Marker& Marker::operator=(const Marker& marker)
{ 
    m_name = marker.m_name;
    m_pos = marker.m_pos;
    
    return *this;
}


Marker::~Marker()
{
}


std::string Marker::writeToBinary()
{
    std::string bName(m_name), bPos(m_pos.writeToBinary());
    unsigned int bNameLen(bName.size()), bPosLen(bPos.size());
    
    std::stringstream ss(std::ios_base::out);
    ss.write(reinterpret_cast<char*>(&bNameLen), sizeof(bNameLen));
    ss.write(bName.c_str(), sizeof(char)*bNameLen);
    ss.write(reinterpret_cast<char*>(&bPosLen), sizeof(bPosLen));
    ss.write(bPos.c_str(), sizeof(char)*bPosLen);
    
    return ss.str();
}


bool Marker::loadFromBinary(std::string str)
{
    std::string bName(""), bPos("");
    unsigned int bNameLen(0), bPosLen(0);
    
    std::stringstream ss(str, std::ios_base::in);
    // Name
    ss.read(reinterpret_cast<char*>(&bNameLen), sizeof(bNameLen));
    for(unsigned int i=0; i<bNameLen; ++i)
        bName += ss.get();
    
    // Point
    ss.read(reinterpret_cast<char*>(&bPosLen), sizeof(bPosLen));
    for(unsigned int i=0; i<bPosLen; ++i)
        bPos += ss.get();
    
    // Load
    if(m_pos.loadFromBinary(bPos) && !ss.bad() && !ss.fail())
    {
        m_name = bName;
        
        return true;            
    }
    else
        return false;
}
