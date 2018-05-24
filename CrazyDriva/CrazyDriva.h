/*
 * CrazyDriva.h
 *
 *  Created on: 2018. 4. 27.
 *      Author: Cho
 */


#ifndef CRAZYDRIVA_H_
#define CRAZYDRIVA_H_

#include <iostream>
#include <cstring>
#include <cstring>
using namespace std;

void setboard(char[20][20]);
void printboard(char[20][20]);
void title();
void start();
void howtoplay();
void exit();

struct obstacle{
	string name;
	obstacle* next;
};


class competitor{
	private:
		string name;
		int xpos;
		int ypos;
		int score;
		char symbol;
		obstacle* point;
		char prev;

	public:
	// COSNTRUCTORS
		competitor();
		competitor(string n, int x, int y, int sc, char s, obstacle* head, char p);
	// MUTATOR
		void set(string n, int x, int y, int sc, char s, obstacle* head, char p);
		void move(char index, char board[20][20]);
		void enemymove(char board[20][20]);
		void showscore();
		int returnX(char board[20][20]);
		int returnY(char board[20][20]);
		void print();


};






#endif /* CRAZYDRIVA_H_ */

















