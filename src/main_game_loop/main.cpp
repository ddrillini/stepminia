#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <queue>
#include <ctime>

#include "../all_includes.h"

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

int main()
{
	std::cout << "Note that stepminia must currently be run from the"
		<< "executable's directory, because it expects the assets folder"
		<< "to be in the current working directory." << std::endl;

	#include "window_setup.cpp"

	//Game States
	playfield playfield_inst;
	menu menu_inst;

	//Pointer for housing state
	base_screenstate* screenstate(&playfield_inst);

	#include "receptor_setup.cpp"
	#include "main_loop.cpp"

	_CrtDumpMemoryLeaks();
}
