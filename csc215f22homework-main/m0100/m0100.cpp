#include <string>
#include <iostream>
#include <fstream>

using namespace std;

enum trait {POTENCY, ESSENCE, ASPECT};

struct rune
{
    string name = "None";
    trait t;
};

void rec(rune runes[], string previousRunes, int level = 0);

int main(int argc, char ** argv)
{
    ifstream file;

    rune runes[300];

    string tmpStr;

    trait type;

    int index = 0;

    if (argc != 2)
    {
        cout << "m0100.exe csvdatafile" << endl;
        return 0;
    }

    file.open(argv[1]);

    if (!file.is_open())
    {
        cout << "Unable to open: " << argv[1] << endl;
    }

    getline(file, tmpStr);

    while (getline(file, tmpStr))
    {
        runes[index].name = tmpStr.substr(0, tmpStr.find(","));

        type = POTENCY;
        
        tmpStr = tmpStr.substr(tmpStr.find(",") + 1, tmpStr.length());

        if (tmpStr == "Essence")
        {
            type = ESSENCE;
        }
        else if (tmpStr == "Aspect")
        {
            type = ASPECT;
        }
        
        runes[index].t = type;

        index++;
    }

    rec(runes, "");
}


void rec(rune runes[], string previousRunes, int level)
{
    int index;

    for(index = 0; runes[index].name != "None"; index++)
    {
        if (runes[index].t == level)
        {

            if (level != 2)
            {
                rec(runes, previousRunes + runes[index].name + " ", level + 1);
            }

            else
            {
                cout << previousRunes << runes[index].name << endl;
            }
        }
    }
}

