/** ***************************************************************************
* @file
******************************************************************************/

#include "thpe2.h"

/** ***************************************************************************
 *  @author Oliver Schwab
 *
 *  @par Description
 *  Uses Newton's Method to estimate the square root of the given number
 *
 *  @param[in] x The number to find the square root of.
 *
 *  @returns A double estimation of the square root of x. Or, if the number 
 *              passed in was negative function returns -1.
 
 *  @par Example
 *  @verbatim
    double result;
	
    double num = 4;
    result = mySqrt(num); // result would be 2

    num = 2;
	result = mySqrt(num); // result would be about 1.41421

    @endverbatim
 *****************************************************************************/
double mySqrt(double x)
{
    double max;
    double mid;
    double min = 0;

    if (x <= 0)
    {
        return 0;
    }

    max = x;

    if (x < 1)
    {
        max = 1.0;
    }

    mid = (max + min) / 2;
    //essentially bouncing between the high and low 
    //values to find the appropriate value
    while (abs(pow(mid, 2) - x) > ERRORVALUE) 
    // determing how close we are to corretc value
    {
        if (pow(mid, 2) > x) // if we are above the mid the value 
        // is in the higher range of values
        {
            max = mid;
        } else
        {
            min = mid;
        }

        mid = (max + min) / 2; // middle of two values
    }

    return mid;
}


/** ***************************************************************************
 *  @author Oliver Schwab
 *
 *  @par Description
 *  Uses Newton's Method to estimate the cubed root of the given number
 *
 *  @param[in] x The number to find the cubed root of.
 *
 *  @returns A double estimation of the cubed root of x. Or, if the number 
 *              passed in was negative function returns -1.
 *
 *  @par Example
 *  @verbatim
    double result;
	
    double num = 27;
    result = myCbrt(num); // result would be 3

    num = 8;
	result = myCbrt(num); // result would be 2

    @endverbatim
 *****************************************************************************/
double myCbrt(double x)
{
    double max;
    double mid;
    double min = 0;

    if (x <= 0)
    {
        return 0;
    }

    max = x;

    if (x < 1)
    {
        max = 1.0;
    }

    mid = (max + min) / 2;
    //same as sqrt but cubing it instead
    while (abs(pow(mid, 3) - x) > ERRORVALUE)
    {
        if (pow(mid, 3) > x)
        {
            max = mid;
        } else
        {
            min = mid;
        }

        mid = (max + min) / 2;
    }

    return mid;
}


/** ***************************************************************************
 *  @author Oliver Schwab
 *
 *  @par Description
 *  Uses Newton's Method to estimate the logarithm of a number when given the 
 * 		base and the number.
 *
 *  @param[in] x The number to find the logarithm of.
 *  @param[in] base The base for the logarithm.
 *
 *  @returns A double estimation of the logarithm of x.
 *
 *  @par Example
 *  @verbatim
    double result;
	
    double num = 64;
	double base = 8;
    result = myLog(num, base); // result would be 2

    num = 1024;
	base = 2;
	result = myLog(num, base); // result would be 10

    @endverbatim
 *****************************************************************************/
double myLog(double x, int base)
{
    double min;
    double max = 1;
    double mid;

    while (pow(base, max) < x)
    {
        max++; // find the intial max value, must be bigger the base^mid
    }

    min = max - 1;

    mid = (max + min) / 2;
    // same method assqrt root but using mid as exponent and a given base
    while (abs(pow(base, mid) - x) > ERRORVALUE)
    {
        if (pow(base, mid) > x)
        {
            max = mid;
        } else
        {
            min = mid;
        }

        mid = (max + min) / 2;
    }

    return mid;
}


/** ***************************************************************************
 *  @author Oliver Schwab
 *
 *  @par Description
 *  Uses the Taylor Series for sine to calculate the sine of the angle value 
 * 		passed in.
 *
 *  @param[in] x The angle value in radians.
 *
 *  @returns A double estimation of the sine value at that angle.
 *
 *  @par Example
 *  @verbatim
    double result;
	
    double num = 0;
    result = mySin(num); // result would be approx 0

    num = 3.14159/2;
	result = mySin(num); // result would be approx 1

    @endverbatim
 *****************************************************************************/
