/** ***************************************************************************
* @file
* 
* @brief Reads in ppm image and provides operations to modify the image, allows
* for output to pgm and ppm files in both ascii and binary
******************************************************************************/

    /** ***************************************************************************
    * 
    * @mainpage thpe01 - Image manipulation
    * 
    * @section 215 Programing Techniques
    * 
    * @authors Oliver Schwab
    * 
    * @date October 17, 2022
    * 
    * @par Instructor
    *          Dr. Schrader
    * 
    * @par Course
    *          CSC 215 - Section 1 - 2pm
    * 
    * @par Location
    *          Classroom Building - Room 112
    * 
    * @section program_section Program Information
    * 
    * @details This program takes a ppm image and allows for output to ppm and pgm
    * in both ascii and binary via --binary or --ascii. This program also allows you 
    * to perform opertion on images, "--negate", "--brighten", "--sharpen", 
    * "--smooth", "--grayscale", "--contrast" with each one performings its repective
    * operation on the given image befroe writing to the output file.
    * 
    * @par Compiling Instruction:
    *       None
    * 
    * @par Usage
    * @verbatim
    * thpe01.exe [option] --outputtype basename image.ppm
    *
    * Output Type
    *       --ascii  pixel values will be written in text form
    *       --binary pixel values will be written in binary form*
    *
    * Option Code
    *       --negate
    *       --brighten #
    *       --sharpen
    *       --smooth
    *       --grayscale
    *       --contrast
    * 
    * @endverbatim
    * 
    */

#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "netpbm.h"
const bool runcatch = false;
int main(int argc, char** argv)
{ 

    int brightenVal = -1;
    string option, tmpStr;
    //int i;
    ifstream file;
    image iImage;
    //char tmpChr;

    if (runcatch)
    {
        Catch::Session session;
        int returnCode;
        returnCode = session.run(argc, argv);
        if (returnCode != 0)
            cout << "A Test case failed" << endl;
        return 0;
    }

    handleCommandLine(option, brightenVal, argc, argv);

    openFileInput(file, argv[argc - 1]);

    readFileData(iImage, file);

    performOperation(option, iImage, brightenVal);

    callOutputFunction(option, argv, iImage);

    deleteArrays(iImage);

    // your code goes here
    return 0;
}

/**
 * @author Oliver Schwab
 * 
 * @par prints the usage statment for the program
 * 
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * printUsageStatment();
 * 
 * @endverbatim
 */
void printUsageStatment()
{
    cout << "thpe01.exe [option] --outputtype basename image.ppm" << endl;
    cout << endl;
    cout << "Output Type" << endl;
    cout << "       --ascii  pixel values will be written in text form"
        << endl;
    cout << "       --binary pixel values will be written in binary form"
        << endl;
    cout << endl;
    cout << "Option Code" << endl;
    cout << "       --negate" << endl;
    cout << "       --brighten #" << endl;
    cout << "       --sharpen" << endl;
    cout << "       --smooth" << endl;
    cout << "       --grayscale" << endl;
    cout << "       --contrast" << endl;
}

/**
 * @author Oliver Schwab
 * 
 * @par Determines which option was passed in
 * 
 * @param[in, out] option the option value to assign
 * @param[in, out] brightVal if the option was brighten, 
 * this is the corresponding value to brighten by, otherwise -1
 * @param[in] argc length of the passed in arguments
 * @param[in] argv the arguments passed in
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * int main(int argc, char** argv)
 * {
 * string option;
 * int brightenVal = -1;
 * 
 * handleCommandLine(option, brightenVal, argc, argv); // option is the passed in option
 * }
 * 
 * @endverbatim
 */
void handleCommandLine(string& option, int& brightVal, int argc, char** argv)
{
    bool found = false;

    string outputType;

    string options[6] = { "--negate", "--brighten", "--sharpen", 
        "--smooth", "--grayscale", "--contrast" }; // The six possible options


    //thpe01.exe[option] --ascii honey bees.ppm
        
    if (argc > 4 && argc < 7)
    { // the posisble length of args given for it to be a viable startup
        for (string op : options)
        { //determining if an option was passed
            if (strcmp(op.c_str(), argv[1]) == 0)
            {
                found = true;
                option = op;
            }
        }

        if (!found)
        {
            cout << "Invalid Option" << endl;
            printUsageStatment();
            exit(0);
        }

        found = false; // using found to determine if brighten was the option

        outputType = argv[2];

        if (argc == 6)
        {// specifically for the brighten option
            found = true;
            brightVal = stoi(argv[2]);

            outputType = argv[3];
        }
    }

    else if (argc == 4)
    {
        option = "None";
        outputType = argv[1];
    }

    else
    {
        cout << "Invalid Startup" << endl;
        printUsageStatment();
        exit(0);
    }

    if (outputType != "--ascii" && outputType != "--binary")
    {
        cout << "Invalid Startup" << endl;
        printUsageStatment();
        exit(0);
    }

}

