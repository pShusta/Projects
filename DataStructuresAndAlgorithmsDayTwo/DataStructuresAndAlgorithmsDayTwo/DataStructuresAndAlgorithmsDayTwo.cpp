// DataStructuresAndAlgorithmsDayTwo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	int aLength;
	string aString, bString;
	bString = "";
	while(aLength < 10){
		cin >> aString;
		aLength++;
		bString += aString;
	}
	cout << "bString: " <<
	return 0;
}

