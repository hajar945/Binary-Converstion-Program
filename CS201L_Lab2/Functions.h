#pragma once
/*prevents the same header file from
being included more than once in your program, which helps to avoid errors and keeps your code running smoothly*/
#include <iostream>
#include <limits>
#include <cctype>  
#include <cstring>

using namespace std;

char displayMenuAndGetSelection();
int binaryToDecimal();
int binaryToBase();
int decimalToBinary();
int anyBaseToBinary();
