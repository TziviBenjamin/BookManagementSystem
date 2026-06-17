#include "Magazine.h"
#include <iostream>
#include <algorithm> 

Magazine::Magazine()
    : magazineName_(),
      issueNumber_(0),
      publicationDate_(),
      partnerCompanies_(nullptr),
      maxSize_(0),
      currentSize_(0)
{
}

Magazine::Magazine(const std::string& magazineName,
                   int issueNumber,
                   const std::string& publicationDate,
                   int maxSize)
    : magazineName_(magazineName),
      issueNumber_(issueNumber),
      publicationDate_(publicationDate),
      maxSize_(maxSize),
      currentSize_(0)
{
    partnerCompanies_ = new std::string[maxSize];
}

// Copy constructor
Magazine::Magazine(const Magazine& other)
    : magazineName_(other.magazineName_),
      issueNumber_(other.issueNumber_),
      publicationDate_(other.publicationDate_),
      maxSize_(other.maxSize_),
      currentSize_(other.currentSize_)
{
    partnerCompanies_ = new std::string[maxSize_];
    for (int i = 0; i < currentSize_; ++i)
    {
        partnerCompanies_[i] = other.partnerCompanies_[i];
    }
}

// Move constructor
Magazine::Magazine(Magazine&& other) noexcept
    : magazineName_(std::move(other.magazineName_)),
      issueNumber_(other.issueNumber_),
      publicationDate_(std::move(other.publicationDate_)),
      partnerCompanies_(other.partnerCompanies_),
      maxSize_(other.maxSize_),
      currentSize_(other.currentSize_)
{
    other.partnerCompanies_ = nullptr;
    other.maxSize_ = 0;
    other.currentSize_ = 0;
}

Magazine::~Magazine()
{
    delete[] partnerCompanies_;
}

// Copy assignment
Magazine& Magazine::operator=(const Magazine& other)
{
    if (this != &other)
    {
        delete[] partnerCompanies_;
        magazineName_ = other.magazineName_;
        issueNumber_ = other.issueNumber_;
        publicationDate_ = other.publicationDate_;
        maxSize_ = other.maxSize_;
        currentSize_ = other.currentSize_;
        partnerCompanies_ = new std::string[maxSize_];
        for (int i = 0; i < currentSize_; ++i)
        {
            partnerCompanies_[i] = other.partnerCompanies_[i];
        }
    }
    return *this;
}

// Move assignment
Magazine& Magazine::operator=(Magazine&& other) noexcept
{
    if (this != &other)
    {
        delete[] partnerCompanies_;
        magazineName_ = std::move(other.magazineName_);
        issueNumber_ = other.issueNumber_;
        publicationDate_ = std::move(other.publicationDate_);
        partnerCompanies_ = other.partnerCompanies_;
        maxSize_ = other.maxSize_;
        currentSize_ = other.currentSize_;
        other.partnerCompanies_ = nullptr;
        other.maxSize_ = 0;
        other.currentSize_ = 0;
    }
    return *this;
}

void Magazine::AddPartner(const std::string& partner)
{
    if (currentSize_ >= maxSize_)
    {
        int newMaxSize = maxSize_ * 2;
        if (newMaxSize == 0) newMaxSize = 1;
        std::string* newArray = new std::string[newMaxSize];
        for (int i = 0; i < currentSize_; ++i)
        {
            newArray[i] = partnerCompanies_[i];
        }
        delete[] partnerCompanies_;
        partnerCompanies_ = newArray;
        maxSize_ = newMaxSize;
    }
    partnerCompanies_[currentSize_] = partner;
    currentSize_++;
}

const std::string* Magazine::GetPartners() const
{
    return partnerCompanies_;
}

std::string Magazine::ToString() const
{
    std::string result = magazineName_ + " | " + std::to_string(issueNumber_) + " | " + publicationDate_;
    result += " | Partners: ";
    for (int i = 0; i < currentSize_; ++i)
    {
        result += partnerCompanies_[i];
        if (i < currentSize_ - 1) result += ", ";
    }
    return result;
}
