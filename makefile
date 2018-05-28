TARGET	:= war 
SOURCE	:= $(wildcard src/*.cpp)
OBJECT	:= $(patsubst src/%.cpp, obj/%.o, $(SOURCE))
DIR_bin := $(addprefix bin/, $(TARGET))
PROJECT_DIR := /home/student/Desktop/battleship
INCLUDE_PATH := -I$(PROJECT_DIR)/src
CC		:= g++


$(TARGET): $(OBJECT)
	@mkdir -p bin
	@$(CC) $^ -o bin/$@

obj/%.o: src/%.cpp
	@mkdir -p obj
	@$(CC) -c $^ $(INCLUDE_PATH) -o $@ 

.PHONY: clean
clean: 
	@echo " Cleaning data...."
	@rm -rf bin
	@rm -rf ./docs/doxygen
	@rm -rf ./obj/*.o
	@echo " Data cleaned!!"

.PHONY: doxygen
doxygen:
	@echo " Doxygen documentation making is in process."
	@doxygen Doxyfile	
	@echo " Doxygen is ready :D"
