#include "Point.hpp"

/***************************************************************************************************
 * PUBLIC METHODS
 */
Point::Point() :
    m_x(0.f), m_y(0.f){}


Point::Point(float x, float y) :
    m_x(x), m_y(y){}


Point::Point(const Point& p) :
    m_x(p.m_x), m_y(p.m_y){}


Point& Point::operator=(const Point& p)
{
    m_x = p.m_x;
    m_y = p.m_y;
    
    return *this;
}


Point::~Point()
{
    
}


bool Point::operator==(const Point& p)
{
    if(p.m_x == m_x && p.m_y == m_y)
        return true;
    else
        return false;
}


bool Point::operator!=(const Point& p)
{
    if(p.m_x != m_x || p.m_y != m_y)
        return true;
    else
        return false;
}


Point Point::operator+(const Point& p)
{
    Point newP(m_x+p.x(), m_y+p.y());
    
    return newP;
}

Point& Point::operator+=(const Point& p)
{
    m_x += p.x();
    m_y += p.y();
    
    return *this;    
}


Point Point::operator-(const Point& p)
{
    Point newP(m_x-p.x(), m_y-p.y());
    
    return newP;
}

Point& Point::operator-=(const Point& p)
{
    m_x -= p.x();
    m_y -= p.y();
    
    return *this;    
}


std::string Point::writeToBinary()
{
    std::stringstream ss(std::ios_base::out);
    ss.write(reinterpret_cast<char*>(&m_x), sizeof(m_x));
    ss.write(reinterpret_cast<char*>(&m_y), sizeof(m_y));
    
    return ss.str();
}


bool Point::loadFromBinary(std::string str)
{
    std::stringstream ss(str, std::ios_base::in);
    ss.read(reinterpret_cast<char*>(&m_x), sizeof(m_x));
    ss.read(reinterpret_cast<char*>(&m_y), sizeof(m_y));
    
    if(ss.bad() || ss.fail())
    {
        m_x = 0.f;
        m_y = 0.f;
        
        return false;
    }
    else
        return true;
}


float Point::distance(Point p) const
{
    return std::sqrt((m_x-p.m_x)*(m_x-p.m_x)+(m_y-p.m_y)*(m_y-p.m_y));
}
