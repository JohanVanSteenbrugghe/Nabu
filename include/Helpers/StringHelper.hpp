#ifndef STRINGHELPER_HPP
#define STRINGHELPER_HPP

#include <string>
#include <vector>

class StringHelper{
    public:
        static std::vector<std::string> GetVectorOfWords(std::string input);
        static std::string GetFilteredWord(std::string word);
        static std::vector<std::string> GetVectorOfWordsWithoutDuplicates(std::vector<std::string> word);
};

#endif