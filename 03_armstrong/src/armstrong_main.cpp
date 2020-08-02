#include <iostream>
#include <string>
#include <math.h>
bool isArmstrongNumber(int number)
{
	// TODO: implement some functionality to see if this number is an armstrong number
	int result = 0;
	int iteration = 0;
	int originalNumber = number;

	while (originalNumber != 0)
	{
		//every iteration contains the last digit of the original number
		iteration = originalNumber % 10;
		
		//let's put every iteration in a result parameter 
		result += pow(iteration, 3);

		//eliminate the processed digit from the original number
		originalNumber = originalNumber / 10;
	}

	if (result == number)
		return true;
	else		
		return false;
}

void printIsArmstrong(int number)
{
	if (isArmstrongNumber(number))
	{
		std::cout << "Armstrong" << std::endl;
	}
	else
	{
		std::cout << "NOT Armstrong" << std::endl;
	}
}

int main(int argc, char *argv[])
{
	// What is this program expected to do?
	// - Shows whether an argument is an armstrong number.
	// (what?)
	// -	An Armstrong number is a number that is equal to the sum of cubes of its digits.
	//		For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
	//		Let's try to understand why 153 is an Armstrong number:
	//			1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
	//
	// How to launch it?
	// - Execute the binary and pass a parameter to it?
	// - E.g. Open CMD in bin/Debug or bin/Release
	//		  03_armstrong.exe 1		=> Output: Armstrong
	//		  03_armstrong.exe 2		=> Output: Armstrong
	//		  03_armstrong.exe 			=> Output: No program arguments found.
	//		  03_armstrong.exe ABC		=> Undefined output (do whatever).
	//		  03_armstrong.exe 153		=> Output: Armstrong
	//		  03_armstrong.exe 154		=> Output: NOT Armstrong
	//

	// Make sure there are some program arguments available.
	if (argc <= 1)
	{
		std::cout << "No program arguments found." << std::endl;
		return 1;
	}

	int readNumber = 0;
	// Get the first argument
	std::string argumentAsString = argv[1];
	const char* argumentAsCharArray = argumentAsString.c_str();
	
	if ((argumentAsCharArray[0] >= 'a' && argumentAsCharArray[0] < 'z') ||
		(argumentAsCharArray[0] >= 'A' && argumentAsCharArray[0] < 'Z'))
		std::cout << "Nope. Try again :) " << std::endl;

	else
	{
		readNumber = std::stoi(argumentAsString);
		// TODO: read number / cast to integer
		printIsArmstrong(readNumber);
	}

	return 0;
}