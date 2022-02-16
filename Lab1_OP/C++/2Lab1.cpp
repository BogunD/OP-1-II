#include <iostream>
#include<string>
#include <fstream>
#include <vector>
#include "functions.h"

int main() {
	std::string firstName = "Text.txt", secondName = "Text2.txt";
	std::vector <std::string> text = get_text();
	std::cout << "\nI N P U T   T E X T:\n";
	printVector(text);
	fill_file(text, firstName);
	std::vector<std::string> text1 = edit_file(firstName);
	std::cout << "\n\nO U T P U T   T E X T :\n";
	printVector(text1);
	fill_file(text1, secondName);
}

