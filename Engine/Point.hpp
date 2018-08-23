#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>

#include "Binarizable.hpp"

/***************************************************************************************************
 * Point : Coordinates 2D
 */
class Point : public Binarizable
{
    float m_x, m_y;
    
    public:
        Point();
        Point(float Px, float Py);
        Point(const Point& p);
        Point& operator=(const Point& p);
        ~Point();
        
        bool operator==(const Point& p);
        bool operator!=(const Point& p);
        Point operator+(const Point& p);
        Point& operator+=(const Point& p);
        Point operator-(const Point& p);
        Point& operator-=(const Point& p);
        
        std::string writeToBinary();
        bool loadFromBinary(std::string str);
        
        float distance(Point p) const;
        inline float x() const { return m_x; }
        inline float y() const { return m_y; }
        inline void setX(float x){ m_x = x; }
        inline void setY(float y){ m_y = y; }
};

#endif // POINT_HPP
