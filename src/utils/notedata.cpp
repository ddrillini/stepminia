#include "notedata.hpp"
#include <iostream>
#include <fstream>

// contains notedata and beat types

beat::beat(std::string str)
{
	// L D U R
	if ( str[0] == '1' )
		left = 1;
	if ( str[1] == '1' )
		down = 1;
	if ( str[2] == '1' )
		up = 1;
	if ( str[1] == '1' )
		right = 1;
}

notedata::notedata(std::string filename)
{
	// open the file
	/* looks like
	0000
	0110
	0000
	1001 */
	// read entire file into a single string.

	std::ifstream ifs (filename, std::ifstream::in);

	if ( ifs.fail() )
		abort();

	for (std::string line; std::getline(ifs, line); )
	{
		beat beat_inst(line);
		note_queue.push(beat_inst);
	}

	// in parser.cpp, iterate over the string, parse each line into a class
	// beat, that simply contains int LEFT, DOWN, UP, RIGHT; throw these
	// all into a queue inside the notedata class

	// main should look roughly like 
	// notedata simfile1("filename");
	// simfile1.parse; // parses simfile string into a queue of beats
	// then maybe try drawing this to the screen, but you'll have to figure
	// out that
}
