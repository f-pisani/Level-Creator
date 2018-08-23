#ifndef COLLIDER_HPP
#define COLLIDER_HPP

#include <iostream>
#include <sstream>

#include "Binarizable.hpp"
#include "Point.hpp"
#include "Size.hpp"

/***************************************************************************************************
 * Collider: Collider is an object with a position (Point) and a size (Size) in a 2D space
 */
class Collider : public Binarizable
{
    public:
        Collider();
        Collider(Point p, Size s);
        Collider(const Collider& c);
        Collider& operator=(const Collider& c);
        ~Collider();
        
        bool collide(Collider c);
        bool collide(Point p);
        
        std::string writeToBinary();
        bool loadFromBinary(std::string str);
        
        inline Point position(){ return m_pos; }
        inline Size size(){ return m_size; }
        inline void setPosition(Point p){ m_pos = p; }
        inline void setSize(Size s){ m_size = s; }
        
    private:
        Point m_pos;
        Size m_size;
};

#endif // COLLIDER_HPP
