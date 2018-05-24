/*
 * CrazyDriva.cpp
 *
 *  Created on: 2018. 4. 27.
 *      Author: Cho
 */



#include <iostream>
#include "CrazyDriva.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <cstring>
#include <ctime>

using namespace std;


bool gameoverindex = false;


obstacle* obstaclehead = new obstacle;
competitor player("Player", 19, 19, 0, 'P', obstaclehead, ' ');
competitor enemy1("Enemy1", 0, 0, 0, 'E', obstaclehead, ' ');





competitor::competitor(){
	name = "void";
	xpos = 0;
	ypos = 0;
	score = 0;
	symbol = '*';
	point = nullptr;
	prev = ' ';
}


competitor::competitor(string n, int x, int y, int sc, char s, obstacle* head, char p){
	set(n, x, y, sc, s, head, p);
}


void competitor::set(string n, int x, int y, int sc, char s, obstacle* head, char p){
	name = n;
	xpos = x;
	ypos = y;
	score = sc;
	symbol = s;
	point = head;
	prev = p;
}

bool isvalid(char board[20][20], int x, int y){
	if(x < 0 || x >20 || y<0 || y>20)
		return false;
	if(board[x][y] == '#')
		return false;
	return true;
}

void competitor::move(char index, char board[20][20]){
	for(int i = 0; i<20; i++){
		for(int j = 0; j<20; j++){
			if(board[i][j] == symbol){
				xpos = i;
				ypos = j;
			}
		}
	}


	board[xpos][ypos] = ' ';

	switch(index){
	case 'a':
	case 'A':
		if(ypos != 0 && board[xpos][ypos-1] != '#'){
			ypos--;
		}else{}
		break;
	case 'd':
	case 'D':
		if(ypos != 19 && board[xpos][ypos+1] != '#'){
			ypos++;
		}else{}
		break;
	case 'w':
	case 'W':
		if(xpos != 0 && board[xpos-1][ypos] != '#'){
			xpos--;
		}else{}
		break;
	case 's':
	case 'S':
		if(xpos != 19 && board[xpos+1][ypos] != '#'){
			xpos++;
		}else{}
		break;
	default:
		break;
	}

	if(board[xpos][ypos] == '*'){
		score++;
	}

	if(board[xpos][ypos] == 'C' || board[xpos][ypos] == 'T'){
		obstacle* newobstacle = new obstacle;
		newobstacle->next = point;
		point = newobstacle;
		if(board[xpos][ypos] == 'C'){
			newobstacle->name = "Can";
			score = score - 1;
		}
		if(board[xpos][ypos] == 'T'){
			newobstacle->name = "Tomato";
			score = score - 3;
		}
	}

	if(board[xpos][ypos] == 'E'){
		gameoverindex = true;
		return;
	}

	board[xpos][ypos] = symbol;

}



void competitor::showscore(){
	cout << "Score: " << score << endl;
}


void competitor::print(){
	cout << "Obstalces " << name << " has collected: ";
	for(obstacle* p = point; p->next != nullptr; p = p->next){
		cout << p->name << " ";
	}
	cout << endl;
}


