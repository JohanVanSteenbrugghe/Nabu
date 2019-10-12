#include <string>
#include <vector>
#include "../../include/Collections/DictionaryCollection.hpp"
#include "../../include/Helpers/SQLiteHelper.hpp"

void DictionaryCollection::Add(Dictionary dictionary){
    std::string sql = "INSERT INTO Dictionary (Name) VALUES ('" + dictionary.Name + "');";
    SQLiteHelper::ExecuteCommand(sql);
}

Dictionary DictionaryCollection::Get(std::string dictionaryName){
    std::string sql = "SELECT * FROM Dictionary WHERE Name = '" + dictionaryName + "' COLLATE NOCASE;";
    std::vector<std::vector<std::string>> table = SQLiteHelper::ExecuteSelect(sql);
    
    Dictionary dictionary;
    if (table.size() == 1){
        dictionary.ID = std::stoi(table[0][0]);
        dictionary.Name = table[0][1];
    }

    return dictionary;
}

std::vector<Dictionary> DictionaryCollection::GetAll(std::string orderBy){
    std::string sql = "SELECT * FROM Dictionary ORDER BY " + orderBy + ";";
    std::vector<std::vector<std::string>> table = SQLiteHelper::ExecuteSelect(sql);

    std::vector<Dictionary> dictionaryVector;
    for (int i = 0; i < table.size(); i++){
        Dictionary dictionary;
        dictionary.ID = std::stoi(table[i][0]);
        dictionary.Name = table[i][1];
        dictionaryVector.push_back(dictionary);
    }

    return dictionaryVector;
}

void DictionaryCollection::Update(Dictionary dictionary){
    std::string sql = "UPDATE Dictionary SET Name = '" + dictionary.Name + "' WHERE ID = " + std::to_string(dictionary.ID) + ";";
    SQLiteHelper::ExecuteCommand(sql);
}

void DictionaryCollection::Delete(Dictionary dictionary){
    std::string sql = "DELETE FROM Dictionary WHERE ID = " + std::to_string(dictionary.ID) + ";";
    SQLiteHelper::ExecuteCommand(sql);
}