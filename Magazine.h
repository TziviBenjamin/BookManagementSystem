#pragma once

#include <string>

class Magazine
{
public:
    Magazine();
    Magazine(const std::string& magazineName,
             int issueNumber,
             const std::string& publicationDate,
             int maxSize);
    Magazine(const Magazine& other); 
    Magazine(Magazine&& other) noexcept; 
    ~Magazine();

    Magazine& operator=(const Magazine& other); 
    Magazine& operator=(Magazine&& other) noexcept; 

    std::string ToString() const;
    const std::string& GetName() const { return magazineName_; }

   
    void AddPartner(const std::string& partner); 
    const std::string* GetPartners() const; 
    
private:
    std::string magazineName_;       
    int issueNumber_;                
    std::string publicationDate_;    
    std::string* partnerCompanies_;  
    int maxSize_;                    
    int currentSize_;                
};
