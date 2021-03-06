// Keywords - word cracking program
#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// seed the random number generator
	srand(static_cast<unsigned int>(time(0)));

	// setup enum for array
	enum fields {WORD, HINT, NUM_FIELDS};
	// number of words that can be in the array, doesn't change
	const int NUM_WORDS = 10;
	// initialize the arry
	const string WORDS[NUM_WORDS][NUM_FIELDS] = 
	{
		{"picture", "worth a thousand words"},
		{"television", "popular entertainment device"},
	    {"jacket", "smart in the winter, strange in the summer"},
		{"apple", "a food and a tech company"},
		{"router", "an internet device"},
		{"cat", "popular household pet"},
		{"dog", "popular household pet"},
		{"playstation", "popular gaming device"},
		{"vacuum", "household cleaning product"},
		{"refrigerator", "your favorite kitchen appliance"}
	};

	cout << "This is the CIA Code Break Training Simulation Program" << endl;
	cout << "You must guess all the jumbled words shown to you. You can use !hint for help or !quit to exit the program.\n";

	// loop until the !quit command is used
	while (true) 
	{
		// track the number of guesses the code breaker has made
		int guesses = 0;
		// randomly choose the index of the words that will be used
		int choice = rand() % NUM_WORDS;
		int choiceTwo = rand() % NUM_WORDS; 
		int choiceThree = rand() % NUM_WORDS;

		// array of the words that were picked
		const string PICKED_WORDS[3][3] = 
		{
			{WORDS[choice][WORD], WORDS[choice][HINT]},
			{WORDS[choiceTwo][WORD], WORDS[choiceTwo][HINT]},
			{WORDS[choiceThree][WORD], WORDS[choiceThree][HINT]}
		};
		
		// jumbled form of the words that were picked
		string jumbleOne;
		string jumbleTwo;
		string jumbleThree;

		// loop over each word and scramble it
		// then save it to jumble variables
		for (int i = 0; i < 3; i++) 
		{
			int length = PICKED_WORDS[i]->size();
			string jumble = *PICKED_WORDS[i];
			// loop over each character in the word
			for (int i2 = 0; i2 < length; i2++) 
			{
				// get two random indexes and mix up the word
				int index1 = rand() % length;
				int index2 = rand() % length;
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}
			
			switch (i) 
			{
			case 0:
				jumbleOne = jumble;
				break;
			case 1:
				jumbleTwo = jumble;
				break;
			case 2:
				jumbleThree = jumble;
				break;
			}
		}

		cout << "Your first word is " << jumbleOne << endl;
		
		// loop until the word is guessed
		// then move on to the next word
		while (true)
		{
			cout << "Your guess: ";

			string guessOne;
			cin >> guessOne;

			// if the guess is correct then break out of the loop
			if (guessOne == *PICKED_WORDS[0])
			{
				// increment guesses
				guesses++;
				cout << "\nYou got the first word! Moving on to the next one...\n";
				break;
			}
			// if !hint is used, then print the hint to console
			else if (guessOne == "!hint")
			{
				cout << PICKED_WORDS[0][1] << endl;
			}
			// send a try again message if the guess was wrong
			else
			{
				cout << "\nTry again!";
				guesses++;
			}
		}

		cout << "Your second word is " << jumbleTwo << endl;

		// loop until the second word is guessed
		// then move on to the third
		while (true)
		{
			cout << "Your guess: ";

			string guessTwo;
			cin >> guessTwo;

			if (guessTwo == *PICKED_WORDS[1])
			{
				guesses++;
				cout << "\nYou got the second word! Almost done...\n";
				break;
			}
			else if (guessTwo == "!hint")
			{
				cout << PICKED_WORDS[1][1] << endl;
			}
			else
			{
				cout << "Try again!";
				guesses++;
			}
		}

		cout << "Your final word is " << jumbleThree << endl;

		// loop until the third word is guessed
		// then ask if they want to quit or restart
		while (true)
		{
			cout << "Your guess: ";

			string guessThree;
			cin >> guessThree;

			if (guessThree == *PICKED_WORDS[2])
			{
				guesses++;
				cout << "\nYou got the final word! Congratz!\n";
				cout << "You finished the simulation in " << guesses << " guesses.\n";
				break;
			}
			else if (guessThree == "!hint")
			{
				cout << PICKED_WORDS[2][1] << endl;
			}
			else
			{
				cout << "\nTry again!";
				guesses++;
			}
		}

		cout << "Type !quit to end the program.";
		
		string command;
		cin >> command;

		if (command == "!quit")
		{
			break;
		}
	}

	return 0;
}