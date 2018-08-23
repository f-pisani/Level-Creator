#include "Collider.hpp"

/***************************************************************************************************
 * PUBLIC METHODS
 */
Collider::Collider() :
    m_pos(Point()),
    m_size(Size())
{
}


Collider::Collider(Point p, Size s) :
    m_pos(p),
    m_size(s)
{  
}


Collider::Collider(const Collider& c) :
    m_pos(c.m_pos), m_size(c.m_size)
{
}


Collider&Collider::operator=(const Collider& c)
{
    m_pos = c.m_pos;
    m_size = c.m_size;
    
    return *this;
}


Collider::~Collider()
{
    
}


bool Collider::collide(Collider c)
{
	if((c.position().x() >= m_pos.x() + m_size.w())
	 || (c.position().x() + c.size().w() <= m_pos.x())
	 || (c.position().y() >= m_pos.y() + m_size.h())
	 || (c.position().y() + c.size().h() <= m_pos.y()))
		   return false; 
	else
		   return true;    
}


bool Collider::collide(Point p)
{
    if((p.x() >= m_pos.x())
       && (p.x() <= m_pos.x()+m_size.w())
       && (p.y() >= m_pos.y())
       && (p.y() <= m_pos.y()+m_size.h()))
        return true;
    else
        return false;
}


std::string Collider::writeToBinary()
{
    std::string bPoint(m_pos.writeToBinary()), bSize(m_size.writeToBinary());
    unsigned int bPointLen(bPoint.size()), bSizeLen(bSize.size());
    
    std::stringstream ss(std::ios_base::out);
    ss.write(reinterpret_cast<char*>(&bPointLen), sizeof(bPointLen));
    ss.write(bPoint.c_str(), sizeof(char)*bPointLen);
    ss.write(reinterpret_cast<char*>(&bSizeLen), sizeof(bSizeLen));
    ss.write(bSize.c_str(), sizeof(char)*bSizeLen);
    
    return ss.str();
}


bool Collider::loadFromBinary(std::string str)
{
    std::string bPoint(""), bSize("");
    unsigned int bPointLen(0), bSizeLen(0);
    
    std::stringstream ss(str, std::ios_base::in);
    // Point
    ss.read(reinterpret_cast<char*>(&bPointLen), sizeof(bPointLen));
    for(unsigned int i=0; i<bPointLen; ++i)
        bPoint += ss.get();
    
    // Size
    ss.read(reinterpret_cast<char*>(&bSizeLen), sizeof(bSizeLen));
    for(unsigned int i=0; i<bSizeLen; ++i)
        bSize += ss.get();
    
    // Load
    if(m_pos.loadFromBinary(bPoint) && m_size.loadFromBinary(bSize))
        return true;
    else
        return false;
}
