#include "Book.h"
#include "InvalidBookException.h"


Book::Book()
    : title_(),
      author_(),
      publicationYear_(0),
      category_(),
      level_()
{
}

Book::Book(const std::string& title,
           const std::string& author,
           int publicationYear,
           const Category& category,
           const Level& level)
    : title_(title),
      author_(author),
      publicationYear_(publicationYear),
      category_(category),
    level_(level)
{
    if (title.empty() || author.empty())
    {
        throw InvalidBookException("Book title or author cannot be empty");
    }
}

std::string Book::Display() const
{
    return title_ + " | " + author_ + " | " +
           std::to_string(publicationYear_) + " | " +
        std::to_string(static_cast<int>(category_)) + " | " + std::to_string(static_cast<int>(level_));
}



