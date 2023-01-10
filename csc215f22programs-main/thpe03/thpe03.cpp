/** ***************************************************************************
* @file
* 
* @brief Reads in ppm image and provides operations to modify the image, allows
* for output to pgm and ppm files in both ascii and binary
******************************************************************************/

/** ***************************************************************************
* 
* @mainpage thpe03 - flood fill
* 
* @section 215 Programing Techniques
* 
* @authors Oliver Schwab
* 
* @date 11/18/2022  
* 
* @par Instructor
*          Dr. Schrader
* 
* @par Course
*          CSC 215 - Section m01 -2pm
* 
* @par Location
*          Classroom Building - Room 112
* 
* @section program_section Program Information
* 
* @details This program accepts a color image in the ppm format. 
* Allows for the data to be both ascii or binary data.
* Usage for the program is as follows:
* thpe03.exe imageFile row col redValue greenValue blueVale
* Where the row and col is the place to start the bucket fill,
* and the rgb values are the color to fill with.
* The program fills all adjacent pixels of the same color.
* 
* @par Compiling Instruction:
*       None
* 
* @par Usage
* @verbatim
* thpe03.exe imageFile row col redValue greenValue blueValue
*
* Invalid Usage: 
* thpe3.exe imageFile row col redValue greenValue blueValue
* 
* thpe03.exe square.ppm 10 10 255 0 0 
* This would fill the image at the given spot with red pixels. 
* And all adjacent pixels of the same color.
* @endverbatim
* 
*/

#include "netPBM.h"
#include <vector>
#include <algorithm>

/**
 * @author Oliver Schwab    
 * 
 * @par Description 
 * The location class that holds the data of a pixel and creates some methods
 * useful for Filling an image.
 */
class location 
{
    public:

        location(int row1 = 0, int col1 = 0);
        ~location();

        int row; /**< The row of this classes pixel*/
        int col; /**< the column of this classes pixel*/

        bool equal(location toCheck);

        void replace(image &i, int r, int g, int b);

        bool in(vector<location> &v1);

        void adjacent(vector<location>& v1);

        bool pixelsEqual(image& i, location l);
};

void generatePixels(image &i, location l, vector<location> &v1); // old method

void genPixels(image& i, location l, vector<bool>& v2, vector<location>& v1);


/**
 * @author Oliver Schwab
 * 
 * @par The function that performs the image fill operations.
 * Handles all command line arguments and calls the appropraite
 * functions to fill the image.
 * 
 * @param[in] argc number of arguments passed to the executable
 * @param[in] argv arguments passed to the executable
 * 
 * @return int success code
 * 
 * @par Example
 * @verbatim
 * 
 * thpe03.exe imageFile row col redValue greenValue blueValue
 *
 * Invalid Usage: 
 * thpe3.exe imageFile row col redValue greenValue blueValue
 * 
 * thpe03.exe square.ppm 10 10 255 0 0 
 * This would fill the image at the given spot with red pixels. 
 * And all adjacent pixels of the same color.
 * 
 * @endverbatim
 */
int main(int argc, char** argv)
{
    ifstream file;

    ofstream ofile;

    image i;

    string tmpStr, toCheck;

    int r, g, b;

    vector<location> v1; // row col

    vector<bool> v2;

    if (argc != 7)
    {
        cout << "Invalid Usage: \n" << "thpe3.exe imageFile row col redValue greenValue blueValue" << endl;
        return 0;
    }

    openFileInput(file, argv[1]);

    readFileData(i, file);

    file.close();

    v2.reserve(i.rows * i.cols);

    for (int r = 0; r < i.rows; r++)
    {
        for (int c = 0; c < i.cols; c++)
        {
            v2.push_back(false);
        }
    }

    location tmp = location(stoi(argv[2]), stoi(argv[3]));

    genPixels(i, tmp, v2, v1);

    r = stoi(argv[4]), g = stoi(argv[5]), b = stoi(argv[6]);

    for (location l : v1)
    {
        l.replace(i, r, g, b);
    }

    openFileOutput(ofile, argv[1]);

    if (i.magicNumber == "P3")
    {
        outputToP3File(i, ofile);
    }

    else
    {
        outputToP6File(i, ofile);
    }

    ofile.close();
}


