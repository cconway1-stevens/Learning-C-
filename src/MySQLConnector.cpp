// MySQLConnector.cpp
#include "MySQLConnector.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

MySQLConnector::MySQLConnector() : driver(nullptr), connection(nullptr) {
    loadEnv();
}

MySQLConnector::~MySQLConnector() {
    delete connection;
}

void MySQLConnector::loadEnv() {
    std::ifstream envFile(".env");
    if (!envFile.is_open()) {
        throw std::runtime_error("Could not open .env file");
    }

    std::string line;
    while (std::getline(envFile, line)) {
        std::istringstream ss(line);
        std::string key, value;
        if (std::getline(ss, key, '=') && std::getline(ss, value)) {
            if (key == "DB_HOST") host = value;
            else if (key == "DB_USER") user = value;
            else if (key == "DB_PASS") password = value;
            else if (key == "DB_NAME") database = value;
        }
    }
    envFile.close();
}

bool MySQLConnector::connect() {
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        connection = driver->connect(host, user, password);
        connection->setSchema(database);
        return true;
    } catch (sql::SQLException& e) {
        std::cerr << "Could not connect to the database. Error: " << e.what() << std::endl;
        return false;
    }
}

sql::ResultSet* MySQLConnector::query(const std::string& query) {
    sql::Statement* stmt = connection->createStatement();
    return stmt->executeQuery(query);
}