double mySin(double x)
{
    int i;
    double total = 0;
    double num = 1;
    int neg = 1; // used to invert the sign when adding values each iteration

    for (i = 0; i < TERMS; i++)
    {
        total += ((pow(x, num)
         / factorial(num)) 
         * neg); // formula for equation
        neg *= -1; // inverting next addition
        num += 2;
    }

    return total;
}


/** ***************************************************************************
 *  @author Oliver Schwab
 *
 *  @par Description
 *  Uses the Taylor Series for sine to calculate the sine of the angle value 
 * 		passed in.
 *
 *  @param[in] x The angle value in degrees.
 *
 *  @returns A double estimation of the sine value at that angle.
 *
 *  @par Example
 *  @verbatim
    double result;
	
    double num = 0;
    result = mySinD(num); // result would be approx 0

    num = 90;
	result = mySinD(num); // result would be approx 1

    @endverbatim
 *****************************************************************************/
double mySinD(double x)
{
    //same as mySinD but converting the input to radians first
    double radians = x * (PI/180);

    int i;
    double total = 0;
    int neg = 1;

    for (i = 1; i < (TERMS - 2) * 2; i = i + 2)
    {
        total += (pow(radians, i) / factorial(i)) * neg;
        neg *= -1;
    }

    return total;


}


/** ***************************************************************************
 *  @author Oliver Schwab
 *
 *  @par Description
 *  Calculates the factorial of given number.
 *
 *  @param[in] x The number to find the factorial of.
 *
 *  @returns A double that is the factorial of the number.
 *
 *  @par Example
 *  @verbatim
    double result;
	
    double num = 3;
    result = factorial(num); // result would be 1*2*3 = 6

    num = 5;
	result = factorial(num); // result would be 1*2*3*4*5 = 120

    @endverbatim
 *****************************************************************************/
double factorial(double x)
{
    double facSum = 1;
    double   i = 1;

    if (x <= 0)
    {
        return 0;
    }

    for (i; i <= x; i++)
    {
        facSum *= i; // multiply the total by the current i iteration
    }

    return facSum;
}


/** ***************************************************************************
 *  @author Oliver Schwab
 *
 *  @par Description
 *  Uses the Taylor Series for cosine to calculate the cosine of the angle value 
 * 		passed in.
 *
 *  @param[in] x The angle value in radians.
 *
 *  @returns A double estimation of the cosine value at that angle.
 *
 *  @par Example
 *  @verbatim
    double result;
	
    double num = 0;
    result = myCos(num); // result would be approx 1

    num = 3.14159/2;
	result = myCos(num); // result would be approx 0

    @endverbatim
 *****************************************************************************/
double myCos(double x)
{
    int i;
    double total = 1;
    int neg = -1; // used to invert the addition of terms
    int num = 2;

    for (i = 1; i < TERMS - 1; i++)
    {
        total += (pow(x, num) / factorial(num)) * neg; // formula for cos calculation
        neg *= -1;
        num += 2;
    }

    return total;
}


/** ***************************************************************************
 *  @author Oliver Schwab
 *
 *  @par Description
 *  Uses the Taylor Series for cosine to calculate the cosine of the angle value 
 * 		passed in.
 *
 *  @param[in] x The angle value in degrees.
 *
 *  @returns A double estimation of the cosine value at that angle.
 *
 *  @par Example
 *  @verbatim
    double result;
	
    double num = 0;
    result = myCosD(num); // result would be approx 1

    num = 90;
	result = myCosD(num); // result would be approx 0

    @endverbatim
 *****************************************************************************/
double myCosD(double x)
// same as MyCos but converts given input to radians first
{
    double radians = x * (PI/180);
    return myCos(radians);
}


/** ***************************************************************************
 *  @author Oliver Schwab
 *
 *  @par Description
 *  Uses the Taylor Series for sine & cosine to calculate the tangent of the 
 *	angle value passed in by using tangent = sine/cosine. Will not work at 
 * 	values where cosine is 0.
 *
 *  @param[in] x The angle value in radians.
 *
 *  @returns A double estimation of the tangent value at that angle.
 *
 *  @par Example
 *  @verbatim
    double result;
	
    double num = 0;
    result = myTan(num); // result would be approx 0

    num = 3.14159/4;
	result = myTan(num); // result would be approx 1

    @endverbatim
 *****************************************************************************/
