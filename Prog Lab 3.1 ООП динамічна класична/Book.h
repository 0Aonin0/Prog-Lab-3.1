#ifndef BOOK_H
#define BOOK_H

#include "Section.h"
#include <string>
#include <vector>

class Book
{
public:
	void addSection(Section*);
	bool loadSections(const std::string&);
	void chooseSections();
	~Book();
private:
	std::vector<Section*> sections;
};

#endif // BOOK_H