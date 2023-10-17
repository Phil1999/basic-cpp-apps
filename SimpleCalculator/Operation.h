// File: Operation.h
// Author: Philip Lee
// Description: This header file defines an enum class, Operation, to represent
// different types of arithmetic operations. The enum class ensures type safety
// and better encapsulation compared to a regular enum.

#pragma once

// Enum class to represent the types of operations supported by the calculator
enum class Operation
{
    Add,        // Addition operation
    Subtract,   // Subtraction operation
    Multiply,   // Multiplication operation
    Divide,     // Division operation
    Invalid     // Invalid operation or error state
};