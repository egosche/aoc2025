# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
DATA_DIR = data

# Find all day source files
DAY_SRCS = $(wildcard $(SRC_DIR)/day*.cpp)
DAYS = $(patsubst $(SRC_DIR)/%.cpp,%,$(DAY_SRCS))
EXECUTABLES = $(addprefix $(BIN_DIR)/,$(DAYS))

# Shared sources (included in all builds)
SHARED_SRCS = \
	$(SRC_DIR)/range_tools.cpp \
	$(SRC_DIR)/compute.cpp

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(DAY_SRCS) $(SHARED_SRCS))

# Default target: build all executables
all: $(EXECUTABLES)

# Rule to build executables
$(BIN_DIR)/%: $(BUILD_DIR)/%.o $(filter-out $(BUILD_DIR)/day%.o,$(OBJS))
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run a specific day
# Usage: make run DAY=day01
run: $(BIN_DIR)/$(DAY)
	./$(BIN_DIR)/$(DAY)

# Clean build and bin directories
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)