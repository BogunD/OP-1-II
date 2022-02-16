#include <iostream>
#include<string>
#include <fstream>
#include <vector>
std::vector<std::string> get_text() {
	char ctrl_D = 4;
	std::vector<std::string> lines;
	std::string line = "";
	while (line[0] != ctrl_D) {
		getline(std::cin, line);
		lines.push_back(line);
	}
	lines.pop_back();
	return lines;
}
void fill_file(std::vector<std::string> text, std::string file) {
	std::ofstream fout(file, std::ios_base::out | std::ios_base::trunc);
	if (!fout.is_open())
		std::cout << "Error";
	int i;
	for (i = 0; i < text.size(); i++) {
		fout << text[i]<<"\n";
	}
	fout.close();
}
std::vector<std::string> edit_file( std::string file_name) {
	std::vector<std::string> text1, text2;
	std::string	sent;
	std::ifstream rfile(file_name, std::ios::in);
	while (!rfile.eof()) {
		getline(rfile, sent);
		if (sent[0] != '#')
			text1.push_back(sent);
		else {
			sent = sent.substr(1, sent.size() / 2) + "!" + sent.substr((sent.size() / 2)+1, sent.size());
			text2.push_back(sent);
		}
	}
	text1.pop_back();
	text1.insert(text1.end(), text2.begin(), text2.end());
	return text1;
}
void printVector(std::vector<std::string> name) {
	for (int i = 0; i < name.size(); i++) {
		std::cout << name[i]<<"\n";
	}
}
