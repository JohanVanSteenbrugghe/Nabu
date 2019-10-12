#ifndef WORDCOLLECTION_HPP
#define WORDCOLLECTION_HPP

#include <string>
#include <vector>
#include "../Models/Word.hpp"

class WordCollection{
    public:
        static void Add(Word word);
        static Word Get(int dictionaryID, std::string wordName);
        static std::vector<Word> GetAll(int dictionaryID, std::string orderBy);
        static void Update(Word word);
        static void Delete(Word word);
};

#endif