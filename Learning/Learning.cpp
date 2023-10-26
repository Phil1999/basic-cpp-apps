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
 * Special thanks to Dave's Garage! :)
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

// --------------------------
// Tip 3: Finding the Size of an Array
// --------------------------

// Macro Approach: Using a Macro to Get Array Size
// This example demonstrates how to find the size of an array using
// a macro. The macro divides the total size of the array in bytes
// by the size of a single element to get the number of elements.
#define ARRAYSIZEM(b) (sizeof(b) / sizeof(b[0]))

void getArrSize()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	std::cout << ARRAYSIZEM(a) << std::endl;
}

// Template Approach: Using a Template Function to Get Array Size
// This example uses a template function to find the size of an array.
// The template argument deduction mechanism of C++ automatically deduces
// the type and size of the array, making this approach type-safe and
// more idiomatic in modern C++.
template<typename T, size_t N>
size_t ARRAYSIZET(T(&a)[N]) // Note: T(&a)[N] is a reference to an array of N elements of type T
							// This is important because we stop the array from decaying into a
							// pointer when passed into a function.
{
	return N;
}


// Tip 4: Replacing Unsafe String Functions with Safe Alternatives
// ----------------------------------------------------------

// Improved Approach: Using Safe String Functions
// This cheat sheet provides a list of traditional string manipulation
// functions alongside their modern, safer alternatives. The new functions
// offer better bounds and buffer checking, which can help to minimize the
// risks of buffer overflow vulnerabilities.

// Old vs New Function Mapping
// The following list maps older, less secure functions to their safer
// counterparts that should be used to enhance the security and robustness
// of your code.

// Old			New
// -----------------------
// strlen		->	strnlen_s
// strcpy		->	strcpy_s
// strcat		->	strcat_s
// sprintf		->	_snprintf_s
// vsprintf		->	vsnprintf_s
// makepath		->	_makepath_s
// _splitpath	->	_splitpath_s
// scanf/sscanf ->	sscanf_s
// snscanf		->	_snscanf_s
// gets			->	gets_s

#include <string.h>  // The newer, safer string functions are available in <string.h>

// Tip 5: Forward Declarations for Utility Functions
// ----------------------------------------------------------
// The following are forward declarations.
// These declarations allow us to inform the compiler about the existence of these
// functions before they are actually implemented.
// 
// Forward declarations serve multiple purposes:
// 1. Compilation Speed: 
//    They allow for faster compilation by eliminating the need to include the header
//    file where the function is defined. This reduces the amount of code the compiler 
//    has to process.
// 2. Circular Dependencies:
//    Forward declarations can resolve issues related to circular dependencies between
//    classes or functions, as they allow you to declare the existence of a function
//    or class before it is actually defined.
// 3. Code Organization:
//    They provide a way to list all the functions being used in the file at the top,
//    making it easier to understand the file's dependencies without digging through
//    the entire codebase.
// 4. Type Safety:
//    Forward declarations help in enforcing type safety. Since the compiler knows 
//    the function signature beforehand, it can catch any type mismatches earlier.
//		
//	  However, we should be purposeful in our usage of forward declarations. It should not
//	  be a default practice.
//

int sum(int a, int b);  // Calculates the sum of two integers
void TurnOffAsserts();  // Function to disable asserts in the code



