#ifndef SECTION_H
#define SECTION_H

#include <string>
#include <iostream>

class Section
{
public:
	Section(const std::string&, const int&);
	std::string name;
	int time;
};

#endif // SECTION_H