/**
 * @author Oliver Schwab
 * 
 * @par Calls the appropriate output function based on the passed
 *  in option and the desired output type to the passed in file
 * 
 * @param[in] option the selected option, can be empty
 * @param[in] argv the arguments passed to main
 * @param[in] iImage the image struct full of image
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * string option = "--negate";
 * //argv output type is ascii
 * image i; // image is populated with image data
 * 
 * callOutputFunction(option, argc, argv, i); will write to a P3 file
 * 
 * @endverbatim
 */
void callOutputFunction(string option, char** argv, image &iImage) // assumes data has been modified
/*

p2 is grayscale ascii
p5 is grayscale binary
p3 is color ascii
p6 is color binary

*/
{
    ofstream file;
    int index = 3; //location of the output file
    string tmpStr;

    //option is "None" is nothing is specified

    if (option.length() > 0) 
    {// function to auto adjust the index of the arguments passed 
        if (option == "--brighten")
        {
            index++;
        }

        else if (option == "None")
        {
            index--;
        }
    }    

    tmpStr = argv[index];

    if (strcmp(option.c_str(), "--grayscale") != 0 && strcmp(option.c_str(), "--contrast") != 0)
    {
        tmpStr += ".ppm";
    }

    else
    {
        tmpStr += ".pgm";
    }

    if (!openFileOutput(file, tmpStr))
    {
        deleteArrays(iImage);
        exit(0);
    }

    index--; // now location of output method

    if (strcmp(option.c_str(), "--grayscale") != 0 && strcmp(option.c_str(), "--contrast") != 0)
    { // if not contrast or grayscale

        //calling the outputToFile with the proper variables being passed and modified
        if (strcmp(argv[index], "--ascii") == 0)
        {
            iImage.magicNumber = "P3";

            outputToP3File(iImage, file);
        }

        if (strcmp(argv[index], "--binary") == 0)
        {
            iImage.magicNumber = "P6";

            outputToP6File(iImage, file);
        }

    }

    else
    {

        if (strcmp(argv[index], "--ascii") == 0)
        {
            iImage.magicNumber = "P2";

            outputToP2File(iImage, file);
        }

        else if (strcmp(argv[index], "--binary") == 0)
        {
            iImage.magicNumber = "P5";

            outputToP5File(iImage, file);
        }

    }
}


/**
 * @author Oliver Schwab
 * 
 * @par Performs the passed in operation on the read in image
 * 
 * @param[in] option the option to be performed
 * @param[in,out] iImage the structure with the image data to be modified
 * @param[in] brighten if the brighten option was specified, how much to brighten by
 * 
 * 
 * @par Example
 * @verbatim
 * 
 * string option = "--negate";
 * image i; // image is populated with image data
 * 
 * performOperation(option, i, -1); // image negated
 * 
 * option = "--brighten"
 * 
 * perform operation(option, i, 100); // image brightend by 100
 * 
 * @endverbatim
 */

void performOperation(string option, image& iImage, int brighten)
/*

determing the given option and calling the correct fucntion

*/
{
    string options[6] = { "--negate", "--brighten", "--sharpen", "--smooth", "--grayscale", "--contrast" };
    //option is "None" is nothing is specified

    if (option == "--negate")
    {
        negateOp(iImage);
    }

    else if (option == "--brighten")
    {
        brightenOp(iImage, brighten);
    }

    else if (option == "--sharpen")
    {
        sharpen(iImage);
    }

    else if (option == "--smooth")
    {
        smooth(iImage);
    }

    else if (option == "--grayscale")
    {
        grayscale(iImage);
    }

    else if (option == "--contrast")
    {
        contrast(iImage);
    }

    //boundChecking(iImage);
}

