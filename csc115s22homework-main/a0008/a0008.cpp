#include "a0008.h"

void splitNameLF(string fullName, string &firstName, string &lastName) 
{
    lastName = fullName.substr(0, fullName.find(","));
    firstName = fullName.substr(fullName.find(",") + 2);
}   

void splitNameFL(string fullName, string &firstName, string &lastName)
{
    firstName = fullName.substr(0, fullName.find(" "));
    lastName = fullName.substr(fullName.find(" ") + 1);
}

string createEmail(string firstName, string lastName, string domainName)
{
    return "" + firstName + "." + lastName + "@" + domainName;
}


void fixList(string * mixedStudents, string * studentsFL, string * studentsLF, string *emails, int size, string domain)
{
    int i;
    string firstName;
    string lastName;

    for (i = 0; i < size; i++)
    {   
        if (mixedStudents[i].find(",") == string::npos)
        {
            splitNameFL(mixedStudents[i], firstName, lastName);
        }   else
        {
            splitNameLF(mixedStudents[i], firstName, lastName);
        }

        studentsFL[i] = "" + firstName + " " + lastName;
        studentsLF[i] = "" + lastName + ", " + firstName;
        emails[i] = "" + firstName + "." + lastName + "@" + domain;
    }
}