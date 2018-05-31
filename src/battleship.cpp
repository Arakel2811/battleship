#include <iostream>
#include <cstdlib>
#include <ctime>
#include <assert.h>
#include <string>

const unsigned int size = 10;
enum {hor, vert};
int** array = 0;

/**
 *@brief Function creates a matrix.
 *@name Function "create_array()" 
 *@param Function doesn't have arguments.
 *@return void. Function doesn't returns value.
 */
void create_array()
{ 
   array = new int* [size];
   if(!array) {
     throw std::bad_alloc();
   }
   for(int i = 1 ; i <= size; ++i) {
     array[i-1] = new int [size]; 
     if(!array[i - 1]) {
     throw std::bad_alloc();
     }
   } 
}

/**
 *@brief Function prints a matrix
 *@name Function "print()"
 *@param Function doesn't have arguments.
 *@return void. Function doesn't returns value.
 */
void print()
{
  for(int i = 1; i <= size; ++i) {
    for(int j = 1; j <= size; ++j) {
      std::cout << array[i-1][j-1] << " ";
    }
    std::cout << std::endl;
  }
}

/**
 *@brief Function generates a number.
 *@name Function "random()"
 *@param min is an integer number.
 *@param max is an integer number.
 *@return int. Function returns an integer number.
 */
int random(int min, int max)
{	
  if(min == max) {
  min -= 1; 
  }
  return min + rand() % (max - min);
}

/**
 *@brief Function sets zeros in the matrix 
 *@name Function "create_sea()"
 *@param Function doesn't have arguments.
 *@return void. Function doesn't returns value.
 */
void create_sea()
{
  for(int i = 1; i <= size; ++i) {
    for(int j = 1; j <= size; ++j) {
      array[i-1][j-1] = 0;
    }
  }
}

/**
 *@brief Function sets a ship.
 *@name Function "append_ship()"
 *@param x is an integer number, the abscissa of the field.
 *@param y is an integer number, the ordinate of the field.
 *@param length is an integer number, the length of the ship.
 *@param direction is an integer number 0 or 1, the direction of the ship.
 *@return void. Function doesn't returns value.
 */
void append_ship(int x, int y, int length, int direction)
{
  if (hor == direction) {
    for (int i = 1; i <= length; ++i) {
      assert(x < size);
      assert(y + i - 1 < size);
      array[x][y + i - 1] = 1;
    }
  } else if(vert == direction) {
      for (int i = 1; i <= length; ++i) {
        assert(x + i - 1 < size);
        assert(y < size);
        array[x + i - 1][y] = 1;
      }
    }
}

/**
 *@brief Function is_square_checked for a free space for replaceing a ship.
 *@name Function "is_square_checked()"
 *@param x is an integer number, the abscissa of the field.
 *@param y is an integer number, the ordinate of the field.
 *@param d is an integer number(0 or 1), the direction of a created ship.
 *@param l is an integer number, the length of the ship.
 *@return bool. Function returns a boolean value.
 */
bool is_square_checked(int x, int y, int d, int l)
{    
  if(vert == d) {
    if(x + l >= size || y >= size) {
      return false;
    } else {
        for(int i = 0; i < l; ++i) {
          assert(x + i < size);
          assert(y < size);
          if(0 != array[x + i][y]) {
            return false;
          }
        } 
        return true;
      }
  } else {
      if(y + l >= size || x >= size) {
        return false;
      } else {
        for (int i = 0; i < l; ++i) {
          if (0 != array[x][y + i]) {
            return false;
          }
        }
        return true;
       }
    }
}

/**
 *@brief Function checks for a correct position in the sea.
 *@name Function "check_position()
 *@param x is an integer number, the abscissa of the field.
 *@param y is an integer number, the ordinate of the field.
 *@return bool. Function returns a boolean value.
 */
bool check_position(const int x, const int y)
{
  if(x < size && y < size) {
    return true;
  }
  return false;
}

/**
 *@brief Function checks for a free square in the sea.
 *@name Function "is_square_free()
 *@param x is an integer number, the abscissa of the field.
 *@param y is an integer number, the ordinate of the field.
s_square_free 
 *@return bool. Function returns a boolean value.
 */
bool is_square_free(int x, int y)
{
  return !(array[x][y]);
}

/**
 *@brief Function checks if in that square is a ship in the sea.
 *@name Function "is_ship()
 *@param x is an integer number, the abscissa of the field.
 *@param y is an integer number, the ordinate of the field.
 *@return int. Function returns an array[x][y]'s value.
 */
int is_ship(int x, int y)
{
  return array[x][y];
}

/**
 *@brief Function sets 2 arround a single cell.
 *@name Function "set_around_for_single_cell()"
 *@param x is an integer number, the abscissa of the field.
 *@param y is an integer number, the ordinate of the field.
 *@return void. Function doesn't returns value.
 */
