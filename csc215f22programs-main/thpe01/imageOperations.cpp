/** ***************************************************************************
* @file
* 
* @brief contains functions to modify images
******************************************************************************/

#include "netPBM.h"

/**
 * @author Oliver Schwab
 * 
 * @par Given an image of color, turns image into grayscale version
 * 
 * @param[in, out] iImage the image to perform grayscale operation on
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * iImage i; pretend its full of image data
 * 
 * grayscale(i); i.redgray would now contain grayscale pixels
 * 
 * @endverbatim
 */
void grayscale(image& iImage)
{

    int row, col, result;

    for (row = 0; row < iImage.rows; row++)
    {
        for (col = 0; col < iImage.cols; col++)
        {
            // for every pixel in image apply the given function
            

            result = (int) round((0.3 * iImage.redgray[row][col]) + 
                (0.6 * iImage.green[row][col]) + 
                (0.1 * iImage.blue[row][col]));

            // bound checking

            if (result > 255)
            {
                result = 255;
            }

            else if (result < 0)
            {
                result = 0;
            }            

            iImage.redgray[row][col] = (pixel) result;

        }
    }
}

/**
 * @author Oliver Schwab
 * 
 * @par Given an image of color, performs negate operation on image
 * 
 * @param[in, out] iImage the image to perform negate operation on
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * iImage i; pretend its full of image data
 * 
 * grayscale(i); 
 * //i.redgray would now contain pixels that have been contrasted
 * 
 * @endverbatim
 */
void negateOp(image& iImage)
{
    int row, col;

    for (row = 0; row < iImage.rows; row++)
    {
        for (col = 0; col < iImage.cols; col++)
        {
            // for exery pixel apply given function to every rgb value
            if (255 - iImage.redgray[row][col] < 0)
            {
                iImage.redgray[row][col] = 0;
            }

            else
            {
                iImage.redgray[row][col] = 255 - iImage.redgray[row][col];
            }


            if (255 - iImage.green[row][col] < 0)
            {
                iImage.green[row][col] = 0;
            }

            else
            {
                iImage.green[row][col] = 255 - iImage.green[row][col];
            }


            if (255 - iImage.blue[row][col] < 0)
            {
                iImage.blue[row][col] = 0;
            }

            else
            {
                iImage.blue[row][col] = 255 - iImage.blue[row][col];
            }
        }
    }
}

/**
 * @author Oliver Schwab
 * 
 * @par Given a image struct populated with image date, performs sharpen 
 * method on every pixel
 * 
 * @param[in, out] iImage image to perform the sharpen operation on
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * iImage i; //pretend its full of image data
 * 
 * sharpen(i); //the pixel arrays wold now contain a sharpened image
 * 
 * @endverbatim
 */
void sharpen(image& iImage)
{
    // need to create and allocate three new 2d pixel arrays for storage
    pixel** newr = nullptr;
    pixel** newg = nullptr;
    pixel** newb = nullptr;

    int row, col;

    int tmp = 0;
    
    allocate2d(newr, iImage.rows, iImage.cols);

    if (newr == nullptr)
    {
        deleteArrays(iImage);
        exit(0);
    }

    allocate2d(newg, iImage.rows, iImage.cols);

    if (newg == nullptr)
    {
        deleteArrays(iImage);
        free2d(newr, iImage.rows);
        exit(0);
    }

    allocate2d(newb, iImage.rows, iImage.cols);

    if (newb == nullptr)
    {
        deleteArrays(iImage);
        free2d(newg, iImage.rows);
        free2d(newr, iImage.rows);
        exit(0);
    }

    for (row = 0; row < iImage.rows; row++)
    {
        for (col = 0; col < iImage.cols; col++)
        {// do not apply formula to edge of image
            if (col == 0 || col == iImage.cols - 1 
                || row == 0 || row == iImage.rows - 1)
            {
                newr[row][col] = 0;
                newg[row][col] = 0;
                newb[row][col] = 0;
            }

            else
            { // generate number based on given formula
                tmp = 5 * iImage.redgray[row][col] - 
                    iImage.redgray[row][col - 1] - 
                    iImage.redgray[row - 1][col] - 
                    iImage.redgray[row + 1][col] - 
                    iImage.redgray[row][col + 1];

                //bound checking
                if (tmp > 255)
                {
                    newr[row][col] = 255;
                }

                else if (tmp < 0)
                {
                    newr[row][col] = 0;
                }

                else
                {
                    newr[row][col] = (pixel) tmp;
                }

                //repeated algorithim for green
                tmp = 5 * iImage.green[row][col] - 
                    iImage.green[row][col - 1] - 
                    iImage.green[row - 1][col] - 
                    iImage.green[row + 1][col] - 
                    iImage.green[row][col + 1];

                if (tmp > 255)
                {
                    newg[row][col] = 255;
                }

                else if (tmp < 0)
                {
                    newg[row][col] = 0;
                }

                else
                {
                    newg[row][col] = (pixel) tmp;
                }

                // repeated algoritim for blue
                tmp = 5 * iImage.blue[row][col] - 
                    iImage.blue[row][col - 1] - 
                    iImage.blue[row - 1][col] - 
                    iImage.blue[row + 1][col] - 
                    iImage.blue[row][col + 1];
                
                if (tmp > 255)
                {
                    newb[row][col] = 255;
                }

                else if (tmp < 0)
                {
                    newb[row][col] = 0;
                }

                else
                {
                    newb[row][col] = (pixel) tmp;
                }
            }
        }

    }

    for (row = 0; row < iImage.rows; row++)
    {
        for (col = 0; col < iImage.cols; col++)
        {
            // assign all new generated values to image data
            iImage.redgray[row][col] = newr[row][col];

            iImage.green[row][col] = newg[row][col];

            iImage.blue[row][col] = newb[row][col];

        }
    }
    // free up storage arrays
    free2d(newr, row);
    free2d(newg, row);
    free2d(newb, row);


}

