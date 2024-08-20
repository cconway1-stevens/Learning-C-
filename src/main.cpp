// main.cpp
#include "MySQLConnector.h"
#include <iostream>


int main() {
    MySQLConnector dbConnector;

    if (!dbConnector.connect()) {
        std::cerr << "Failed to connect to the database." << std::endl;
        return 1;
    }

    sql::ResultSet* res = dbConnector.query("SELECT VERSION()");
    while (res->next()) {
        std::cout << "MySQL Version: " << res->getString(1) << std::endl;
    }

    delete res;
    return 0;
}