/**
 * @author Oliver Schwab
 * 
 * @par Description Recusrive function to 
 * determine which pixels need to be filled.
 * Adds pixels needing to be filled to the passed in vector.
 * This method is a slower way then the other included in this file
 * as it stictly uses recursion.
 * 
 * @param[in] i the image to fill, does not modify image only checks pixels.
 * @param[in] l the location of a pixel to check
 * @param[in] v1 the list of pixels that have already been checked.
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * generatePixels(i, l, v1); // assume i is a valid image, 
 * //l is the gievn location to start at,
 * // and v1 is the vector in which the pixels to be modified will be stored.
 * 
 * @endverbatim
 */
void generatePixels(image &i, location l, vector<location> &v1) // depreciated slow way
{
    vector<location> v2;

    if (l.in(v1))
    {
        return;
    }

    v1.push_back(l);

    l.adjacent(v2);

    for (location tmp : v2)
    {
        if (l.row < i.rows
            && l.row >= 0
            && l.col < i.cols
            && l.col >= 0
            && tmp.row < i.rows
            && tmp.row >= 0
            && tmp.col < i.cols
            && tmp.col >= 0
            && l.pixelsEqual(i, tmp))
        {
            generatePixels(i, tmp, v1);
        }
    }
}


/**
 * @author Oliver Schwab
 * 
 * @par Description Function to determine the pixels that need to filled.
 * This fucntion uses a faster method by implmenting a lookup array.
 * The pixels needing to be filled are added to the passed in v1 vector.
 * When intitally calling the fucntion, 
 * the l varible is assumed to be the pixel we are starting at.
 * 
 * The function returns nothing. 
 * The v1 array contains all the pixels to be filled
 * 
 * @param[in] i image that needs to be filled. not modified only used to check
 * @param[in] l the location of the pixel to check
 * @param[in] v2 the lookup array, assumed the array is all false.
 * @param[in] v1 the vector of pixels that need to be filled.
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * generatePixels(i, l, v2, v1); // assume i is a valid image, 
 * //l is the gievn location to start at,
 * // and v1 is the vector in which the pixels to be modified will be stored.
 * // and v2 is a bool array intiallized to false
 * 
 * @endverbatim
 */
void genPixels(image& i, location l, vector<bool>& v2, vector<location>& v1) //vroom
{
    vector<location> v3;

    if (v2[l.row * i.cols + l.col])
    {
        return;
    }

    v2[l.row * i.cols + l.col ] = true;

    v1.push_back(l);

    l.adjacent(v3);

    for (location tmp : v3)
    {
        if (tmp.row < i.rows
            && tmp.row >= 0
            && tmp.col < i.cols
            && tmp.col >= 0
            && l.pixelsEqual(i, tmp))
        {
            genPixels(i, tmp, v2, v1);
        }
    }
}

/**
 * @author Oliver Schwab
 * 
 * @par Description returns the 4 pixels adjacent to the pixels
 * 
 * -------
 * - -x- -
 * -x-p-x-
 * - -x- -
 * -------
 * 
 * if p is the current pixel, returns the 4 pixels marked x.
 * 
 * @param[in] v1 the array to populate with the adjacent pixels
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * vector<location> v1;
 * 
 * location p = location(10, 10);
 * 
 * p.adjacent(v1); // v1 would now contain a location class for the pixels
 * //[9, 10], [10,9] [11, 10], [10, 11]
 * 
 * @endverbatim
 */
void location::adjacent(vector<location>& v1)
{
    location tmp = location(row - 1, col);

    v1.push_back(tmp);

    tmp = location(row + 1, col);

    v1.push_back(tmp);

    tmp = location(row, col - 1);

    v1.push_back(tmp);

    tmp = location(row, col + 1);

    v1.push_back(tmp);

}

