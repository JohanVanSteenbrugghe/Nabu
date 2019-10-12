#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <regex>
#include "../../Include/Helpers/StringHelper.hpp"

std::vector<std::string> StringHelper::GetVectorOfWords(std::string input){
    std::vector<std::string> wordVector; 
    std::vector<std::string> wordResultVector;

    std::stringstream iss(input);
    while (iss) {
        std::string word;
        iss >> word;
        wordVector.push_back(word);     
    }
    
    for (int i = 0; i < wordVector.size(); i++){
        std::string wordFiltered = GetFilteredWord(wordVector[i]);
        if (wordFiltered != ""){
            wordResultVector.push_back(wordFiltered);
        }
    }

    return wordResultVector;
}

std::string StringHelper::GetFilteredWord(std::string word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    std::regex reg("[^a-zA-Z']");
    std::string wordFiltered = regex_replace(word, reg, "");
    return wordFiltered;
}