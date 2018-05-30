# battleship
This is the README file of the game Battleship developed by
Arakel Galeyan.

CONTENTS
        1. AUTHOR
        2. INTRODUCTION
        3. PREREQUISITES
        4. INSTALL
        5. DIRECTORY STRUCTURE
        6. USAGE
        7. DOCUMENTATION

1. AUTHOR
Arakel Galeyan
E-mail: galeyanarakel@gmail.com
Tel: +374-98-363766

Project Maintainer
	Arakel Galeyan 
	galeyanarakel@gmail.com

2. INTRODUCTION
This project is a game called Battliship which is written in C++ and is intended to be used only for entertainment purposes.
The game implements several basic features:

   1) Creation of game battlefield of 10x10 plates.
   2) Automatically generate ships.
   3) Providing a simple parameters based way of firing shots for the console application. The game will end when all ships will be damaged.

3. PREREQUISITES
The following third party tools and libraries should be installed before the compilation.

Tools:
g++
doxygen

1) Battleship uses prerequisite tools which would be
executed in the current environment. I.e. it does this by searching the
PATH for executable files. So if the prerequisite tools are not installed in
standard paths in your system, make sure you have setup your environment
properly. I.e. PATH contains paths of prerequisite paths.

2) Build the project
	make

3) Generate Doxygen documentation
	make doxygen

4) Delete the project
	make clean

4. DIRECTORY STRUCTURE

src/            - the source files of the project
src/docs/       - the documentation of the project.
makefile        - top level makefile to build / run the project
Doxyfile        - doxygen configuration for the documentation of the project

5. USAGE
 After downloading the project open terminal in battlefild folder and enter "make" command. There will be created folder bin and obj. In obj will be object files of source 
code and in bin will be executable file with the help of which one can run the game. Go to the bin folder and type in terminal "./war". After typing the command the game will 
start, it'll automatically place the ships. After finishing placement of ships (10 ships) the game will ask you to type coordinates for shooting untill you destroy 
all the ships. The game will be finished after destroying all the ships. In battleship folder you can also run "make doxygen" and doxygen documentation will be created in docs folder. 
Besides, in battleship folder you can run "make clean" command which will delete bin folder, content of obj folder and doxygen documentation.

6. DOCUMENTATION
"make" command will be created folder bin and obj.
"make doxygen" command generates doxygen documentation.
"make clean" command will delete bin and obj folders, and doxygen documentation.

The source code of the documentation is located in the directory src/docs.

Doxygen also generates documentation from C/C++ code comments.

