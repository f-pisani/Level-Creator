#ifndef TRIGGER_HPP
#define TRIGGER_HPP

#include <sstream>

#include "Binarizable.hpp"
#include "Collider.hpp"

class Trigger : public Binarizable
{
    public:
        Trigger();
        Trigger(std::string name, Collider collider);
        Trigger(const Trigger& trigger);
        Trigger& operator=(const Trigger& trigger);
        ~Trigger();
        
        std::string writeToBinary();
        bool loadFromBinary(std::string str);
        
        inline std::string name(){ return m_name; }
        inline Collider collider(){ return m_collider; }
        inline void setName(std::string name){ m_name = name; }
        inline void setCollider(Collider collider){ m_collider = collider; }
        
    private:
        std::string m_name;
        Collider m_collider;
};

#endif // TRIGGER_HPP
