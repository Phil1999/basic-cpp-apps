#include <iostream>
#include <sstream>
#include <random>


constexpr int lower_bound = 1;
constexpr int upper_bound = 10;

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

int generateRandNum(std::mt19937& gen)
{
	int result;

	std::uniform_int_distribution<> distr(lower_bound, upper_bound);

	result = distr(gen);

	return result;
}


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
			userGuess = getNumFromUser(guessNumberPrompt);
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