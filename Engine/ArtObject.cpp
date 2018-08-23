#include "ArtObject.hpp"

/***************************************************************************************************
 * PUBLIC METHODS
 */
ArtObject::ArtObject() :
    m_pos(Point(0.f, 0.f)), m_asset("")
{
    
}


ArtObject::ArtObject(Point p) :
    m_pos(p), m_asset("")
{
    
}


ArtObject::ArtObject(Point p, std::string asset) :
    m_pos(p), m_asset(asset)
{
    
}


ArtObject::ArtObject(const ArtObject& obj) :
    m_pos(obj.m_pos), m_asset(obj.m_asset)
{
    
}


ArtObject& ArtObject::operator=(const ArtObject& obj)
{
    m_pos = obj.m_pos;
    m_asset = obj.m_asset;
    
    return *this;
}


ArtObject::~ArtObject()
{
    
}


std::string ArtObject::writeToBinary()
{
    std::string bPos(m_pos.writeToBinary()), bAsset(m_asset);
    unsigned int bPosSize(bPos.size()), bAssetSize(bAsset.size());
    
    std::stringstream ss(std::ios_base::out);
    ss.write(reinterpret_cast<char*>(&bPosSize), sizeof(bPosSize));
    ss.write(bPos.c_str(), sizeof(char)*bPosSize);
    ss.write(reinterpret_cast<char*>(&bAssetSize), sizeof(bAssetSize));
    ss.write(bAsset.c_str(), sizeof(char)*bAssetSize);
    
    return ss.str();
}


bool ArtObject::loadFromBinary(std::string str)
{
    std::string bPos(""), bAsset("");
    unsigned int bPosSize(0), bAssetSize(0);
    
    std::stringstream ss(str, std::ios_base::in);
    ss.read(reinterpret_cast<char*>(&bPosSize), sizeof(bPosSize));
    for(unsigned int i=0; i<bPosSize; ++i)
        bPos += ss.get();
    
    ss.read(reinterpret_cast<char*>(&bAssetSize), sizeof(bAssetSize));
    for(unsigned int i=0; i<bAssetSize; ++i)
        bAsset += ss.get();
    
    if(m_pos.loadFromBinary(bPos) && !ss.bad() && !ss.fail())
        return true;
    else
    {
        m_pos = Point(0.f, 0.f);
        m_asset = -1;
        
        return false;
    }
}
