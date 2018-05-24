 /*
 * MinionTicTacToe.cpp
 *
 *  Created on: 2018. 3. 4.
 *      Author: Cho
 */


#include <iostream>
using namespace std;

/*
 * 기본 판은 4x4 의 ---- 2d array
 * 세가지 기호: O / X / Y
 * 세로, 가로 옵션 입력하면 받아서 (1.2.3.4, 1.2.3.4) 해당하는 타일에 입력 (array는 0.1.2.3 이니까 1 빼주기)
 * 만약 그 자리에 이미 누가 놨으면 (-가 아니면): invalid, 다시하기
 * 각 플레이어가 놓을 때 마다 check 함수 돌리기
 * check 함수: 어떤 column 이나 row 든 (for문 사용) 3 consecutive icons (123이 같거나 234가 같거나) 하면 int로 return (0 = default 1 = player1 2 = player2 3 = player3)
 *
 *
 *
 *
 */

// 4*4 2d array print function
void print(char arr[4][4]){
	for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				cout << arr[i][j];
				if(j == 3)
					continue;
				cout << " ";
			}
			cout << "\n";
		}
}


/* array check function
 *
 */
int check(char arr[4][4]){
	char check = '-';
	for(int i = 0; i<4; i++){
		if(arr[i][1] != '-' && arr[i][1] == arr[i][2] && (arr[i][0] == arr[i][1] || arr[i][3] == arr[i][1])){
			check = arr[i][1];
		}
		if(arr[1][i] != '-' && arr[1][i] == arr[2][i] && (arr[0][i] == arr[1][i] || arr[3][i] == arr[1][i])){
			check = arr[1][i];
		}

	}
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			if(arr[i][j] != '-' && arr[i][j] == arr[i+1][j+1] && arr[i][j] == arr[i+2][j+2]){
				check = arr[i][j];
			}
		}
	}
	for(int i = 0; i<2; i++){
		for(int j = 2; j<4; j++){
			if(arr[i][j] != '-' && arr[i][j] == arr[i+1][j-1] && arr[i][j] == arr[i+2][j-2]){
				check = arr[i][j];
			}
		}
	}

	switch (check){
		case 'O':
			return 1;
		case 'X':
			return 2;
		case 'Y':
			return 3;
		default:
			return 0;
	}
}

void input(char symbol, char arr[4][4]){
	int row;
	int column;
	int i = 0;
	while(i==0){
		cin >> row;
		cin >> column;

		if(row > 4 || row < 1 || column > 4 || column < 1){
			cout << "Invalid position!" << endl;
			continue;
		}
		if(arr[row-1][column-1] != '-'){
			cout << "Invalid position!" << endl;
			continue;
		}
		i = 2;
	}
	cout << "Placed " << symbol << " on " << "row: " << row << " column: " << column << "." << endl;
	--row;
	--column;
	arr[row][column] = symbol;
}

int main(){
	// 게임 시작 전 설명
	cout << "Welcome to the game of Minion Tic Tac Toe! \n" << endl;
	cout << "Three players will play this game. Each player is assigned a symbol. Player 1: O, Player 2: X, Player 3: Y. \n" << endl;
	cout << "The game board is a 4 x 4 square. Each player gets to place his symbol on one tile of the board. \n" << endl;
	cout << "The first player who completes a row of 3 same symbols will win the game!" << endl;

	char board[4][4] = {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'};
	int winner = 0;
	while(winner == 0){
		int draw = 0;
		//Player 1
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "Player 1, please type the row and column you would like to place your symbol on." << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		print(board);
		input('O', board);
		winner = check(board);
		if(winner == 1 || winner == 2 || winner == 3)
			break;
		//Player 2
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "Player 2, please type the row and column you would like to place your symbol on." << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		print(board);
		input('X', board);
		winner = check(board);
		if(winner == 1 || winner == 2 || winner == 3)
			break;
		//Player 3
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "Player 3, please type the row and column you would like to place your symbol on." << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		print(board);
		input('Y', board);
		winner = check(board);
		if(winner == 1 || winner == 2 || winner == 3)
			break;
		for(int i = 0; i<5; i++){
			for(int j = 0; j<5; j++){
				if(board[i][j] == 'O' || board[i][j] == 'X' || board[i][j] == 'Y')
					draw++;
			}
		}
		if(draw == 16){
			cout << "Nobody wins!" << endl;
			return 0;
		}
	}
	print(board);
	cout << "-----------------------------------------------------------------------" << endl;
	switch(winner){
	case 1:
		cout << "Congratulations! Player 1 has won!" << endl;
		break;
	case 2:
		cout << "Congratulations! Player 2 has won!" << endl;
		break;
	case 3:
		cout << "Congratulations! Player 3 has won!" << endl;
		break;
	}


}
