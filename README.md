# battleship
About: As you can see this project consisits of the following folders: docs, tests, src and a makefile. In folder docs one can find all the documantation that is needed for this project 
(devspec, fspec, prd). In foder test are written tests for this project. Folder src contains main source code of the project.

Short manual: After downloading the project open terminal in battlefild folder and enter "make" command. There will be created folder bin and obj. In obj will be object files of source 
code and in bin will be executable file with the help of which one can run the game. Go to the bin folder and type in terminal "./war". After typing the command the game will 
start, it'll automatically place the ships. After finishing placement of ships (10 ships) the game will ask you to type coordinates for shooting untill you destroy 
all the ships. The game will be finished after destroying all the ships. In battleship folder you can also run "make doxygen" and doxygen documentation will be created in docs folder. 
Besides, in battleship folder you can run "make clean" command which will delete bin folder, content of obj folder and doxygen documentation.

The game: This project is a game called Battliship which is written in C++ and is intended to be used only for entertainment purposes. The game implements several basic features:

   1) Creation of game battlefield of 10x10 plates.
   2) Automatically generate ships.
   3) Providing a simple parameters based way of firing shots for the console application. The game will end when all ships will be damaged.