void set_around_for_single_cell(int x, int y)
{
  for (int i = -1; i < 2; ++i) {
    if (check_position(x - 1, y + i) && is_square_free(x - 1, y + i)) {
      assert(unsigned(x - 1) < size);
      assert(unsigned(y + i) < size);
      array[x - 1][y + i] = 2;
    }
  }
  for (int i = -1; i < 2; i += 2) {   
    if (check_position(x, y + i) && is_square_free(x, y + i)) { 
      assert(unsigned(x) < size);
      assert(unsigned(y + i) < size);
      array[x][y + i] = 2;    
    }  
  }
  for (int i = -1; i < 2; ++i) {
    if (check_position(x + 1, y + i) && is_square_free(x + 1, y + i)) {
      assert(unsigned(x + 1) < size);
      assert(unsigned(y + i) < size);
      array[x + 1][y + i] = 2;
    } 
  }
}

/**
 *@brief Function sets 2 arround the ship.
 *@name Function "set_around()"
 *@param x is an integer number, the abscissa of the field.
 *@param y is an integer number, the ordinate of the field.
 *@param d is an integer number(0 or 1), the direction of a created ship.
 *@param l is an integer number, the length of the ship.
 *@return void. Function doesn't return a value.
 */
void set_around(int x, int y, int d, int l)
{
  set_around_for_single_cell(x,y);
  if (hor == d) {
    set_around_for_single_cell(x, y + l - 1);
  } else {
    set_around_for_single_cell(x + l - 1, y);
  }
}

/**
 *@brief Function creates all ships for the game.
 *@name Function "create_ships()"
 *@param Function doesn't have arguments.
 *@return void. Function doesn't return a value.
 */
void create_ships()
{
  srand(time(0));
  int ship_length = 4;
  for (int length = ship_length; length > 0; --length){
    int x = random(0, size);
    int y = random(0, size);
    int d = random(0,2);
    for(int i = 0; i < 5 - length; ++i) {
      while(true) {
        if(is_square_checked(x,y,d,length)) {
          append_ship(x, y, length, d);
          set_around(x,y,d,length);
          break;
        } else {
            x = random(0, size);
            y = random(0, size);
            d = random(0, 2);
          }
      }
    }
  }
}

/**
 *@brief shooting. If in the field of ship is "1" prints "The field is damaged" and prints in that place 6, else "The field *is empty" and prints 8.
 *@name Function "shoot"
 *@param x is an integer number, the abscissa of the field.
 *@param y is an integer number, the ordinate of the field.
 *@return void. Function doesn't return a value.
 */
void shoot(int x, int y)
{
  if(6 == is_ship(x, y) || 8 == is_ship(x, y)) { 
    std::cout << "Sorry but you already asked for this field !!!!" << std::endl;
    print();
  }
  else if(0 == is_ship(x, y)) {
    std::cout << "The field is empty." << std::endl;
    array[x][y] = 8;
    print();
  }
  else if(1 == is_ship(x, y)) {
    std::cout << "The field is damaged." << std::endl;
    array[x][y] = 6;
    print();
  }
}

/**
 *@brief Function replaces all "2" to "0" in the sea.
 *@name Function "final_sea"
 *@param Function doesn't have arguments.
 *@return void. Function doesn't return a value.
 */
void final_sea()
{
  for(int i = 1; i <= size; ++i) {
    for(int j = 1; j <= size; ++j) {
      if(2 == array[i-1][j-1]) {
        array[i-1][j-1] = 0;
      }
    }
  }
}

/**
 *@brief Function takes as an input coordinat of x or y, and error then assignes their values.
 *@name Function "verify_coordinate_format"
 *@param ptr is a pointer to the X or Y coordinate.
 *@param err is a pointer to the error. 
 *@return void. Function doesn't return a value.
*/
void verify_coordinate_format(int* ptr, int* err)
{
  std::string x = "";
  std::cin >> x;
  char array[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  if (1 == x.size()) {
    int n = 0; 
    for (int i = 0; i < size; ++i) {
      if (x[0] == array[i]) {
        ++n;
        break;
      }
    }
    if (n > 0) {
      *err = 0;
      *ptr = (x[0] - '0');
    } else {
        *err = 1;
        std::cout << "Please insert numbers only from 0 to 9." << std::endl;
      }
  } else {
      *err = 1;
      std::cout << "Please insert numbers only from 0 to 9." << std::endl;
    }
}

/**
   *@brief Function deletes the sea
   *@name Function "delete_sea()"
   *@param array is a two dementional array.
   *@return void. Function doesn't return a value.
   */
void delete_sea()
{
  assert(array);
  for(int i = 0; i < size; ++i) {
    delete [] *(array + i);
  }
  delete [] array;
} 

/**
 *@brief Function calls verify_coordinate_format() function, and returns if any ship was damaged or not.
 *@name Function "play"
 *@param Function doesn't have arguments.
 *@return void. Function doesn't return a value.
 */
void play()
{
  int x = 0;    
  int y = 0;
  int count = 20;
  while(count > 0) {
    int error = 0;
    std::cout<< "Enter X : " << std::endl;
    verify_coordinate_format(&x, &error);
    if(1 == error) {
      continue;
    }
    std::cout<< "Enter Y : " << std::endl;
    verify_coordinate_format(&y, &error);
    if(1 == error) {
      continue;
    }
    if(is_ship(x, y)) {
      --count;
      shoot(x,y);    
    } else {
      shoot(x,y);
      continue;
    }
  }
  std::cout << "Game over" << std::endl;
  delete_sea();
}

