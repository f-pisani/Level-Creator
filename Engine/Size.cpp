#include "Size.hpp"

/***************************************************************************************************
 * PUBLIC METHODS
 */
Size::Size() :
    m_w(0.f), m_h(0.f){}


Size::Size(float w, float h) :
    m_w(w), m_h(h){}


Size::Size(const Size& s) :
    m_w(s.m_w), m_h(s.m_h){}


Size& Size::operator=(const Size& s)
{
    m_w = s.m_w;
    m_h = s.m_h;
    
    return *this;
}


Size::~Size()
{
}


bool Size::operator>=(Size s)
{
    if(s.area() >= area())
        return true;
    else
        return false;
}


bool Size::operator<=(Size s)
{
    if(s.area() <= area())
        return true;
    else
        return false;
}


bool Size::operator>(Size s)
{
    if(s.area() > area())
        return true;
    else
        return false;
}


bool Size::operator<(Size s)
{
    if(s.area() < area())
        return true;
    else
        return false;
}


bool Size::operator==(Size s)
{
    if(s.area() == area())
        return true;
    else
        return false;
}


bool Size::operator!=(Size s)
{
    if(s.area() != area())
        return true;
    else
        return false;
}


std::string Size::writeToBinary()
{
    std::stringstream ss(std::ios_base::out);
    ss.write(reinterpret_cast<char*>(&m_w), sizeof(m_w));
    ss.write(reinterpret_cast<char*>(&m_h), sizeof(m_h));
    
    return ss.str();
}


bool Size::loadFromBinary(std::string str)
{
    std::stringstream ss(str, std::ios_base::in);
    ss.read(reinterpret_cast<char*>(&m_w), sizeof(m_w));
    ss.read(reinterpret_cast<char*>(&m_h), sizeof(m_h));
    
    if(ss.fail() || ss.bad())
    {
        m_w = 0.f;
        m_h = 0.f;
        
        return false;
    }
    else
        return true;
}
