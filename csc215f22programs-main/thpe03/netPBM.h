/** ***************************************************************************
* @file
******************************************************************************/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
#ifndef __NETPBM__H__
#define __ NETPBM__H__
/**
* 
* @brief a char representing a single section of a rgb pixel
* 
*/
typedef unsigned char pixel;
/**
* 
* @brief the strcutrue of the data storing the data of the given image
*
*/
struct image
{ // you may not add other fields to this
// structure.
    string magicNumber; /**< Determines what type of image is being read in or out. 
    Either ascii or binary in either color or grayscale.*/
    string comment; /**< the comments present in the image.*/
    int rows; /**< the number of pixel rows present in the image.*/
    int cols; /**< The number of pixel columns present in the image.*/
    pixel** redgray; /**< The dynamically allocated array of red pixels or 
    the gray pixels depending on the image type.*/ // handles red channel or grayscale
    pixel** green; /**< The dynamically allocated array of green pixels in the image*/
    pixel** blue; /**< The dynamically allocated array of blue pixels in the image*/
};
// place your function prototypes here


void printUsageStatment();

void openFileInput(ifstream& file, char* fileName);

bool openFileOutput(ofstream& file, string fileName);

//void outputToFile(image& iImage, ofstream& file);

void handleCommandLine(string& option, int& brightVal, int argc, char** argv);

//void allocateMem(image& iImage, ifstream& file);

void free2d(pixel**& arr, int rows);

void allocate2d(pixel** &arr, int rows, int cols);

//void readAsciiFileData(image& iImage, ifstream& file);

//void readBinaryFileData(image& iImage, ifstream& file);

void readBothFileData(image& iImage, ifstream& file);

void readFileData(image& iImage, ifstream& file);

void deleteArrays(image& iImage);

void outputToP3File(image& iImage, ofstream& file);

void outputToP6File(image& iImage, ofstream& file);

void callOutputFunction(string option, char** argv, image& iImage);

void outputToP2File(image& iImage, ofstream& file);

void outputToP5File(image& iImage, ofstream& file);

void performOperation(string option, image &iImage, int brighten);

void grayscale(image& iImage);

void negateOp(image& iImage);

void sharpen(image& iImage);

void smooth(image& iImage);

void contrast(image& iImage);

void brightenOp(image& iImage, int brighten);

//void boundChecking(image& iImage);
#endif