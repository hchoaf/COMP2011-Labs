/*
 * GrabaGraba.cpp
 *
 *  Created on: 2018. 4. 13.
 *      Author: Cho
 */

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <ctime>
#include <cstring>
#include <string.h>
#include <cmath>

using namespace std;

struct weapon{
	string name;
	int firepower;
	weapon* next;

};

struct minion{
	string name;
	int number;
	int score;
	weapon* w;
};


void title();
void howtoplay();
void start();
void exitgame();
void setboard(char[15][15]);
void printboard(minion*, minion*, minion*, int, char [15][15]);
void playermove(minion*, char, char, char[15][15]);
void createweapon(char [15][15]);
int calculatescore(minion*);
void scottmove(minion*, char[15][15]);
void zackmove(minion*, char[15][15]);
void printresult(minion*);
void winner(minion*, minion*, minion*);





void title(){
	cout << " ____________________________________________________________________________________________________________________" << endl;
	cout << "|                                                                                                                    |"<< endl;
	cout << "|     GGGGGG   RRRRRRR      AAAA     BBBBBBB      AAAA          GGGGGG   RRRRRRR      AAAA     BBBBBBB      AAAA     |"<< endl;
	cout << "|    G         R      R    A    A    B      B    A    A        G         R      R    A    A    B      B    A    A    |"<< endl;
	cout << "|   G          R      R   A      A   B      B   A      A      G          R      R   A      A   B      B   A      A   |"<< endl;
	cout << "|   G          RRRRRRR    A      A   BBBBBBB    A      A      G          RRRRRRR    A      A   BBBBBBB    A      A   |"<< endl;
	cout << "|   G   GGGG   R  R       AAAAAAAA   B      B   AAAAAAAA      G   GGGG   R  R       AAAAAAAA   B      B   AAAAAAAA   |"<< endl;
	cout << "|   G      G   R   R      A      A   B      B   A      A      G      G   R   R      A      A   B      B   A      A   |"<< endl;
	cout << "|    G     G   R    R     A      A   B      B   A      A       G     G   R    R     A      A   B      B   A      A   |"<< endl;
	cout << "|     GGGGGG   R     R    A      A   BBBBBBB    A      A        GGGGGG   R     R    A      A   BBBBBBB    A      A   |"<< endl;
	cout << "|____________________________________________________________________________________________________________________|"<< endl;
	cout << "___________________________________________________"<< endl;
	cout << "|              |                    |             |" << endl;
	cout << "|   1. Start   |   2. How to Play   |   3. Exit   |" << endl;
	cout << "|______________|____________________|_____________|" << endl;
	char index;
	while(index != '1' && index != '2' && index != '3'){
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
			exitgame();
			break;
		default:
			break;
		}

	}
}



void howtoplay(){

	cout << "**************************************************************************************************" << endl;
	cout << "You, minion Scott, and minion Zack will try to collect as many weapons as they can!" << endl;
	cout << "Each weapon has different power: It increases from Axe (A) to JavelinThrower(J)" << endl;
	cout << "Each time a player collects a weapon, it will be collected to his collection of weapons. " << endl;
	cout << "Scott is dumb and move at random, while Zack follows the nearest weapon to him." << endl;
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
}


void exitgame(){
	exit(0);
}

