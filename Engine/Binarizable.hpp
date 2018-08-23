#ifndef BINARIZABLE_HPP
#define BINARIZABLE_HPP

#include <string>
#include <sstream>

class Binarizable
{
    public:
        Binarizable();
        ~Binarizable();
        virtual std::string writeToBinary() = 0;
        virtual bool loadFromBinary(std::string str) = 0;
};

#endif // BINARIZABLE_HPP
