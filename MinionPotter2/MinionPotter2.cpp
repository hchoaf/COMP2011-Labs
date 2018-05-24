/*
 * MinionPotter.cpp
 *
 *  Created on: 2018. 3. 31.
 *      Author: Cho
 */


#include <iostream>
#include <ctime>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

void title();
void start();
void howtoplay();
void highscore();
void credit();
void exitgame();
void print(char[30][21]);
void fallbanana(char[30][21] );
void create(int, char[30][21]);
void move(char[30][21]);
void calculate(string, int);
void checkdeath(bool&);



char bananaboard[30][21];
int firsthighscore = 0;
int secondhighscore = 0;
string first = " ";
string second = " ";
bool death;

struct minion{
	string name = "Minion";
	int banana = 0;
	string difficulty = "default";
};

minion minion1;




void title(){

	cout << "|*************************************************************************************************************************|"<< endl;
	cout << "|  M         M  III  N      N  III    OOO    N      N         PPPPPP     OOO    TTTTTTT  TTTTTTT  EEEEEEEE  RRRRRR    !!  |"<< endl;
	cout << "|  MM       MM   I   NN     N   I    O   O   NN     N         P     P   O   O      T        T     E         R     R   !!  |"<< endl;
	cout << "|  M M     M M   I   N N    N   I   O     O  N N    N         P     P  O     O     T        T     E         R     R   !!  |"<< endl;
	cout << "|  M M     M M   I   N  N   N   I   O     O  N  N   N         PPPPPP   O     O     T        T     E         RRRRRR    !!  |"<< endl;
	cout << "|  M  M   M  M   I   N   N  N   I   O     O  N   N  N         P        O     O     T        T     EEEEEEEE  R  R      !!  |"<< endl;
	cout << "|  M  M   M  M   I   N    N N   I   O     O  N    N N         P        O     O     T        T     E         R   R     !!  |"<< endl;
	cout << "|  M   M M   M   I   N     NN   I    O   O   N     NN         P         O   O      T        T     E         R    R        |"<< endl;
	cout << "|  M    M    M  III  N      N  III    OOO    N      N         P          OOO       T        T     EEEEEEEE  R     R   !!  |"<< endl;
	cout << "***************************************************************************************************************************"<< endl;
	cout << "________________________________________________________________________________________"<< endl;
	cout << "|              |                    |                  |                 |             |" << endl;
	cout << "|   1. Start   |   2. How to Play   |   3. Highscore   |    4. Credit    |   5. Exit   |" << endl;
	cout << "|______________|____________________|__________________|_________________|_____________|" << endl;
	char index;
	while(index != '1' && index != '2' && index != '3' && index != '4'){
		cin >> index;
		switch(index){
		case '1':
			system("cls");
			start();
			break;
		case '2':
			system("cls");
			howtoplay();
			break;
		case '3':
			system("cls");
			highscore();
			break;
		case '4':
			system("cls");
			credit();
			break;
		case '5':
			exitgame();
			break;
		default:
			break;
		}

	}
}

void start(){


	for(int i=0; i<30; i++){
		for(int j = 0; j<21; j++){
			bananaboard[i][j] = ' ';
		}
	}
	bananaboard[29][10] = 'M';

	print(bananaboard);
	cout << "\n" << "Type your name!" << endl;
	cin >> minion1.name;

	system("cls");

	print(bananaboard);
	cout << "\n" << endl;
	cout << "Select your Difficulty" << "\n" << "1: EASY\n2: MEDIUM \n3: HARD" << endl;
	int difficulty;
	cin >> difficulty;
	switch(difficulty){
	case 1:
		minion1.difficulty = "EASY";
		break;
	case 2:
		minion1.difficulty = "MEDIUM";
		break;
	case 3:
		minion1.difficulty = "HARD";
		break;
	default:
		break;
	}
	cout << "You have 30 seconds! Collect as many bananas as you can!" << endl;
	cout << "Press 1 to start!" << endl;
	char startindex;
	while(startindex != '1'){
		cin >> startindex;
		if(startindex == '1'){
			system("cls");
			break;
		}
	}


	bool checktime = true;
	time_t start_time = time(nullptr);
	if(time(nullptr) - start_time > 30){
		checktime = false;
	}

	death = false;

	while(checktime){
		system("cls");
		print(bananaboard);
		create(difficulty, bananaboard);
		fallbanana(bananaboard);
		Sleep(50);
		move(bananaboard);
		if(time(nullptr) - start_time > 30){
			break;
		}
		if(death){
			break;

		}

	}


	calculate(minion1.name, minion1.banana);

	system("cls");

	if(!death){
	cout << "Time's up!\n" << endl;
	}else if(death){
		cout << "Oh no! A bomb hit you!" << endl;
	}
	cout << "You've collected " << minion1.banana << " bananas!\n" << endl;
	cout << "Press 1 to start!" << endl;
	cout << "Press 0 to go back to title!" << endl;
	char restartindex;
		while(restartindex != '0' && restartindex != '1'){
			cin >> restartindex;
			if(restartindex == '0'){
				system("cls");
				title();
				break;
			}
			if(restartindex == '1'){
				system("cls");
				start();
				break;
			}
		}



}

