#include <stdio.h>
#include "../../Include/Helpers/SQLiteHelper.hpp"

const char* _FilePath = "Seshat.db";

bool SQLiteHelper::SetupDatabase(){
    sqlite3 *db;

    //sqlite3_open return an int, if int == 0 (SQLITE_OK) then it was succesfull
    //sqlite3_open creates the database file if it does not exist
    if (sqlite3_open(_FilePath, &db) == SQLITE_OK){
        sqlite3_close(db);
    }
    else{
        return false;
    }

    std::string sql;

    sql = "CREATE TABLE IF NOT EXISTS Dictionary ("  \
            "ID INTEGER PRIMARY KEY AUTOINCREMENT, " \
            "Name TEXT NOT NULL);";

    if (!ExecuteCommand(sql)){
        return false;
    }

    sql = "CREATE TABLE IF NOT EXISTS Word ("  \
            "ID INTEGER PRIMARY KEY AUTOINCREMENT, " \
            "DictionaryID INT NOT NULL, " \
            "Name TEXT NOT NULL, " \
            "Count INT NOT NULL);";

    if (!ExecuteCommand(sql)){
        return false;
    }

    return true;
}

bool SQLiteHelper::ExecuteCommand(std::string sql){
    sqlite3 *db;

    if (!sqlite3_open(_FilePath, &db) == SQLITE_OK){
        return false;
    }

    if (sqlite3_exec(db, sql.c_str(), 0, 0, 0) == SQLITE_OK){
        sqlite3_close(db);
        return true;
    }
    else{
        sqlite3_close(db);
        return false;
    }
}

std::vector<std::vector<std::string>> SQLiteHelper::ExecuteSelect(std::string sql){
    sqlite3 *db;
    sqlite3_stmt * stmt;
    std::vector<std::vector<std::string>> table;

    if (sqlite3_open(_FilePath, &db) == SQLITE_OK)
    {
        sqlite3_prepare(db, sql.c_str(), -1, &stmt, NULL);

        //Go through every row with sqlite3_step
        //Use stmt type to get column/row information
        int countColumns = sqlite3_column_count(stmt);
        while (sqlite3_step(stmt) == SQLITE_ROW){
            std::vector<std::string> row;
            for (int i = 0; i < countColumns; i++){
                std::string value = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
                row.push_back(value);
            }
            table.push_back(row);
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    return table;
}