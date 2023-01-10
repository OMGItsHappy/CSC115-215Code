#include "a0004.h"

bool isPrime(int n)
{
    if (n < 2) {
        return false;
    }  else if (n == 2) {
        return true;
    }  else if (n % 2 == 0) {
        return false;
    }  else {
        int i = 3;
        for (i; i < n/2 + 1; i+=2) {
            if (n % i == 0) {
                return false;
            }
        }
    }

    return true;
}

bool isTwinPrime(int n)
{
    return (isPrime(n)) ? (isPrime(n-2) || isPrime(n+2)) : false;
}

int nextPrime(int n) {
    int i = n + 1;
    while (!isPrime(i)) {
        i++;
    }

    return i;
}