/**
 * @author Oliver Schwab
 * 
 * @par given a image struct populated with image data, 
 * performs the smooth operation on the image.
 * 
 * @param[in, out] iImage image to perform sharpen operation
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * iImage i; pretend its full of image data
 * 
 * smooth(i); the image struct would now contain a smoothed image
 * 
 * @endverbatim
 */
void smooth(image& iImage)
{
    // new 2d pixel arrays for storage
    pixel** newr = nullptr;
    pixel** newg = nullptr;
    pixel** newb = nullptr;;

    int row, col;

    int tmp = 0;
    // allocation of arrays
    allocate2d(newr, iImage.rows, iImage.cols); // Allocating the new arrays

    if (newr == nullptr)
    {
        deleteArrays(iImage);
        exit(0);
    }

    allocate2d(newg, iImage.rows, iImage.cols);

    if (newg == nullptr)
    {
        deleteArrays(iImage);
        free2d(newr, iImage.rows);
        exit(0);
    }

    allocate2d(newb, iImage.rows, iImage.cols);

    if (newb == nullptr)
    {
        deleteArrays(iImage);
        free2d(newg, iImage.rows);
        free2d(newr, iImage.rows);
        exit(0);
    }


    for (row = 0; row < iImage.rows; row++)
    {
        for (col = 0; col < iImage.cols; col++)
        {
            if (col == 0 || col == iImage.cols - 1 
                || row == 0 || row == iImage.rows - 1)
            {// do not modify bounds
                newr[row][col] = iImage.redgray[row][col];
                newg[row][col] = iImage.green[row][col];
                newb[row][col] = iImage.blue[row][col];
            }

            else
            {// apply formula for red column in for every pixel
                tmp = (int) round((iImage.redgray[row - 1][col - 1] + 
                    iImage.redgray[row - 1][col] + 
                    iImage.redgray[row - 1][col + 1] +
                    iImage.redgray[row][col - 1] + 
                    iImage.redgray[row][col] + 
                    iImage.redgray[row][col + 1] +
                    iImage.redgray[row + 1][col - 1] + 
                    iImage.redgray[row + 1][col] + 
                    iImage.redgray[row + 1][col + 1])/9);
            // bound checking and assignment of appropriate value to copy array
                if (tmp > 255)
                {
                    newr[row][col] = 255;
                }

                else if (tmp < 0)
                {
                    newr[row][col] = 0;
                }

                else
                {
                    newr[row][col] = (pixel)tmp;
                }

                // repeat for green and blue
                tmp = (int) round((iImage.green[row - 1][col - 1] + 
                    iImage.green[row - 1][col] + 
                    iImage.green[row - 1][col + 1] +
                    iImage.green[row][col - 1] + 
                    iImage.green[row][col] + 
                    iImage.green[row][col + 1] +
                    iImage.green[row + 1][col - 1] + 
                    iImage.green[row + 1][col] + 
                    iImage.green[row + 1][col + 1]) / 9);

                if (tmp > 255)
                {
                    newg[row][col] = 255;
                }

                else if (tmp < 0)
                {
                    newg[row][col] = 0;
                }

                else
                {
                    newg[row][col] = (pixel)tmp;
                }

                tmp = (int) round((iImage.blue[row - 1][col - 1] + 
                    iImage.blue[row - 1][col] + 
                    iImage.blue[row - 1][col + 1] +
                    iImage.blue[row][col - 1] + 
                    iImage.blue[row][col] + 
                    iImage.blue[row][col + 1] +
                    iImage.blue[row + 1][col - 1] + 
                    iImage.blue[row + 1][col] + 
                    iImage.blue[row + 1][col + 1]) / 9);

                if (tmp > 255)
                {
                    newb[row][col] = 255;
                }

                else if (tmp < 0)
                {
                    newb[row][col] = 0;
                }

                else
                {
                    newb[row][col] = (pixel)tmp;
                }
            }
        }

    }


    for (row = 0; row < iImage.rows; row++)
    {
        for (col = 0; col < iImage.cols; col++)
        {
            // assign modified values to image arrays
            iImage.redgray[row][col] = newr[row][col];

            iImage.green[row][col] = newg[row][col];

            iImage.blue[row][col] = newb[row][col];

        }
    }

        // delete copied arrays
    free2d(newr, iImage.rows);
    free2d(newg, iImage.rows);
    free2d(newb, iImage.rows);
}

