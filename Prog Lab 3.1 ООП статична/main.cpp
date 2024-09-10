#include "Book.h"

int main() {
	Book book;
	if (book.loadSections("Sections.txt")) {
		book.chooseSections();
	}
}