/**
 * @file    NumberGuesser.cpp
 * @author  Philip Lee
 * @date    October 18, 2023
 * @version 1.0
 *
 * @brief   A simple higher-lower game in C++.
 *
 * This program prompts the user to guess a randomly generated number
 * between a specified lower and upper bound. It provides feedback to
 * guide the user to the correct answer and counts the number of guesses
 * it takes for the user to find the correct number.
 */


#include <iostream>
#include <sstream>
#include <random>


 // Define constants for the lower and upper bounds for the random number
constexpr int lower_bound = 1;
constexpr int upper_bound = 10;

// Function to print prompts to the console
void printPrompt(std::string prompt, bool nl = true)
{
	if (nl)
	{
		std::cout << prompt << std::endl;
	}
	else
	{
		std::cout << prompt;
	}
}

// Function to generate a random number using the Mersenne Twister algorithm
int generateRandNum(std::mt19937& gen)
{
	int result;
	std::uniform_int_distribution<> distr(lower_bound, upper_bound);
	result = distr(gen);
	return result;
}

// Function to get a number from the user and validate it
double getNumFromUser(const std::string& prompt)
{
	std::string input;
	printPrompt(prompt, false);
	std::cin >> input;

	try
	{
		double val = std::stod(input);
		return val;
	}
	catch (const std::invalid_argument& ia)
	{
		std::cerr << "Invalid argument: " << ia.what() << std::endl;
	}
	catch (const std::out_of_range& oor)
	{
		std::cerr << "Out of range: " << oor.what() << std::endl;
	}

	return -1;
}

// Main game logic
void startGame(std::mt19937& gen)
{
	int numGuesses = 0;
	double targetNum = generateRandNum(gen);
	bool numFound = false;

	std::string guessNumberPrompt = "Guess a number: ";
	double userGuess;

	while (!numFound)
	{
		userGuess = getNumFromUser(guessNumberPrompt);

		if (userGuess == -1)
		{
			printPrompt("Something went wrong, please try guessing again");
			continue; // Go back to the beginning of the loop
		}

		numGuesses++;

		if (userGuess > targetNum)
		{
			printPrompt("Try a lower number!");
		}
		else if (userGuess < targetNum)
		{
			printPrompt("Try a higher number!");
		}
		else
		{
			numFound = true;
		}

	}

	std::cout << "You won! it took you " << numGuesses << " tries!" << std::endl;
}

// Main driver for program
int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::string intro = "Welcome to the higher-lower game\n"
		"Guess the correct number between " + std::to_string(lower_bound) +
		"-" + std::to_string(upper_bound) + "!\n";

	printPrompt(intro);

	startGame(gen);

	return 0;
}