#include <battleship.h>

/**
*@brief In main function we create a matrix, then matrix changes to sea by including zeros and set ships in the sea.
*@name Function "main()"
*@param Function doesn't have arguments.
*/
int main()
{
  create_array();
  create_sea();
  create_ships();
  finall_sea();
  print();
  play();
  return 0;
}
