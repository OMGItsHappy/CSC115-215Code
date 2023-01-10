#include "a0010.h"

//write functions here

void sortArray(int array[], int size)
{

    int i;
    int j;
    int temp;

    for(i = 0; i<size; i++) {
   for(j = i+1; j<size; j++)
   {
      if(array[j] < array[i]) {
         temp = array[i];
         array[i] = array[j];
         array[j] = temp;
      }
   }
}
}


int sumArray(int array[], int size)
{
    int total = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        total += array[i];
    }

    return total;
}


int min(int array[], int size)
{
    int i;
    int min = array[0];

    for (i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}


int max(int array[], int size)
{
    int i;
    int max = array [0];

    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}


double average(int array[], int size)
{
    return (double) sumArray(array, size) / (double) size;
}