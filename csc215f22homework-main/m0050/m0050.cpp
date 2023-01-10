#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct emp
{
	int id;
	string firstName;
	string lastName;
	double salary;
	double bonus;
};

bool sortById(emp e1, emp e2);

bool sortBySalary(emp e1, emp e2);

bool sortByNames(emp e1, emp e2);


int main(int argc, char** argv)
{
	vector<emp> employees;

	string s, firstLine;

	emp e;

	ifstream ifile;

	ofstream ofile;

	if (argc != 4)
	{
		cout << "Usage: m0050.exe inputCSVFile outputCSVFile sortMethod";
		return 0;
	}


	ifile.open(argv[1]);

	if (!ifile.is_open())
	{
		cout << "Unable to open input file: " << argv[1];
		return 0;
	}

	ofile.open(argv[2]);

	if (!ofile.is_open())
	{
		cout << "Unable to open output file: " << argv[2];
		return 0;
	}

	if (strcmp(argv[3], "-i") != 0 && strcmp(argv[3], "-n") != 0 && strcmp(argv[3], "-s") != 0)
	{
		cout << "Invalid Sort Method:" << endl
			<< "-i - sort by id" << endl
			<< "-n - sort by name" << endl
			<< "-s - sort by salary";
		return 0;
	}	

	ifile >> firstLine;

	while (getline(ifile, s))
	{
		if (s.length() == 0) continue;

		e.id = stoi(s.substr(0, s.find(",")));
		s = s.substr(s.find(",") + 1);
		e.firstName = s.substr(0, s.find(","));
		s = s.substr(s.find(",") + 1);
		e.lastName = s.substr(0, s.find(","));
		s = s.substr(s.find(",") + 1);
		e.salary = stod(s.substr(0, s.find(",")));
		s = s.substr(s.find(",") + 1);
		e.bonus = stod(s);

		employees.push_back(e);
	}

	if (strcmp(argv[3], "-i") == 0)
	{
		sort(employees.begin(), employees.end(), sortById);
	}

	else if (strcmp(argv[3], "-s") == 0)
	{
		sort(employees.begin(), employees.end(), sortBySalary);
	}

	else
	{
		sort(employees.begin(), employees.end(), sortByNames);
	}

	ofile << firstLine << endl;

	for (emp e : employees)
	{
		ofile << e.id << ","
			<< e.firstName << ","
			<< e.lastName << ","
			<< fixed << setprecision(2) << e.salary << ","
			<< e.bonus
			<< endl;
	}

	ofile.close();
	ifile.close();

	return 0;

}

bool sortById(emp e1, emp e2)
{	
	return e1.id < e2.id;
}

bool sortBySalary(emp e1, emp e2)
{
	return e1.salary > e2.salary;
}

bool sortByNames(emp e1, emp e2)
{
	if (e1.lastName == e2.lastName)
	{
		return e1.firstName < e2.firstName;
	}

	return e1.lastName < e2.lastName;
}


