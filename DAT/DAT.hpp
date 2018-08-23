#ifndef DAT_HPP
#define DAT_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class DAT
{
    std::map<std::string, std::string> m_storedFile;

    public:
        DAT();
        DAT(const DAT& dat);
        DAT& operator=(const DAT& dat);
        ~DAT();
        
        static std::string fileName(std::string path);
        bool loadFromFile(std::string filename);
        bool loadFromStream(std::string str);
        bool saveToFile(std::string filename);
        std::string saveToStream();
        void clear();

        bool add(std::string filename);
        bool add(std::string filename, std::string data);
        bool rename(std::string cur_name, std::string new_name);
        bool remove(std::string name);

        bool exists(std::string name);
        unsigned int fileSize(std::string name);
        std::string file(std::string name);
        std::string fileNameByIndex(unsigned int index);
        inline unsigned int count(){ return m_storedFile.size(); }
};

#endif // DAT_HPP
