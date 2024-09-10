#include "Book.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <iomanip>
#include <windows.h>

void Book::addSection(std::unique_ptr<Section> section) {
	sections.push_back(std::move(section));
};

bool Book::loadSections(const std::string& file_name) {
	std::ifstream file(file_name);
	if (!file) {
		std::cerr << "error: " << file_name << " can't be loaded!!!" << std::endl;
		return false;
	}

	std::string name;
	std::string time;
	while (std::getline(file, name) && std::getline(file, time)) {
		std::unique_ptr<Section> sec = std::make_unique<Section>(Section(name, stoi(time)));
		addSection(std::move(sec));
	}

	file.close();
	return true;
};

std::ostream& operator<<(std::ostream& a, const Section& section) {
	a << std::setw(15) << section.name << "   " << section.time;
	return a;
}

void Book::chooseSections() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(out, 0x07);
	std::set<int> choosen;
	int size = sections.size();
	int ans = 0;
	do {
		system("cls");
		std::cout << "choose sections from list (enter number):" << std::endl;
		std::cout << "enter \"0\" to finish" << std::endl << std::endl;
		std::cout << "section name       |    time to read (hours)" << std::endl;
		int num = 1;
		for (const auto& section : sections) {
			if (choosen.count(num))SetConsoleTextAttribute(out, 0x0a);
			std::cout << num << ". " << *section << std::endl;
			SetConsoleTextAttribute(out, 0x07);
			++num;
		}
		std::cout << std::endl;
		std::cin >> ans;
		if (ans <= size && ans > 0) {
			if (choosen.count(ans)) {
				choosen.erase(ans);
			}
			else choosen.insert(ans);
		}
	} while (ans != 0);
	int sum = 0;
	for (auto num : choosen) {
		sum += sections[num - 1]->time;
	}
	std::cout << std::endl << "you will spend " << sum << " hours to read it." << std::endl << std::endl;
	system("pause");
}