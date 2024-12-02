/*
Author: Matthew Nash
Date: 2024-12-01
Purpose: C++ program to read a string from the user and extract
the double precision floating point numbers from the string.
Handles potential errors on user input and provides feedback.
Returns without using library function std::stod
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double extractNumeric(const string& str)
{
    string number = str; // Copy the input string to a local variable
    bool negative = false; // Flag to indicate if the number is negative

    // Logic to handle the case where the input string is empty
    if ((number[0] == '-' || number[0] == '+') && (number.size() == 1 || (number[1] != '.' && (number[1] < '0' || number[1] > '9')))) {
        // Invalid: only a sign without a valid number/decimal following
        return -999999.99;
    }


    // Check if the number is negative
    if (!number.empty() && (number[0] == '-' || number[0] == '+')) {
        negative = (number[0] == '-');
        number.erase(0, 1); // Remove the sign
    }


    // Initialize result variables
    double integerPart = 0.0;
    double fractionalPart = 0.0;
    bool decimalEncountered = false;
    double divisor = 10.0;

    // Loop through each character in the string
    for (char character : number) {
        if (character == '.') {
            if (decimalEncountered) {
                // Invalid: multiple decimals
                return -999999.99;
            }
            decimalEncountered = true;
            continue;
        }

        if (character < '0' || character > '9') {
            // Invalid character in the number
            return -999999.99;
        }

        if (!decimalEncountered) {
            // Construct integer part
            integerPart = integerPart * 10 + (character - '0');
        } else {
            // Construct fractional part
            fractionalPart += (character - '0') / divisor;
            divisor *= 10.0;
        }
    }

    // Combine integer and fractional parts
    double result = integerPart + fractionalPart;
    if (negative) {
        result = -result;
    }

    return result;
}


int main() 
{
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4)
                    << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}