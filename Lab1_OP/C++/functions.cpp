#include <iostream>
#include<string>
#include <fstream>
std::string get_text() {
	char ctrl_D = 4;
	std::string lines = {};
	std::string line;
	while (line[0] != ctrl_D) {
		getline(std::cin, line);
		lines += line + "\n";
	}
	lines = lines.substr(0, lines.size() - 3);
	return lines;
}
void fill_file(std::string text, std::string file) {
	std::ofstream fout(file, std::ios_base::out | std::ios_base::trunc);
	if (!fout.is_open())
		std::cout << "Error";
	fout << text;
	fout.close();
}
std::string edit_file(std::string text, std::string file_name) {
	std::string text1, text2, sent;
	std::ifstream rfile(file_name, std::ios::in);
	while (!rfile.eof()) {
		getline(rfile, sent);
		if (sent[0] != '#') 
			text1 += sent + "\n";
		else {
			sent = sent.substr(1, sent.size() / 2) + "!" + sent.substr((sent.size() / 2)+1, sent.size());
			text2 += sent + "\n";
		}
	}
	text1 = text1.substr(0, text1.size() - 3);
	text1 += "\n"+text2;
	return text1;
}
