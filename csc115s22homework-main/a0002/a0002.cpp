#include "a0002.h"
#include <cmath>

//formula = 35.74 + 0.6215*temp - 35.5*pow(windSpeed, 0.16) + .4275*temp*pow(windSpeed, 0.16);

int windChill(int temp, int windSpeed)
{
    int result = int (round(35.74 + 0.6215*temp - 35.5*pow(windSpeed, 0.16) + 
    0.4275*temp*pow(windSpeed, 0.16)));
    return result;
}

string windChillWarning(int temp, int windSpeed)
{
    int finalTemp = windChill(temp, windSpeed);
    

    
    if (finalTemp >= 32) {
        return "None";
    } else if (finalTemp >= 0 && finalTemp < 32) {
        return "Minimal";
    } else if (finalTemp >= -20 && finalTemp < 0) {
        return "Caution";
    } else if (finalTemp >= -40 && finalTemp < -20) {
        return "Intermediate";
    } else {
        return "Extreme";
    }
}