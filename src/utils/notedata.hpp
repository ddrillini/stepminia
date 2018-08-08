#pragma once
#include <string>
#include <queue>

// contains notedata and beat types

// not really a beat so much as a subdivision
class beat
{
public:
	explicit beat(std::string str);

	int left = 0;
	int down = 0;
	int up = 0;
	int right = 0;
};

class notedata
{
public:
	explicit notedata(std::string filename); // explict to avoid implicit conversion
	// this is a problem with one-arg constructors.
	// that means that if you have a function foo(notedata)
	// and you pass a string by accident, you'll call the notedata
	// constructor instead of failing to compile
	std::queue<beat> note_queue;
};
