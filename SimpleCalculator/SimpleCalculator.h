// File: SimpleCalculator.h
// Author: Philip Lee
// Description: This header file defines a Calculator class that provides
// basic arithmetic operations (addition, subtraction, multiplication,
// and division). The class uses template functions to support different
// data types for calculations.

#pragma once

#include <iostream>

class Calculator
{
public:
    // Default constructor
    Calculator() {}

    // Function to add two numbers
    // @param a: First operand
    // @param b: Second operand
    // @return: Sum of a and b
    template <typename T>
    T add(T a, T b) {
        return a + b;
    }

    // Function to subtract two numbers
    // @param a: First operand
    // @param b: Second operand
    // @return: Difference of a and b
    template <typename T>
    T subtract(T a, T b) {
        return a - b;
    }

    // Function to multiply two numbers
    // @param a: First operand
    // @param b: Second operand
    // @return: Product of a and b
    template <typename T>
    T multiply(T a, T b) {
        return a * b;
    }

    // Function to divide two numbers
    // @param a: Dividend
    // @param b: Divisor
    // @return: Quotient of a and b
    // Note: Returns 0 if the divisor is zero
    template <typename T>
    T divide(T a, T b) {
        if (b == 0) {
            std::cout << "Cannot divide by 0";
            return 0;
        }
        return a / b;
    }
};