double myTan(double x)
{
    //tan is sin/cos
    return mySin(x)/myCos(x);
}


/** ***************************************************************************
 *  @author Oliver Schwab
 *
 *  @par Description
 *  Uses the Taylor Series for sine & cosine to calculate the tangent of the 
 *	angle value passed in by using tangent = sine/cosine. Will not work at 
 * 	values where cosine is 0.
 *
 *  @param[in] x The angle value in degrees.
 *
 *  @returns A double estimation of the tangent value at that angle.
 *
 *  @par Example
 *  @verbatim
    double result;
	
    double num = 0;
    result = myTanD(num); // result would be approx 0

    num = 45;
	result = myTanD(num); // result would be approx 1

    @endverbatim
 *****************************************************************************/
double myTanD(double x)
{
    //same a myTan just calling degree functions instead
    return mySinD(x)/myCosD(x);
}   

/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * Copy's an array from a given source array to a given destinations array
 * by iterating through every element in the source array and assigning each 
 * coresponding value in the destination array to its value.
 * both arrays must be of equal lenght and data type
 * 
 * @param[in] dest the array that the data will be copied into
 * @param[in] source the array we are copying the data from
 * @param[in] size length of both arrays
 * 
 * 
 * @par Example
 * @verbatim
 * double source[3] = {1,2,3};
 * double destination[3];
 * 
 * copyArray(destination, source, 3); // destination will be {1,2,3}
 * 
 * source = {4,5,6};
 * 
 * copyArray(destination, source, 3); // destination will be {4,5,6}
 * 
 * @endverbatim
 */
void copyArray(double * dest, double * source, int size)
{
    int i;
    // iterates through the source array and assigns each
    // value in the destination to the same value
    for (i = 0; i < size; i++)
    {
        dest[i] = source[i];
    }
}

/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * sets every value within the given array to the given value
 * 
 * @param[in] array the array manipulate
 * @param[in] size size of the given array
 * @param[in] val the value to set every item within the array to
 * 
 * 
 * @par Example
 * @verbatim
 * double array[3];
 * 
 * initialArray(array, 3, 1); // array would be {1,1,1}
 * 
 * double array2[5] = {1,2,3,4,5};
 * 
 * initialArray(array, 5, 6); // array2 would be {6,6,6,6,6}
 * @endverbatim
 */
void initialArray(double array[], int size, double val) 
{
    int i;
    // assign each value within the given size to the given value
    for (i = 0; i< size; i++)
    {
        array[i] = val;
    }
}

/**
 * @author Oliver Schwab
 * 
 * @par Description
 * returns the sum of every element within the array 
 * 
 * @param[in] array the array that will be summed
 * @param[in] size the size of the given arrray
 * 
 * @return a double that is the sum of the array
 * 
 * @par Example
 * @verbatim
 * 
 * double array1[3] = {1,2,3};
 * 
 * int result = sumArray(array, 3); // result = 3
 * 
 * double array2[4] = {-2,2,5,6};
 * 
 * result = sumArray(array, 4); // result = 11
 * 
 * @endverbatim
 */
