#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/**
	Define a simple book.
*/
class Book
{
public:
	std::string name;
	std::string authors;

	void print()
	{
		std::cout << this->name << std::endl;
		std::cout << "\t(by " << this->authors << ")" << std::endl;
	}
};

/**
	Reads a vector of books from a text file.
	Note: the text file shall contain lines of text in pairs for the book name and authors
	E.g.
		BOOK 1
		AUTHOR 1
		BOOK 2
		AUTHOR 2
		BOOK 3
		AUTHOR 1, AUTHOR 2, AUTHOR 3
	@param file_name The name of the file to read from (must include path).
	@return Vector of books.
*/
std::vector<Book> readBooksFromTextFile(const std::string& file_name)
{
	std::vector<Book> results;
	// TODO: BEGIN read the file -------------------------------------
	std::ifstream myData(file_name);
	
	// checks if the file is open
	if (myData)
	{
		// string line;
		// reads through the file line by line
		while (!myData.eof())
		{
			Book newBook;
			// read book from text file
			std::getline(myData,newBook.name);
			std::getline(myData,newBook.authors);
			// add this book to inventory
			results.emplace_back(newBook);
		}

		myData.close();
		std::cout << " Books were successfully added to memory"<<std::endl;
	}

	// if failed to open the file
	else
		std::cout<<"Cannot open the file. Make sure the file name is correct"<<std::endl;

	// TODO: END read file and add to results vector ------------------
	return results;
}

int main()
{
	// Read a collection of books from a file.
	// Simple examples can be found everywhere.
	// E.g. https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c

	// Read the data
	std::string input_data("../../data/ermahgerd_berks.txt");
	std::cout << "Reading the data from " << input_data << std::endl;
	std::vector<Book> books_from_file = readBooksFromTextFile(input_data);

	// Print the data
	std::cout << "Here are all the books found in the data file..." << std::endl;
	for (auto book : books_from_file)
	{
		book.print();
	}

	return 0;
}