void competitor::enemymove(char board[20][20]){
	int playerxpos;
	int playerypos;
	for(int i = 0; i<20; i++){
		for(int j = 0; j<20; j++){
			if(board[i][j] == 'P'){
				playerxpos = i;
				playerypos = j;
			}
		}
	}

	if(playerxpos > xpos){
		if(xpos != 19 && board[xpos+1][ypos] != '#'){
			board[xpos][ypos] = prev;
			xpos++;
			prev = board[xpos][ypos];
			if(board[xpos][ypos] == 'P'){
				gameoverindex = true;
			}
			board[xpos][ypos] = symbol;
			return;
		}
	}
	if(playerxpos < xpos){
		if(xpos != 0 && board[xpos-1][ypos] != '#'){
			board[xpos][ypos] = prev;
			xpos--;
			prev = board[xpos][ypos];
			if(board[xpos][ypos] == 'P'){
				gameoverindex = true;
			}
			board[xpos][ypos] = symbol;
			return;
		}
	}
	if(playerypos > ypos){
		if(ypos != 19 && board[xpos][ypos+1] != '#'){
			board[xpos][ypos] = prev;
			ypos++;
			prev = board[xpos][ypos];
			if(board[xpos][ypos] == 'P'){
				gameoverindex = true;
			}
			board[xpos][ypos] = symbol;
			return;
		}
	}
	if(playerypos < ypos){
		if(ypos != 0 && board[xpos][ypos-1] != '#'){
			board[xpos][ypos] = prev;
			ypos--;
			prev = board[xpos][ypos];
			if(board[xpos][ypos] == 'P'){
				gameoverindex = true;
			}
			board[xpos][ypos] = symbol;
			return;
		}
	}

	if(xpos != 19 && board[xpos+1][ypos] != '#'){
		board[xpos][ypos] = prev;
		xpos++;
		prev = board[xpos][ypos];
		if(board[xpos][ypos] == 'P'){
			gameoverindex = true;
		}
		board[xpos][ypos] = symbol;
		return;
	}
	if(xpos != 0 && board[xpos-1][ypos] != '#'){
		board[xpos][ypos] = prev;
		xpos--;
		prev = board[xpos][ypos];
		if(board[xpos][ypos] == 'P'){
			gameoverindex = true;
		}
		board[xpos][ypos] = symbol;
		return;
	}
	if(ypos != 19 && board[xpos][ypos+1] != '#'){
		board[xpos][ypos] = prev;
		ypos++;
		prev = board[xpos][ypos];
		if(board[xpos][ypos] == 'P'){
			gameoverindex = true;
		}
		board[xpos][ypos] = symbol;
		return;
	}
	if(ypos != 0 && board[xpos][ypos-1] != '#'){
		board[xpos][ypos] = prev;
		ypos--;
		prev = board[xpos][ypos];
		if(board[xpos][ypos] == 'P'){
			gameoverindex = true;
		}
		board[xpos][ypos] = symbol;
		return;
	}


}


void printboard(char arr[20][20]){
	cout << "######################" << endl;
	for(int i = 0; i<20; i++){
		cout << "#";
		for(int j = 0; j<20; j++){
			cout << arr[i][j];
		}
		cout << "#" << endl;
	}
	cout << "######################" << endl;
}







