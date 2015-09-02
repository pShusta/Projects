// flghtReservations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

//using iostream
void readFile(string);
//usinng iostream
void writeFile(string);
void reserveSeat();
//using iostream
void printMap();


class Plane{
public:
	void printMap() const;
	void reserveSeat(); 
	void writeFile(string);
	void readFile(string);
private:
	int rows;
	int columns;
	bool seats[20][10];
};

void Plane::printMap() const {
	cout << "The following seatmap depicts our current plane with occupied seats denoted as an X" << endl;
	for (int i = 0; i < rows; i++){
		cout << i + 1 << ": ";
		for (int j = 0; j < columns; j++){
			cout << seats[i][j] << " ";
		}
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
	if (c >= 97) { c -= 32; }
	c -= 16;
	int d = c - '0';
	if (r <= rows && d <= columns) { seats[r][d] = false; }
	return;
}

void Plane::writeFile(string filePath){

}

void Plane::readFile(string filePath){

}

int _tmain(int argc, _TCHAR* argv[])
{
	testFunc();
	int a;
	cin >> a;
	return 0;
}

