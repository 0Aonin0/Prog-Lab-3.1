#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

struct Section {
public:
	std::string name;
	int time;
};

void addSection(std::vector<Section>&, const std::string&, const int&);

bool loadSections(std::vector<Section>&, const std::string&);

void chooseSections(std::vector<Section>&);

#endif // BOOK_H