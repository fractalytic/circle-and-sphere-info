// CircleAndSphereInfo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//Circle and Sphere information
//by Shane
//
//The code requires an input floating point number
//and will then return some information regarding a circle or sphere with that value as the radius
//
//Feel free to look at this code and learn but please don't reuse it without my permission
//
//This code works best using a proper C++ compiler rather than the SoloLearn testing environment
//due to needing input from the user
//It has been tested using Visual Studio 2017
//
//
//original code: 22nd April 2017
//update: No further updates yet
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <sstream>
using namespace std;

int main()
{
	//declare the variables
	double radius = 0.0;
	string inputStr = "";
	bool loopContinue = true;
	bool validInput = false;
	string loopAnswer = "";
	clock_t startTime, currentTime;
	double elapsedSeconds;
	const double PI = 3.1415926535897932384626433832795;

	//set up the output for floating point numbers
	cout << setiosflags(ios::fixed);
	cout << setprecision(6);

	while (loopContinue == true) {

		//get input from the user
		validInput = false;
		while (validInput == false) {
			cout << "Please enter a number greater than 0 > ";
			getline(cin, inputStr);

			//try converting to long 
			stringstream myStream(inputStr);
			if (myStream >> radius) {
				if (radius > 0) {
					validInput = true;
				}
				else {
					cout << "That value isn't valid, please try again" << endl << endl;
				}
			}
			else {
				cout << "That value isn't valid, please try again" << endl << endl;
			}
		}

		startTime = clock();

		//output information as well as a time taken
		cout << "Using " << radius << " units as the radius of a circle or sphere:" << endl << endl;
		cout << "   A circle would have circumference: " << 2.0 * radius * PI << " units" << endl;
		cout << "     and area: " << PI * radius * radius << " square units" << endl << endl;
		cout << "   A sphere would have surface area: " << 4.0 * PI * radius * radius << " square units" << endl;
		cout << "     and volume: " << 4.0 * PI * radius * radius * radius / 3.0 << " cubed units" << endl << endl;

		currentTime = clock();
		elapsedSeconds = ((currentTime - startTime) / (CLOCKS_PER_SEC / 1.0));
		cout << "This took: " << elapsedSeconds << " seconds to run" << endl << endl;

		cout << "Do you want another go (Y/N)? ";
		getline(cin, loopAnswer);
		if (loopAnswer == "y" || loopAnswer == "Y") {
			loopContinue = true;
			cout << endl;
		}
		else {
			loopContinue = false;
		}

	}

	return 0;
}


