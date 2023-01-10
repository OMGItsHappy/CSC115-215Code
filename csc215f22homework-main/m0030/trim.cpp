#include "trim.h"


void cTrim(char str[], trimType method)
{
	int i = 0;

	if (method == FRONT || method == BOTH)
	{
		while (isspace(str[i]) && str[i] != '\0')
		{
			i++;
		}

		strcpy(str, str + i);
	}


	if (method == END || method == BOTH)
	{
		int len = static_cast<int>(strlen(str));
		i = (len > 0) ? len - 1 : 0;

		while (i != -1 && isspace(str[i]))
		{
			str[i] = '\0';
			i--;
		}
	}
}

void sTrim(string &str, trimType method)
{
	int i = 0;

	if (method == FRONT || method == BOTH)
	{
		while (str[i] != '\0' && isspace(str[i]))
		{
			i++;
		}

		str.erase(0, i);
	}

	if (method == END || method == BOTH)
	{
		int len = static_cast<int>(str.length());
		i = (len > 0) ? len - 1 : 0;

		while (i > -1 && isspace(str[i]))
		{
			i--;
		}

		if (len > 0) str.erase(i+1, len);
	}

}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
m0030.exe is a Catch v2.13.9 host application.
Run with -? for options

-------------------------------------------------------------------------------
cTrim - 1 white space on each end
  End
-------------------------------------------------------------------------------
C:\Users\101098609\source\repos\csc215f22homework\m0030\trimtestcases.cpp(42)
...............................................................................

C:\Users\101098609\source\repos\csc215f22homework\m0030\trimtestcases.cpp(45): FAILED:
  CHECK( strcmp(toTest, endExpected) == 0 )
with expansion:
  -1 == 0

-------------------------------------------------------------------------------
cTrim - 1 white space on each end
  Both
-------------------------------------------------------------------------------
C:\Users\101098609\source\repos\csc215f22homework\m0030\trimtestcases.cpp(48)
...............................................................................

C:\Users\101098609\source\repos\csc215f22homework\m0030\trimtestcases.cpp(51): FAILED:
  CHECK( strcmp(toTest, bothExpected) == 0 )
with expansion:
  1 == 0

-------------------------------------------------------------------------------
cTrim - multiple white spaces one each end
  End
-------------------------------------------------------------------------------
C:\Users\101098609\source\repos\csc215f22homework\m0030\trimtestcases.cpp(69)
...............................................................................

C:\Users\101098609\source\repos\csc215f22homework\m0030\trimtestcases.cpp(72): FAILED:
  CHECK( strcmp(toTest, endExpected) == 0 )
with expansion:
  -1 == 0

-------------------------------------------------------------------------------
cTrim - multiple white spaces one each end
  Both
-------------------------------------------------------------------------------
C:\Users\101098609\source\repos\csc215f22homework\m0030\trimtestcases.cpp(75)
...............................................................................

C:\Users\101098609\source\repos\csc215f22homework\m0030\trimtestcases.cpp(78): FAILED:
  CHECK( strcmp(toTest, bothExpected) == 0 )
with expansion:
  1 == 0

-------------------------------------------------------------------------------
cTrim - multiple words with spaces on the end
  End
-------------------------------------------------------------------------------
C:\Users\101098609\source\repos\csc215f22homework\m0030\trimtestcases.cpp(121)
...............................................................................

C:\Users\101098609\source\repos\csc215f22homework\m0030\trimtestcases.cpp(124): FAILED:
  CHECK( strcmp(toTest, endExpected) == 0 )
with expansion:
  -1 == 0

-------------------------------------------------------------------------------
cTrim - multiple words with spaces on the end
  Both
-------------------------------------------------------------------------------
C:\Users\101098609\source\repos\csc215f22homework\m0030\trimtestcases.cpp(127)
...............................................................................

C:\Users\101098609\source\repos\csc215f22homework\m0030\trimtestcases.cpp(130): FAILED:
  CHECK( strcmp(toTest, bothExpected) == 0 )
with expansion:
  1 == 0

===============================================================================
test cases: 14 | 11 passed | 3 failed
assertions: 42 | 36 passed | 6 failed


C:\Users\101098609\source\repos\csc215f22homework\m0030\x64\Debug\m0030.exe (process 2052) exited with code 6.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .*/