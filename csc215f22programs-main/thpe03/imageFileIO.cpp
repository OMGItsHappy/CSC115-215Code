/** ***************************************************************************
* @file
* 
* @brief contains all the functions for reading and writing to a file
******************************************************************************/

#include "netpbm.h"

/**
 * @author Oliver Schwab
 * 
 * @par Opens a file and handles the possible errors,
 * exits program if fails
 * 
 * @param[in, out] file the ifstream used to open the file
 * @param[in] fileName the name of the file to open
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * ifstream file;
 * char* filename = "test.txt";
 * 
 * openFileInput(file, filename); // file is now open and can be worked with
 * 
 * @endverbatim
 */
void openFileInput(ifstream &file, char* fileName) 
{ // properly handeling file opening

    file.open(fileName, ios::in | ios::binary);

    if (!file.is_open())
    {
        cout << "Unable to open file: " << fileName << endl;
        exit(0);
    }

}

/**
 * @author Oliver Schwab
 * 
 * @par Opens a file for output and handles the possible errors,
 * exits program if fails
 * 
 * @param[in, out] file the ofstream used to open the file
 * @param[in] fileName the name of the file to open
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * ofstream file;
 * char* filename = "test.txt";
 * 
 * openFileOutput(file, filename); // file is now open and can be worked with
 * 
 * @endverbatim
 */
bool openFileOutput(ofstream& file, string fileName) 
{ // properely handling file closing

    file.open(fileName, ios::out | ios::binary);    

    if (!file.is_open())
    {
        cout << "Unable to open file: " << fileName << endl;
        return false;
    }

    return true;

}

/**
 * @author Oliver Schwab
 * 
 * @par given an open file and a image structure with header read in, 
 * read in both ascii and binary image pixel data
 * 
 * @param[in] iImage image structure to populate with pixel data
 * @param[in] file file to read data from
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * image i; // filled with header data
 * 
 * ifstream file;
 * 
 * openFileInput(file, "file.ppm");
 * 
 * readBothFileData(i, file); // i will be filled with an image pixel data
 * 
 * 
 * @endverbatim
 */
void readBothFileData(image& iImage, ifstream& file)
{ // generic function to read both P3 files and P6
    int col = 0, row = 0, rgb = 0;// rgb = 0 -> red, rgb = 1 -> gren, rgb = 2 -> blue

    int tmpChr;

    //must read in until we read in all pixel data
    while (col < iImage.cols && row < iImage.rows)
    {// check to determine read method, P3 = ascii
        if (iImage.magicNumber == "P3")
        {
            file >> tmpChr;

            if (rgb == 0)
            {
                 iImage.redgray[row][col] = pixel(tmpChr);
            }
            else if (rgb == 1)
            {
                iImage.green[row][col] = pixel(tmpChr);
            }
            else
            {
                iImage.blue[row][col] = pixel(tmpChr);
            }
        }
        
        else
        {
            if (rgb == 0)
            {
                file.read((char*)&iImage.redgray[row][col], sizeof(pixel));
            }
            else if (rgb == 1)
            {
                file.read((char*)&iImage.green[row][col], sizeof(pixel));
            }
            else
            {
                file.read((char*)&iImage.blue[row][col], sizeof(pixel));
            }
        }

        rgb++; //because we only read in one integer at a time
        // we must keep track of which pixel we are on

        if (rgb == 3)
        {
            // once we have read all trhree pixels we must increment the column
            //in to read in the next pixel

            rgb = 0;

            col++;


            if (col == iImage.cols)
            {
                // making sure we dont overstep col bounds
                col = 0;
                row++;
            }
        }
    }

    file.close();
}

