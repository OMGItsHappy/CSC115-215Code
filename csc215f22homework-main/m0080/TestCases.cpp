#include "sortedSingle.h"
#include "..\catch.hpp"
#include <sstream>
#include <iostream>

using namespace std;


TEST_CASE("testing things")
{
	sortedSingle a;

	a.insert(2);

	REQUIRE(a.empty() == false);
	REQUIRE(a.size() == 1);

	REQUIRE(a.find(1) == false);

	REQUIRE(a.retrievePosition(1) == 0);
}


TEST_CASE("empty")
{
	sortedSingle a;

	REQUIRE(a.empty() == true);
}


TEST_CASE("size")
{
	sortedSingle a;

	REQUIRE(a.size() == 0);

	a.insert(1);

	a.insert(2);

	a.insert(4);

	REQUIRE(a.size() == 3);

	a.remove(1);
	a.remove(2);

	REQUIRE(a.size() == 1);

	a.insert(100);
	a.insert(1000);
	a.insert(1000);

	REQUIRE(a.size() == 4);
}


TEST_CASE("retrievePosition")
{
	sortedSingle a;

	REQUIRE(a.retrievePosition(1) == 0);

	a.insert(1);

	a.insert(2);

	a.insert(4);

	REQUIRE(a.retrievePosition(4) == 3);

	a.insert(3);

	for (int i = 5; i < 100; i++)
	{
		a.insert(i);
	}

	REQUIRE(a.retrievePosition(50) == 50);

	a.insert(1);

	REQUIRE(a.retrievePosition(1) == 1);

	REQUIRE(a.retrievePosition(2) == 3);

	REQUIRE(a.retrievePosition(50) == 51);
}

TEST_CASE("Constructor")
{
	sortedSingle a;

	REQUIRE(a.size() == 0);
	REQUIRE(a.empty() == true);
}

TEST_CASE("deconstructor")
{
	sortedSingle a;

	a.insert(1);

	a.insert(2);
}


TEST_CASE("insert")
{
	
	sortedSingle a;

	a.insert(1);
	a.insert(2);

	REQUIRE(a.find(1));

	for (int i = 0; i < 100; i++)
	{
		a.insert(3);
	}

	REQUIRE(a.size() == 102);
	

	SECTION("end of list")
	{
		stringstream s;

		sortedSingle b;

		b.insert(1);

		b.insert(50);

		b.insert(30);

		b.insert(10);
		b.insert(20);

		b.insert(40);

		b.insert(50);

		

		b.print(s);

		REQUIRE(s.str() == "1, 10, 20, 30, 40, 50, 50");
	}

	SECTION("middle of list")
	{
		stringstream s3;

		sortedSingle c;
		c.insert(50);
		c.insert(40);
		c.insert(30);
		c.insert(20);
		c.insert(10);

		c.insert(35);

		c.print(s3);

		REQUIRE(s3.str() == "10, 20, 30, 35, 40, 50");

		c.insert(35);

		s3.str("");

		c.print(s3);

		REQUIRE(s3.str() == "10, 20, 30, 35, 35, 40, 50");

	}

}

TEST_CASE("print")
{
	stringstream s1, s2;

	sortedSingle a;

	a.insert(1);
	a.insert(2);

	for (int i = 3; i < 10; i++)
	{
		a.insert(i);
	}
	 
	a.print(s1);

	REQUIRE(s1.str() == "1, 2, 3, 4, 5, 6, 7, 8, 9");

	sortedSingle b;

	b.insert(1);

	b.print(s2);

	REQUIRE(s2.str() == "1");
		
}

TEST_CASE("remove")
{
	sortedSingle a;

	a.insert(1);

	a.remove(1);

	a.insert(1);

	a.insert(2);

	a.insert(3);

	a.remove(2);

	a.remove(3);

	for (int i = 0; i < 50; i++)
	{
		a.insert(3);
	}

	a.remove(3);

	REQUIRE(a.size() == 50);

	REQUIRE(a.remove(100) == false);


}

TEST_CASE("clear")
{
	sortedSingle a;

	a.insert(1);

	a.clear();

	REQUIRE(a.empty() == true);

	for (int i = 0; i < 50; i++)
	{
		a.insert(i);
	}

	a.clear();

	REQUIRE(a.empty() == true);
}


TEST_CASE("copy constructor")
{
	sortedSingle a;

	a.insert(1);

	sortedSingle b(a);

	stringstream c;

	b.print(c);

	REQUIRE(c.str() == "1");

	a.insert(1);

	a.insert(5);

	a.insert(4);

	a.insert(1000);

	c.str("");

	sortedSingle d(a);

	d.print(c);

	REQUIRE(c.str() == "1, 1, 4, 5, 1000");

	for (int i = 6; i < 1000; i++)
	{
		a.insert(i);
	}

	sortedSingle e(a);

	stringstream f;

	c.str("");

	e.print(c);

	a.print(f);

	REQUIRE(f.str() == c.str());
}