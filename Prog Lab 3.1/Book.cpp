#include "Book.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include <windows.h>

void addSection(std::vector<Section>& book, const std::string& name, const int& time) {
	book.push_back({name, time});
}

bool loadSections(std::vector<Section>& book, const std::string& file_name) {
	std::ifstream file(file_name);
	if (!file) {
		std::cerr << "ERROR: " << file_name << " can't be loaded!!!" << std::endl;
		return false;
	}

	std::string name;
	std::string time;
	while (std::getline(file, name) && std::getline(file, time)) {
		addSection(book, name, stoi(time));
	}

	file.close();
	return true;
}

void chooseSections(std::vector<Section>& book) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(out, 0x07);
	std::set<int> choosen;
	int size = book.size();
	int ans = 0;
	do {
		system("cls");
		std::cout << "choose sections from list (enter number):" << std::endl;
		std::cout << "enter \"0\" to finish" << std::endl << std::endl;
		std::cout << "section name       |    time to read (hours)" << std::endl;
		int num = 1;
		for (const auto& section : book) {
			if (choosen.count(num))SetConsoleTextAttribute(out, 0x0a);
			std::cout << num << ". " << std::setw(15) << section.name << "   " << section.time << std::endl;
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
		sum += book[num - 1].time;
	}
	std::cout << std::endl << "you will spend " << sum << " hours to read it." << std::endl << std::endl;
	system("pause");
}