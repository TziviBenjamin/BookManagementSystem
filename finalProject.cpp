
#include <iostream>
#include "InvalidBookException.h"
#include "PictureBook.h"
#include "Library.h"

int main()
{
    Library library;
    try
    {
        library.addBook(Book("The Alchemist", "Paulo Coelho", 1988, Book::Category::Reading, Book::Level::Adults));
        library.addBook(Book("Titanic", "J.K. Rowling", 1997, Book::Category::Reading, Book::Level::Children));
        library.addBook(Book("Clean Code", "Robert Martin", 2008, Book::Category::Learning, Book::Level::Adults));
        library.addBook(Book("The Very Hungry Caterpillar", "Eric Carle", 1969, Book::Category::Picture, Book::Level::Toddlers));
        library.addBook(PictureBook("Where the Wild Things Are", "Maurice Sendak", 1963,Book::Category::Picture, Book::Level::Children, "Maurice Sendak", PictureBook::IllustrationType_::NormalIllustration));         
    }
    catch (const InvalidBookException& e)
    {
        std::cout << "Error adding book: " << e.what() << std::endl;
    }

    // Add magazines
    auto mag1 = std::make_shared<Magazine>("National Geographic", 1, "2023-01", 3);
    mag1->AddPartner("Disney");
    mag1->AddPartner("Fox");

    auto mag2 = std::make_shared<Magazine>("Time", 5, "2023-05", 2);
    mag2->AddPartner("CNN");

    auto mag3 = std::make_shared<Magazine>("National Geographic", 2, "2023-02", 2);
    mag3->AddPartner("BBC");

    library.addMagazine(mag1);
    library.addMagazine(mag2);
    library.addMagazine(mag3);

    // Show full collection
    library.ShowCollection();
    std::cout << std::endl;

    // Show only picture books
    library.ShowPictureBook();
    std::cout << std::endl;

    // Show books from a specific year
    std::cout << "Books from 1997:" << std::endl;
    std::vector<Book> booksIn1997 = library.ShowBooksInYear(1997);
    for (const auto& book : booksIn1997)
        std::cout << book.Display() << std::endl;
    std::cout << std::endl;

    // Remove all magazines by name
    std::cout << "Removing all 'National Geographic' magazines..." << std::endl;
    library.RemoveMagazinesByName("National Geographic");

    // Show collection after removal
    library.ShowCollection();
    std::cout << std::endl;

    // Save to file
    library.SaveCollection("library_collection.txt");
    std::cout << "Collection saved to library_collection.txt" << std::endl;

    return 0;
}
