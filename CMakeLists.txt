CXX = g++
CXXFLAGS = -std=c++11 -I/usr/local/include/mysql
LDFLAGS = -L/usr/local/lib -lmysqlcppconn

SRC = src/main.cpp src/MySQLConnector.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = MySQLProject

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)