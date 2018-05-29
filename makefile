TARGET	:= war 
HEADER  := $(wildcard src/*.h)
SOURCE	:= $(wildcard src/*.cpp)
OBJECT	:= $(patsubst src/%.cpp, obj/%.o, $(SOURCE))
DIR_bin := $(addprefix bin/, $(TARGET))
PROJECT_DIR := $(shell pwd)
INCLUDE_PATH := -I$(PROJECT_DIR)/src
CC		:= g++


$(TARGET): $(OBJECT) $(HEADER)
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
	@rm -rf obj
	@echo " Data cleaned!!"

.PHONY: doxygen
doxygen:
	@echo " Doxygen documentation making is in process."
	@doxygen Doxyfile	
	@echo " Doxygen is ready :D"
