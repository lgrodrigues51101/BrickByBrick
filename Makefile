CXX = g++
CXXFLAGS = -Wall -std=c++11 -I./config

# Source files
USER_SRC = user/user.cpp
CONFIG_SRC = config/read_config.cpp

# Object files
USER_OBJ = $(USER_SRC:.cpp=.o)
CONFIG_OBJ = $(CONFIG_SRC:.cpp=.o)

# Executable name
TARGET = server

all: $(TARGET)

$(TARGET): $(USER_OBJ) $(CONFIG_OBJ)
	$(CXX) $(USER_OBJ) $(CONFIG_OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(USER_OBJ) $(CONFIG_OBJ) $(TARGET)

.PHONY: all clean