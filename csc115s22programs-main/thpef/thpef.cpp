#define _CRT_SECURE_NO_WARNINGS
#include "thpef.h"

//write functions here

/**
 * @author Oliver Schwab
 * 
 * @par Opens file located at the file path. Returns a bool representing
 * as succseful opening 
 * 
 * @param[in] inFile the file object to use to opne the file
 * @param[in] filePath the file path to open
 * 
 * @return a boolean to indiciate if the file opened
 * 
 * @par Example
 * @verbatim
 * 
 * ifstream datapath;
 * string fp = "here";
 * bool result = openInput(datapath, fp); // bool = false
 * 
 *  ofstream testFile;
 * 
 * testFile.open("given1.txt");
 *
 * testFile.close();
 *
 * ifstream df;
 * string fp = "given1.txt";
 * bool result = openInput(df, fp); // result = true
 * 
 * @endverbatim
 */
bool openInput(ifstream& inFile, string filePath)
{
    inFile.open(filePath);

    if (!inFile.is_open()) //  asserts the file opened,
                           //if it didnt print an error and return false
    {
        cout << "Unable to open the input file: " << filePath << endl;
        return false;
    }

    return true;
}

/**
 * @author Oliver Schwab
 * 
 * @par Opens file located at the file path. Returns a bool representing
 * as succseful opening 
 * 
 * @param[in] inFile the file object to use to opne the file
 * @param[in] filePath the file path to open
 * 
 * @return a boolean to indiciate if the file opened
 * 
 * @par Example
 * @verbatim
 * 
 * ifstream datapath;
 * string fp = "here";
 * bool result = openTemplate(datapath, fp); // bool = false
 * 
 *  ofstream testFile;
 * 
 * testFile.open("given1.txt");
 *
 * testFile.close();
 *
 * ifstream df;
 * string fp = "given1.txt";
 * bool result = openTemplate(df, fp); // result = true
 * 
 * @endverbatim
 */
bool openTemplate(ifstream& inFile, string filePath)
{ //funtions the same as openInput
    inFile.open(filePath);

    if (!inFile.is_open())
    {
        cout << "Unable to open the template file: " << filePath << endl;
        return false;
    }

    return true;
}

/**
 * @author Oliver Schwab
 * 
 * @par opens a file for output at the given filepath
 * retruns bool representing if the operation was succsesful
 * 
 * @param[in] inFile the file object to use to opne the file
 * @param[in] filePath the file path to open
 * 
 * @return a boolean to indiciate if the file opened
 * 
 * @par Example
 * @verbatim
 * 
 * ofstream f;
 * string fp = "oliver";
 * bool result = openOutput(f, fp); // bool  = true
 * 
 * ofstream df;
 * string fp = "P:\\oliver.txt";
 * bool result = openOutput(df, fp); // bool  = false
 * 
 * @endverbatim
 */
bool openOutput(ofstream& outFile, string filePath)
{   //functions the same as openInput
    outFile.open(filePath);

    if (!outFile.is_open())
    {
        cout << "Unable to open the output file: " << filePath << endl;
        return false;
    }

    return true;
}


/**
 * @author Oliver Schwab
 * 
 * @par Description Gets the current date in the format "day month, year"
 * 
 * 
 * @return string the current date in the format "day month, year"
 * 
 * @par Example
 * @verbatim
 * 
 * srting date = getDate();
 * 
 * @endverbatim
 */
string getDate()
{
    time_t myTimeT = time(nullptr);
    string currentTime = ctime( &myTimeT );
    //here we are splicing the ctime string into what we desire, locations are predefined
    string date = currentTime.substr(8,2) + " ";
    date += currentTime.substr(4, 3) + ", ";
    date += currentTime.substr(20, 4);

    return date;
}

/**
 * @author Oliver Schwab
 * 
 * @par Reads a line form the given file and converts the infromation 
 * into a transaction to populate the toFill struct
 * 
 * @param[in] inFile the file you want to read from
 * @param[in] toFill the struct to populate
 * 
 * @return bool indicating if the operation was a sucsses
 * 
 * @par Example
 * @verbatim
 * 
 * 
 * ifstream inFile;
 * ofstream tempFile;
 * 
 * tempFile.open("test1.txt");
 * 
 * tempFile << "James,Smith,123 Main St,Rapid City,SD,57701,89.55,12.5";
 * 
 * tempFile.close();
 * 
 * inFile.open("test1.txt");
 * 
 * transaction test;
 * 
 * getClient(inFile, test) // result is true and all the information from 
 *                         //the transaction is in the test struct
 * 
 *  ifstream inFile;
 * ofstream tempFile;
 * 
 * tempFile.open("test1.txt");
 * 
 * tempFile << "";
 * 
 * tempFile.close();
 * 
 * inFile.open("test1.txt");
 * 
 * transaction test;
 * 
 * getClient(inFile, test) // returns false as there was nothing to read
 * 
 * @endverbatim
 */
