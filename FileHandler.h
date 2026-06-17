#pragma once
#include <fstream>
#include <string>

class FileHandler
{
public:
    FileHandler(const std::string& filename);
    void write(const std::string& data);
    void setBuffer(const char* data);
    ~FileHandler();
    
private:
    std::ofstream file;
    char* buffer;
};

