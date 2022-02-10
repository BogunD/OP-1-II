#pragma once
#include <iostream>
#include<string>
#include <fstream>
#include <vector>
std::string get_text();
void fill_file(std::string text, std::string file);
std::string edit_file(std::string text, std::string file_name);