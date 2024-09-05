/*
NAME: Hajar Wilkes
DATE: Sept. 4, 2024
PROGRAM: CS201L-Lab2
DESCRIPTION: provides a menu to convert numbers between different formats: from binary to decimal, from binary
to other bases (2 to 16), from decimal to binary, and from any base (2 to 16) to binary
*/
#include <iostream>
#include "Functions.h"
using namespace std;

char displayMenuAndGetSelection() {
    char choice;

    // Display the menu options
    cout << "Menu Options:\n";
    cout << "a) Convert from binary to decimal.\n";
    cout << "b) Convert from binary to another base.\n";
    cout << "c) Convert from decimal to binary\n";
    cout << "d) Convert from any base to binary\n";
    cout << "e) Exit\n";

    // Loop to ensure a valid choice is made
    do {
        cout << "Please enter your choice (a-e): ";
        cin >> choice;

        // Convert choice to lowercase to handle case-insensitivity
        choice = tolower(choice);

        // Check if the choice is valid
        if (choice < 'a' || choice > 'e') {
            cout << "Invalid choice. Please select a valid option (a-e).\n";
        }

    } while (choice < 'a' || choice > 'e'); // Repeat until a valid choice is made

    // Return the valid choice
    return choice;
}

// Implement the binaryToDecimal function
int binaryToDecimal() {
    string binary;
    int decimal = 0;

    cout << "Enter a binary number (only 0s and 1s): ";
    cin >> binary;

    // Validate the binary string
    for (char c : binary) {
        if (c != '0' && c != '1') {
            cout << "Invalid input: Binary numbers can only contain 0s and 1s." << endl << endl;
            return -1;
        }
        // Calculate decimal value
        decimal = decimal * 2 + (c - '0');
    }

    // Display the original binary value and decimal value
    cout << "Binary: " << binary << endl;
    cout << "Decimal: " << decimal << endl;

    return 1;
}

int binaryToBase() {
    string binary;
    int decimal = 0;
    int base;
    string result;

    cout << "Enter a binary number (only 0s and 1s): ";
    cin >> binary;

    // Validate the binary string
    for (char c : binary) {
        if (c != '0' && c != '1') {
            cout << "Invalid input: Binary numbers can only contain 0s and 1s." << endl << endl;
            return -1;
        }
        // Calculate decimal value
        decimal = decimal * 2 + (c - '0');
    }

    // Get the target base from the user
    cout << "Enter the target base (2 to 16): ";
    cin >> base;

    // Validate the base
    if (base < 2 || base > 16) {
        cout << "Invalid base. Please enter a base between 2 and 16." << endl;
        return -1;
    }

    // Convert decimal to the desired base
    const char digits[] = "0123456789ABCDEF"; // Define characters used in bases up to 16
    result = ""; // Start with an empty result string
    int temp = decimal; // Copy the decimal number to use for conversion

    // Loop to convert decimal to the new base
    do {
        result = digits[temp % base] + result; //Gets the character for that remainder from the digits array (e.g., '0', '1', 'A', 'F').
        temp /= base;
    } while (temp > 0);

    // Display the original binary value and the converted value
    cout << "Binary: " << binary << endl;
    cout << "Value in base " << base << ": " << result << endl << endl;

    return 1;
}

int decimalToBinary() {
    int decimal, originalDecimal;
    string binary;

    cout << "Enter a decimal number: ";
    cin >> decimal;

    // Validate decimal input
    if (decimal < 0) {
        cout << "Invalid input: Decimal number must be non-negative." << endl << endl;
        return -1;
    }

    // Store original decimal value
    originalDecimal = decimal;

    // Convert decimal to binary
    if (decimal == 0) {
        binary = "0";
    }
    else {
        binary = "";
        while (decimal > 0) {
            binary = (char)(decimal % 2 + '0') + binary;
            decimal /= 2;
        }
    }

    // Display the original decimal value and binary value
    cout << "Decimal: " << originalDecimal << endl;
    cout << "Binary: " << binary << endl;

    return 1;
}
int anyBaseToBinary() {
    string number;
    int base;
    int decimal = 0;
    string binary;

    cout << "Enter a number in the base system: ";
    cin >> number;

    // Validate the base system input
    cout << "Enter the base of the number (2 to 16): ";
    cin >> base;

    if (base < 2 || base > 16) {
        cout << "Invalid base. Please enter a base between 2 and 16." << endl;
        return -1;
    }

    // Convert the number to decimal
    for (char c : number) {
        int value;
        if (c >= '0' && c <= '9') {
            value = c - '0';  // Convert character to integer
        }
        else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;  // Convert character to integer (A=10, B=11, ...)
        }
        else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;  // Convert character to integer (a=10, b=11, ...)
        }
        else {
            cout << "Invalid digit in the number for the given base." << endl << endl;
            return -1;
        }

        if (value >= base) {
            cout << "Invalid digit in the number for the given base." << endl << endl;
            return -1;
        }

        decimal = decimal * base + value;
    }

    // Convert decimal to binary
    if (decimal == 0) {
        binary = "0";
    }
    else {
        binary = "";
        while (decimal > 0) {
            binary = (char)(decimal % 2 + '0') + binary;
            decimal /= 2;
        }
    }

    // Display the number in the original base and the binary value
    cout << "Number in base " << base << ": " << number << endl;
    cout << "Binary: " << binary << endl;

    return 1;
}
int main() {
    char userChoice;
    do {
        userChoice = displayMenuAndGetSelection();

        if (userChoice == 'a') {
            if (binaryToDecimal() == -1) {
                cout << "Error converting binary to decimal." << endl << endl;
            }
        }
        else if (userChoice == 'b') {
            if (binaryToBase() == -1) {
                cout << "Error converting binary to the specified base." << endl << endl;
            }
        }
        else if (userChoice == 'c') {
            if (decimalToBinary() == -1) {
                cout << "Error converting decimal to binary." << endl << endl;
            }
        }
        else if (userChoice == 'd') {
            if (anyBaseToBinary() == -1) {
                cout << "Error converting from any base to binary." << endl << endl;
            }
        }

    } while (userChoice != 'e');

    cout << "Exiting program." << endl;
    return 0;
}