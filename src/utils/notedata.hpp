#pragma once
#include <string>

class notedata
{
public:
	explicit notedata(std::string filename); // explict to avoid implicit conversion
	// that means that if you have a function foo(notedata)
	// and you pass a string by accident, you'll call the notedata
	// constructor instead of failing to compile
};