/*
void readAsciiFileData(image& iImage, ifstream& file) // depreciated
{

    int col = 0, row = 0, rgb = 0, count;// rgb = 0 -> red, rgb = 1 -> gren, rgb = 2 -> blue

    string tmpChr;

    while (file >> tmpChr && col != iImage.cols && row != iImage.rows)
    {

        if (rgb == 0) iImage.redgray[row][col] = stoi(tmpChr);
        else if (rgb == 1) iImage.green[row][col] = stoi(tmpChr);
        else iImage.blue[row][col] = stoi(tmpChr);


        rgb++;

        if (rgb == 3)
        {

            //cout << iImage.redgray[row][col] << " " << iImage.green[row][col] << " " << iImage.blue[row][col] << endl;

            rgb = 0;

            col++;


            if (col == iImage.cols)
            {
                col = 0;
                row++;
            }

        }
    }

    file.close();
}


void readBinaryFileData(image& iImage, ifstream& file) // depreciated
{
    int col = 0, row = 0, rgb = 0, count;// rgb = 0 -> red, rgb = 1 -> gren, rgb = 2 -> blue

    
    while (col < iImage.cols && row < iImage.rows)
    {
        if (rgb == 0) file.read((char*)&iImage.redgray[row][col], sizeof(pixel));
        else if (rgb == 1) file.read((char*)&iImage.green[row][col], sizeof(pixel));
        else file.read((char*)&iImage.blue[row][col], sizeof(pixel));


        rgb++;

        if (rgb == 3)
        {

            //cout << iImage.redgray[row][col] << " " << iImage.green[row][col] << " " << iImage.blue[row][col] << endl;

            rgb = 0;

            col++;


            if (col == iImage.cols)
            {
                col = 0;
                row++;
            }

        }
    }

    file.close();
}
*/

/**
 * @author Oliver Schwab
 * 
 * @par Reads in header data and calls function to read in pixel data
 * 
 * @param[in] iImage image strcture to populate
 * @param[in] file file to read from, assumed opened
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * image i; 
 * 
 * ifstream file;
 * 
 * openFileInput(file, "file.ppm");
 * 
 * readFileData(i, file); // i will be filled with an image header data
 * 
 * @endverbatim
 */
void readFileData(image& iImage, ifstream& file) 
{ // function to read in all data with the bluk of this function
    // reading in the header and the reading of the image data being done in a called function

    string tmpStr;

    getline(file, iImage.magicNumber);

    iImage.magicNumber = iImage.magicNumber.substr(0, 2);

    if (iImage.magicNumber != "P3" && iImage.magicNumber != "P6") // only valid option
    {
        cout << "Invalid Image";
        file.close();
        exit(0);
    }

    while (getline(file, tmpStr) && tmpStr[0] == '#')// handles an number of comments
    {
        iImage.comment += tmpStr + "\n";
    }
    // rows and coloumns on one line

    iImage.cols = stoi(tmpStr.substr(0, tmpStr.find(" ")));
    iImage.rows = stoi(tmpStr.substr(tmpStr.find(" ") + 1, tmpStr.length() - 1));

    getline(file, tmpStr); // getting rid of the byte size as its always 255

    // allocating our image 2d arrays

    allocate2d(iImage.redgray, iImage.rows, iImage.cols);

    if (iImage.redgray == nullptr)
    {
        deleteArrays(iImage);
        file.close();
        exit(0);
    }

    allocate2d(iImage.green, iImage.rows, iImage.cols);

    if (iImage.green == nullptr)
    {
        deleteArrays(iImage);
        file.close();
        exit(0);
    }

    allocate2d(iImage.blue, iImage.rows, iImage.cols);

    if (iImage.blue == nullptr)
    {
        deleteArrays(iImage);
        file.close();
        exit(0);
    }

    // reading in the image data, binary or ascii

    readBothFileData(iImage, file);

    file.close();
}


/**
 * @author Oliver Schwab
 * 
 * @par outputs image data to p3 file (full color ascii)
 * 
 * @param[in] iImage image to write
 * @param[in] file output file to write to
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * image i; // populate image structure
 * 
 * ofstream file;
 * 
 * openOutputFile(file, "outfile.ppm");
 * 
 * outputToP3File(i, file); // function will write image in struct in file
 * 
 * @endverbatim
 */
void outputToP3File(image& iImage, ofstream& file)
{

    int row, col;

    // write header

    file << "P3" << "\n";

    file << iImage.comment;

    file << iImage.cols << " " << iImage.rows << "\n";

    file << "255" << "\n";

    // for every pixel output rgb in ascii format with 
    //space between each value and newline between each pixel
    for (row = 0; row < iImage.rows; row++)
    {
        for (col = 0; col < iImage.cols; col++)
        {

            file << int(iImage.redgray[row][col]) << " "
                << int(iImage.green[row][col]) << " "
                << int(iImage.blue[row][col]) << "\n";
        }
    }

    file.close();

}

/**
 * @author Oliver Schwab
 * 
 * @par outputs image data to p6 file (full color binary)
 * 
 * @param[in] iImage image to write
 * @param[in] file output file to write to
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * 
 * image i; // populate image structure
 * 
 * ofstream file;
 * 
 * openOutputFile(file, "outfile.ppm");
 * 
 * outputToP6File(i, file); // function will write image in struct in file
 * 
 * @endverbatim
 */
