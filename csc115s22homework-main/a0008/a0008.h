#pragma once
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

//Write prototypes here

void splitNameLF(string fullName, string &firstName, string &lastName); 

void splitNameFL(string fullName, string &firstName, string &lastName);

string createEmail(string firstName, string lastName, string domainName);

void fixList(string * mixedStudents, string * studentsFL, string * studentsLF, string *emails, int size, string domain);