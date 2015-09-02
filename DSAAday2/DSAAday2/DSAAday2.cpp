// DSAAday2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double totalCost(int);  //this is the prototype function so that the compiler doesn't yell about syntax.
int roundInt(double number);
void increment(int& number);
void showValue(int one, int two = 2, int three = 3); //gives showvalue with default params for two and three.

class DayOfYear{
public:
	DayOfYear(int monthValue = 1, int dayValue = 1);
	//initializes Day of year defaulting to january first.
	//DayOfYear _day;
	//_day would be january first
	int month;
	int year;
	void output();
};

void alterDay(){
	DayOfYear _day;
	_day.month = 1;
}

void DayOfYear::output(){
	switch (month){
	case 1:
		break;
	}
}

/*
int _tmain(int argc, _TCHAR* argv[])
{
	string nFirst, nLast;
	int score;
	int scores[5]; //creates an array of length of 5.
	fstream inputStream;
	fstream outputStream;

	//outputStream.open("Player.txt");
	//outputStream.write("10 Nailo Aldavir", );
	//outputStream.close();

	inputStream.open("Player.txt");

	inputStream >> score;
	inputStream >> nFirst >> nLast;

	cout << "Name: " << nFirst << " " << nLast << endl;

	cout << "Score: " << score << endl;

	inputStream.close();

	int prediction;
	switch (prediction){
	case 0:
		cout << "Hi";
		break;
	case 1:
		cout << "two";
		break;
	}

	return 0;
}
*/

double totalCost(int numberInt){
	double numberDouble;
	return numberDouble;
}

int roundInt(double number){
	return static_cast<int>(floor(number));
}

void increment(int& number){  //whatever is passed as number in incremented in this example
	number++;
	return;
}

void showValue(int one, int two, int three){
	return;
}