void outputToP6File(image& iImage, ofstream& file)
{
    int row, col;

    //outpur header

    file << "P6" << "\n";

    file << iImage.comment;

    file << iImage.cols << " " << iImage.rows << "\n";

    file << "255" << "\n";

    for (row = 0; row < iImage.rows; row++)
    {
        for (col = 0; col < iImage.cols; col++)
        {
            // for every pixel output rgb in binary format 
            file.write((char*)&iImage.redgray[row][col], sizeof(pixel));

            file.write((char*)&iImage.green[row][col], sizeof(pixel));

            file.write((char*)&iImage.blue[row][col], sizeof(pixel));
        }
    }

    file.close();
}

/**
 * @author Oliver Schwab
 * 
 * @par outputs image data to p2 file (grayscale ascii)
 * 
 * @param[in] iImage image to write
 * @param[in] file output file to write to
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * image i; // populate image structure
 * 
 * ofstream file;
 * 
 * openOutputFile(file, "outfile.pgm");
 * 
 * outputToP2File(i, file); // function will write image in struct in file
 * 
 * @endverbatim
 */
void outputToP2File(image& iImage, ofstream& file)
{

    int row, col;

    //output header

    file << "P2" << "\n";

    file << iImage.comment;

    file << iImage.cols << " " << iImage.rows << "\n";

    file << "255" << "\n";

    for (row = 0; row < iImage.rows; row++)
    {
        for (col = 0; col < iImage.cols; col++)
        {
            // output each gray pixel with in ascii 
            //value with newline between each pixel
            //cout << int(iImage.redgray[row][col]);

            file << int(iImage.redgray[row][col]) << "\n";
        }
    }

    file.close();
}

/**
 * @author Oliver Schwab
 * 
 * @par outputs image data to p5 file (grayscale binary)
 * 
 * @param[in, out] iImage image to write
 * @param[in, out] file output file to write to
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * image i; // populate image structure
 * 
 * ofstream file;
 * 
 * openOutputFile(file, "outfile.pgm");
 * 
 * outputToP5File(i, file); // function will write image in struct in file
 * 
 * @endverbatim
 */
void outputToP5File(image& iImage, ofstream& file)
{
    int row, col;

    //output to header

    file << "P5" << "\n";

    file << iImage.comment;

    file << iImage.cols << " " << iImage.rows << "\n";

    file << "255" << "\n";

    for (row = 0; row < iImage.rows; row++)
    {
        for (col = 0; col < iImage.cols; col++)
        {

            //output each graypixel

            file.write((char*)&iImage.redgray[row][col], sizeof(pixel));

            //file.write((char*)&iImage.green[row][col], sizeof(pixel));

            //file.write((char*)&iImage.blue[row][col], sizeof(pixel));
        }
    }

    file.close();
}


/*
void outputToFile(image& iImage, ofstream& file)
{

    int row, col;

    // outputing our header
    file << iImage.magicNumber << "\n";

    file << iImage.comment;

    file << iImage.cols << " " << iImage.rows << "\n";

    file << "255" << "\n";

    for (row = 0; row < iImage.rows; row++) // must iterate through every pixel
    {
        for (col = 0; col < iImage.cols; col++)
        {

            if (iImage.magicNumber == "P3") // standard pixel output to ascii
            {

                file << int(iImage.redgray[row][col]) << " "
                    << int(iImage.green[row][col]) << " "
                    << int(iImage.blue[row][col]);
                if ((col != iImage.cols - 1) + 
                    (row != iImage.rows - 1) != 0) file << "\n"; 
                // avoiding extra newline

            }

            else if (iImage.magicNumber == "P6")
            { // color binary

                file.write((char*)&iImage.redgray[row][col], sizeof(pixel));

                file.write((char*)&iImage.green[row][col], sizeof(pixel));

                file.write((char*)&iImage.blue[row][col], sizeof(pixel));

            }

            else if (iImage.magicNumber == "P2")
            { // grayscale ascii

                file << int(iImage.redgray[row][col]);

                if ((col != iImage.cols - 1) + 
                    (row != iImage.rows - 1) != 0) file << "\n";

            }

            else if (iImage.magicNumber == "P5")
            {//grayscale binary

                file.write((char*)&iImage.redgray[row][col], sizeof(pixel));

            }

        }
    }

    file.close();
}
*/