bool getClient(ifstream& inFile, transaction &toFill)
{
    string tempStr, readFromTemp;
    int i = 0;

    getline(inFile, tempStr); // read a line from the transaction

    if (tempStr == "") return false; // asserts the line contains a transaction

    for (i = 0; i < 8; i++) // iterate through the predetermined 
                            //number of commas
    {
        // reading the first piece of data
        readFromTemp = tempStr.substr(0, tempStr.find(',')); 
        //triming the line so we can repeatable perform the same operation
        tempStr = tempStr.substr(tempStr.find(',') + 1, string::npos);
        // each index is a predetermined piece of data, 
        // so if we are looking at that index we 
        // need to assign that value to the struct
        if (i == 0) toFill.firstName = readFromTemp;
        if (i == 1) toFill.lastName = readFromTemp;
        if (i == 2) toFill.streetAddress = readFromTemp;
        if (i == 3) toFill.city = readFromTemp;
        if (i == 4) toFill.state = readFromTemp;
        if (i == 5) toFill.zipCode = readFromTemp;
        if (i == 6) toFill.transAmount = stod(readFromTemp);
        if (i == 7) toFill.curBal = stod(readFromTemp);
    }

    return true; // operation was succsesful
}

/**
 * @author Oliver Schwab
 * 
 * @par Description given a populated struct represetning a transaction, 
 * the type of transaction, and the date. it will create a new file under 
 * the clients name with all the transaction details
 * 
 * @param[in] customer struct representing the transaction
 * @param[in] fp what template to use when creating the file 
 * @param[in] date the current date
 * 
 * 
 * @par Example
 * @verbatim
 * 
 *  ifstream clients;
 * transaction customer;
 * ofstream tempFile;
 * 
 * tempFile.open("test1.txt");
 * 
 * tempFile << "James,Smith,123 Main St,Rapid City,SD,57701,89.55,12.5";
 * 
 * tempFile.close();
 * 
 * openInput(clients, "test1.txt");
 * 
 * getClient(clients, customer);
 * 
 * writeLetter(customer, "purchaseTemplate.txt", getDate()); // the file James.Smith.txt 
 *                                                           //contains the transaction details
 * 
 * @endverbatim
 */
void writeLetter(transaction customer, string fp, string date)
{
    ifstream templateFile;
    ofstream clientFile;
    string outputFileFP = customer.firstName + "." + customer.lastName + ".txt";
    string tempLine;
    int i, p = 0, numOfLines = 0;

    // setting up what is essentially a linked list
    string toTest[10] = {"#FULLNAME", "#ADDRESS", "#CITY", "#STATE",
    "#ZIP", "#FIRST", "#LAST", "#DATE", "#TRANSACTION", "#BALANCE"};
    // other half of linked list. 
    // cant inclued last two as they are different data types
    string values[8] = {customer.firstName + " " + customer.lastName,
    customer.streetAddress, customer.city,
    customer.state, customer.zipCode, customer.firstName,
    customer.lastName, date};
    // making sure all the files opened correctly
    if (openTemplate(templateFile, fp) == false ||
    openOutput(clientFile, outputFileFP) == false) return;
    // number of lines in the template file. In order to prevent duplicate newlines
    while (getline(templateFile, tempLine)) numOfLines++;
    // reopen file to start at the first line
    templateFile.close();
    templateFile.clear();

    openTemplate(templateFile, fp);
    // iterate through the template file copying each line and 
    // replacing matching strings untill end of line
    while (!templateFile.eof())
    {
        getline(templateFile, tempLine); // current line
        for (i = 0; i < 10; i++) // there are 10 possible matches we need to check
        {
            if (tempLine.find(toTest[i]) != string::npos) // if we found a match
            {
                // incase we are working with doubles
                ostringstream myStream;
                myStream << fixed << setprecision(2);
                // first 8 matches can interact with the linked list
                if (i < 8)
                {
                    //replace the matched str with its eqivelent value
                    tempLine.replace(tempLine.find(toTest[i]), toTest[i].size(), values[i]);
                }
                // if the match was transaction amount
                else if (i == 8)
                {
                    // if transaction is negitive we need to make it positive
                    if (fp.find("payment") != string::npos && customer.transAmount < 0)
                    {
                        customer.transAmount *= -1;
                    }
                    // format double to str
                    myStream << customer.transAmount;
                    //replace the matched str with its eqivelent value
                    tempLine.replace(tempLine.find(toTest[i]), toTest[i].size(), myStream.str());
                }
                // same proccess as transaction amount but with current balance
                else 
                {
                    if (fp.find("overdue") != string::npos && customer.curBal < 0)
                    {
                        customer.curBal *= -1;
                    }
                    myStream << customer.curBal;
                    tempLine.replace(tempLine.find(toTest[i]), toTest[i].size(), myStream.str());  
                }
            }
        }
        //write the file we checked and replace to the clients file
        clientFile << tempLine;
        // if we arnt on the last line add a newline
        if (p != numOfLines) clientFile << "\n"; 
        p++;
    }
    //cleanup
    templateFile.close();
    clientFile.close();
}