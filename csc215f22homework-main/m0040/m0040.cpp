
#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct empData
{
	int id;
	char firstName[20];
	char lastName[40];
	double salary;
	double bonus;
};

void printFile(fstream& file);
bool applyBonus(fstream& file, int empId);

int main(int argc, char** argv)
{

	fstream file;

	if (argc != 3)
	{
		cout << "Usage: m0040.exe binaryData employeeID";
		return 0;
	}

	file.open(argv[1], ios::in | ios::out | ios::binary);

	if (!file.is_open())
	{
		cout << "Unable to open binary file: " << argv[1];
		return 0;
	}

	printFile(file);

	cout << endl;

	if (applyBonus(file, atoi(argv[2])))
	{ 
		cout << "Employee ID " << argv[2] << " has been updated." << endl << endl;
	}

	else cout << "Employee ID " << argv[2] << " was not found." << endl << endl;

	file.clear();

	printFile(file);

	file.close();
	
	return 0;
}

void printFile(fstream &file)
{

	file.seekg(0, ios::end);
	int i = 0, count = (int) (file.tellg()/sizeof(empData));
	empData emp;

	while (i < count)
	{
		file.seekg(i * sizeof(empData), ios::beg);
		file.read((char*) &emp, sizeof(empData));


		cout << setw(7) << emp.id << " "
			<< left << setw(20) << emp.firstName
			<< setw(40) << emp.lastName << right
			<< " Salary: " << setw(10) << fixed << setprecision(2) << emp.salary
			<< " Bonus: " << setw(10) << emp.bonus << endl;
		i++;
	}

	file.clear();
}

bool applyBonus(fstream &file, int empId)
{

	file.seekg(0, ios::end);
	int i = 0, count = (int)(file.tellg() / sizeof(empData));
	empData emp;

	file.seekg(0, ios::beg);
	file.read((char*)&emp, sizeof(empData));
	i++;

	while (i < count && emp.id != empId)
	{
		file.seekg(i * sizeof(empData), ios::beg);
		file.read((char*)&emp, sizeof(empData));

		i++;
	}

	file.clear();

	if (i != count+1 && emp.id == empId)
	{

		emp.bonus += 500;

		file.seekp((i - 1) * sizeof(empData), ios::beg);
		file.write((char*) &emp, sizeof(empData));

		file.clear();

		return true;
	}

	file.clear();

	return false;
}