double sumArray(double array[], int size)
{
    int i;
    double total = 0;

    // add each value of the array to the total variable

    for (i = 0; i < size; i++)
    {
        total += array[i];
    }

    return total;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * returns the average of every element within the array
 * 
 * @param[in] array the array that will be averaged
 * @param[in] size the size of the given array
 * 
 * @return a double that is the average of the array
 * 
 * @par Example
 * @verbatim
 * 
 *  double array[3] = {1,2,3};
 *
 *  double average = averageArray(array, 3); // average is 2
 * 
 *  double array1[6] = {1,2,3,3,2,1};
 *
 *   average = averageArray(array, 6); // average is 2
 * 
 * @endverbatim
 */
double averageArray(double array[], int size)
{
    // sum / size
    return sumArray(array, size)/size;
}
/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * Find the maximum value within the array and returns the location
 * If there are multiple values within the array that are the max return the smallest index
 * 
 * @param[in] array the array we are searching through
 * @param[in] size the size of the given array
 * 
 * @return an integer value thats the index of the max value
 * 
 * @par Example
 * @verbatim
 * 
 *  double array[4] = {1,2,3,4};
 *
 *  int max = maxLocation(array, 4); // max = 3
 * 
 *  double array1[4] = {6,5,6,3};
 * 
 *  max = maxLocation(array1, 4); // max is 0
 *
 * 
 * @endverbatim
 */
int maxLocation(double array[], int size)
{
    int i;
    double maxVal = array[0];
    int maxIndex = 0; // intializin the value to zero incase first vale is the greatest


    for (i = 1; i < size; i++)
    //compare every value in the array to the max value, 
    //if the value in array is great set max value to 
    //that vaue and the index to that location
    {
        if (array[i] > maxVal)
        {
            maxVal = array[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * Finds the maximum value within the array and returns that value
 * 
 * @param[in] array the array we are searching for the largest value
 * @param[in] size the size of the given array
 * 
 * @return a double that is maximum value found within the array
 * 
 * @par Example
 * @verbatim
 * 
 * double array[4] = {1,2,3,4};
 *
 *  double max = maxValue(array, 4); // max = 4
 * 
 *  double array[6] = {0,4,-2,6,4,2};
 *
 *  double max = maxValue(array, 6); // max = 6
 * 
 * @endverbatim
 */
double maxValue(double array[], int size)
{
    //same as max location but we dont need to save the index
    int i;
    double maxVal = array[0];


    for (i = 1; i < size; i++)
    {
        if (array[i] > maxVal)
        {
            maxVal = array[i];
        }
    }

    return maxVal;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * searches the entire array and find the smallest 
 * value of within the array and returns its location within the array
 * if there are multiple values that are equal and are the smallest 
 * it returns the first index
 * 
 * @param[in] array the array to search
 * @param[in] size size of the given array
 * 
 * @return an integer represting the location of the min value within the array
 * 
 * @par Example
 * @verbatim
 * 
 *  double array[4] = {1,2,3,4};
 *
 *  int max = minLocation(array, 4); // min = 0
 * 
 *  double array[4] = {6,5,6,3};
 *
 *  int max = minLocation(array, 4); // min = 3
 *
 * 
 * @endverbatim
 */
int minLocation(double array[], int size)
{
    // same a maxLocation but we are just checking if anything is lower
    // instead of greater
    int i;
    double maxVal = array[0];
    int maxIndex = 0;


    for (i = 1; i < size; i++)
    {
        if (array[i] < maxVal)
        {
            maxVal = array[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * searches the entire array and finds the smallest value.
 * returns that value;
 * 
 * @param[in] array the array to search through
 * @param[in] size the length of the given array
 * 
 * @return a double representing the smallest found value
 * 
 * @par Example
 * @verbatim
 * 
 *  double array[4] = {1,2,3,4};
 *
 *  double min = minValue(array, 4); // min = 1
 * 
 *  double array[6] = {0,4,-2,6,4,2};
 *
 *  double min = minValue(array, 6); // min = -2
 * 
 * @endverbatim
 */
double minValue(double array[], int size)
{
    // same a minLocation except we dont save the location
    int i;
    double minVal = array[0];


    for (i = 1; i < size; i++)
    {
        if (array[i] < minVal)
        {
            minVal = array[i];
        }
    }

    return minVal;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * iterates through the array and counts the number 
 * of elements matching the given value
 * 
 * @param[in] array the array to search through
 * @param[in] size the size of the given array
 * @param[in] toCount the value to compare to
 * 
 * @return an integer representing the number of times the value was found
 * 
 * @par Example
 * @verbatim
 * 
 *  double array[4] = {1,2,3,3};
 *
 *  int count = countIf(array, 4, 3); // count = 1
 * 
 *  double array[6] = {0,4,-2,6,4,2};
 *
 *  int count = countIf(array, 6, 4); // count = 2
 *
 * 
 * @endverbatim
 */
int countIf(double array[], int size, double toCount)
{
    // iterates through the array and if any value is in the array we add one to the total
    int total = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        if (array[i] == toCount)
        {
            total += 1;
        }
    }

    return total;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * sorts the array in either ascending or descending 
 * order depening upon the given string.
 * Sorted using selection sort method
 * 
 * @param[in] array the given array to sort
 * @param[in] size the size of the given array
 * @param[in] method the order of the sorted array
 * 
 * 
 * @par Example
 * @verbatim
 * 
 *  double array[5] = {2,3,5,9,1};
 *
 *  mySort(array, 5, "DSC"); // array = {9,5,3,2,1}
 * 
 *  double array[5] = {2,3,5,9,1};
 *
 *  mySort(array, 5, "ASC"); // array = {1,2,3,5,9}
 * 
 * @endverbatim
 */
void mySort(double array[], int size, string method)
{
    int i;
    int z;
    double stor;
    double tempMax;
    int swapIndex;
    
    if (method == "DSC")
    {

        for (i = 0; i < size; i++) // iterate through the entire array
        {
            tempMax = array[i]; // assume max is the start of the array being looking at
            swapIndex = i;
            for (z = i+1; z < size; z++) // iterate from the point of the outer 
            //iteration to the end of the array
            {
                if (array[z] > tempMax)
                // if we find a larger value in the array we 
                // then set that value and the index
                {
                    tempMax = array[z];
                    swapIndex = z;
                }
            }
            // swap the value at the start of the secnd iteration and the max value
            stor = array[swapIndex];
            array[swapIndex] = array[i];
            array[i] = stor;
            
        }

    } else if (method == "ASC")
    {
        // same as DSC but we just find the smallest value each iteration
        for (i = 0; i < size; i++)
        {
            tempMax = array[i];
            swapIndex = i;
            for (z = i+1; z < size; z++)
            {
                if (array[z] < tempMax)
                {
                    tempMax = array[z];
                    swapIndex = z;
                }
            }

            stor = array[swapIndex];
            array[swapIndex] = array[i];
            array[i] = stor;
            
        }
    }
}

/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * iterates through the entire array or until the desired element is found
 * and returns its location.
 * if there is no matching element a -1 is returned.
 * 
 * @param[in] array the array to search through
 * @param[in] size the size of the given array
 * @param[in] toFind the value being searched for
 * 
 * @return an integer representing the location of the element in the array
 * 
 * @par Example
 * @verbatim
 * 
 *  double array[3] = {0, 5, 7};
 *
 *  int result = linearSearch(array, 3, 5); // result = 1
 * 
 *  double array[3] = {0, 5, 7};
 *
 *  int result = linearSearch(array, 3, 2); // result = -1
 * 
 * @endverbatim
 */
int linearSearch(double array[], int size, double toFind)
{
    // iterate through array and if there is something 
    // that equals the given value return its location
    int i;

    for (i = 0; i < size; i++)
    {
        if (array[i] == toFind)
        {
            return i;
        }
    }

    return -1;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * sorts and then searches the given array for the given value 
 * using the binary search method.
 * If the value is not found return -1 indicating it is not in the array.
 * 
 * @param[in] array the array to search through
 * @param[in] size the size of the given array
 * @param[in] toFind the value being searched for
 * 
 * @return and integer representing the location of the matching element
 * 
 * @par Example
 * @verbatim
 * 
 *  double array[5] = {4,2,5,6,3};
 *
 *  int result = binarySearch(array, 5, 4); // result = 2
 * 
 *  double array[15] = {1,5,7,8,2,4,5,6,2,5,66,2,4,6,7};
 *
 * int result = binarySearch(array, 15, 5); // result = 7
 * 
 * @endverbatim
 */
int binarySearch(double array[], int size, double toFind)
{
    
    int max = size;
    int min = 0;
    int mid = (max-min)/2 + min;
    //sort array and set high and low values
    mySort(array, size, "ASC");
    // while there are still value to search through
    while (min <= max)
    {   // if we found the value
        if (array[mid] == toFind)
        {
            return mid;
        }
        // if the middle value is less then the value we are 
        // looking for look at the top half of the array
        if (array[mid] < toFind)
        {
            min = mid + 1;
        } else 
        //look at the bottom half
        {
            max = mid - 1;
        }

        mid = (max-min)/2 + min; // new mid values
    }

    return -1;
}