#include "PictureBook.h"

PictureBook::PictureBook()
    : Book(),
      painterName_(),
      illustrationType_()
{
}

PictureBook::PictureBook(const std::string& title,
                         const std::string& author,
                         int publicationYear,
                         const Category& category,
                         const Level& level,
                         const std::string& painter,
                         const IllustrationType_& illustrationType)
    : Book(title, author, publicationYear, category, level),
    painterName_(painter),
    illustrationType_(illustrationType)
{
}

std::string PictureBook::Display() const
{
    return Book::Display() + " | " + painterName_ + " | " + std::to_string(static_cast<int>(illustrationType_));
}
