#include "FileHandler.h"
#include <cstring>

FileHandler::FileHandler(const std::string& filename)
{
    file.open(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filename);
    }
    buffer = nullptr;
}
void FileHandler::write(const std::string& data)
{
    if (file.is_open())
    {
        file << data << std::endl;
    }
    else
    {
        throw std::runtime_error("File is not open for writing.");
    }
}

void FileHandler::setBuffer(const char* data)
{
    if (buffer != nullptr)
    {
        delete[] buffer;
    }
    if (data != nullptr)
    {
        size_t len = strlen(data) + 1;
        buffer = new char[len];
        strcpy(buffer, data);
    }
    else
    {
        buffer = nullptr;
    }
}

FileHandler::~FileHandler()
{
    if (file.is_open())
    {
        file.close();
    }
    if (buffer != nullptr)
    {
        delete[] buffer;
        buffer = nullptr;
    }
}