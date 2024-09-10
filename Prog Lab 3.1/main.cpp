#include "Book.h"

int main() {
	std::vector<Section> book;
	if (loadSections(book, "Sections.txt")) {
		chooseSections(book);
	}
}