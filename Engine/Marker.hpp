#ifndef MARKER_HPP
#define MARKER_HPP

#include <sstream>

#include "Binarizable.hpp"
#include "Point.hpp"

class Marker : public Binarizable
{
    public:
        Marker();
        Marker(std::string name, Point p);
        Marker(const Marker& marker);
        Marker& operator=(const Marker& marker);
        ~Marker();
        
        std::string writeToBinary();
        bool loadFromBinary(std::string str);
        
        inline std::string name(){ return m_name; }
        inline Point position(){ return m_pos; }
        inline void setName(std::string name){ m_name = name; }
        inline void setPosition(Point p){ m_pos = p; }
        
    private:
        std::string m_name;
        Point m_pos;
};

#endif // MARKER_HPP
