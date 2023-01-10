#include "..\\catch.hpp"
#include "trim.h"

TEST_CASE("cTrim - intial test case")
{
	char toTest[100] = "Hello!";
	char expected[100] = "Hello!";

	SECTION("Front")
	{
		cTrim(toTest, FRONT);
		CHECK(strcmp(toTest, expected) == 0);
	}

	SECTION("End")
	{
		cTrim(toTest, END);
		CHECK(strcmp(toTest, expected) == 0);
	}

	SECTION("Both")
	{
		cTrim(toTest, BOTH);
		CHECK(strcmp(toTest, expected) == 0);
	}

}

TEST_CASE("cTrim - 1 white space on each end")
{
	char toTest[100] = " Hello! ";
	char frontExpected[100] = "Hello! ";
	char endExpected[100] = " Hello!";
	char bothExpected[100] = "Hello!";

	SECTION("Front")
	{
		cTrim(toTest, FRONT);
		CHECK(strcmp(toTest, frontExpected) == 0);
	}

	SECTION("End")
	{
		cTrim(toTest, END);
		CHECK(strcmp(toTest, endExpected) == 0);
	}

	SECTION("Both")
	{
		cTrim(toTest, BOTH);
		CHECK(strcmp(toTest, bothExpected) == 0);
	}
}


TEST_CASE("cTrim - multiple white spaces one each end")
{
	char toTest[100] = "   Hello!   ";
	char frontExpected[100] = "Hello!   ";
	char endExpected[100] = "   Hello!";
	char bothExpected[100] = "Hello!";

	SECTION("Front")
	{
		cTrim(toTest, FRONT);
		CHECK(strcmp(toTest, frontExpected) == 0);
	}

	SECTION("End")
	{
		cTrim(toTest, END);
		CHECK(strcmp(toTest, endExpected) == 0);
	}

	SECTION("Both")
	{
		cTrim(toTest, BOTH);
		CHECK(strcmp(toTest, bothExpected) == 0);
	}
}

TEST_CASE("cTrim - multiple words with no spaces on either end")
{
	char toTest[100] = "Hello World!";
	char frontExpected[100] = "Hello World!";
	char endExpected[100] = "Hello World!";
	char bothExpected[100] = "Hello World!";

	SECTION("Front")
	{
		cTrim(toTest, FRONT);
		CHECK(strcmp(toTest, frontExpected) == 0);
	}

	SECTION("End")
	{
		cTrim(toTest, END);
		CHECK(strcmp(toTest, endExpected) == 0);
	}

	SECTION("Both")
	{
		cTrim(toTest, BOTH);
		CHECK(strcmp(toTest, bothExpected) == 0);
	}
}

TEST_CASE("cTrim - multiple words with spaces on the end")
{
	char toTest[100] = "  Hello World!   ";
	char frontExpected[100] = "Hello World!   ";
	char endExpected[100] = "  Hello World!";
	char bothExpected[100] = "Hello World!";

	SECTION("Front")
	{
		cTrim(toTest, FRONT);
		CHECK(strcmp(toTest, frontExpected) == 0);
	}

	SECTION("End")
	{
		cTrim(toTest, END);
		CHECK(strcmp(toTest, endExpected) == 0);
	}

	SECTION("Both")
	{
		cTrim(toTest, BOTH);
		CHECK(strcmp(toTest, bothExpected) == 0);
	}
}

TEST_CASE("cTrim - testing empty string")
{
	char toTest[100] = "";
	char frontExpected[100] = "";
	char endExpected[100] = "";
	char bothExpected[100] = "";

	SECTION("Front")
	{
		cTrim(toTest, FRONT);
		CHECK(strcmp(toTest, frontExpected) == 0);
	}

	SECTION("End")
	{
		cTrim(toTest, END);
		CHECK(strcmp(toTest, endExpected) == 0);
	}

	SECTION("Both")
	{
		cTrim(toTest, BOTH);
		CHECK(strcmp(toTest, bothExpected) == 0);
	}
}

TEST_CASE("cTrim - testing string full of spaces")
{
	char toTest[100] = "      ";
	char frontExpected[100] = "";
	char endExpected[100] = "";
	char bothExpected[100] = "";

	SECTION("Front")
	{
		cTrim(toTest, FRONT);
		CHECK(strcmp(toTest, frontExpected) == 0);
	}

	SECTION("End")
	{
		cTrim(toTest, END);
		CHECK(strcmp(toTest, endExpected) == 0);
	}

	SECTION("Both")
	{
		cTrim(toTest, BOTH);
		CHECK(strcmp(toTest, bothExpected) == 0);
	}
}