void start(){
	minion* player = new minion;
	cout << "What is your name?" << endl;
	string playername;
	cin >> playername;
	player->name = playername;
	player->number = 0;
	player->score = 0;
	weapon* playerhead = new weapon;
	player->w = playerhead;
	playerhead->firepower = 0;
	playerhead->name = "void";
	playerhead->next = nullptr;

	minion* scott = new minion;
	scott->name = "Scott";
	weapon* scotthead = new weapon;
	scott->w = scotthead;
	scott->number = 0;
	scott->score = 0;
	scotthead->firepower = 0;
	scotthead->name = "void";
	scotthead->next = nullptr;

	minion* zack = new minion;
	zack->name = "Zack";
	weapon* zackhead = new weapon;
	zack->w = zackhead;
	zack->number = 0;
	zack->score = 0;
	zackhead->firepower = 0;
	zackhead->name = "void";
	zackhead->next = nullptr;

	char board[15][15];
	setboard(board);


	cout << "Press 1 to start" << endl;
	char startindex;
	while(startindex != '1'){
		cin >> startindex;
	}
	int round = 1;

	while(round < 16){
		createweapon(board);
		printboard(player, scott, zack, round, board);
		cout << "W: Up, A: Left, S: Down, D: Right" << endl;
		char playermoveindex = ' ';
		cin >> playermoveindex;
		playermove(player, 'P', playermoveindex, board);
		system("cls");
		printboard(player, scott, zack, round, board);
		cout << "Scott is moving.." << endl;
		Sleep(500);
		system("cls");
		if(round == 1){
			playermove(scott, 'S', 'W', board);
		}else if(round == 2){
			playermove(scott, 'S', 'A', board);
		}else{
			scottmove(scott, board);
		}
		printboard(player, scott, zack, round, board);
		Sleep(1000);
		cout << "Zack is moving.." << endl;
		Sleep(500);
		system("cls");
		zackmove(zack, board);
		printboard(player, scott, zack, round, board);
		Sleep(1000);
		system("cls");
		round++;
	}

	player->score = calculatescore(player);
	scott->score = calculatescore(scott);
	zack->score = calculatescore(zack);


	printresult(player);
	cout << player->name << "'s score is " << player->score << endl;
	printresult(scott);
	cout << scott->name << "'s score is " << scott->score << endl;
	printresult(zack);
	cout << zack->name << "'s score is " << zack->score << endl;
	Sleep(6000);
	system("cls");
	winner(player, scott, zack);
	Sleep(6000);
	system("cls");
	cout << "Press 0 to go back to title" << endl;
	char gobackindex = ' ';
	while(gobackindex != '0'){
		cin >> gobackindex;
	}
	title();


}

void playermove(minion* minion, char character, char index, char arr[15][15]){
	int xpos;
	int ypos;
	for(int i = 0; i<15; i++){
		for(int j = 0; j<15; j++){
			if(arr[i][j] == character){
				xpos = i;
				ypos = j;
			}
		}
	}
	arr[xpos][ypos] = ' ';
	switch(index){
	case 'A':
	case 'a':
		if(ypos!=0)
			ypos--;
		break;
	case 'W':
	case 'w':
		if(xpos!=0)
			xpos--;
		break;
	case 'D':
	case 'd':
		if(ypos != 14)
			ypos++;
		break;
	case 'S':
	case 's':
		if(xpos != 14)
			xpos++;
		break;
	}
	if(arr[xpos][ypos] != ' '){
		weapon* newweapon = new weapon;
		newweapon->next = minion->w;
		minion->w = newweapon;
		switch(arr[xpos][ypos]){
		case 'J':
			newweapon->name = "JavelinThrower";
			newweapon->firepower = 10;
			minion->number++;
			break;
		case 'I':
			newweapon->name = "IceRay";
			newweapon->firepower = 9;
			minion->number++;
			break;
		case 'H':
			newweapon->name = "Hypnotizer";
			newweapon->firepower = 8;
			minion->number++;
			break;
		case 'G':
			newweapon->name = "Grenade";
			newweapon->firepower = 7;
			minion->number++;
			break;
		case 'F':
			newweapon->name = "FlameThrower";
			newweapon->firepower = 6;
			minion->number++;
			break;
		case 'E':
			newweapon->name = "Extinguisher";
			newweapon->firepower = 5;
			minion->number++;
			break;
		case 'D':
			newweapon->name = "Dynamite";
			newweapon->firepower = 4;
			minion->number++;
			break;
		case 'C':
			newweapon->name = "Cleaver";
			newweapon->firepower = 3;
			minion->number++;
			break;
		case 'B':
			newweapon->name = "Bomb";
			newweapon->firepower = 2;
			minion->number++;
			break;
		case 'A':
			newweapon->name = "Axe";
			newweapon->firepower = 1;
			minion->number++;
			break;
		}
	}

	arr[xpos][ypos] = character;

}

void setboard(char arr[15][15]){
	for(int i = 0; i<15; i++){
		for(int j = 0; j<15; j++){
			arr[i][j] = ' ';
		}
	}
	arr[0][0] = 'P';
	arr[14][14] = 'S';
	arr[0][14] = 'Z';
}


