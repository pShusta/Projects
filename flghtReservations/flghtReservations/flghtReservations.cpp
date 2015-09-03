/*
Author:         Phillip Shusta
Class:          Data Structures and Algorithems
Professor:      Marty Wolf
Assignment:     Project 1
Date:           September 2, 2015
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Plane Class Methods

//Using:          iostream, fstream, string
//Precondition:   passing a string filePath so that the file we read from can be changed simply by passing a different name
//Postcondition:  Reset seats[][] to a blank array and read the contents of a file into seats[][]
void readFile(string);
//Using:          iostream, fstream, string
//Precondition:   passing a string filePath so that the file we write from can be changed simply by passing a different name
//Postcondition:  Write the contents of seats[][] to the file located at the passed filePath
void writeFile(string);
//Using:          iostream, string
//Precondition:   
//Postcondition:  Allow the user to reserve seats by converting a location into an X
void reserveSeat();
//Using:          iostream, string
//Precondition:   
//Postcondition:  Prints to the screen seats[][] in a seatmap format
void printMap();

//Extra Functions

//Using:          
//Precondition:   char to be converted
//Postcondition:  Converts the passed char to an int
int letterToNumber(char);
//Using:          
//Precondition:   int to be converted
//Postcondition:  Converts the passed int to a char
char numberToLetter(int);


class Plane{
public:
	void printMap();
	void reserveSeat(); 
	void writeFile(string);
	void readFile(string);
private:
	int rows;
	int columns;
	string seats[20][10];
};

void Plane::printMap() {
	cout << "The following seatmap depicts our current plane with occupied seats denoted as an X" << endl;
	//loops through each column of the array each step of the loop for the rows, thus the array is read top left to bottem right like a book
	for (int i = 0; i < rows; i++){
		cout << i + 1 << ": ";
		for (int j = 0; j < columns; j++){
			cout << seats[i][j] << " ";
		}
		cout << endl;
	}
}

void Plane::reserveSeat(){

	Plane::printMap();
	cout << "Please enter the seat which you would like to reserve.\n"
		 << "Please use the format of row number followed by column letter. ex: 1A\n"
		 << "If you do not wish to reserve a seat at this time please enter the number 0.\n";
	int r;
	char c;
	cin >> r;
	if (r = 0) { return; }
	cin >> c;
	int d = letterToNumber(c);
	if (0 < r <= rows && 0 < d <= columns) {
		if (seats[r - 1][d - 1] == "X"){
			cout << "I am sorry that seat is already taken" << endl;
		}
		else { seats[r - 1][d - 1] = "X"; }
	}
	return;
}

void Plane::writeFile(string filePath){

	fstream outputStream;
	outputStream.open("newPlane.txt");

	outputStream << rows << " " << columns << endl;
	//loops through each column of the array each step of the loop for the rows, thus the array is read top left to bottem right like a book
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			if (seats[i][j] == "X") { outputStream << i + 1 << numberToLetter(j + 1) << endl; }
		}
	}

	outputStream.close();
}

void Plane::readFile(string filePath){
	fstream inputStream;
	inputStream.open("plane.txt");
	cout << inputStream.is_open();

	int _rows, _columns;
	inputStream >> _rows >> _columns;
	cout << _rows << " " << _columns;
	if (0 < _rows <= 20 && 0 < _columns < 10) { rows = _rows; columns = _columns; }

	//Reset seats[][] to a blank array
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 10; j++){
			seats[i][j] = numberToLetter(j+1);
		}
	}

	int _number;
	char _letter;
	//while not end of file, read a seat coordinate
	while (inputStream >> _number){
		inputStream >> _letter;
		cout << _number << _letter;
		if (0 < _number <= rows && 0 < letterToNumber(_letter) <= columns){ seats[_number  - 1][letterToNumber(_letter) - 1] = "X"; }
	}
}

int letterToNumber(char letter){
	if (letter >= 97) { letter -= 32; }
	letter -= 16;
	int _number = letter - '0';
	return _number;
}

char numberToLetter(int number){
	char _letter = '0';
	_letter += number;
	_letter += 16;
	return _letter;
}

int _tmain(int argc, _TCHAR* argv[]) { 
	Plane plane;
	plane.readFile("plane.txt");
	plane.printMap();
	plane.reserveSeat();
	plane.writeFile("newPlane.txt");
	char a;
	cin >> a;
}