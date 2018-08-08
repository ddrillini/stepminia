#pragma once
#include <string>
#include <queue>

// contains notedata and note types

class note
{
public:
	explicit note(std::string str);

	char left = 0;
	char down = 0;
	char up = 0;
	char right = 0;
};

class measure
{
public:
	measure() = default;
	measure(std::string str);
	std::queue<note> note_queue;
};

class chart
{
public:
	chart() = default; // means we don't want to actually implement this
	explicit chart(std::string str);
	std::queue<measure> measure_queue;
};

class notedata
{
public:
	notedata() = default;
	explicit notedata(std::string filename); // explict to avoid implicit conversion
	// this is a problem with one-arg constructors.
	// that means that if you have a function foo(notedata)
	// and you pass a string by accident, you'll call the notedata
	// constructor instead of failing to compile

	// TODO: setter function to set the current chart inside the notedata
	// object, and getter to get eg the next row
	chart expert_chart;
};
