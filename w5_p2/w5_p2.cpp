﻿/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 02 - 18

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"     // intentional
#include "SpellChecker.h"
#include "SpellChecker.h"   // intentional
#include "Book.h"
#include "Book.h"           // intentional
#include "Movie.h"
#include "Movie.h"          // intentional

using namespace seneca;

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const seneca::Collection<seneca::Book>& theCollection,
	const seneca::Book& theBook)
{
	std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const seneca::Collection<seneca::Movie>& theCollection,
	const seneca::Movie& theMovie)
{
	std::cout << "Movie \"" << theMovie.title()
		<< "\" added to collection \"" << theCollection.name()
		<< "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	seneca::Collection<seneca::Book> library("Bestsellers");
	if (argc == 5) {
		// TODO: load the first 4 books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the collection "library" (use the += operator)
		//       - lines that start with "#" are considered comments and should be ignored
		//       - if the file cannot be open, print a message to standard error console and
		//                exit from application with error code "AppErrors::CannotOpenFile"
		std::ifstream _readFile(argv[1]);

		if (!_readFile) {
			std::cout << "Cannot Open the File: " << argv[1] << std::endl;
			exit(AppErrors::CannotOpenFile);
		}

		std::string _line{ "" };
		size_t _count{ 0u };

		while (_count < 4 && std::getline(_readFile, _line)) {
			if (_line[0] != '#') {
				Book _temp(_line);
				library += _temp;
				_count++;
			}
		}



		/*
		 ♪ Hey, I just met you,      ♪
		 ♪ And this is crazy,        ♪
		 ♪ But here's my number.     ♪    (register the observer)
		 ♪ So, if something happens, ♪    (event)
		 ♪ Call me, maybe?           ♪    (callback)
		 */


		library.setObserver(bookAddedObserver);

		// TODO: add the rest of the books from the file.

		while (std::getline(_readFile, _line)) {
			if (_line[0] != '#') {
				Book _temp(_line);
				library += _temp;
				_count++;
			}
		}

	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		std::exit(AppErrors::BadArgumentCount);
	}

	double USD_TO_CAD_RATE = 1.3;
	double GBP_TO_CAD_RATE = 1.5;

	// TODO: (from part #1) create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object


	auto exchagRate = [=](Book& _book) {
		if (_book.country() == "US")
			_book.price() *= USD_TO_CAD_RATE;
		else if (_book.country() == "UK" && _book.year() >= 1990 && _book.year() <= 1999)
			_book.price() *= GBP_TO_CAD_RATE;

		return _book;
	};


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	// TODO (from part #1): iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (auto i = 0u; i < library.size(); ++i)
		exchagRate(library[i]);

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	seneca::Collection<seneca::Movie> theCollection("Action Movies");

	// Process the file
	seneca::Movie movies[5];
	if (argc > 2) {
		// TODO: load 5 movies from the file "argv[2]".
		//       - read one line at a time, and pass it to the Movie constructor
		//       - store each movie read into the array "movies"
		//       - lines that start with "#" are considered comments and should be ignored


		std::ifstream _readFile(argv[2]);

		if (!_readFile) {
			std::cout << "Cannot Open the File: " << argv[2] << std::endl;
			exit(AppErrors::CannotOpenFile);
		}

		std::string _line{ "" };
		size_t _count{ 0 };

		while (_count < 5 && std::getline(_readFile, _line)) {
			if (_line[0] != '#' && _count < 7) {
				Movie _temp(_line);
				movies[_count++] = _temp;
			}
		}
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing addition and callback function\n";
	std::cout << "-----------------------------------------\n";
	if (argc > 2) {
		// Add a few movies to collection; no observer is set
		((theCollection += movies[0]) += movies[1]) += movies[2];
		theCollection += movies[1];
		// add more movies; now we get a callback from the collection
		theCollection.setObserver(movieAddedObserver);
		theCollection += movies[3];
		theCollection += movies[3];
		theCollection += movies[4];
	}
	else {
		std::cout << "** No movies in the Collection\n";
	}
	std::cout << "-----------------------------------------\n\n";

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing exceptions and operator[]\n";
	std::cout << "-----------------------------------------\n";


	// TODO: The following loop can generate generate an exception
	//         write code to handle the exception
	//       If an exception occurs print a message in the following format
	//** EXCEPTION: ERROR_MESSAGE<endl>
	//         where ERROR_MESSAGE is extracted from the exception object.


	try {
		for (auto i = 0u; i < 10; ++i)
			std::cout << theCollection[i];
	}
	catch (std::out_of_range& err) {
		std::cout << "** EXCEPTION: " << err.what() << std::endl;
	}
	catch (std::exception& err) {
		std::cout << "** EXCEPTION: " << err.what() << std::endl;
	}
	std::cout << "-----------------------------------------\n\n";


	std::cout << "-----------------------------------------\n";
	std::cout << "Testing the functor\n";
	std::cout << "-----------------------------------------\n";
	for (auto i = 3; i < argc; ++i)
	{
		// TODO: The following statement can generate generate an exception
		//         write code to handle the exception
		//       If an exception occurs print a message in the following format
		//** EXCEPTION: ERROR_MESSAGE<endl>
		//         where ERROR_MESSAGE is extracted from the exception object.
		try {
			seneca::Spell_Checker sp(argv[i]);
			for (auto j = 0u; j < library.size(); ++j)
				library[j].fixSpelling(sp);
			sp.showStatistics(std::cout);

			for (auto j = 0u; j < theCollection.size(); ++j)
				theCollection[j].fixSpelling(sp);
			sp.showStatistics(std::cout);
		}
		catch (const char* err) {
			std::cout << "** EXCEPTION: " << err << std::endl;
		}
	}
	if (argc < 3) {
		std::cout << "** Spellchecker is empty\n";
		std::cout << "-----------------------------------------\n";
	}
	std::cout << "\n";

	std::cout << "=========================================\n";
	std::cout << "Wrapping up this workshop\n";
	std::cout << "--------------- Movies ------------------\n";
	std::cout << theCollection;
	std::cout << "--------------- Books -------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n";
	std::cout << "Testing operator[] (the other overload)\n";
	std::cout << "-----------------------------------------\n";
	const seneca::Movie* aMovie = theCollection["Terminator 2"];
	if (aMovie == nullptr)
		std::cout << "** Movie Terminator 2 not in collection.\n";
	aMovie = theCollection["Dark Phoenix"];
	if (aMovie != nullptr)
		std::cout << "In this collection:\n" << *aMovie;
	std::cout << "-----------------------------------------\n";

	return cout;
}