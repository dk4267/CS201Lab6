//Debbie Kirchner
//dkkbd@mail.umkc.edu
//4/17/2019
//CS 201 Program 6

#include <iostream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//tokenSequence takes 4 parameters: a vector to start with, the goal number that was input by the user, the number of 
//turns the reach the goal, and the turns remaining. It outputs the required steps to reach the goal if the goal was
//reached, and if not, it says that it was not reached. It is a recursive function.
void tokenSequence(vector<int> &tokens, int goal, int totalTurns, int turnsRemaining) {
	bool correct = false;

	//base case: if there are no turns remaining, or the goal number was found, then end the function
	if ((turnsRemaining == 0) || (correct == true)) {
		//Only prints out "sorry, not found" if the correct answer was not reached
		if (!correct) {
			cout << "Sorry, solution wasn't found within allotted turns." << endl;
		}
	}

	else {
		//Searches through vector for goal, outputs the steps taken to reach the goal if found
		int currIndex = totalTurns - turnsRemaining;
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens.at(i) == goal) {
				correct = true;
				int num = 0;
				for (int j = 1; j < i + 1; j++) {
					if (tokens.at(j) == tokens.at(j - 1) + 25) {
						cout << "Adding 25, you get " << tokens.at(j) << " tokens." << endl;
						num++;
					}
					else if (tokens.at(j) == tokens.at(j - 1) / 2) {
						cout << "Reducing by half, you get " << tokens.at(j) << " tokens." << endl;
						num++;
					}
				}
				cout << "Solution found with " << totalTurns - num - 1 << " turn(s) remaining." << endl;
				break;
			}
		}
		//If goal was not found, divide by 2 if the current number is even, and add 25 to the rest of the vector
		if (!correct) {
			if (tokens.at(currIndex) % 2 == 0) {
				if (currIndex < tokens.size() - 1) {
					tokens.at(currIndex + 1) = tokens.at(currIndex) / 2;
					for (int i = currIndex + 2; i < tokens.size(); i++) {
						tokens.at(i) = tokens.at(i - 1) + 25;
					}
				}
			}
			//recursive call
			tokenSequence(tokens, goal, totalTurns, turnsRemaining - 1);
		}
	}
}

int main() {

	vector<int> tokens;
	int goal;
	int turns;

	//Get input from user
	cout << "Enter the number of tokens you want to reach:" << endl;
	cin >> goal;
	cout << "What is the number of turns:" << endl;
	cin >> turns;
	cout << "Searching for a solution within " << turns << " turn(s)..." << endl;
	int currValue = 13;
	//Accounts for the initial checking of the vector in the function
	turns++;

	//Load initial vector by only adding 25 to the previous number. The combinations where even numbers are divided by 2
	//are tried in the recursive function.
	for (int i = 0; i < turns; i++) {
		tokens.push_back(currValue);
		currValue += 25;
	}

	//Function call with the info that the user entered and the initial vector
	tokenSequence(tokens, goal, turns, turns);

	system("pause");
	return 0;
}