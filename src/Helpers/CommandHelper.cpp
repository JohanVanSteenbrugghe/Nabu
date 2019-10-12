#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "../../Include/Helpers/CommandHelper.hpp"

std::string CommandHelper::AddDictionary(std::string dictionaryName){
    Dictionary dictionary;
    dictionary.Name = dictionaryName;
    DictionaryCollection::Add(dictionary);
    return "Dictionary succesfully added.";
}

std::vector<Dictionary> CommandHelper::GetListDictionariesFIFO(){
    std::vector<Dictionary> dictionaryVector = DictionaryCollection::GetAll("ID ASC");
    return dictionaryVector;
}

std::string CommandHelper::UpdateDictionary(std::string dictionaryNameCurrent, std::string dictionaryNameNew){
    Dictionary dictionary = DictionaryCollection::Get(dictionaryNameCurrent);
    if (dictionary.Name != ""){
        dictionary.Name = dictionaryNameNew;
        DictionaryCollection::Update(dictionary);
        return "Dictionary succesfully updated.";
    }
    else{
        return "Dictionary not found!";
    }
}

std::string CommandHelper::DeleteDictionary(std::string dictionaryName){
    Dictionary dictionary = DictionaryCollection::Get(dictionaryName);
    if (dictionary.Name == ""){
        return "Dictionary not found!";
    }

    std::vector<Word> wordVector  = WordCollection::GetAll(dictionary.ID, "ID ASC");
    for (int i = 0; i < wordVector.size(); i++){
        WordCollection::Delete(wordVector[i]);
    }

    DictionaryCollection::Delete(dictionary);
    return "Dictionary succesfully deleted.";
}

std::string CommandHelper::AddWordsFromFile(std::string dictionaryName, std::string filePath){ 
    std::ifstream file (filePath);
    std::string line;

    std::vector<std::string> wordVector;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            std::vector<std::string> wordLineVector = StringHelper::GetVectorOfWords(line);
            for (int i = 0; i < wordLineVector.size(); i++){
                wordVector.push_back(wordLineVector[i]);
            }
        }
        file.close();
    }
    else{
        return "File not found!";
    }

    Dictionary dictionary = DictionaryCollection::Get(dictionaryName);
    if (dictionary.Name == ""){
        return "Dictionary not found!";
    }

    for (int i = 0; i < wordVector.size(); i++){
        Word word = WordCollection::Get(dictionary.ID, wordVector[i]);
        if (word.Name == ""){
            Word wordNew;
            wordNew.DictionaryID = dictionary.ID;
            wordNew.Name = wordVector[i];
            wordNew.Count = 1;
            WordCollection::Add(wordNew);
        }
        else{
            word.Count = word.Count + 1;
            WordCollection::Update(word);
        }
    }

    return "Text file succesfully added.";
}

Word CommandHelper::GetWord(std::string dictionaryName, std::string wordName){
    Word word;
    Dictionary dictionary = DictionaryCollection::Get(dictionaryName);
    if (dictionary.Name == ""){
        return word;
    }

    word = WordCollection::Get(dictionary.ID, wordName);
    return word;
}

std::vector<Word> CommandHelper::GetListWordsFIFO(std::string dictionaryName){
    std::vector<Word> wordVector;
    Dictionary dictionary = DictionaryCollection::Get(dictionaryName);
    if (dictionary.Name == ""){
        return wordVector;
    }

    wordVector = WordCollection::GetAll(dictionary.ID, "ID ASC");
    return wordVector;
}

std::vector<Word> CommandHelper::GetListWordsAlfaAscending(std::string dictionaryName){
    std::vector<Word> wordVector;
    Dictionary dictionary = DictionaryCollection::Get(dictionaryName);
    if (dictionary.Name == ""){
        return wordVector;
    }

    wordVector = WordCollection::GetAll(dictionary.ID, "Name ASC");
    return wordVector;
}

std::vector<Word> CommandHelper::GetListWordsAlfaDescending(std::string dictionaryName){
    std::vector<Word> wordVector;
    Dictionary dictionary = DictionaryCollection::Get(dictionaryName);
    if (dictionary.Name == ""){
        return wordVector;
    }

    wordVector = WordCollection::GetAll(dictionary.ID, "Name DESC");
    return wordVector;
}

std::vector<Word> CommandHelper::GetListWordsCountAscending(std::string dictionaryName){
    std::vector<Word> wordVector;
    Dictionary dictionary = DictionaryCollection::Get(dictionaryName);
    if (dictionary.Name == ""){
        return wordVector;
    }

    wordVector = WordCollection::GetAll(dictionary.ID, "Count ASC");
    return wordVector;
}

std::vector<Word> CommandHelper::GetListWordsCountDescending(std::string dictionaryName){
    std::vector<Word> wordVector;
    Dictionary dictionary = DictionaryCollection::Get(dictionaryName);
    if (dictionary.Name == ""){
        return wordVector;
    }

    wordVector = WordCollection::GetAll(dictionary.ID, "Count DESC");
    return wordVector;
}