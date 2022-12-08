#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;


int main()
{

start:;
	system("color B0");
	system("cls");
	int yourNumber = 0, nextCard = 0, enemyNumber = 0, enemyFirstCard = 0, bet = 0, fishes = 0;
	char choice, c2;
	
	srand(time(NULL));
	cout << "how much do you want to bet?" << endl;
	cin >> bet;
	fishes -= bet;
	fstream f2;
	f2.open("fishes.txt", ios::in);
	f2 >> fishes;
	f2.close();
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tyour fishes: " << fishes << endl;
	nextCard = (rand() % 11) + 1;
	yourNumber += nextCard;
	cout << "\n\nfirst card: " << nextCard << endl;
	nextCard = (rand() % 11) + 1;
	yourNumber += nextCard;
	cout << "second card: " << nextCard << endl << endl;

	while (yourNumber <= 21)
	{
		
		cout << "Cards value: " << yourNumber << endl;
		cout << "do you want to take another card? [y/n]" << endl;
		cin >> choice;
		if (choice == 'y')
		{
			nextCard = (rand() % 11) + 1;
			yourNumber += nextCard;
		}
		else
		{
			enemyFirstCard = (rand() % 11) + 1;
			enemyNumber += enemyFirstCard;
			enemyFirstCard = (rand() % 11) + 1;
			enemyNumber += enemyFirstCard;
			if (enemyFirstCard < 16)
			{
				enemyFirstCard = (rand() % 11) + 1; 
				enemyNumber += enemyFirstCard;	
			}


			if (enemyNumber < 21)
			{
				if (enemyNumber > yourNumber)
				{
					cout << "you lost!  -" << bet << " fishes" << endl;
					fishes -= bet;
					cout << "enemy number: " << enemyNumber << endl;
					goto exit_loop;
				}
				else if (enemyNumber < yourNumber)
				{
					cout << "you won!  +" << (bet * 2) << "fishes" << endl;
					fishes += (bet * 2);
					cout << "enemy number: " << enemyNumber << endl;
					goto exit_loop;
				}
				else if (enemyNumber == yourNumber)
				{
					cout << "it's a draw, you haven't gained or lost anything" << endl;
					cout << "enemy number: " << enemyNumber << endl;
					goto exit_loop;
				}
			} 
			else
			{
				cout << "you won!!" << endl;
				cout << "enemy number: " << enemyNumber << endl;
				goto exit_loop;
			}
		}
	}
		if (yourNumber > 21)
		{
			cout << "you got over 21, -" << bet << " fishes" << endl;
			fishes -= bet;
		}
	exit_loop:;
		fstream f1;
		f1.open("fishes.txt", ios::out);
		f1 << fishes;
		f1.close();
		cout << "do you want to play again ? " << endl;
		cin >> c2;
		if (c2 == 'y')
		{
			goto start;
		}
		else
		{
			cout << "your fishes: " << fishes << endl;
			cout << "Bye!";
		}
	
}