void zackmove(minion* zack, char arr[15][15]){
	int zackxpos = 0;
	int zackypos = 0;

	for(int i = 0; i<15; i++){
		for(int j = 0; j<15; j++){
			if(arr[i][j] == 'Z'){
				zackxpos = i;
				zackypos = j;
			}
		}
	}


	int maxxpos = 14;
	int maxypos = 0;
	for(int k = 0; k<15; k++){
		for(int l = 0; l<15; l++){
			if(arr[k][l] != 'P' && arr[k][l] != 'Z' && arr[k][l] != 'S' && arr[k][l] != ' '){
				if(sqrt((maxxpos-zackxpos)*(maxxpos-zackxpos)+(maxypos-zackypos)*(maxypos-zackypos)) > sqrt((k-zackxpos)*(k-zackxpos)+(l-zackypos)*(l-zackypos))){

					maxxpos = k;
					maxypos = l;
				}

			}
		}
	}

	if(maxxpos > zackxpos){
		playermove(zack, 'Z', 'S', arr);
	}else if(maxxpos < zackxpos){
		playermove(zack, 'Z', 'W', arr);
	}else if(maxypos > zackypos){
		playermove(zack, 'Z', 'D', arr);
	}else if(maxypos < zackypos){
		playermove(zack, 'Z', 'A', arr);
	}


}


