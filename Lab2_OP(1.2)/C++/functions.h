#pragma once
#include <iostream>
#include<vector>
#include<string>
#include <fstream>
struct product
{
	std::string name, firstDate, lastDate;
};
struct dates {
	int dayF, monthF, yearF, dayL, monthL, yearL;
};
void  outFromFile(std::string name);
std::vector<product> WriteToFile(std::string fileName);
int datesdifference(product a);
std::vector<int> DiffsVector(std::vector<product> v, product a);
void printVector(std::vector<int> a);
std::vector<int> LessThan5Days(std::vector<product> list, std::vector<int> datesDiffs);
bool WantToClear();
std::vector<product> AddToFile(std::string fileName);
void addToDiffFiles(std::vector<int> diffs, std::vector<product> prodList, std::string fileName, std::string fileName2);
void clearFile(std::string fileName);