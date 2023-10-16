// Filename: main.cpp
// Purpose: This program converts between different units (inches, cm, kg, lbs).
// Author: Philip Lee
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "ConversionType.h" // Custom header for the ConversionType enum class

using namespace std;

// Prints a message to the console.
// Parameters:
// - msg: The message to print
// - withNewLine: Whether to print a new line after the message (default true)
void printMessage(const string& msg, bool withNewLine = true) {
    withNewLine ? cout << msg << endl : cout << msg;
}

// Formats a double to a string with a specific number of decimal places,
// removing trailing zeros.
// Parameters:
// - val: The double value to format
// - precision: The number of decimal places to show
string formatDouble(double val, int precision) {
    ostringstream out;
    out << fixed << setprecision(precision) << val;
    string str = out.str();
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    if (str.back() == '.') {
        str.pop_back();
    }
    return str;
}

// Determines the type of unit conversion based on the input units.
// Parameters:
// - unit1: The unit to convert from
// - unit2: The unit to convert to
// Returns:
// - A ConversionType value corresponding to the desired conversion
ConversionType determineConversionType(const string& unit1, const string& unit2) {
    if (unit1 == "inches" && unit2 == "cm") {
        return ConversionType::InchesToCm;
    }
    else if (unit1 == "cm" && unit2 == "inches") {
        return ConversionType::CmToInches;
    }
    else if (unit1 == "kg" && unit2 == "lbs") {
        return ConversionType::KgToLbs;
    }
    else if (unit1 == "lbs" && unit2 == "kg") {
        return ConversionType::LbsToKg;
    }
    else {
        return ConversionType::Invalid;
    }
}

// Converts a value between different units.
// Parameters:
// - val: The value to convert
// - type: The type of conversion to perform
// Returns:
// - The converted value
double convert(double val, ConversionType type) {
    switch (type) {
    case ConversionType::InchesToCm:
        return val * 2.54;
    case ConversionType::CmToInches:
        return val / 2.54;
    case ConversionType::KgToLbs:
        return val * 2.20462;
    case ConversionType::LbsToKg:
        return val / 2.20462;
    default:
        return 0.0;
    }
}

// Gets a double value from the user.
// Parameters:
// - userNumVal: Reference to store the input value
// Returns:
// - true if successful, false if an invalid input was given
bool getUserInput(double& userNumVal) {
    string userNum;
    try {
        cin >> userNum;
        userNumVal = stod(userNum);
        return true;
    }
    catch (const invalid_argument& e) {
        printMessage("Conversion failed: invalid argument");
        return false;
    }
    catch (const out_of_range& e) {
        printMessage("Conversion failed: out of range");
        return false;
    }
}

// Main function: Entry point for the unit conversion program
int main() {
    // Introductory message displayed to the user
    string introMessage = "Welcome to my unit converter program! Made by Philip Lee\n"
        "You can convert inches - cm, cm - inches, kg - lbs, and lbs - kg\n";

    // Prompts for user input
    string promptNumber = "Enter an amount: ";
    string promptUnits1 = "Enter first unit: ";
    string promptUnits2 = "Enter second unit: ";

    // Variables to hold user input and conversion result
    string unit1, unit2;
    double userNumVal, result;

    // Display intro message
    printMessage(introMessage);

    // Get units from user
    printMessage(promptUnits1, false);
    cin >> unit1;
    printMessage(promptUnits2, false);
    cin >> unit2;

    // Determine the type of conversion based on user input
    ConversionType currentConversion = determineConversionType(unit1, unit2);

    // Check for invalid unit input
    if (currentConversion == ConversionType::Invalid) {
        printMessage("Invalid units entered. Exiting.");
        return 1; // Exit with an error code
    }

    // Display the selected conversion type
    string unitMessage = "You have chosen to convert " + unit1 + " to " + unit2;
    printMessage(unitMessage);

    // Get the numeric value to convert from the user
    printMessage(promptNumber, false);
    if (!getUserInput(userNumVal)) {
        return 1; // Exit with an error code if input is invalid
    }

    // Perform the conversion
    result = convert(userNumVal, currentConversion);

    // Display the conversion result
    string resultMessage = formatDouble(userNumVal, 2) + " " + unit1 + " is equivalent to " +
        formatDouble(result, 2) + " " + unit2;
    printMessage(resultMessage);

    return 0; // Exit successfully
}
