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

// << for notes
std::ostream& operator<<(std::ostream& stream, const note& note_inst)
{
	if ( note_inst.left )
		stream << "1";
	else
		stream << "0";
	if ( note_inst.down )
		stream << "1";
	else
		stream << "0";
	if ( note_inst.up )
		stream << "1";
	else
		stream << "0";
	if ( note_inst.right )
		stream << "1";
	else
		stream << "0";
	stream << std::endl;
	return stream;
}

// "XXXX" string from simfile to memory
note::note(std::string str)
{
	if ( str[0] == '1' ) left = 1;
	if ( str[1] == '1' ) down = 1;
	if ( str[2] == '1' ) up = 1;
	if ( str[3] == '1' ) right = 1;
}

measure chart::get_top_measure()
{
	return measure_deque.front();
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

	chart chart_inst;
	measure measure_inst;

	// parse 0000 columns
	for (std::string line; std::getline(ifs, line); )
	// this is a regular for loop, though it looks fancy
	{
		// ; - we are done with the current difficulty
		if ( line.find(";") != -1 )
		{
			// push the last measure
			chart_inst.measure_deque.push_back(measure_inst);
			break;
		}

		// , - we're done with the measure
		if ( line.find(",") != -1 )
		{
			chart_inst.measure_deque.push_back(measure_inst);
			measure_inst = measure();
			continue;
		}

		// create a measure, fill it with notes
		note note_inst(line);
		measure_inst.note_deque.push_back(note_inst);
	}

	// TODO: this should be handled by the main menu and should hand multiple difficulties
	expert_chart = chart_inst; 
	active_chart = &expert_chart;
}