int main(){
	obstaclehead->name = "void";
	obstaclehead->next = nullptr;

	char board[20][20]	 = {
				{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
				{'*', '#', '*', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '*', '#', '*'},
				{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
				{'*', '#', '*', '#', '#', '#', '*', '#', '#', '#', '#', '#', '#', '*', '#', '#', '#', '*', '#', '*'},
				{'*', '#', '*', '#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#', '*', '#', '*'},
				{'*', '#', '*', '#', '*', '#', '#', '*', '#', '#', '#', '#', '*', '#', '#', '*', '#', '*', '#', '*'},
				{'*', '#', '*', '*', '*', '#', '*', '*', '*', '*', '*', '*', '*', '*', '#', '*', '*', '*', '#', '*'},
				{'*', '#', '*', '#', '*', '#', '*', '#', '#', '*', '*', '#', '#', '*', '#', '*', '#', '*', '#', '*'},
				{'*', '#', '*', '#', '*', '*', '*', '#', '*', '*', '*', '*', '#', '*', '*', '*', '#', '*', '#', '*'},
				{'*', '#', '*', '#', '*', '#', '*', '*', '*', '#', '#', '*', '*', '*', '#', '*', '#', '*', '#', '*'},
				{'*', '#', '*', '#', '*', '#', '*', '*', '*', '#', '#', '*', '*', '*', '#', '*', '#', '*', '#', '*'},
				{'*', '#', '*', '#', '*', '*', '*', '#', '*', '*', '*', '*', '#', '*', '*', '*', '#', '*', '#', '*'},
				{'*', '#', '*', '#', '*', '#', '*', '#', '#', '*', '*', '#', '#', '*', '#', '*', '#', '*', '#', '*'},
				{'*', '#', '*', '*', '*', '#', '*', '*', '*', '*', '*', '*', '*', '*', '#', '*', '*', '*', '#', '*'},
				{'*', '#', '*', '#', '*', '#', '#', '*', '#', '#', '#', '#', '*', '#', '#', '*', '#', '*', '#', '*'},
				{'*', '#', '*', '#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#', '*', '#', '*'},
				{'*', '#', '*', '#', '#', '#', '*', '#', '#', '#', '#', '#', '#', '*', '#', '#', '#', '*', '#', '*'},
				{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
				{'*', '#', '*', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '*', '#', '*'},
				{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
		};

	for(int i = 0; i<20; i++){
		for(int j = 0; j<20; j++){
			if(board[i][j] == '*'){
				board[i][j] = ' ';
			}
		}
	}




	cout << "You(P) will try to avoid enemies (E) and collect stars (*)!" << endl;
	cout << "You can also collect cans (C) and tomatoes (T), but they will reduce your score by 1 and 3 respectively!" << endl;
	cout << "You have 30 seconds to collect the stars! " << endl;
	cout << "Press 1 to start!" << endl;
	char startnum = ' ';
	while(startnum != '1'){
		cin >> startnum;
	}
	system("cls");
	cout << "Empty board" << endl;
	printboard(board);
	Sleep(3000);
	system("cls");

	for(int i = 0; i<20; i++){
		for(int j = 0; j<20; j++){
			if(board[i][j] == ' '){
				board[i][j] = '*';
				cout << "Placing stars on the board..." << endl;
				printboard(board);
				Sleep(0.1);
				system("cls");
			}
		}
	}
	printboard(board);
	Sleep(1000);
	for(int i = 0; i<10; i++){
		int a = rand()%20;
		int b = rand()%20;
		if(board[a][b] == '*'){
			cout << "Placing cans on the board..." << endl;
			board[a][b] = 'C';
			Sleep(100);
			system("cls");
		}
	}
	printboard(board);
	Sleep(1000);
	for(int i = 0; i<10; i++){
		int a = rand()%20;
		int b = rand()%20;
		if(board[a][b] == '*'){
			cout << "Placing tomatoes on the board..." << endl;
			board[a][b] = 'T';
			Sleep(100);
			system("cls");
		}
	}

	cout << "Placing Enemy and Player on the board... Enemy: E, Player: P..." << endl;
	board[0][0] = 'E';
	printboard(board);
	Sleep(1000);
	system("cls");
	board[19][19] = 'P';
	printboard(board);
	Sleep(1000);
	system("cls");

	char startstartnum = ' ';
	printboard(board);
	cout << "Press 1 to start! You have 30 seconds. " << endl;
	cout << "Move with W, A, S, D."  << endl;
	while(startstartnum != '1'){
		cin >> startstartnum;
	}

	time_t starttime = time(NULL);

	while(difftime(time(NULL), starttime) < 30 && !gameoverindex){
		player.showscore();
		player.print();
		printboard(board);
		cout << "Press W, A, S, or D" << endl;
		char index1 = ' ';
		cin >> index1;
		player.move(index1, board);
		enemy1.enemymove(board);
		system("cls");



	}

	if(gameoverindex){
		system("cls");
		cout << "You've been caught!" << endl;
		player.showscore();
		player.print();
		Sleep(3000);
	}else if(!gameoverindex){
		system("cls");
		cout << "Time's up!" << endl;
		player.showscore();
		player.print();
		Sleep(3000);
	}

	return 0;




}
