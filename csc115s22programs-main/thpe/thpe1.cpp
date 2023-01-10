/** ************************************************************
 * @file
***************************************************************/

#include "thpe1.h"
/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * Looks at the intial digits of a given credit card number and returns
 * the card brand. 
 * If no valid card brand is found it returns Unknown
 * 
 * @param[in] cardNumber The card number to be checked
 * 
 * @return string Returns the brand of card given [Visa, American Express, Mastercard, Discover, Unknown]
 * 
 * @par Example
 * @verbatim
  string cardNumber;
  string result;
  cardNumber = "4794630503276178";
  result = getCCType(cardNumber); // result would be Visa
  
  cardNumber = "7425473237792;
  result = getCCType(cardNumber); // result would be Unknown
  
  cardNumber = "53828876876874";
  result = getCCType(cardNumber); // result will be mastercard
 
   @endverbatim
 */
string getCCType(string cardNumber) 
    {
    // a lookup array of ints for discover cards
    int validNums [6] = {65, 644, 649, 6011, 622126, 622926}; 

    // a loopup array to find the length of the given digit
    string validNumsStr [6]= {"65", "644", "649", "6011", "622126", "622926"}; 

    // visa you ony need to check if the first digit is four 
    // and if its length is either 13 or 16
    if (cardNumber.at(0) == '4' && 
    (cardNumber.size() == 13 || 
    cardNumber.size() == 16)) 
    { // Visa 
        return "Visa";
    }
    // check if the intial 2 digits of the card 
    // are either 34 or 37, if it return American Express
    else if ((intOfNum(cardNumber, 2) == 34 || 
    intOfNum(cardNumber, 2) == 37) && cardNumber.size() == 15) 
    { // card size must be 15 digits long
        return "American Express";
    }

    // checks if the first two digits of card are within 50 to 55 inclusive
    // and if the length is 16
    else if ((50 <= intOfNum(cardNumber, 2) && intOfNum(cardNumber, 2) <= 55) 
    && cardNumber.size() == 16) 
    { 
        return "Mastercard";
    }


    else 
    { 
        for (int i = 0; i < 6; i++) 
        {
            // for every item in the lookup array check if the intial digits of the
            // card number are within the array. Length must be 16
            if (intOfNum(cardNumber, validNumsStr[i].size()) == validNums[i] 
            && cardNumber.size() == 16) 
            {
                return "Discover";
            }
        }

        return "Unknown";
    }
}
/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * Given a card number and the desired number of digits from the front will 
 * return the int value of the digits
 * 
 * @param[in] cardNumber The string of the card number to be converted
 * @param[in] digits The integer of the number of digits to evalute into ints
 * 
 * @return int The value of the given digits, if the digits given is 
 * larger then the string then return the entire string as a int
 * 
 * @par Example
 * @verbatim
  string cardNumber;
  int result;
  ind digits;8
  
  cardNumber = "53828876876874";
  digits = 4;
  result = intOfNum(cardNumber, digits); // result would be 5382
  
  cardNumber = "6440747636070782";
  digits = 7;
  result = intOfNum(cardNumber, digits); // result would be 6440747
  
  cardNumber = "4794630503276178";
  digits = 3;
  result = intOfNum(cardNumber, digits); // result would be 479
  
  @endverbatim
 */
int intOfNum(string cardNumber, int digits) 
{
    // ensures the given length is not larger then the length of the array 
    int digitsToCount = (digits > (int) cardNumber.size()) 
    ? cardNumber.size() : digits;
    // get a substring of the cardNumber
    string digitsToConvert = cardNumber.substr(0, digits);
    int intialDigits = 0;
    // for each digit desired
    for (int i = 0; i < digitsToCount; i++) 
    {
        // add the number to the total when what is added is the 
        // digit to the nth power where n is the digits position
        intialDigits += (int) round((digitsToConvert[i] - '0') 
        * pow(10, digits - i - 1));
    }
    return intialDigits;
}


