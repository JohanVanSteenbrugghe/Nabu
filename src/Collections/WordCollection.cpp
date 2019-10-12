#include <string>
#include <vector>
#include "../../include/Collections/WordCollection.hpp"
#include "../../include/Helpers/SQLiteHelper.hpp"

void WordCollection::Add(Word word){
    std::string sql = "INSERT INTO Word (DictionaryID, Name, Count) VALUES ( \
                        " + std::to_string(word.DictionaryID) + ", \
                        '" + word.Name + "', \
                        " + std::to_string(word.Count) + " \
                        );";
    SQLiteHelper::ExecuteCommand(sql);
}

Word WordCollection::Get(int dictionaryID, std::string wordName){
    std::string sql = "SELECT * FROM Word WHERE DictionaryID = " + std::to_string(dictionaryID) + " AND Name = '" + wordName + "';";
    std::vector<std::vector<std::string>> table = SQLiteHelper::ExecuteSelect(sql);

    Word word;
    if (table.size() == 1){
        word.ID = std::stoi(table[0][0]);
        word.DictionaryID = std::stoi(table[0][1]);
        word.Name = table[0][2];
        word.Count = std::stoi(table[0][3]);
    }

    return word;
}

std::vector<Word> WordCollection::GetAll(int dictionaryID, std::string orderBy){
    std::string sql = "SELECT * FROM Word WHERE DictionaryID = " + std::to_string(dictionaryID) + " ORDER BY " + orderBy + ";";
    std::vector<std::vector<std::string>> table = SQLiteHelper::ExecuteSelect(sql);

    std::vector<Word> wordVector;
    for (int i = 0; i < table.size(); i++){
        Word word;
        word.ID = std::stoi(table[i][0]);
        word.DictionaryID = std::stoi(table[i][1]);
        word.Name = table[i][2];
        word.Count = std::stoi(table[i][3]);
        wordVector.push_back(word);
    }

    return wordVector;
}

void WordCollection::Update(Word word){
    std::string sql = "UPDATE WORD SET \
                        DictionaryID = " + std::to_string(word.DictionaryID) + ", \
                        Name = '" + word.Name + "', \
                        Count = " + std::to_string(word.Count) + " \
                        WHERE ID = " + std::to_string(word.ID) + ";";
    SQLiteHelper::ExecuteCommand(sql);   
}

void WordCollection::Delete(Word word){
    std::string sql = "DELETE FROM Word WHERE ID = " + std::to_string(word.ID) + ";";
    SQLiteHelper::ExecuteCommand(sql);
}