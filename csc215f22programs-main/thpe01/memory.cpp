/** ***************************************************************************
* @file
* 
* @brief contains functions to create and delete dynamically allocated arrays
******************************************************************************/


#include "netPBM.h"
/*
void allocateMem(image& iImage, ifstream& file)
{
    iImage.redgray = new (nothrow) pixel * [iImage.rows];

    if (iImage.redgray == nullptr)
    {
        cout << "Memory Allocation Error";
        deleteArrays(iImage);
        file.close();
        exit(0);
    }

    iImage.green = new (nothrow) pixel * [iImage.rows];

    if (iImage.green == nullptr)
    {
        cout << "Memory Allocation Error";
        deleteArrays(iImage);
        file.close();
        exit(0);
    }

    iImage.blue = new (nothrow) pixel * [iImage.rows];

    if (iImage.blue == nullptr)
    {

        cout << "Memory Allocation Error";
        deleteArrays(iImage);
        file.close();
        exit(0);
    }

    //cout << iImage.rows << endl << iImage.cols << endl << iImage.comment;

    for (int i = 0; i < iImage.rows; i++)
    {

        iImage.redgray[i] = new (nothrow) pixel[iImage.cols];

        if (iImage.redgray[i] == nullptr)
        {
            cout << "Memory Allocation Error";
            deleteArrays(iImage);
            file.close();
            exit(0);
        }

        iImage.green[i] = new (nothrow) pixel[iImage.cols];

        if (iImage.green[i] == nullptr)
        {
            cout << "Memory Allocation Error";
            deleteArrays(iImage);
            file.close();
            exit(0);
        }

        iImage.blue[i] = new (nothrow) pixel[iImage.cols];

        if (iImage.blue[i] == nullptr)
        {

            cout << "Memory Allocation Error";
            deleteArrays(iImage);
            file.close();
            exit(0);
        }
    }
}
*/

/**
 * @author Oliver Schwab
 * 
 * @par deletes given image arrays from memory, pulls rows from image
 * 
 * @param[in, out] iImage the image strcture to delete arrays for
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * image i;
 * 
 * int rows = 10, col = 10;
 * 
 * allocate2d(i.redgray, row, col);
 * allocate2d(i.green, row, col);
 * allocate2d(i.blue, row, col);
 * 
 * deleteArrays(iImage);
 * 
 * @endverbatim
 */
void deleteArrays(image& iImage)
{
    // delete immage arrays
    int rows = iImage.rows;
    free2d(iImage.redgray, rows);
    free2d(iImage.green, rows);
    free2d(iImage.blue, rows);
}

/**
 * @author Oliver Schwab
 * 
 * @par frees memory of 2d array of pixels
 * 
 * @param[in, out] arr array to clear
 * @param[in] rows the number of rows of the array
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * pixel ** arr;
 * 
 * allocated2d(arr, 10, 10);
 * 
 * free2d(arr, 10); // arr no longer has a place in memory, is a null ptr
 * 
 * @endverbatim
 */
void free2d(pixel**& arr, int rows)
{// deletes 2d array
    int i;

    if (arr == nullptr)
    {
        return;
    }

    for (i = 0; i < rows; i++)
    {
        if (arr[i] != nullptr) delete[] arr[i];
    }

    if (arr != nullptr)
    {
        delete[] arr;
    }
    
}

/**
 * @author Oliver Schwab
 * 
 * @par allocates a 2d pixel array to the size [row][col]
 * 
 * @param[in, out] arr the array to allocate
 * @param[in] rows number of rows
 * @param[in] cols number of columns
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * pixel ** arr;
 * 
 * allocated2d(arr, 10, 10); // arr is now a arr with 10 rows of 10 columns
 * 
 * @endverbatim
 */
void allocate2d(pixel** &arr, int rows, int cols)
{
    //allocates 2d array with error checking
    int r;

    arr = new (nothrow) pixel*[rows];

    if (arr == nullptr)
    {
        cout << "Memory Allocation Error";
        //free2d(arr, rows);
    }

    else
    {
        for (r = 0; r < rows; r++)
        {
            arr[r] = new (nothrow) pixel[cols];

            if (arr[r] == nullptr)
            {
                cout << "Memory Allocation Error";
                free2d(arr, r);
                return;
            }
        }
    }

}