#ifndef DICTIONARYCOLLECTION_HPP
#define DICTIONARYCOLLECTION_HPP

#include <string>
#include <vector>
#include "../Models/Dictionary.hpp"

class DictionaryCollection{
    public:
        static void Add(Dictionary dictionary);
        static Dictionary Get(std::string dictionaryName);
        static std::vector<Dictionary> GetAll(std::string orderBy);
        static void Update(Dictionary dictionary);
        static void Delete(Dictionary dictionary);
};

#endif