// File: main.cpp
// Author: Philip Lee
// Description: This is the main driver code for a simple calculator program.
// The program can perform addition, subtraction, multiplication, and division
// on two numbers entered by the user.

#include <iostream>
#include "SimpleCalculator.h"
#include "Operation.h"
#include <sstream>

// Function to check if the given string contains a decimal point
bool containsDecimal(const std::string& givenString)
{
	return givenString.find('.') != std::string::npos;
}

// Function to get a number from the user
double getNumberFromUser(const std::string& prompt) {
	std::string input;
	std::cout << prompt;
	std::cin >> input;
	return containsDecimal(input) ? std::stod(input) : std::stoi(input);
}

// Function to determine the operation based on the user's input
Operation determineOperation(const std::string& op)
{
	if (op == "add") return Operation::Add;
	if (op == "sub") return Operation::Subtract;
	if (op == "mul") return Operation::Multiply;
	if (op == "div") return Operation::Divide;
	return Operation::Invalid;
}

int main()
{
	Calculator calc;

	// Introduction and instructions
	std::cout << "Welcome to my calculator program. This program is a basic calculator app "
		"that can add, subtract, multiply, or divide two numbers.\n";

	std::string input1, input2, operation; // Variables to store user input

	// Neat type promotion trick to allow template functions to work properly!
	double num1 = getNumberFromUser("Please enter the first number: ");
	double num2 = getNumberFromUser("Please enter the second number: ");

	std::cout << "Enter an operation (add, sub, mul, div): ";
	std::cin >> operation;

	// Determine the operation
	Operation op = determineOperation(operation);

	if (op == Operation::Invalid)
	{
		std::cout << "You entered an invalid operation..";
		return 0;
	}

	// Perform the calculation based on the operation
	switch (op)
	{
	case Operation::Add:
		std::cout << "Result: " << calc.add(num1, num2) << std::endl;
		break;
	case Operation::Subtract:
		std::cout << "Result: " << calc.subtract(num1, num2) << std::endl;
		break;
	case Operation::Multiply:
		std::cout << "Result: " << calc.multiply(num1, num2) << std::endl;
		break;
	case Operation::Divide:
		std::cout << "Result: " << calc.divide(num1, num2) << std::endl;
		break;
	case Operation::Invalid:
		std::cout << "Invalid operation entered." << std::endl;
		break;
	}

	return 0;
}