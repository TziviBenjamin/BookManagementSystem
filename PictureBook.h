#pragma once

#include "Book.h"
#include <string>

class PictureBook : public Book
{
public:
    enum class IllustrationType_{ Commic,NormalIllustration};

    PictureBook();
    PictureBook(const std::string& title,
                const std::string& author,
                int publicationYear,
                const Category& category,
                const Level& level,
                const std::string& painter,
                const IllustrationType_& illustrationType);

    std::string Display() const override; 

private:
    std::string painterName_;    
    IllustrationType_ illustrationType_;
};
