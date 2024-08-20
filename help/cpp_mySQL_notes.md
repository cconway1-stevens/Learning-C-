---

# C++ Coding Cheat Sheet

## Table of Contents

1. [Basic Syntax and Setup](#basic-syntax-and-setup)
2. [Common Libraries and Their Uses](#common-libraries-and-their-uses)
   - [`<iostream>`](#iostream)
   - [`<vector>`](#vector)
   - [`<string>`](#string)
   - [`<algorithm>`](#algorithm)
   - [`<map>`](#map)
   - [`<set>`](#set)
   - [`<cmath>`](#cmath)
   - [`<fstream>`](#fstream)
   - [`<thread>`](#thread)
   - [`<chrono>`](#chrono)

3. [MySQL Database Connection](#mysql-database-connection)
   - [MySQL Connector Setup](#mysql-connector-setup)
   - [Connecting to a MySQL Database](#connecting-to-a-mysql-database)

4. [Useful Tips](#useful-tips)

---

## Basic Syntax and Setup

```cpp
#include <iostream>  // For standard input/output operations
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```

---

## Common Libraries and Their Uses

### `<iostream>`

- **Purpose**: Input/output stream.

- **Common Commands**:

```cpp
int x;
cin >> x;                   // Input an integer
cout << "Value: " << x << endl;  // Output an integer
cerr << "Error message" << endl; // Output error message
```

### `<vector>`

- **Purpose**: Dynamic array.

- **Common Commands**:

```cpp
#include <vector>
vector<int> v;               // Create an empty vector
v.push_back(10);            // Add element to the end
v.pop_back();               // Remove the last element
v.size();                   // Get the number of elements
v[2];                       // Access element at index 2
v.front();                  // Access the first element
v.back();                   // Access the last element
v.empty();                  // Check if the vector is empty
v.insert(v.begin(), 20);    // Insert 20 at the beginning
v.erase(v.begin());         // Erase the first element
v.clear();                  // Remove all elements
```

### `<string>`

- **Purpose**: String operations.

- **Common Commands**:

```cpp
string s = "Hello";
s += " World";              // Concatenate strings
s.size();                   // Get length of the string
s.substr(1, 4);             // Get substring from index 1 of length 4
s.find("llo");              // Find substring, returns index
s.erase(0, 2);              // Erase characters from index 0 to 2
s.insert(2, "abc");         // Insert "abc" at index 2
s.clear();                  // Clear the string
```

### `<algorithm>`

- **Purpose**: Standard algorithms like sort, find, etc.

- **Common Commands**:

```cpp
#include <algorithm>
vector<int> v = {4, 2, 3, 1};
sort(v.begin(), v.end());            // Sort in ascending order
reverse(v.begin(), v.end());         // Reverse the vector
int maxElem = *max_element(v.begin(), v.end());  // Find the max element
int minElem = *min_element(v.begin(), v.end());  // Find the min element
find(v.begin(), v.end(), 3);         // Find element 3
count(v.begin(), v.end(), 2);        // Count occurrences of 2
```

### `<map>`

- **Purpose**: Associative array (key-value pairs).

- **Common Commands**:

```cpp
#include <map>
map<string, int> m;
m["apple"] = 50;                     // Insert key-value pair
m["banana"] = 100;
m.size();                            // Get number of elements
m["apple"];                          // Access value by key
m.erase("apple");                    // Remove element by key
m.find("banana");                    // Find element by key
m.clear();                           // Remove all elements
```

### `<set>`

- **Purpose**: Collection of unique elements.

- **Common Commands**:

```cpp
#include <set>
set<int> s;
s.insert(10);               // Insert an element
s.insert(20);
s.size();                   // Get number of elements
s.erase(10);                // Remove an element
s.find(20);                 // Find an element
s.clear();                  // Remove all elements
```

### `<cmath>`

- **Purpose**: Mathematical functions.

- **Common Commands**:

```cpp
#include <cmath>
double x = 9.0;
sqrt(x);            // Square root
pow(x, 3);          // x raised to the power 3
abs(-5);            // Absolute value
ceil(4.3);          // Round up to nearest integer
floor(4.7);         // Round down to nearest integer
sin(M_PI/2);        // Sine function
cos(0);             // Cosine function
log(1.0);           // Natural logarithm
exp(2.0);           // e^x
```

### `<fstream>`

- **Purpose**: File operations.

- **Common Commands**:

```cpp
#include <fstream>
ofstream ofs("output.txt");   // Create and open file for writing
ofs << "Text" << endl;        // Write text to file
ofs.close();                  // Close the file

ifstream ifs("input.txt");    // Open file for reading
string line;
while (getline(ifs, line)) {  // Read file line by line
    cout << line << endl;
}
ifs.close();                  // Close the file
```

### `<thread>`

- **Purpose**: Multithreading.

- **Common Commands**:

```cpp
#include <thread>
void myFunction() { /* code */ }
thread t1(myFunction);   // Start a new thread
t1.join();               // Wait for the thread to finish
t1.detach();             // Detach the thread (run independently)
this_thread::sleep_for(chrono::seconds(1));  // Sleep for 1 second
```

### `<chrono>`

- **Purpose**: Timing and clocks.

- **Common Commands**:

```cpp
#include <chrono>
using namespace std::chrono;
auto start = high_resolution_clock::now();  // Start timer
// Code to measure
auto stop = high_resolution_clock::now();   // Stop timer
auto duration = duration_cast<microseconds>(stop - start);
cout << duration.count() << " microseconds" << endl;
```

---

## MySQL Database Connection

### MySQL Connector Setup

- **Installation**: Use a MySQL C++ connector library, e.g., MySQL Connector/C++.

### Connecting to a MySQL Database

- **Example Code**:

```cpp
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

using namespace std;
using namespace sql::mysql;

int main() {
    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "username", "password"));
        con->setSchema("database_name");

        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM table_name"));

        while (res->next()) {
            cout << "Column Data: " << res->getString("column_name") << endl;
        }
    } catch (sql::SQLException& e) {
        cout << "SQLException: " << e.what() << endl;
    }
    return 0;
}
```

---

## Useful Tips

- **Error Handling**: Always use try-catch blocks when working with file operations and database connections to handle exceptions.
- **Documentation**: Refer to official documentation for each library for advanced features and updates.

---

This format uses sections and containers to make the information more organized and easier to read.