/**
 * @author Oliver Schwab
 * 
 * @par Description determines if two location objects are equal
 * 
 * @param[in] toCheck the given location to compare the current object against
 * 
 * @return bool if the objects are equal or not
 * 
 * @par Example
 * @verbatim
 * 
 * location l1 = location(10, 10);
 * 
 * location l2 = location(10, 10);
 * 
 * l1.equal(l2); // would return true
 * 
 * l2 = location(10, 11);
 * 
 * l1.equal(l2); // would return false
 * 
 * @endverbatim
 */
bool location::equal(location toCheck)
{
    if (row == toCheck.row
        && col == toCheck.col)
    {
        return true;
    }

    return false;
}

/**
 * @author Oliver Schwab
 * 
 * @par Description Construct a new location::location object
 * 
 * @param[in] row1 The row of the given pixel. defaults to zero.
 * @param[in] col1 The col of the given pixel. defaults to zero.
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * location l1 = location(); // row =0, col = 0
 * 
 * l1 = location(10, 10);// row = 10, col = 10
 * 
 * location l2; // row = 0, col = 0
 * 
 * @endverbatim
 */
location::location(int row1, int col1)
{
    row = row1;
    col = col1;
}


/**
 * @author Oliver Schwab
 * 
 * @par Description Destroy the location::location object
 * 
 * 
 * 
 * @par Example
 * @verbatim
 *
 * location l1; // when l1 leaves scope, function ends l1 will be destroyed
 * 
 * @endverbatim
 */
location::~location()
{

}


/**
 * @author Oliver Schwab
 * 
 * @par determines if the current object is in the passed in vector.
 * being in the function means it has the same value as a element of the array.
 * it does not mean it has the same pointers.
 * 
 * @param[in] v1 the array to check for the current object
 * 
 * @return bool returns true if object is in array, false if it is not
 * 
 * @par Example
 * @verbatim
 * 
 * vector<location> v1;
 * 
 * v1.push_back(location());
 * 
 * location l1;
 * 
 * l1.in(v1); // would return true as 0,0 is in v1
 * 
 * l1 = location(1, 1);
 * 
 * l1.in(v1) //would return false as 1, 1 is not in the vector with 0,0
 * // as the only element
 * 
 * @endverbatim
 */
bool location::in(vector<location>& v1)
{
    for (location l : v1)
    {
        if (equal(l))
        {
            return true;
        }
    }

    return false;
}


/**
 * @author Oliver Schwab
 * 
 * @par Description replaces the pixel at the locaton of the object
 *  in the given image with the passed in rgb values.
 * 
 * @param[in, out] i the image to modify the pixels of
 * @param[in] r the red value to replace
 * @param[in] g the green value to replace
 * @param[in] b the blue value to replace
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * location l1 = location(10, 10);
 * 
 * l1.replace(i, 255, 0, 0); // assume i is a valid image,
 * this call would replace the pixel at 10, 10 with a red pixel
 * 
 * @endverbatim
 */
void location::replace(image& i, int r, int g, int b)
{
    i.redgray[row][col] = r;
    i.green[row][col] = g;
    i.blue[row][col] = b;
}


/**
 * @author Oliver Schwab
 * 
 * @par Description Determines if the current objects pixel values are
 * equal to the passed in location objects pixel values in the context of the
 * passed in image.
 * 
 * @param[in] i image to check pixels of
 * @param[in] l location to compare to
 * 
 * @return bool if the pixel values are equal return true, otherwise false
 * 
 * @par Example
 * @verbatim
 * 
 * //assume the pixel value in image at [0, 0] = 0,0,0
 * [1,0] = 255, 0, 0
 * 
 * location l1 = location(0, 0);
 * 
 * location l2 = location(0, 0);
 * 
 * image i; // assume image is a valid image
 * 
 * l1.pixelEquals(i, l2); // would return true 
 * 
 * l2 = location(1, 0);
 * 
 * l1.equals(i, l2); // would return false
 * 
 * @endverbatim
 */
bool location::pixelsEqual(image& i, location l)
{
    if (i.redgray[row][col] == i.redgray[l.row][l.col]
        && i.green[row][col] == i.green[l.row][l.col]
        && i.blue[row][col] == i.blue[l.row][l.col]
        )
    {
        return true;
    }


    return false;
}