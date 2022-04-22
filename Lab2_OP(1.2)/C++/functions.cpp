#include <iostream>
#include<vector>
#include<string>
#include <fstream>
#include "functions.h"
#include <atltime.h>
std::ostream& write(std::ostream& out, product const& data)
{
	size_t len = data.name.size();
	out.write((char const*)&len, sizeof(len));
	out.write(data.name.c_str(), len);
	size_t lenf = data.firstDate.size();
	out.write((char const*)&lenf, sizeof(lenf));
	out.write(data.firstDate.c_str(), lenf);
	size_t lenl = data.lastDate.size();
	out.write((char const*)&lenl, sizeof(lenl));
	out.write(data.lastDate.c_str(), lenl);
	return out;
}
std::istream& read(std::istream& in, product& data)
{
	size_t len;
	in.read((char*)&len, sizeof(len));
	if (!in) return in; //fix

	char* name = new char[len + 1];
	in.read(name, len);
	if (!in) { delete[] name; return in; } // fix
	name[len] = '\0';
	data.name = name;
	delete[] name;

	size_t lenf;
	in.read((char*)&lenf, sizeof(lenf));
	if (!in) return in; // fix

	char* firstDate = new char[lenf + 1];
	in.read(firstDate, lenf);
	if (!in) { delete[] firstDate; return in; } // fix

	firstDate[lenf] = '\0';
	data.firstDate = firstDate;
	delete[] firstDate;

	size_t lenl;
	in.read((char*)&lenl, sizeof(lenl));
	if (!in) return in; // fix

	char* lastDate = new char[lenl + 1];
	in.read(lastDate, lenl);
	if (!in) { delete[] lastDate; return in; } // fix
	lastDate[lenl] = '\0';
	data.lastDate = lastDate;
	delete[] lastDate;

	return in;
}

int datesdifference(product a) {
	dates b;
	b.dayF = std::stoi(a.firstDate.substr(0, 2));
	b.dayL = std::stoi(a.lastDate.substr(0, 2));
	b.monthF = std::stoi(a.firstDate.substr(3, 5));
	b.monthL = std::stoi(a.lastDate.substr(3, 5));
	b.yearF = std::stoi(a.firstDate.substr(6));
	b.yearL = std::stoi(a.lastDate.substr(6));
	CTime t1(b.yearF, b.monthF, b.dayF, 0, 0, 0);
	CTime t2(b.yearL, b.monthL, b.dayL, 0, 0, 0);
	CTimeSpan ts = t2 - t1;
	int days = ts.GetDays();
	return days;
}
bool isOverdue(product a) {
	dates b;
	b.dayL = std::stoi(a.lastDate.substr(0, 2));
	b.monthL = std::stoi(a.lastDate.substr(3, 5));
	b.yearL = std::stoi(a.lastDate.substr(6));
	CTime t1 = CTime::GetCurrentTime();
	CTime t2(b.yearL, b.monthL, b.dayL, 0, 0, 0);
	CTimeSpan ts = t2 - t1;
	int days = ts.GetDays();
	if (days >= 0)
		return false;
	else
		return true;
}

bool WantToClear() {
	char ans;
	std::cout << "Do you want to clear file? (Y/N)\n";
	std::cin >> ans;
	while (ans != 'n' && ans != 'N' && ans != 'y' && ans != 'Y') {
		std::cout << "Incorrect answer. Try again: ";
		std::cin >> ans;
	}
	std::cin.ignore();
	if (ans == 'Y' || ans == 'y')
		return true;
	else
		return false;
}

bool DateIsCorrect(std::string date)
{
	
	int day = std::stoi(date.substr(0, 2));
	int month = std::stoi(date.substr(3, 5));
	int year = std::stoi(date.substr(6));
	if (month > 12 || month < 1) return false;
	if (day > (30 + ((month + (month / 8)) % 2)) || day < 1) return false;
	if (month == 2 && day > 28) return false;
	if (year < 1900 || year > 2200) return false;
	return true;
}
std::vector<product> AddToFile(std::string fileName) {
	product b;
	char ans;
	std::vector<product> m;
	std::fstream fout(fileName, std::ios::app | std::ios::binary);
	do {
		std::cout << "Name: "; getline(std::cin, b.name);
		std::cout << "Date of issue: "; getline(std::cin, b.firstDate);
		while (!DateIsCorrect(b.firstDate)) { 
			std::cout << "Incorrect input. Try again:"; getline(std::cin, b.firstDate);
		}
		std::cout << "Expiry date: "; getline(std::cin, b.lastDate);
		while (!DateIsCorrect(b.lastDate)) {
			std::cout << "Incorrect input. Try again:"; getline(std::cin, b.lastDate);
		}
		write(fout, b);
		std::cout << "Continue?(Y/N)"; std::cin >> ans;
		std::cin.ignore();
		m.push_back(b);
	} while (ans != 'n' && ans != 'N');
	fout.close();
	return m;
}


void outFromFile(std::string name) {
	product b;
	std::fstream fin(name,std::ios::in | std::ios::binary);
	std::string line;
	while (read(fin, b)) {
		std::cout << "\n" << b.name; //<< "  " << b.firstDate << "  " << b.lastDate;
	}
	fin.close();
	}


std::vector<int> DiffsVector(std::vector<product> v, product a) {
	std::vector <int> diffs;
	for (int i = 0; i < v.size(); i++) {
		a = v[i];
		int days = datesdifference(a);
		diffs.push_back(days);
	}
	return diffs;
}
void addToDiffFiles(std::vector<int> diffs, std::vector<product> prodList, std::string fileName1, std::string fileName2) {
	std::fstream fout(fileName1, std::ios::app | std::ios::binary);
	std::fstream fout2(fileName2, std::ios::app | std::ios::binary);
	for (int i = 0; i < diffs.size(); i++) {
		if (isOverdue(prodList[i]))
			continue;
		else {
			if (diffs[i] <= 5) {
				write(fout, prodList[i]);
			}
			else
				write(fout2, prodList[i]);
		}
	}
	fout.close();
}
void clearFile(std::string fileName) {
	std::fstream clear_file(fileName, std::ios::out);
	clear_file.close();
}