// CISC192Homework11_Ron_Landagan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct MovieData
{
	string title;
	string director;
	string yearReleased;
	string runningTime;

	int productionCosts;
	int firstYearRevenues;
};

/**
	Takes in a MovieData data type and displays the film's information.
	@param MovieData the film's information
*/
void displayStruct(MovieData movie);

/**
	Takes in an integer amount of money and formats it into a currency string.
	@param int The amount of money to format.
	@return The formatted money string.
*/
string formatMoney(int money);

int main()
{
	//Create two instances of MovieData structure
	MovieData firstMovie;
	firstMovie.title = "Goodfellas";
	firstMovie.director = "Martin Scorsese";
	firstMovie.yearReleased = "1990";
	firstMovie.runningTime = "2h 26min";
	firstMovie.productionCosts = 25000000;
	firstMovie.firstYearRevenues = 46261759;

	MovieData secondMovie;
	secondMovie.title = "Whiplash";
	secondMovie.director = "Damien Chazelle";
	secondMovie.yearReleased = "2014";
	secondMovie.runningTime = "1h 47min";
	secondMovie.productionCosts = 3300000;
	secondMovie.firstYearRevenues = 13092006;

	//Display information of the two movies
	displayStruct(firstMovie);
	displayStruct(secondMovie);

	system("pause");
    return 0;
}

void displayStruct(MovieData movie)
{
	//Displays the movie's information
	cout << "Title:\t\t" << setw(25) << movie.title << endl
		<< "Director:\t" << setw(25) << movie.director << endl
		<< "Year Released:\t" << setw(25) << movie.yearReleased << endl
		<< "Running Time:\t" << setw(25) << movie.runningTime << endl;

	//This prints if the movie made a profit in the first year
	if (movie.firstYearRevenues - movie.productionCosts > 0)
	{
		cout << "Profit:\t\t" << setw(25) << formatMoney(movie.firstYearRevenues - movie.productionCosts) 
			<< endl << endl;
	}
	else
		cout << "Loss:\t\t" << setw(25) << formatMoney(movie.firstYearRevenues - movie.productionCosts) 
			<< endl << endl;
}

string formatMoney(int n)
{
	//Turns the money into a string
	string money = to_string(n);
	
	//Adds a dollar sign to the beginning of the string
	money.insert(0, "$");
	return money;
}
