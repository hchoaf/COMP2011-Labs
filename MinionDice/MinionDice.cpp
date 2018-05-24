/*
 * MinionDice.cpp
 *
 *  Created on: 2018. 3. 10.
 *      Author: Cho
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

void print(int a){
	cout << "The number is " << a << "." << endl;
}

int rollDice(){
	int number = rand()%6+1;
	return number;
}




bool check(int a, int b, int c){
	bool A = (a!=6 && b!=6 && c!=6);
	return A;
}

int roll3Dice(int a, int b, int c){
	print(a);
	print(b);
	print(c);
	int sum = a+b+c;
	cout << "Sum of this throw: " << sum << "." << endl;
	cout << "\n";
	return sum;
}


int game(){
	int a = rollDice();
	int b = rollDice();
	int c = rollDice();
	if(check(a, b, c)){
		cout << "6 didn't appear!" << endl;
		return roll3Dice(a, b, c);
	}
	else{
		cout << "6 appeared! Dice are thrown again!" << endl;
		return roll3Dice(a, b, c) + game();
	}
}

int count6(int a, int b, int c){
	int count = 0;
	if(a == 6)
		count++;
	if(b == 6)
		count ++;
	if(c == 6)
		count ++;
	return count;
}

void printscore(int a, int b, int c){
	cout << "Your score: " << a << endl;
	cout << "Bob's score: " << b << endl;
	cout << "Jack's score:" << c << endl;
}

int max(int a, int b, int c){
	if(a>b && a>c)
		return a;
	if(b>c && b>a)
		return a;
	if(c>a && c>b)
		return c;
	else
		return 0;
}

int main(){
	srand(time(NULL));
	cout << "Welcome to the game of minion dice! Each minion will throw 3 dice and the highest sum wins!" << endl;
	cout << "However, for each dice that shows 6, you roll and sum again!" << endl;
	cout << "You, Bob, and Jack will play this game!" << endl;
	cout << "Press 1 to start the game!" << endl;
	cout << "               _________________________________" << endl;
	cout << "              /                                /|" << endl;
	cout << "             /         4444444                / |" << endl;
	cout << "            /         44    44               /  |" << endl;
	cout << "           /         444444444444           /   |" << endl;
	cout << "          /                 44             /    |" << endl;
	cout << "         /_______________________________ /     |" << endl;
	cout << "        |                                |  1   |" << endl;
	cout << "        |                                |  1   |" << endl;
	cout << "        |        5555555555555555        |  1   |" << endl;
	cout << "        |        555                     |  1   |" << endl;
	cout << "        |        555                     |  1   |" << endl;
	cout << "        |        555                     |  1   |" << endl;
	cout << "        |        5555555555555555        |  1  /" << endl;
	cout << "        |                    555         |  1 /" << endl;
	cout << "        |                   555          |   /" << endl;
	cout << "        |         5555    5555           |  /  " << endl;
	cout << "        |           55555555             | /    " << endl;
	cout << "        |________________________________|/ "<< endl;

	cout << "----------------------------------------------------------------------------" << endl;

	int start = 0;
	cin >> start;
	if(start != 1){
		cout << "Game ended!" << endl;
		return 0;
	}



	int yourScore = 0;
	int bobScore = 0;
	int jackScore = 0;


	printscore(yourScore, bobScore, jackScore);


	cout << "\n" << "Press B so Bob can throw dice!" << endl;
	char bob = '2';
	cin >> bob;
	while(bob != 'B'){
		cout << "Wrong character! Press B so Bob can throw dice!" << endl;
		cin >> bob;
	}

	cout << "\n" << "Now, Bob will roll 3 dice!" << endl;
	bobScore = game();
	cout << "Sum of the numbers that Bob gained: " << bobScore << endl;
	printscore(yourScore, bobScore, jackScore);

	cout << "\n" << "Press J so Jack can throw dice!" << endl;
	char jack = '2';
	cin >> jack;
	while(jack != 'J'){
		cout << "Wrong character! Press J so Jack can throw dice!" << "\n" << endl;
		cin >> jack;
	}

	cout << "\n" << "Now, Jack will roll 3 dice!" << endl;
	jackScore = game();
	cout << "Sum of the numbers that Jack gained: " << jackScore << "\n" << endl;
	printscore(yourScore, bobScore, jackScore);

	cout << "\n" << "Press Y to throw dice!" << endl;
	char you = '2';
	cin >> you;
	while(you != 'Y'){
		cout << "Wrong character! Press Y to throw dice!" << endl;
		cin >> you;
	}

	cout << "\n" << "Now, you will roll 3 dice!" << endl;
	yourScore = game();
	cout << "Sum of the numbers that You gained: " << yourScore << "\n" << endl;
	printscore(yourScore, bobScore, jackScore);

	cout << "--------------------------------------------------------------------------------" << endl;
	if(max(yourScore, bobScore, jackScore) == yourScore)
		cout << "You won with score: " << yourScore << endl;
	if(max(yourScore, bobScore, jackScore) == jackScore)
		cout << "Jack won with score: " << jackScore << endl;
	if(max(yourScore, bobScore, jackScore) == bobScore)
		cout << "Bob won with score: " << bobScore << endl;
	return 0;
}



