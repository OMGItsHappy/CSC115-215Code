#include "..\\catch.hpp"
#include "network.h"


TEST_CASE("compressOctets, getNetworkType - intial test case for function, should return invalid")
{
	ip result = compressOctets(0, 0, 0, 0);

	REQUIRE(result == 0);

	networkType type = getNetworkType(result);

	REQUIRE(type == INVALID);

}

TEST_CASE("compressOctets, extractOctets - testing the given example ip")
{

	ip result = compressOctets(151, 159, 15, 20);
	octet o1, o2, o3, o4;

	REQUIRE(result == 2543783700);

	extractOctets(result, o1, o2, o3, o4);

	REQUIRE((o1 == 151 && o2 == 159 && o3 == 15 && o4 == 20));

}

TEST_CASE("compressOctets, extractOctets - testing repeating values")
{
	ip result = compressOctets(255, 255, 255, 255);

	REQUIRE(result == 4294967295);

	octet o1, o2, o3, o4;

	extractOctets(result, o1, o2, o3, o4);

	REQUIRE((o1 == 255 && o2 == 255 && o3 == 255 && o4 == 255));
}

TEST_CASE("compressOctets, extractOctets - testing a class A ip value")
{
	ip result = compressOctets(3, 47, 80, 156);

	REQUIRE(result == 53432476);

	octet o1, o2, o3, o4;

	extractOctets(result, o1, o2, o3, o4);

	REQUIRE((o1 == 3 && o2 == 47 && o3 == 80 && o4 == 156));
}

TEST_CASE("compressOctets, extractOctets - testing Class B ip value")
{
	ip result = compressOctets(150, 58, 90, 234);

	REQUIRE(result == 2520406762);

	octet o1, o2, o3, o4;

	extractOctets(result, o1, o2, o3, o4);

	REQUIRE((o1 == 150 && o2 == 58 && o3 == 90 && o4 == 234));
}

TEST_CASE("compressOctets, extractOctets - testing class C ip value")
{
	ip result = compressOctets(200, 123, 43, 76);

	REQUIRE(result == 3363515212);

	octet o1, o2, o3, o4;

	extractOctets(result, o1, o2, o3, o4);

	REQUIRE((o1 == 200 && o2 == 123 && o3 == 43 && o4 == 76));
}

TEST_CASE("compressOctets, extractOctets - testing class D ip value")
{
	ip result = compressOctets(235, 129, 0, 0);

	REQUIRE(result == 3951099904);

	octet o1, o2, o3, o4;

	extractOctets(result, o1, o2, o3, o4);

	REQUIRE((o1 == 235 && o2 == 129 && o3 == 0 && o4 == 0));
}


TEST_CASE("compressOctets, extractOctets - testing class E ip value")
{
	ip result = compressOctets(255, 66, 124, 90);

	REQUIRE(result == 4282547290);

	octet o1, o2, o3, o4;

	extractOctets(result, o1, o2, o3, o4);

	REQUIRE((o1 == 255 && o2 == 66 && o3 == 124 && o4 == 90));
}


TEST_CASE("extractOctets - intial test case")
{
	ip result = compressOctets(0, 0, 0, 0);
	octet o1 = 0, o2 = 0, o3 = 0, o4 = 0;

	extractOctets(result, o1, o2, o3, o4);
	REQUIRE(o1 + o2 + o3 + o4 == 0);
}

TEST_CASE("getNetworktType - Testing class a classifications")
{
	networkType type = getNetworkType(compressOctets(64, 90, 100, 255));

	REQUIRE(type == CLASSA);

	type = getNetworkType(compressOctets(126, 90, 100, 255));

	REQUIRE(type == CLASSA);
}

TEST_CASE("getNetworkType - Testing class B classification")
{
	networkType type = getNetworkType(compressOctets(128, 64, 90, 255));

	REQUIRE(type == CLASSB);

	type = getNetworkType(compressOctets(172, 14, 100, 3));

	REQUIRE(type == CLASSB);
}

TEST_CASE("getNetworkType - Testing class C classification")
{
	networkType type = getNetworkType(compressOctets(200, 98, 255, 1));

	REQUIRE(type == CLASSC);

	type = getNetworkType(compressOctets(192, 167, 0, 64));

	REQUIRE(type == CLASSC);
}


TEST_CASE("getNetworkType - Testing class D classification")
{
	networkType type = getNetworkType(compressOctets(230, 98, 5, 0));

	REQUIRE(type == CLASSD);

	type = getNetworkType(compressOctets(239, 255, 85, 72));

	REQUIRE(type == CLASSD);
}

TEST_CASE("getNetworkType - Testing class E classification")
{
	networkType type = getNetworkType(compressOctets(240, 8, 0, 255));

	REQUIRE(type == CLASSE);

	type = getNetworkType(compressOctets(255, 255, 255, 255));

	REQUIRE(type == CLASSE);
}

TEST_CASE("getNetworkType - Testing both invalid classification")
{
	networkType type = getNetworkType(compressOctets(0, 25, 80, 255));

	REQUIRE(type == INVALID);

	type = getNetworkType(compressOctets(0, 255, 255, 255));

	REQUIRE(type == INVALID);
}

TEST_CASE("getNetworkType - Testing class local host classification")
{
	networkType type = getNetworkType(compressOctets(127, 0, 0, 0));

	REQUIRE(type == LOCALHOST);

	type = getNetworkType(compressOctets(127, 255, 255, 255));

	REQUIRE(type == LOCALHOST);
}

TEST_CASE("getNetworkType - Testing APrivate classification")
{
	networkType type = getNetworkType(compressOctets(10, 0, 0, 0));

	REQUIRE(type == APRIVATE);

	type = getNetworkType(compressOctets(10, 255, 255, 255));

	REQUIRE(type == APRIVATE);
}

TEST_CASE("getNetworkType - Testing BPrivate classification")
{
	networkType type = getNetworkType(compressOctets(172, 16, 0, 0));

	REQUIRE(type == BPRIVATE);

	type = getNetworkType(compressOctets(172, 31, 255, 255));

	REQUIRE(type == BPRIVATE);
}

TEST_CASE("getNetworkType - Testing CPrivate classification")
{
	networkType type = getNetworkType(compressOctets(192, 168, 0, 0));

	REQUIRE(type == CPRIVATE);

	type = getNetworkType(compressOctets(192, 168, 255, 255));

	REQUIRE(type == CPRIVATE);
}

/*
TEST_CASE("getNetworkType - Testing class B classification")
{
	networkType type = getNetworkType(compressOctets());

	REQUIRE(type == );

	type = getNetworkType(compressOctets());

	REQUIRE(type == );
}
*/