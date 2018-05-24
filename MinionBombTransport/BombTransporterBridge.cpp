/*
 * BombTransporterBridge.cpp
 *
 *  Created on: 2018. 2. 23.
 *      Author: Cho
 */

#include <iostream>
using namespace std;

/*
 	 EXPERT: A / NEWBIE: B
 */

void doublecross(char arr1[], char arr2[], char a, char b){
	//왼쪽 1번째
	char tempA;
	char tempB;
	for(int i = 0; i<6; i++){
		if(arr1[i] == a){
			tempA = arr1[i];
			for(int k = i; k<5; k++){
				arr1[k] = arr1[k+1];
			}
			arr1[5] = '0';
			break;
		}
	}
	//왼쪽 2번쨰
	for(int i = 0; i<6; i++){
		if(arr1[i] == b){
			tempB = arr1[i];
			for(int k = i; k<5; k++){
				arr1[k] = arr1[k+1];
			}
			arr1[5] = '0';
			break;
		}
	}
	//오른쪽 1번째
	for(int i = 0; i<6; i++){
		if(arr2[i] == '0'){
			arr2[i] = tempA;
			break;
		}
	}
	//오른쪽 2번째
	for(int i = 0; i<6; i++){
		if(arr2[i] == '0'){
			arr2[i] = tempB;
			break;
		}
	}
}

void singlecross(char arr1[], char arr2[], char a){
	//왼쪽 1번째
	char tempA;
	for(int i = 0; i<6; i++){
		if(arr1[i] == a){
			tempA = arr1[i];
			for(int k = i; k<5; k++){
				arr1[k] = arr1[k+1];
			}
			arr1[5] = '0';
			break;
		}
	}
	//오른쪽 1번째
	for(int i = 0; i<6; i++){
		if(arr2[i] == '0'){
			arr2[i] = tempA;
			break;
		}
	}
}

void print(char arr[]){
	for(int i = 0; i<6; i++){
		cout << arr[i];
		if(i == 5){
			cout << endl;
			break;
		}
		cout << ", ";
	}
}

bool check(char arr1[]){
	int countA = 0;
	int countB = 0;
	for(int i = 0; i<6; i++){
		if(arr1[i] == 'E'){
			countA++;
		}
		if(arr1[i] == 'N'){
			countB++;
		}
	}
	return (countA != 0 && countA < countB);
}



int main(){
	// Game Description
	cout << "Welcome to the game of Bomb_Transporter_Bridge!" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "There is a team of 6 Minion Bomb Transporters, and you must direct them across a high narrow bridge. 3 Minions are experts, but the other 3 are newbies." << endl;
	cout << "The bridge can only take the weight of 1 or 2 Minions at at time, and it's dark!" << endl;
	cout << "Minions only have a single lantern that must be carried with each crossing to light the way across!" << endl;
	cout << "Even worse, when newbies and experts are both together on one side and newbies outnumber experts, the bombs go off and everybody dies!" << endl;
	cout << "Experts are shown as alphabet E, and newbies are shown as alphabet N. Empty space is shown as number 0." << endl;
	cout << "Try to cross the bridge as quickly as you could!" << endl;
	cout << "Now Let's start the game! Press 1." << endl;
	int start;
	cin >> start;
	if(start != 1){
		cout << "GAME OVER! Press RUN to restart!" << endl;
		return 0;
	}
	cout << "Each time you move minion(s), the system will show you current status (left and right), and the time spent.\nIt takes 5 minutes for a minion to move across the bridge." << endl;
	// Variable Initialize
	char left[6] = {'E', 'E', 'E', 'N', 'N', 'N'};
	char right[6] = {'0', '0', '0', '0', '0', '0'};
	int time = 0;
	// done값 설정 (오른쪽에 있는 0의 갯수)



	while(1){
		int done = 0;
		int minionNumber;
		char pos1;
		char pos2;
		char minion1;
		char minion2;
		cout << "\n";
		cout << "------------Current status------------" << endl;
		cout << "Left: ";
		print(left);
		cout << "Right: ";
		print(right);
		cout << "Time spent: " << time << endl;
		cout << "\n";


		cout << "Type the number of minions you would like to move: ";
		cin >> minionNumber;
			// Case 1: 1 minion moves
		if(minionNumber == 1){
			cout << "First type the position from which you will take the minions (left: L, right: R): ";
			cin >> pos1;
			if(pos1 != 'L' && pos1 != 'R'){
				cout << "Invalid position!" << endl;
				continue;
			}
			cout << "Now type the position to which you will take the minions (left: L, right: R): ";
			cin >> pos2;
			if(pos2 != 'L' && pos2 != 'R'){
				cout << "Invalid position!" << endl;
				continue;
			}
			if(pos1 == pos2){
				cout << "Nothing happens!" << endl;
				continue;
			}
			cout << "Now type the minion you would like to move (Expert: E, Newbie: N): ";
			cin >> minion1;
			if(minion1 != 'E' && minion1 != 'N'){
				cout << "Invalid minion!" << endl;
				continue;
			}
			if(pos1 == 'L' && pos2 == 'R'){
				singlecross(left, right, minion1);
				time += 5;
			} else if (pos1 == 'R' && pos2 == 'L'){
				singlecross(right, left, minion1);
				time += 5;
			}
			// Case 2: 2 minion move
		} else if(minionNumber == 2){
			cout << "First type the position from which you will take the minions (left: L, right: R): ";
			cin >> pos1;
			if(pos1 != 'L' && pos1 != 'R'){
			cout << "Invalid position!" << endl;
				continue;
			}
			cout << "Now type the position to which you will take the minions (left: L, right: R): ";
			cin >> pos2;
			if(pos2 != 'L' && pos2 != 'R'){
				cout << "Invalid position!" << endl;
				continue;
			}
			if(pos1 == pos2){
				cout << "Nothing happens!" << endl;
				continue;
			}
			cout << "Now type 2 minions you would like to move (Expert: E, Newbie: N): ";
			cin >> minion1;
			cin >> minion2;
			if(minion1 != 'E' && minion1 != 'N' && minion2 != 'E' && minion2 != 'N'){
				cout << "Invalid minion!" << endl;
				continue;
			}
			if(pos1 == 'L' && pos2 == 'R'){
				doublecross(left, right, minion1, minion2);
				time += 5;
			} else if (pos1 == 'R' && pos2 == 'L'){
				doublecross(right, left, minion1, minion2);
				time += 5;
			}
						// Cas
		} else{
			cout << "Invalid number of minions! The bridge is broken! GAME OVER!" << endl;
			break;
			return 0;
		}

		if(check(left) || check(right)){
			cout << "There are more newbies than experts in one side of the bridge! Bomb goes off and everybody dies! GAME OVER!" << endl;
			break;
			return 0;
		}
		for(int i = 0; i<6; i++){
			if(left[i] == '0')
				done++;
		}
		if(done == 6){
			cout << "Congratulations! All minions have safely crossed the bridge without detonating the bomb!" << endl;
			break;
		}
	}


	return 0;

}
