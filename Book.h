#pragma once

#include <string>

class Book
{
public:
    enum class Category { Reading, Learning, Reference ,Picture};
    enum class Level { Toddlers, Children, Adults };

    Book();
    Book(const std::string& title,
         const std::string& author,
         int publicationYear,
         const Category& category,
         const Level& level);
    virtual ~Book() = default;

    virtual std::string Display() const;

    int GetPublicationYear() const { return publicationYear_; }
    const Category& GetCategory() const { return category_; }

private:
    std::string title_;          
    std::string author_;         
    int publicationYear_;        
    Category category_;      
    Level level_;          
};