void howtoplay(){
	cout << "**************************************************************************************************" << endl;
	cout << "Minion Potter has turned raindrops into banana! Your goal is to collect as many banana as you can!" << endl;
	cout << "However, bombs are also falling from the sky, so you should avoid the bombs!" << endl;
	cout << "You have 20 seconds to collect banana! If you get hit by a bomb, you will die!" << endl;
	cout << "Number of bananas you've collected will be your score!" << endl;
	cout << "**************************************************************************************************" << endl;
	cout << "Press 0 to go back to title." << endl;
	char index;
	while(index != '0'){
		cin >> index;
		if(index == '0'){
			break;
		}
	}
	system("cls");
	title();

}

void highscore(){
	cout << "**************************" << endl;
	cout << "1." << first << endl;
	cout << "Bananas collected: " << firsthighscore << endl;
	cout << "2." << second << endl;
	cout << "Bananas collected: " << secondhighscore << endl;
	cout << "**************************" << endl;
	cout << "Press 0 to go back to title" << endl;
	char index;
	while(index != '0'){
		cin >> index;
		if(index == '0'){
			break;
		}
	}
	system("cls");
	title();
}

void credit(){
	cout << "*****************************" << endl;
	cout << "Made by: 20473370 Hangsun CHO" << endl;
	cout << "*****************************" << endl;
	cout << "Press 0 to go back to title" << endl;
	char index;
	cin >> index;
	while(index !='0'){
		cin >> index;
		if(index == '0'){
			break;
		}
	}
	system("cls");
	title();

}

void exitgame(){
	exit(0);
}




void print(char arr1[30][21]){
	cout << "_______________________" << endl;
	for(int i = 0; i<30; i++){
		cout << "|";
		for(int j = 0; j<21; j++){
			cout << arr1[i][j];
		}
		cout << "|" << endl;
	}
	cout <<"|@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "\n" << "Name: " << minion1.name << endl;
	cout << "Current score: " << minion1.banana << endl;
	cout << "Difficulty: " << minion1.difficulty << endl;

}


void checkdeath(bool& x){
	x = true;
}


void fallbanana(char arr1[30][21]){
		for(int i = 29; i>-1; i--){
			for(int j = 20; j>-1; j--){
				if(i == 28 && arr1[i][j] == ')' && arr1[i+1][j] == 'M'){
					minion1.banana++;
					arr1[i][j] = ' ';
				}else if(i == 28 && arr1[i][j] == 'B' && arr1[i+1][j] == 'M'){
					checkdeath(death);
					arr1[i][j] = ' ';
				}
				else if(i == 29 && (arr1[i][j] == ')' || arr1[i][j] == 'B')){
					arr1[i][j] = ' ';
				}else if(arr1[i][j] == ')'){
					arr1[i][j] = ' ';
					arr1[i+1][j] = ')';
				}else if(arr1[i][j] == 'B'){
					arr1[i][j] = ' ';
					arr1[i+1][j] = 'B';
				}
			}
		}
	}


void move(char arr[30][21]){
	int pos;
	for(int i = 0; i<21; i++){
		if(arr[29][i] == 'M'){
			pos = i;
		}
	}
	if(kbhit()){
		char key = ' ';
		key = _getch();
		switch (key){
		case 'a':
		case 'A':
			if(pos!=0){
				arr[29][pos] = ' ';
				pos--;
			}
			break;
		case 'd':
		case 'D':
			if(pos!=20){
				arr[29][pos] = ' ';
				pos++;
			}
			break;
		default:
			break;
		}
		while(kbhit())
			getch();
	}
	if(arr[29][pos] == ')'){
		minion1.banana++;
	}
	arr[29][pos] = 'M';
}

void calculate(string name, int score){
	if(score > firsthighscore && score > secondhighscore){
		second = first;
		secondhighscore = firsthighscore;
		first = name;
		firsthighscore = score;
	}
	if(score < firsthighscore && score > secondhighscore){
		second = first;
		secondhighscore = score;
	}
}

void create(int index, char arr1[30][21]){
	int a = rand()%21;
	int b;
	switch(index){
	case 1:
		b = rand()%10;
		break;
	case 2:
		b = rand()%6;
		break;
	case 3:
		b = rand()%3;
		break;
	default:
		break;
	}
	if(b == 0){
		arr1[0][a] = 'B';
	}else{
		arr1[0][a] = ')';
	}


}



int main(){
	title();



}


