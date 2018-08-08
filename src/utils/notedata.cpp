#include "notedata.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

// contains notedata and note types

// string splitting functions because the STL doesn't have any 🔪🔪🔪
// https://stackoverflow.com/a/236803/1234621
template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

note::note(std::string str)
{
	if ( str[0] == '1' ) left = 1;
	if ( str[1] == '1' ) down = 1;
	if ( str[2] == '1' ) up = 1;
	if ( str[1] == '1' ) right = 1;
}

chart::chart(std::string str)
{
}

// Construct a notedata. Takes filename_string, instantiates chart type.
notedata::notedata(std::string filename)
{
	std::ifstream ifs (filename, std::ifstream::in);

	if ( ifs.fail() )
		abort();

	// fields that are global to all difficulties:
	// parse all the #TITLE:whatever; into a vector of pairs of strings

	// = Difficulty-specific fields =========================================
	// parse #NOTES: until the final, fifth colon

	// parse 0000 columns
	/*
	for (std::string line; std::getline(ifs, line, ','); )
	// this is a regular for loop, though it looks fancy
	{
		// if ;, we are done with the simfile
		if ( line == ";" )
			break;

		// create a measure, fill it with notes
		measure measure_inst(line);

		measure_inst.note_queue.push(note_inst);
	}

	chart_inst.measure_queue.push(measure_inst);
	*/

	// TODO: this should be handled by the main menu and should hand multiple difficulties
	// expert_chart = chart_inst; 
}
