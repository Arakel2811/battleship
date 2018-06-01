#include <iostream>
#include <string>
#include "battleship.h"
#include <stdio.h>

bool test_get_sea()
{   
    int** sea = 0;
    int const size = 10;
    int const square_count = 20;
    int count = 0;
    create_array();
    create_sea();
    create_ships();
    final_sea();
    sea = get_sea();
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(1 == sea[i][j]) {
                ++count; 
            }
        }
    }   
    if( square_count == count ){
        return true;
    } 
	return false;
}

bool test_shoot_play()
{
    int** sea = 0;
    int const size = 10;
    int const square_count = 20;
    int x;
    int y;
    int pass_fail = 0;
    create_array();
    create_sea();
    create_ships();
    final_sea();
    sea = get_sea();
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(1 == sea[i][j]) {
              x = i;  
              y = j;
              break; 
            }
        }
    }   
    shoot(x, y);
    if(6 == sea[x][y]) {
        ++pass_fail;
    }
    sea = get_sea();
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(0 == sea[i][j]) {
              x = i;  
              y = j;
              break; 
            }
        }
    }   
    shoot(x, y);
    if(8 == sea[x][y]) {
        ++pass_fail;
    }
    if(2 == pass_fail){
        return true;
    } 
	  return false;
}

void write_test_results()
{
  FILE * myFile;
  myFile = fopen ("../test_result/tests.txt","w");
  if (myFile != NULL) {
     if(test_get_sea()) {
      fputs ("get_sea() test pass\n",myFile);
    } else {
        fputs ("get_sea() test fail\n",myFile);
      }
    if(test_shoot_play()) {
      fputs ("shoot_play() test pass\n",myFile);
    } else {
        fputs ("shoot_play() test fail\n",myFile);
      }
    fclose (myFile);
  } 
}

int main()
{
  write_test_results();

  return 0;
}