/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * Returns the interger value of the given char value (expects integers), 
 * and if toDouble is pass through then double the 
 * int before returning the value
 * If the value is greater then 9 the add 
 * the digits in the number together for the result
 * 
 * @param[in] digit the char of the digit to check
 * @param[in] toDouble  boolean to determine if we are to double the digit
 * 
 * @return int the resulting integer value given the digit and if it was doubled
 * 
 * @par Example
 * @verbatim
 
 char digit;
 bool toDouble;
 int result;
 
 digit = '5';
 toDouble = true;
 result = whatToAdd(digit, toDouble); // Result would be 1
 
 digit = '2';
 toDouble = true;
 result = whatToAdd(digit, toDouble); // result would be 4
 
 digit = '9';
 toDouble = false;
 result = whatToAdd(digit, toDouble); // result would be 9
 
 
 @endverbatim
 */
int whatToAdd(char digit, bool toDouble) 
{
    // what int value we are working with
    int value = digit - '0';

    // dont need to modify the int if it dosnt need to be doubled
    if (toDouble == false) 
    {
        return value;
    }

    else {
        // if needs to be doubled we double it and check if its larger then 9
        if (value * 2 < 10) 
        {
            // if not we can return doubled value with no issue
            return value * 2;
        } else 
        {
            // otherwise we need to add the two digits and return them
            // because the intial digit is always one we only 
            // need to calculate the second digit
            return 1 + (value * 2 - 10);
        }
    }
}
/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * Performs Luhns Algorithim on the given credit card.
 * Goes through each digit and depending upon the length doubles 
 * every other digit and adds them together.
 * result must be even divisable by 10 in order to return true
 * 
 * @param[in] cardNumber The string of the card number to check
 * 
 * @return A boolean result of if the card passes luhns algorithim
 * 
 * @par Example
 * @verbatim
 * 
 * string cardNumber;
 * bool result;
 * 
 * cardNumber = "4794630503276178";
 * result = luhnsAlgo(cardNumber); // result should be true
 * 
 * cardNumber = "7425473237792";
 * result = luhnsAlgo(cardNumber); // result should be true
 * 
 * cardNumber = "741615u722142577";
 * result = luhnsAlgo(cardNumber); // result should be false
 * 
 * @endverbatim
 */
bool luhnsAlgo(string cardNumber)
{
    // size because otherwise a conversion error gets thrown on line 224
    int size = cardNumber.size();
    // total of luhns algo when performing algorithum
    int total = 0;
    // if the digit needs to be doubled
    bool doubled;
    // determines if the card length is even or odd, 
    // odd lenths are handled where every odd index is double. 
    // even cards even even digit is doubled
    int evenOdd = size % 2;
    // we must iterate through every digit in the card
    for (int i = 0; i < size; i++) 
    {
        // if the card does not have an int value within it 
        // it is not a valid card number
        if (cardNumber[i] > '9' || cardNumber[i] < '0') 
        {
            return false;
        }
        // doubling depening on the card length and the index value
        doubled = ((i - evenOdd) % 2 == 0) ? true : false;
        // adding the appropriate value, this function deals 
        // with doubling the int and adding its digits
        total += whatToAdd(cardNumber[i], doubled);
    }

    return (total % 10) == 0;
}
/**
 * @author Oliver Schwab
 * 
 * @par Description 
 * uses luhns algorithim and the lenth of the card to determine if 
 * the given card number is valid
 * 
 * @param[in] cardNumber The string of the card number to be checked
 * 
 * @return bool based on if the card is valid or not, true if valid.
 * 
 * @par Example
 * @verbatim
 * 
 * string cardNumber;
 * bool result;
 * 
 * cardNumber = "6440747636070782";
 * result = isValidCC(cardNumber); // result would be true
 * 
 * cardNumber = "53828876876874";
 * result = isValidCC(cardNumber); // result would be false
 * 
 * cardNumber = "6585288877768476";
 * result = isValidCC(cardNumber); // result would be false
 * 
 * @endverbatim
 */
bool isValidCC(string cardNumber)
{
    // checks the card length is appropriate and luhns algorithum applies
    if (cardNumber.size() == 13 ||
        cardNumber.size() == 15 ||
        cardNumber.size() == 16){
            return luhnsAlgo(cardNumber);
    }

    return false;
}