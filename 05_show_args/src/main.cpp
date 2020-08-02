#include <stdio.h>
#include <iostream>
#include <string>


int main(int argc, char *argv[])
{
	std::string delimiter = " ";
	std::string word;

	size_t pos = 0;

	if (argc <= 1)
	{
		printf("No program arguments found.\n");
	}
		
	std::string argumentAsString = argv[1];
	//char* argumentAsCharArray = word.c_str();

	while ((pos = argumentAsString.find(delimiter)) != std::string::npos)
	{
		word = argumentAsString.substr(0, pos);		
		//printArguments(argumentAsCharArray);
		std::cout << word << std::endl;
		argumentAsString.erase(0, pos + delimiter.length());
	}
	
	std::cout << argumentAsString << std::endl;

	
	return 0;
}