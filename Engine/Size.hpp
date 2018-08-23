#ifndef SIZE_HPP
#define SIZE_HPP

#include <sstream>

#include "Binarizable.hpp"

/***************************************************************************************************
 * Size: Width and Height
 */
class Size : public Binarizable
{
    float m_w, m_h;
    
    public:
        Size();
        Size(float w, float h);
        Size(const Size& s);
        Size& operator=(const Size& s);
        ~Size();
        
        bool operator>=(Size s);
        bool operator<=(Size s);
        bool operator>(Size s);
        bool operator<(Size s);
        bool operator==(Size s);
        bool operator!=(Size s);
        
        std::string writeToBinary();
        bool loadFromBinary(std::string str);
        
        inline float area(){ return m_w*m_h; }
        inline float w(){ return m_w; }
        inline float h(){ return m_h; }
        inline void setW(float w){ m_w = w; }
        inline void setH(float h){ m_h = h; }
};

#endif // SIZE_HPP
