#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "../include/Helpers/CommandHelper.hpp"
#include "../include/Helpers/SQLiteHelper.hpp"

int main(){
    if (SQLiteHelper::SetupDatabase()){
        std::cout << "Nabu" << std::endl;
    } 
    else{
        std::cout << "Database error!" << std::endl;
    }
    while(true){
        std::string command = "";
        std::cout << "Command: ";
        getline(std::cin, command);
        transform(command.begin(), command.end(), command.begin(), ::tolower);

        if (command == "dictionary -create"){
            std::string dictionaryName;
            std::cout << "Dictionary Name: ";
            getline(std::cin, dictionaryName);

            std::string result = CommandHelper::AddDictionary(dictionaryName);
            std::cout << result << std::endl;
        }
        else if (command == "dictionary -update"){
            std::string dictionaryNameCurrent;
            std::cout << "Dictionary Name (current): ";
            getline(std::cin, dictionaryNameCurrent);

            std::string dictionaryNameNew;
            std::cout << "Dictionary Name (current): ";
            getline(std::cin, dictionaryNameNew);

            std::string result = CommandHelper::UpdateDictionary(dictionaryNameCurrent, dictionaryNameNew);
            std::cout << result << std::endl;
        }
        else if (command == "dictionary -delete"){
            std::string dictionaryName;
            std::cout << "Dictionary Name: ";
            getline(std::cin, dictionaryName);

            std::string result = CommandHelper::DeleteDictionary(dictionaryName);
            std::cout << result << std::endl;
        }
        else if (command == "dictionary -list"){
            std::vector<Dictionary> dictionaryVector = CommandHelper::GetListDictionariesFIFO();
            if (dictionaryVector.size() != 0){
                for (int i = 0; i < dictionaryVector.size(); i++){
                    std::cout << dictionaryVector[i].Name << std::endl;
                }
            }
            else{
                std::cout << "No dictionaries found!" << std::endl;
            }         
        }
        else if (command == "word -file"){
            std::string dictionaryName;
            std::cout << "Dictionary Name: ";
            getline(std::cin, dictionaryName);

            std::string filePath;
            std::cout << "Filepath: ";
            getline(std::cin, filePath);

            std::string result = CommandHelper::AddWordsFromFile(dictionaryName, filePath);
            std::cout << result << std::endl;
        }
        else if (command == "word -get"){           
            std::string dictionaryName;
            std::cout << "Dictionary Name: ";
            getline(std::cin, dictionaryName);

            std::string wordName;
            std::cout << "Word Name: ";
            getline(std::cin, wordName);

            Word word = CommandHelper::GetWord(dictionaryName, wordName);
            if (word.Name != ""){
                std::cout << std::to_string(word.Count) + "     " + word.Name << std::endl;
            }
            else{
                std::cout << "Word not found!" << std::endl;
            }
        }
        else if (command == "word -list"){           
            std::string dictionaryName;
            std::cout << "Dictionary Name: ";
            getline(std::cin, dictionaryName);

            std::vector<Word> wordVector = CommandHelper::GetListWordsFIFO(dictionaryName);
            if (wordVector.size() != 0){
                for (int i = 0; i < wordVector.size(); i++){
                    std::cout << std::to_string(wordVector[i].Count) + "     " + wordVector[i].Name << std::endl;
                }
            }
            else{
                std::cout << "No words found!" << std::endl;
            }          
        }
        else if (command == "word -list -aa"){           
            std::string dictionaryName;
            std::cout << "Dictionary Name: ";
            getline(std::cin, dictionaryName);

            std::vector<Word> wordVector = CommandHelper::GetListWordsAlfaAscending(dictionaryName);
            if (wordVector.size() != 0){
                for (int i = 0; i < wordVector.size(); i++){
                    std::cout << std::to_string(wordVector[i].Count) + "     " + wordVector[i].Name << std::endl;
                }
            }
            else{
                std::cout << "No words found!" << std::endl;
            }
        }
        else if (command == "word -list -ad"){
            std::string dictionaryName;
            std::cout << "Dictionary Name: ";
            getline(std::cin, dictionaryName);

            std::vector<Word> wordVector = CommandHelper::GetListWordsAlfaDescending(dictionaryName);
            if (wordVector.size() != 0){
                for (int i = 0; i < wordVector.size(); i++){
                    std::cout << std::to_string(wordVector[i].Count) + "     " + wordVector[i].Name << std::endl;
                }
            }
            else{
                std::cout << "No words found!" << std::endl;
            }
        }
        else if (command == "word -list -ca"){
            std::string dictionaryName;
            std::cout << "Dictionary Name: ";
            getline(std::cin, dictionaryName);

            std::vector<Word> wordVector = CommandHelper::GetListWordsCountAscending(dictionaryName);
            if (wordVector.size() != 0){
                for (int i = 0; i < wordVector.size(); i++){
                    std::cout << std::to_string(wordVector[i].Count) + "     " + wordVector[i].Name << std::endl;
                }
            }
            else{
                std::cout << "No words found!" << std::endl;
            }
        }
        else if (command == "word -list -cd"){
            std::string dictionaryName;
            std::cout << "Dictionary Name: ";
            getline(std::cin, dictionaryName);

            std::vector<Word> wordVector = CommandHelper::GetListWordsCountDescending(dictionaryName);
            if (wordVector.size() != 0){
                for (int i = 0; i < wordVector.size(); i++){
                    std::cout << std::to_string(wordVector[i].Count) + "     " + wordVector[i].Name << std::endl;
                }
            }
            else{
                std::cout << "No words found!" << std::endl;
            }
        }
        else if (command == "help"){
            std::cout << "dictionary -create        Creates a dictionary in the database." << std::endl;
            std::cout << "dictionary -update        Updates a dictionary with a new name." << std::endl;
            std::cout << "dictionary -delete        Deletes a dictionary in the database." << std::endl;
            std::cout << "dictionary -list          Shows the list of all dictionares. Ordered by fifo." << std::endl;
            std::cout << "word -file                Add every word from a .txt file to the database." << std::endl;
            std::cout << "word -get                 Get the word and count from a specified dictionary." << std::endl;
            std::cout << "word -list                Shows the list of all words. Ordered by fifo." << std::endl;
            std::cout << "word -list -aa            Shows the list of all words. Ordered alphabetically a to z." << std::endl;
            std::cout << "word -list -ad            Shows the list of all words. Ordered alphabetically z to a." << std::endl;
            std::cout << "word -list -ca            Shows the list of all words. Ordered by count ascending." << std::endl;
            std::cout << "word -list -cd            Shows the list of all words. Ordered by count descending." << std::endl;
            std::cout << "help                      Shows the manual." << std::endl;
            std::cout << "clean                     Clears the console." << std::endl;
            std::cout << "exit                      Exits Nabu program." << std::endl;
        }
        else if (command == "clean"){
            for (int i = 0; i < 100; i++){
                std::cout << std::endl;
            }
            std::cout << "Nabu" << std::endl;
        }
        else if (command == "exit"){
            break;
        }
        else {
            std::cout << "Command not recognised." << std::endl;
        }
    }

    return 0;
}