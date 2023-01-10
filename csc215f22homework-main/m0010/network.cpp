
#include "network.h"

ip compressOctets(octet octet1, octet octet2, octet octet3, octet octet4)
{

	octet octets[4] = { octet1, octet2, octet3, octet4 };

	ip toReturn = 0;

	int index = 0;

	for (octet o : octets)
	{
		toReturn = toReturn | o;
		if (index != 3) toReturn = toReturn << 8;

		index++;
	}
		
	return toReturn;   
}

void extractOctets(ip givenIP, octet& octet1, octet& octet2, octet& octet3, octet& octet4)
{

	octet octets[4] = { octet1, octet2, octet3, octet4 };

	octet1 = (givenIP >> 24) | 0;
	octet2 = (givenIP >> 16) | 0;
	octet3 = (givenIP >> 8) | 0;
	octet4 = givenIP | 0;

}

networkType getNetworkType(ip givenIP)
{

	octet firstVal = (givenIP >> 24) | 0;
	octet secondVal = (givenIP >> 16) | 0;

	networkType type;

	if (firstVal == 0) type = INVALID;

	else if (firstVal == 10) type = APRIVATE;

	else if (firstVal == 127) type = LOCALHOST;

	else if (firstVal > 0 && firstVal < 128)  type = CLASSA;

	else if (firstVal == 172 && (secondVal > 15 && secondVal < 32)) type = BPRIVATE;

	else if (firstVal > 127 && firstVal < 192) type = CLASSB;

	else if (firstVal == 192 && secondVal == 168) type = CPRIVATE;

	else if (firstVal > 191 && firstVal < 224) type = CLASSC;

	else if (firstVal > 223 && firstVal < 240) type = CLASSD;

	else type = CLASSE;	

	return type;
}
