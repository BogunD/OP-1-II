#pragma once
#include <iostream>
#include<string>
#include <fstream>
#include <vector>
std::vector<std::string> get_text();
void fill_file(std::vector<std::string> text, std::string file);
std::vector<std::string> edit_file(std::string file_name);
void printVector(std::vector<std::string> name);
