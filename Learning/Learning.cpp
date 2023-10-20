/**
 * @file    Learning.cpp
 * @author  Philip Lee
 * @date    October 20, 2023
 * @version 1.0
 *
 * @brief   File containing various tips/tricks for C++.
 *
 * This file serves as a repository of useful tips and tricks in C++ programming.
 * Each function or code snippet is accompanied by comments explaining its utility and advantages.
 */

#include <iostream>
#include <algorithm>

// --------------------------
// Tip 1: Simplifying Function Calls with Nested Operations
// --------------------------

// Traditional Approach: Using Nested Function Calls
// This example shows how to find the minimum of multiple numbers
// using nested std::min() calls. While effective, this can quickly 
// become hard to read and maintain.
void naiveMinNum()
{
	int a = 5, b = 2, c = 8, d = 1, e = 3;
	int x1 = std::min(a, std::min(b, std::min(c, std::min(d, e))));
	// x1 will hold the minimum value among a, b, c, d, e
}

// --------------------------
// Tip 2: Using Initializer Lists for Simplicity and Readability
// --------------------------

// Improved Approach: Using C++11 Initializer Lists
// This example demonstrates a more readable way to find the minimum
// of multiple numbers using std::min with an initializer list.
// The function is not only easier to read but also type-safe.
void cleverMinNum()
{
	int a = 5, b = 2, c = 8, d = 1, e = 3;
	int x1 = std::min({ a, b, c, d, e });
	// x1 will hold the minimum value among a, b, c, d, e
}


