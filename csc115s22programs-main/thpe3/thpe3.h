/** ***************************************************************************
* @file
******************************************************************************/ 

#pragma once
#include <cmath>
#include <cctype>
#include <string>
#include <random>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;
/**
 * @brief The number for a hand classified as a royal flush
 */
const int ROYALFLUSH = 9;
/**
 * @brief The number for a hand classified as a straight flush
 */
const int STRAIGHTFLUSH = 8;
/**
 * @brief The number for a hand classified as a Four of a kind
 */
const int FOUROFAKIND = 7;
/**
 * @brief The number for a hand classified as a Full House
 */
const int FULLHOUSE = 6;
/**
 * @brief The number for a hand classified as a Flush
 */
const int FLUSH = 5;
/**
 * @brief The number for a hand classified as a Straight
 */
const int STRAIGHT = 4;
/**
 * @brief The number for a hand classified as a Three of a kind
 */
const int THREEOFAKIND = 3;
/**
 * @brief The number for a hand classified as a Two Pair
 */
const int TWOPAIR = 2;
/**
 * @brief The number for a hand classified as a Two of a Kind
 */
const int TWOOFAKIND = 1;
/**
 * @brief The number for a hand classified as a High Card
 */
const int HIGHCARD = 0;

//Write prototypes here

bool findRoyalFlush(int hand[]);

bool findStraightFlush(int hand[]);

void sort(int array[], int size);

bool findFourOfAKind(int hand[]);

bool findThreeOfAKind(int hand[]);

bool findTwoOfAKind(int hand[]);

bool findFullHouse(int hand[]);

bool findFlush(int hand[]);

bool findStraight(int hand[]);

bool findTwoPair(int hand[]);

int classifyHand(int hand[], int size);

void createHand(int hand[]);

bool search(int array[], int size, int toFind);

void writeOutput(ofstream& outFile, int handsDelt[]);

void printOutput(int handsdelt[]);