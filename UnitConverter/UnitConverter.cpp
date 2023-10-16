#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "ConversionType.h"

using namespace std;

void printMessage(const string& msg, bool withNewLine = true) {
    withNewLine ? cout << msg << endl : cout << msg;
}

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

int main() {
    string introMessage = "Welcome to my unit converter program! Made by Philip Lee\n"
        "You can convert inches - cm, cm - inches, kg - lbs, and lbs - kg\n";
    string promptNumber = "Enter an amount: ";
    string promptUnits1 = "Enter first unit: ";
    string promptUnits2 = "Enter second unit: ";

    string unit1, unit2;
    double userNumVal, result;

    printMessage(introMessage);
    printMessage(promptUnits1, false);
    cin >> unit1;
    printMessage(promptUnits2, false);
    cin >> unit2;

    ConversionType currentConversion = determineConversionType(unit1, unit2);

    if (currentConversion == ConversionType::Invalid) {
        printMessage("Invalid units entered. Exiting.");
        return 1;
    }

    string unitMessage = "You have chosen to convert " + unit1 + " to " + unit2;
    printMessage(unitMessage);

    printMessage(promptNumber, false);

    if (!getUserInput(userNumVal)) {
        return 1;  // Exit if input is invalid
    }

    result = convert(userNumVal, currentConversion);

    string resultMessage = formatDouble(userNumVal, 2) + " " + unit1 + " is equivalent to: " +
        formatDouble(result, 2) + " " + unit2;

    printMessage(resultMessage);

    return 0;
}