/**
 * @author Oliver Schwab
 * 
 * @par given a image struct populated with image data, 
 * performs contrast operation on image
 * 
 * @param[in, out] iImage image struct populated with image data
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * iImage i; pretend its full of image data
 * 
 * contrast(i); i would now contain an image that has been contrasted
 * 
 * @endverbatim
 */
void contrast(image& iImage)
{

    grayscale(iImage); //first step in apply contrast

    int row, col, min = iImage.redgray[0][0], 
        max = iImage.redgray[0][0]; // intial guesses for min/max

    double scale;

    for (row = 0; row < iImage.rows; row++)
    {
        for (col = 0; col < iImage.cols; col++)
        {// find min/max
            if (iImage.redgray[row][col] > max)
            {
                max = iImage.redgray[row][col];
            }
            
            if (iImage.redgray[row][col] < min)
            {
                min = iImage.redgray[row][col];
            }
        }
    }

    scale = 255.0 / (max - min);

    for (row = 0; row < iImage.rows; row++)
    {
        for (col = 0; col < iImage.cols; col++)
        {//bound checking
            if ((scale * ((int) iImage.redgray[row][col] - min)) > 255)
            {
                iImage.redgray[row][col] = 255;
            } 
 
            else if ((scale * ((int) iImage.redgray[row][col] - min)) < 0)
            {
                iImage.redgray[row][col] = 0;
            }
            // apply formula for every pixel
            else
            {

                iImage.redgray[row][col] = pixel(
                    round(scale * (iImage.redgray[row][col] - min)));
            }

        }
    }
}

/**
 * @author Oliver Schwab
 * 
 * @par Given a image struct populated with image data, 
 * brightens every pixel by the specified amount
 * 
 * @param[in, out] iImage the image to perform brighten operation on
 * @param[in] brighten the amount to brighten each pixel by
 *    
 * 
 * @par Example
 * @verbatim
 * 
 * iImage i; pretend its full of image data
 * 
 * brighten(i, 100); 
 * //the image would now have every pixel 100 brighter to a max of 254
 * 
 * @endverbatim
 */
void brightenOp(image& iImage, int brighten)
{
    
    
    int row, col;

    pixel toAdd = (pixel) brighten;

    for (row = 0; row < iImage.rows; row++)
    {
        for (col = 0; col < iImage.cols; col++)
        {// for every pixel add bightness o value and check bounds
            if (iImage.redgray[row][col] + brighten > 255)
            {
                iImage.redgray[row][col] = 255;
            }

            else
            {
                iImage.redgray[row][col] += toAdd;
            }


            if (iImage.green[row][col] + brighten > 255)
            {
                iImage.green[row][col] = 255;
            }

            else
            {
                iImage.green[row][col] += toAdd;
            }

            
            if (iImage.blue[row][col] + brighten > 255)
            {
                iImage.blue[row][col] = 255;
            }
            
            else
            {
                iImage.blue[row][col] += toAdd;
            }
        }
    }
}

/*
void boundChecking(image& iImage)
{

    int row, col;

    for (row = 0; row < iImage.rows; row++)
    {
        for (col = 0; col < iImage.cols; col++)
        {
            if (iImage.redgray[row][col] > 255)
            {
                iImage.redgray[row][col] = 255;
            }
            else if (iImage.redgray[row][col] < 0)
            {
                iImage.redgray[row][col] = 0;
            }

            if (iImage.green[row][col] > 255)
            {
                iImage.green[row][col] = 255;
            }
            else if (iImage.green[row][col] < 0)
            {
                iImage.green[row][col] = 0;
            }
            
            if (iImage.blue[row][col] > 255)
            {
                iImage.blue[row][col] = 255;
            }
            else if (iImage.blue[row][col] < 0)
            {
                iImage.blue[row][col] = 0;
            }
        }
    }
}
*/