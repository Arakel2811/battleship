#include "battleship.h"
#include <iostream>

/**
*@brief In main function we create a matrix, then matrix changes to sea by including zeros and set ships in the sea.
*@name Function "main()"
*@param Function doesn't have arguments.
*@return int. Function return 0.
*/
int main()
{  
   try {
    create_array();
    create_sea();
    create_ships();
    final_sea();
    print();
    play();
   } catch (std::bad_alloc& ba) {
       std::cout << "The system can not allocate enough memory for your program ... " << std::endl;
       std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
       return 123;
     } 
   return 0;
}
