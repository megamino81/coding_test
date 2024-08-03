# Makefile

CXX = g++
#CXXFLAGS = -Wall -Wextra -std=c++17
CXXFLAGS = -std=c++17

BUILD_DIR = build
SOURCES = $(wildcard *.cpp)
BINARY = $(SOURCES:%.cpp=$(BUILD_DIR)/%)


all: $(BUILD_DIR) $(BINARY)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/% : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
