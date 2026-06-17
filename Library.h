#pragma once

#include <memory>
#include <vector>
#include <string>

#include "Book.h"
#include "Magazine.h"
#include "FileHandler.h"

class Library
{

public:
    Library() = default;
    ~Library() = default;

    void addBook(const Book& book);
    void addMagazine(std::shared_ptr<Magazine> magazine);
    void ShowCollection();
    void ShowPictureBook();
    std::vector<Book> ShowBooksInYear(int year);
    void RemoveMagazinesByName(const std::string& name);
    void SaveCollection(const std::string& filename);

private:
    std::vector<Book> books;
    std::vector<std::shared_ptr<Magazine>> magazines;

};