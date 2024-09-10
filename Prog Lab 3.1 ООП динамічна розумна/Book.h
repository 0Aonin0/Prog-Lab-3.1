#ifndef BOOK_H
#define BOOK_H

#include "Section.h"
#include <string>
#include <vector>
#include <memory>

class Book
{
public:
	void addSection(std::unique_ptr<Section>);
	bool loadSections(const std::string&);
	void chooseSections();

private:
	std::vector<std::unique_ptr<Section>> sections;
};

#endif // BOOK_H