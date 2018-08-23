#include "Trigger.hpp"

/***************************************************************************************************
 * PUBLIC METHODS
 */
Trigger::Trigger() :
    m_name(""), m_collider(Collider(Point(0.f, 0.f), Size(0.f, 0.f)))
{
}


Trigger::Trigger(std::string name, Collider collider) :
    m_name(name), m_collider(collider)
{ 
}


Trigger::Trigger(const Trigger& trigger) :
    m_name(trigger.m_name), m_collider(trigger.m_collider)
{
}


Trigger& Trigger::operator=(const Trigger& trigger)
{
    m_name = trigger.m_name;
    m_collider = trigger.m_collider;
    
    return *this;
}


Trigger::~Trigger()
{
}


std::string Trigger::writeToBinary()
{
    std::string bName(m_name), bCollider(m_collider.writeToBinary());
    unsigned int bNameLen(bName.size()), bColliderLen(bCollider.size());
    
    std::stringstream ss(std::ios_base::out);
    ss.write(reinterpret_cast<char*>(&bNameLen), sizeof(bNameLen));
    ss.write(bName.c_str(), sizeof(char)*bNameLen);
    ss.write(reinterpret_cast<char*>(&bColliderLen), sizeof(bColliderLen));
    ss.write(bCollider.c_str(), sizeof(char)*bColliderLen);
    
    return ss.str();
}


bool Trigger::loadFromBinary(std::string str)
{
    std::string bName(m_name), bCollider(m_collider.writeToBinary());
    unsigned int bNameLen(bName.size()), bColliderLen(bCollider.size());
    
    std::stringstream ss(str, std::ios_base::in);
    // Name
    ss.read(reinterpret_cast<char*>(&bNameLen), sizeof(bNameLen));
    for(unsigned int i=0; i<bNameLen; ++i)
        bName += ss.get();
        
    // Collider
    ss.read(reinterpret_cast<char*>(&bColliderLen), sizeof(bColliderLen));
    for(unsigned int i=0; i<bColliderLen; ++i)
        bCollider += ss.get();
    
    if(m_collider.loadFromBinary(bCollider) && !ss.fail() && !ss.bad())
    {
        m_name = bName;
        return true;
    }
    else
        return false;
}
