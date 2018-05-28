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
    finall_sea();
    print();
    play();
   } catch (const std::overflow_error& e) {
    // this executes if f() throws std::overflow_error (same type rule)
    std::cerr << "overflow_error" << std::endl;    
  } catch (const std::runtime_error& e) {
    // this executes if f() throws std::underflow_error (base class rule)
    std::cerr << "runtime_error" << std::endl;
  } catch (const std::exception& e) {
    // this executes if f() throws std::logic_error (base class rule)
    std::cerr << "exception" << std::endl;
  } catch (std::bad_alloc& ba) {
    std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
  } catch (...) {
    // this executes if f() throws std::string or int or any other unrelated type
    std::cout << " Oops something went wrong !!!" << std::endl;
  }
  return 0;
}
