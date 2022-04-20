#include <time.h>
#include <iostream>
#include <atltime.h>
#include <string>
#include <vector>
#include "functions.h"
void main()
{
	std::string fileName = "FirstFile.dat";
	std::string fileMore5 = "Long_term.dat";
	std::string fileLess5 = "Perishable.dat";
	if (WantToClear()) {
		clearFile(fileName);
		clearFile(fileMore5);
		clearFile(fileLess5);
	}
	std::vector<product> v;
	v = AddToFile(fileName);
	product a;
	std::vector <int> diffs = DiffsVector(v, a);
	system("cls");
	std::cout << "A L L   P R O D U C T S:\n";
	outFromFile(fileName);
	addToDiffFiles(diffs, v, fileLess5, fileMore5);
	std::cout << "\n\nP E R I S H A B L E: ";
	outFromFile(fileLess5);
	std::cout << "\n\nL O N G - T E R M:";
	outFromFile(fileMore5);
}
