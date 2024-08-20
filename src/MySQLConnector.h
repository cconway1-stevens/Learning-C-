// MySQLConnector.h
#ifndef MYSQLCONNECTOR_H
#define MYSQLCONNECTOR_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <string>

class MySQLConnector {
public:
    MySQLConnector();
    ~MySQLConnector();

    bool connect();
    sql::ResultSet* query(const std::string& query);

private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* connection;
    std::string host;
    std::string user;
    std::string password;
    std::string database;

    void loadEnv();
};

#endif // MYSQLCONNECTOR_H