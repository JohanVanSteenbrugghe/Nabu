#ifndef SQLITEHELPER_HPP
#define SQLITEHELPER_HPP

#include <string>
#include <vector>
#include "../../lib/sqlite3.h"

class SQLiteHelper{
    public:
        static bool SetupDatabase();
        static bool ExecuteCommand(std::string sql);
        static std::vector<std::vector<std::string>> ExecuteSelect(std::string sql);
};

#endif