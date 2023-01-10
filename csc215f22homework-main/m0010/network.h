#ifndef __NETWORK__H__
#define __NETWORK__H__


enum networkType
{
	INVALID = 0,
	CLASSA = 1,
	APRIVATE = 2,
	LOCALHOST = 3,
	CLASSB = 4,
	BPRIVATE = 5,
	CLASSC = 6,
	CPRIVATE = 7,
	CLASSD = 8,
	CLASSE = 9
};

typedef unsigned char octet;

typedef unsigned int ip;

ip compressOctets(octet octet1, octet octet2, octet octet3, octet octet4);

void extractOctets(ip givenIP, octet& octet1, octet& octet2, octet& octet3, octet& octet4);

networkType getNetworkType(ip givenIP);


#endif