void printboard(minion* player, minion* scott, minion* zack, int round, char arr[15][15]){
	cout << "Round " << round << "!!!" << endl;
	cout << "_________________________________     _____________________" << endl;
	cout << "|                               |     | A: Axe            |" << endl;
	cout << "| ";
	for(int j = 0; j<15; j++){
		cout << arr[0][j] << " ";
	}
	cout << "|     | B: Bomb           |" << endl;
	cout << "| ";
	for(int j = 0; j<15; j++){
		cout << arr[1][j] << " ";
	}
	cout << "|     | C: Cleaver        |" << endl;
	cout << "| ";
	for(int j = 0; j<15; j++){
		cout << arr[2][j] << " ";
	}
	cout << "|     | D: Dynamite       |" << endl;
	cout << "| ";
	for(int j = 0; j<15; j++){
		cout << arr[3][j] << " ";
	}
	cout << "|     | E: Extinguisher   |" << endl;
	cout << "| ";
	for(int j = 0; j<15; j++){
		cout << arr[4][j] << " ";
	}
	cout << "|     | F: FlameThrower   |" << endl;
	cout << "| ";
	for(int j = 0; j<15; j++){
		cout << arr[5][j] << " ";
	}
	cout << "|     | G: Grenade        |" << endl;
	cout << "| ";
	for(int j = 0; j<15; j++){
		cout << arr[6][j] << " ";
	}
	cout << "|     | H: Hypnotizer     |" << endl;
	cout << "| ";
	for(int j = 0; j<15; j++){
		cout << arr[7][j] << " ";
	}
	cout << "|     | I: IceRay         |" << endl;
	cout << "| ";
	for(int j = 0; j<15; j++){
		cout << arr[8][j] << " ";
	}
	cout << "|     | J: JavelinThrower |" << endl;
	cout << "| ";
	for(int j = 0; j<15; j++){
		cout << arr[9][j] << " ";
	}
	cout << "|     |___________________|" << endl;
	for(int i = 10; i<15; i++){
		cout << "| ";
		for(int j = 0; j<15; j++){
			cout << arr[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "|_______________________________|" << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << player->name << " collected " << player->number << " weapons: ";
	for(weapon* p = player->w; p->next != nullptr; p = p->next){
		cout << p->name << " ";
	}
	cout << endl;
	cout << scott->name << " collected " << scott->number << " weapons: ";
	for(weapon* p = scott->w; p->next != nullptr; p = p->next){
		cout << p->name << " ";
	}
	cout << endl;
	cout << zack->name << " collected " << zack->number << " weapons: ";
	for(weapon* p = zack->w; p->next != nullptr; p = p->next){
		cout << p->name << " ";
	}
	cout << endl;
	cout << "***********************************************************************************************************************" << endl;
}

void scottmove(minion* minion, char arr[15][15]){
	int index = rand()%4;
	switch(index){
	case 0:
		playermove(minion, 'S', 'W', arr);
		break;
	case 1:
		playermove(minion, 'S', 'A', arr);
		break;
	case 2:
		playermove(minion, 'S', 'S', arr);
		break;
	case 3:
		playermove(minion, 'S', 'D', arr);
		break;
	}
}

void createweapon(char arr[15][15]){
	int c = rand()%10;
	switch(c){
	case 1:{
		int a = rand()%15;
		int b = rand()%15;
		if(arr[a][b] == ' '){
			arr[a][b] = 'J';
		}
	}
	case 2:{
		int a = rand()%15;
		int b = rand()%15;
		if(arr[a][b] == ' '){
			arr[a][b] = 'I';
		}
	}
	case 3:{
		int a = rand()%15;
		int b = rand()%15;
		if(arr[a][b] == ' '){
			arr[a][b] = 'H';
		}
	}
	case 4:{
		int a = rand()%15;
		int b = rand()%15;
		if(arr[a][b] == ' '){
			arr[a][b] = 'G';
		}
	}
	case 5:{
		int a = rand()%15;
		int b = rand()%15;
		if(arr[a][b] == ' '){
			arr[a][b] = 'F';
		}
	}
	case 6:{
		int a = rand()&15;
		int b = rand()%15;
		if(arr[a][b] == ' '){
			arr[a][b] = 'E';
		}
	}
	case 7:{
		int a = rand()%15;
		int b = rand()%15;
		if(arr[a][b] == ' '){
			arr[a][b] = 'D';
		}
	}
	case 8:{
		int a = rand()%15;
		int b = rand()%15;
		if(arr[a][b] == ' '){
			arr[a][b] = 'C';
		}
	}
	case 9:{
		int a = rand()%15;
		int b = rand()%15;
		if(arr[a][b] == ' '){
			arr[a][b] = 'B';
		}
	}
	case 10:{
		int a = rand()%15;
		int b = rand()%15;
		if(arr[a][b] == ' '){
			arr[a][b] = 'A';
		}
	}

	}

}

void winner(minion* player, minion* scott, minion* zack){
	if(player->score > scott->score && player->score > zack->score){
		cout << "The winner is " << player->name << " with score " << player->score << endl;
		if(scott->score > zack->score){
			cout << "The first runner up is " << scott->name << " with score " << scott->score << endl;
			cout << "The second runner up is " << zack->name << " with score " << zack->score << endl;
		}else if(zack->score > scott->score){
			cout << "The first runner up is " << zack->name << " with score " << zack->score << endl;
			cout << "The second runner up is " << scott->name << " with score " << scott->score << endl;
		}
	}else if(scott->score > player->score && scott->score > zack->score){
		cout << "The winner is " << scott->name << " with score " << scott->score << endl;
		if(player->score > zack->score){
			cout << "The first runner up is " << player->name << " with score " << player->score << endl;
			cout << "The second runner up is " << zack->name << " with score " << zack->score << endl;
		}else if(zack->score > scott->score){
			cout << "The first runner up is " << zack->name << " with score " << zack->score << endl;
			cout << "The second runner up is " << scott->name << " with score " << scott->score << endl;
		}
	}else if(zack->score > scott->score && zack->score > player->score){
		cout << "The winner is " << zack->name << " with score " << zack->score << endl;
		if(scott->score > player->score){
			cout << "The first runner up is " << scott->name << " with score " << scott->score << endl;
			cout << "The second runner up is " << player->name << " with score " << player->score << endl;
		}else if(player->score > scott->score){
			cout << "The first runner up is " << player->name << " with score " << player->score << endl;
			cout << "The second runner up is " << scott->name << " with score " << scott->score << endl;
		}
	}
}

int calculatescore(minion* minion){
	int score = 0;
	for(weapon* p = minion->w; p->next != nullptr; p = p->next){
		score = score + p->firepower;
	}
	return score;
}

void printresult(minion* minion){
	cout << minion->name << " collected " << minion->number << " weapons: ";
	for(weapon* p = minion->w; p->next != nullptr; p = p->next){
		cout << p->name << " ";
	}
	cout << endl;
}




int main(){
	title();

}


