#ifndef COMMANDHELPER_HPP
#define COMMANDHELPER_HPP

#include <string>
#include <vector>
#include "../Collections/DictionaryCollection.hpp"
#include "../Collections/WordCollection.hpp"
#include "../Helpers/StringHelper.hpp"

class CommandHelper{
    public:
        static std::string AddDictionary(std::string dictionaryName);
        static std::vector<Dictionary> GetListDictionariesFIFO();
        static std::string UpdateDictionary(std::string dictionaryNameCurrent, std::string dictionaryNameNew);
        static std::string DeleteDictionary(std::string dictionaryName);

        static std::string AddWordsFromFile(std::string dictionaryName, std::string filePath);
        static Word GetWord(std::string dictionaryName, std::string wordName);
        static std::vector<Word> GetListWordsFIFO(std::string dictionaryName); 
        static std::vector<Word> GetListWordsAlfaAscending(std::string dictionaryName);
        static std::vector<Word> GetListWordsAlfaDescending(std::string dictionaryName);
        static std::vector<Word> GetListWordsCountAscending(std::string dictionaryName);
        static std::vector<Word> GetListWordsCountDescending(std::string dictionaryName);
};

#endif