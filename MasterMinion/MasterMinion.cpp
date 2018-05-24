
/*
 * MasterMinion.cpp
 *
 *  Created on: 2018. 2. 15.
 *      Author: Cho
 */


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

int main() {
		// rand 함수 이용할 때 완전히 무작위로 나오도록
	srand(time(NULL));

	cout << "Welcome to the game of MasterMinion!" << endl;
	int answer;
	cout << "Each minion is assigned a number. \nKevin: 1, Bob: 2, Stuart: 3, Dave: 4, Phil: 5, Tim: 6" << endl;
	cout << "Three of them are hanging out at the table, and they've ordered themselves randomly." << endl;
	cout << "Guess the Minions and their order from left to right!\nThey'll tell you 2 hints, (1) How many you get right, and (2) How many you get half-right (right name, wrong position)." << endl;
	cout << "Now type your 3 digit number!" << endl;
		// 정답 설정: a, b, c 1~6 사이 임의의 정수, 정답 = a x 100 + b x 10 + c
	int a, b, c;
	a = rand()%6 + 1;
	do{
		b = rand()%6 + 1;
	}while (b==a);
	do{
		c = rand()%6 + 1;
	}while (c == a || c == b);
	answer = a*100 + b*10 + c;


	int input;
	do{
		cin >> input;
		if(input/100 > 7 || (input%100)/10 > 7 || input%10 > 7){
			cout << "Invalid range!" << endl;
			break;
		}

		int right = 0;
		int halfRight = 0;
		if(input/100 == answer/100)
			right++;
		if((input%100)/10 == (answer%100)/10)
			right++;
		if(input%10 == answer%10)
			right++;
		if(input/100 == (answer%100)/10 || input/100 == answer%10)
			halfRight++;
		if((input%100)/10 == answer/100 || (input%100)/10 == answer%10)
			halfRight++;
		if(input%10 == answer/100 || input%10 == (answer%100)/10)
			halfRight++;

		cout << "Right answers: " << right << ", Half-right answers: " << halfRight << endl;
		if(right != 3){
			cout << "Type your 3 digit number again!" << endl;
		}
	} while (input != answer);
	if(input == answer){
	cout << "Congratulations! You won!" << endl;
	}
}

