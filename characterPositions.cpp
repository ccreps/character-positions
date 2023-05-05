// characterPositions.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Code Created by Collin Creps on 2/4/2021

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Function printIndex prints the indexes of the found character separated by a single space.

string printIndex(vector<int> const &input) {
	
	string outIndex;

	for (auto j : input) {
		outIndex += std::to_string(j) + " ";
	}

	return outIndex;
}

int main() {
	ifstream inFS;
	string textLine;
	char userCharacter;
	vector<int> indicies;
	int count = 0;
	
	inFS.open("input.txt");

	if (!inFS.is_open()) {
		cout << "The input file input.txt could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Enter the character to search for: ";
	cin >> userCharacter;

	
	getline(inFS, textLine);
	inFS.close();

	for (int i = 0; i < textLine.size(); i++) {
		if (textLine.at(i) == userCharacter) {
			indicies.push_back(i);
			count += 1;
		}
	}

	cout << "The number of occurrences of the character " << userCharacter << " is " << count << endl;

	if (count != 0) {
		cout << "The indices of the character positions are " << printIndex(indicies) << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
