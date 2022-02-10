#include <iostream>
#include<string>
#include <fstream>
#include <vector>
#include "functions.h"

int main() {
	std::string firstText = "Text.txt", secondText = "Text2.txt";
	std::string text = get_text();
	std::cout << "\nInput text:\n"<< text << "\n\n";
	fill_file(text, firstText);
	std::string text1 = edit_file(text,firstText);
	std::cout << "Output text:\n" << text1 << "\n\n";
	fill_file(text1, secondText);
}

