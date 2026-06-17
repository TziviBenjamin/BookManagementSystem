#include "Library.h"
#include "PictureBook.h"
#include <iostream>
#include <algorithm>

void Library::addBook(const Book& book)
{
    books.push_back(book);
}

void Library::addMagazine(std::shared_ptr<Magazine> magazine)
{
    magazines.push_back(std::move(magazine));
}

void Library::ShowCollection()
{
    std::cout << "Books in the library:" << std::endl;
    for (const auto& book : books)
        std::cout << book.Display() << std::endl;

    std::cout << "Magazines in the library:" << std::endl;
    for (const auto& magazine : magazines)
        std::cout << magazine->ToString() << std::endl;
}

void Library::ShowPictureBook()
{
    std::cout << "Picture Books in the library:" << std::endl;
    for (const auto& book : books)
    {
        if (book.GetCategory() == Book::Category::Picture)
            std::cout << book.Display() << std::endl;
    }
}

std::vector<Book> Library::ShowBooksInYear(int year)
{
    std::vector<Book> result;
    std::copy_if(books.begin(), books.end(), std::back_inserter(result),
        [year](const Book& book) { return book.GetPublicationYear() == year; });
    return result;
}

void Library::RemoveMagazinesByName(const std::string& name)
{
    magazines.erase(std::remove_if(magazines.begin(), magazines.end(),
        [&name](const std::shared_ptr<Magazine>& magazine)
        {
            return magazine->GetName() == name;
        }), magazines.end());
}

void Library::SaveCollection(const std::string& filename)
{
    FileHandler fileHandler(filename);
    for (const auto& book : books)
        fileHandler.write(book.Display());
    for (const auto& magazine : magazines)
        fileHandler.write(magazine->ToString());
}