TEST_CASE("sTrim - testing single word with no whitespace on either end")
{
	string toTest = "Hello!";
	string frontExpected = "Hello!";
	string endExpected = "Hello!";
	string bothExpected = "Hello!";

	SECTION("Front")
	{
		sTrim(toTest, FRONT);
		CHECK(toTest == frontExpected);
	}

	SECTION("End")
	{
		sTrim(toTest, END);
		CHECK(toTest == endExpected);
	}

	SECTION("Both")
	{
		sTrim(toTest, BOTH);
		CHECK(toTest == bothExpected);
	}
}

TEST_CASE("sTrim - testing single word with 1 whitespace on either end")
{
	string toTest = " Hello! ";
	string frontExpected = "Hello! ";
	string endExpected = " Hello!";
	string bothExpected = "Hello!";

	SECTION("Front")
	{
		sTrim(toTest, FRONT);
		CHECK(toTest == frontExpected);
	}

	SECTION("End")
	{
		sTrim(toTest, END);
		CHECK(toTest == endExpected);
	}

	SECTION("Both")
	{
		sTrim(toTest, BOTH);
		CHECK(toTest == bothExpected);
	}
}

TEST_CASE("sTrim - testing single word with multiple whitespace on either end")
{
	string toTest = "  Hello!   ";
	string frontExpected = "Hello!   ";
	string endExpected = "  Hello!";
	string bothExpected = "Hello!";

	SECTION("Front")
	{
		sTrim(toTest, FRONT);
		CHECK(toTest == frontExpected);
	}

	SECTION("End")
	{
		sTrim(toTest, END);
		CHECK(toTest == endExpected);
	}

	SECTION("Both")
	{
		sTrim(toTest, BOTH);
		CHECK(toTest == bothExpected);
	}
}

TEST_CASE("sTrim - multiple words with 1 whitespace on either end")
{
	string toTest = " Hello World! ";
	string frontExpected = "Hello World! ";
	string endExpected = " Hello World!";
	string bothExpected = "Hello World!";

	SECTION("Front")
	{
		sTrim(toTest, FRONT);
		CHECK(toTest == frontExpected);
	}

	SECTION("End")
	{
		sTrim(toTest, END);
		CHECK(toTest == endExpected);
	}

	SECTION("Both")
	{
		sTrim(toTest, BOTH);
		CHECK(toTest == bothExpected);
	}
}

TEST_CASE("sTrim - testing multiple words with multiple whitespaces on either end")
{
	string toTest = "  Hello World!   ";
	string frontExpected = "Hello World!   ";
	string endExpected = "  Hello World!";
	string bothExpected = "Hello World!";

	SECTION("Front")
	{
		sTrim(toTest, FRONT);
		CHECK(toTest == frontExpected);
	}

	SECTION("End")
	{
		sTrim(toTest, END);
		CHECK(toTest == endExpected);
	}

	SECTION("Both")
	{
		sTrim(toTest, BOTH);
		CHECK(toTest == bothExpected);
	}
}

TEST_CASE("sTrim - testing empty string")
{
	string toTest = "";
	string frontExpected = "";
	string endExpected = "";
	string bothExpected = "";

	SECTION("Front")
	{
		sTrim(toTest, FRONT);
		CHECK(toTest == frontExpected);
	}

	SECTION("End")
	{
		sTrim(toTest, END);
		CHECK(toTest == endExpected);
	}

	SECTION("Both")
	{
		sTrim(toTest, BOTH);
		CHECK(toTest == bothExpected);
	}
}

TEST_CASE("sTrim - testing string of spaces")
{
	string toTest = "   ";
	string frontExpected = "";
	string endExpected = "";
	string bothExpected = "";

	SECTION("Front")
	{
		sTrim(toTest, FRONT);
		CHECK(toTest == frontExpected);
	}

	SECTION("End")
	{
		sTrim(toTest, END);
		CHECK(toTest == endExpected);
	}

	SECTION("Both")
	{
		sTrim(toTest, BOTH);
		CHECK(toTest == bothExpected);
	}
}