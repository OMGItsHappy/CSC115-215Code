#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

enum trimType { BOTH, FRONT, END };

void cTrim(char str[], trimType method);

void sTrim(string &str, trimType method);

// add your prototype for your cTrim function here.
// add your prototype for your sTrim function here.