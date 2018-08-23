#include "DAT.hpp"


/***************************************************************************************************
 * STATIC METHODS
 */
std::string DAT::fileName(std::string path)
{
    const size_t last_slash_dir = path.find_last_of("\\/");
    
    return path.substr(last_slash_dir+1);
}


/***************************************************************************************************
 * PUBLIC METHODS
 */
DAT::DAT() :
    m_storedFile()
{
}


DAT::DAT(const DAT& dat) :
    m_storedFile(dat.m_storedFile)
{
}


DAT&DAT::operator=(const DAT& dat)
{
    clear();
    m_storedFile = dat.m_storedFile;
    
    return *this;
}


DAT::~DAT()
{
    m_storedFile.clear();
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// LOAD
bool DAT::loadFromFile(std::string filename)
{
    unsigned int file_count(0);

    std::fstream file(filename.c_str(), std::fstream::in | std::fstream::binary);
    if(file.is_open())
    {
        file.read(reinterpret_cast<char*>(&file_count), sizeof(file_count));
        for(size_t i=0; i<file_count; ++i)
        {
            unsigned int name_size(0), data_size(0);
            std::string name(""), data("");

            file.read(reinterpret_cast<char*>(&name_size), sizeof(name_size));
            for(size_t b=0; b<name_size; ++b)
                name += file.get();

            file.read(reinterpret_cast<char*>(&data_size), sizeof(data_size));
            for(size_t b=0; b<data_size; ++b)
                data += file.get();

            m_storedFile[name] = data;
        }
        
        file.close();
        return true;
    }
    
    return false;
}


bool DAT::loadFromStream(std::string str)
{
    std::stringstream stream(str, std::ios_base::in | std::ios_base::binary);
    unsigned int file_count(0);
    
    stream.read(reinterpret_cast<char*>(&file_count), sizeof(file_count));
    for(size_t i=0; i<file_count; ++i)
    {
        unsigned int name_size(0), data_size(0);
        std::string name(""), data("");

        stream.read(reinterpret_cast<char*>(&name_size), sizeof(name_size));
        for(size_t b=0; b<name_size; ++b)
            name += stream.get();

        stream.read(reinterpret_cast<char*>(&data_size), sizeof(data_size));
        for(size_t b=0; b<data_size; ++b)
            data += stream.get();

        m_storedFile[name] = data;
    }
    
    if(!stream.bad() && !stream.fail())
        return true;
    else
        return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// SAVE
bool DAT::saveToFile(std::string filename)
{
    std::fstream file(filename.c_str(), std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
    
    if(file.is_open())
    {
        unsigned int file_count(m_storedFile.size());
        file.write(reinterpret_cast<char*>(&file_count), sizeof(file_count));
        for(auto it=m_storedFile.begin(); it!=m_storedFile.end(); ++it)
        {
            std::string name(it->first), data(it->second);
            unsigned int name_size(name.size()), data_size(data.size());
            
            file.write(reinterpret_cast<char*>(&name_size), sizeof(name_size));
            file.write(name.c_str(), sizeof(char)*name_size);
            
            file.write(reinterpret_cast<char*>(&data_size), sizeof(data_size));
            file.write(data.c_str(), sizeof(char)*data_size);
        }
        
        file.close();
        return true;
    }
    
    return false;
}


std::string DAT::saveToStream()
{
    std::stringstream stream(std::ios_base::out | std::ios_base::binary);
    
    unsigned int file_count(m_storedFile.size());
    stream.write(reinterpret_cast<char*>(&file_count), sizeof(file_count));
    for(auto it=m_storedFile.begin(); it!=m_storedFile.end(); ++it)
    {
        std::string name(it->first), data(it->second);
        unsigned int name_size(name.size()), data_size(data.size());
                
        stream.write(reinterpret_cast<char*>(&name_size), sizeof(name_size));
        stream.write(name.c_str(), sizeof(char)*name_size);
                
        stream.write(reinterpret_cast<char*>(&data_size), sizeof(data_size));
        stream.write(data.c_str(), sizeof(char)*data_size);
    }
    
    if(!stream.bad() && !stream.fail())
        return stream.str();
    else
        return std::string("");
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// MANAGE (Clear, Add, Remove, Rename)
void DAT::clear()
{
    m_storedFile.clear();
}


bool DAT::add(std::string filename)
{
    if(m_storedFile.count(fileName(filename)) == 0)
    {
        std::fstream file(filename.c_str(), std::fstream::in | std::fstream::binary);
        if(file.is_open())
        {
            std::string data("");
            
            while(!file.eof())
                data += file.get();

            m_storedFile[fileName(filename)] = data;

            file.close();
            return true;
        }
    }

    return false;
}


bool DAT::add(std::string filename, std::string data)
{
    if(!exists(filename))
    {
        m_storedFile[filename] = data;
        
        return true;
    }
    
    return false;
}


bool DAT::rename(std::string cur_name, std::string new_name)
{
    if(exists(cur_name) && !exists(new_name))
    {
        m_storedFile[new_name] = m_storedFile[cur_name];
        m_storedFile.erase(m_storedFile.find(cur_name));

        return true;
    }

    return false;
}


bool DAT::remove(std::string name)
{
    if(m_storedFile.count(name) == 1)
    {
        m_storedFile.erase(m_storedFile.find(name));
        
        return true;
    }

    return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// Gettor
bool DAT::exists(std::string name)
{
    if(m_storedFile.count(name) == 1)
        return true;
    else
        return false;
}


unsigned int DAT::fileSize(std::string name)
{
    if(exists(name))
        return m_storedFile[name].size();
    else
        return 0;
}


std::string DAT::file(std::string name)
{
    if(exists(name))
        return m_storedFile[name];
    else
        return std::string("");
}


std::string DAT::fileNameByIndex(unsigned int index)
{
    if(index < m_storedFile.size())
    {
        auto it = std::next(m_storedFile.begin(), index);

        return it->first;
    }

    return std::string("");
}
