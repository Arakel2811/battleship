TARGET	:= test
SOURCE	:= ../src/battleship.cpp
SOURCE_TEST := $(wildcard ./*.cpp)
DEPS     := $(patsubst src/%.cpp, deps/%.dep, $(SOURCE))
OBJ_TEST := $(patsubst %.cpp, %.o, $(SOURCE_TEST))
INCLUDE_PATH := -I../src/
CC		:= g++
OBJECT := battleship.o

	
$(TARGET): $(OBJECT) $(OBJ_TEST)
	@mkdir -p ../test_results
	@$(CC) $^ -o $@

%.o: %.cpp 
	@$(CC) -c $^ $(INCLUDE_PATH) -o $@ 

battleship.o : $(SOURCE)
	@$(CC) -c $^ $(INCLUDE_PATH) -o $@

dep/%.dep : src/%.cpp
	@mkdir -p ./deps
	@$(CC) -MM $< -MT "$@ $(patsubst %.dep, %.o, $@)" -o $@ -I./src
  
	-include $(DEPS)

.PHONY: clean
clean: 
	@echo " Cleaning test data...."
	@rm -rf ./*.o
	@rm -rf test
	@echo " Test data cleaned!!"



