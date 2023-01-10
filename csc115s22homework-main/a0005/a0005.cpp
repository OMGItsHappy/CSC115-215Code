#include "a0005.h"

void passwordCalc(string pw, int &pwEntropy, string &pwStrength) {
    int totalEntropy [5] = {}; // lower, upper, digit, blank, punc
    int i;
    int total;

    for(i = 0; i < (int) pw.size(); i++)
    {
        if (islower(pw[i]))
        {
            totalEntropy[0] = 26;
        } else if (isupper(pw[i]))
        {
            totalEntropy[1] = 26;
        } else if (isdigit(pw[i]))
        {
            totalEntropy[2] = 10;
        } else if (isblank(pw[i]))
        {
            totalEntropy[3] = 2;
        } else if (ispunct(pw[i]))
        {
            totalEntropy[4] = 32;
        }
    }

    total = 0;

    for (i = 0; i < 5; i++) 
    {
        total += totalEntropy[i];
    }

    pwEntropy = int(round(log2(total) * pw.size()));

    if (pwEntropy <= 28)
    {
        pwStrength = "Very Weak";
    } else if (pwEntropy <= 35) 
    {
        pwStrength = "Weak";
    } else if (pwEntropy <= 59) 
    {
        pwStrength = "Reasonable";
    } else if (pwEntropy <= 127) 
    {
        pwStrength = "Strong";
    } else 
    {
        pwStrength = "Very Strong";
    }

}

