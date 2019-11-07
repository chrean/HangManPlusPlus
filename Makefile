CXX		 		= g++
CXXFLAGS 		= -std=c++17
#LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    		= ./build
OBJ_DIR  		= $(BUILD)/objects
APP_DIR  		= $(BUILD)/apps
MAIN_TARGET  	= hangman
PARSE_TARGET    = parse
#INCLUDE  := -Iinclude/
MAIN_TARGET_SRC = src/main.cpp
PARSE_TARGET_SRC = src/parse.cpp

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(APP_DIR)/$(MAIN_TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(MAIN_TARGET) $(MAIN_TARGET_SRC)

$(APP_DIR)/$(PARSE_TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(PARSE_TARGET) $(PARSE_TARGET_SRC)


.PHONY: all build clean

all: build $(APP_DIR)/$(MAIN_TARGET) $(APP_DIR)/$(PARSE_TARGET)

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*