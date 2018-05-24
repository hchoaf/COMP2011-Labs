/*
 * MambaBomba.cpp
 *
 *  Created on: 2018. 4. 9.
 *      Author: Cho
 */

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <ctime>
#include <cstring>

using namespace std;

struct minion{
	string name;
	int bombnumber;
	int bombpower;
	int bomb1;
	int bomb2;
	int bomb3;
	int bomb4;
	int bomb5;
	int bomb6;
	int bomb7;
};





void start();
void howtoplay();
void exitgame();
void title();
void printgame(minion, minion);
bool dealerai(int, int);
void thinking();
void printnumber(int);
bool dealerchange(minion, minion);
void bomboff(int&, bool&);



void title(){
	cout << " _____________________________________________________________________________________________________________________________" << endl;
	cout << "|                                                                                                                             |"<< endl;
	cout << "|  M         M     AAAA     M         M   BBBBBBB      AAAA          BBBBBBB      OOOO     M         M   BBBBBBB      AAAA    |"<< endl;
	cout << "|  MM       MM    A    A    MM       MM   B      B    A    A         B      B    O    O    MM       MM   B      B    A    A   |"<< endl;
	cout << "|  M M     M M   A      A   M M     M M   B      B   A      A        B      B   O      O   M M     M M   B      B   A      A  |"<< endl;
	cout << "|  M M     M M   A      A   M M     M M   BBBBBBB    A      A        BBBBBBB    O      O   M M     M M   BBBBBBB    A      A  |"<< endl;
	cout << "|  M  M   M  M   AAAAAAAA   M  M   M  M   B      B   AAAAAAAA        B      B   O      O   M  M   M  M   B      B   AAAAAAAA  |"<< endl;
	cout << "|  M  M   M  M   A      A   M  M   M  M   B      B   A      A        B      B   O      O   M  M   M  M   B      B   A      A  |"<< endl;
	cout << "|  M   M M   M   A      A   M   M M   M   B      B   A      A        B      B    O    O    M   M M   M   B      B   A      A  |"<< endl;
	cout << "|  M    M    M   A      A   M    M    M   BBBBBBB    A      A        BBBBBBB      OOOO     M    M    M   BBBBBBB    A      A  |"<< endl;
	cout << "|_____________________________________________________________________________________________________________________________|"<< endl;
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


void start(){
	minion player = {" ", 0, 0, 0, 0, 0, 0, 0, 0, 0};
	minion dealer = {" ", 0, 0, 0, 0, 0, 0, 0, 0, 0};
	dealer.name = "Dealer";

	bool dealerhit = true;
	bool playerhit = true;
	bool dealerdeath = true;
	bool playerdeath = true;


	printgame(player, dealer);
	cout <<"Player, what is your name?" << endl;
	cin >> player.name;
	system("cls");

	printgame(player, dealer);
	cout << "Round 1!!" << endl;
	cout << "Press 1 to hit a bomb." << endl;
	char getbombindex;
	while(getbombindex != '1'){
		cin >> getbombindex;
		if(getbombindex == 1){
			break;
		}
	}

	thinking();
	player.bomb1 = 1+rand()%10;
	player.bombnumber++;
	player.bombpower += player.bomb1;

	system("cls");
	printgame(player, dealer);



	if(player.bomb1 == 1){
		cout << "You have 1-bomb. You can choose to use it as 1 or 11. Would you like to use 11 instead of 1? Y: YES   N: NO " << endl;
		char index1;
		while(index1 != 'Y' || index1 != 'y' || index1 != 'N' || index1 != 'n'){
			cin >> index1;
			if(index1 == 'Y' || index1 == 'y'){
				player.bomb1 = 11;
				player.bombpower += 10;
				cout << "You have chosen to use 11 instead of 1." << endl;
				break;
			}else if(index1 == 'N' || index1 == 'n'){
				break;
			}
		}
	}

	Sleep(3000);

	system("cls");
	printgame(player, dealer);
	cout <<"Dealer hits a bomb" << endl;
	thinking();
	dealer.bomb1 = 1+rand()%10;
	if(dealer.bomb1 == 1){
	}
	dealer.bombnumber++;
	dealer.bombpower += dealer.bomb1;

	system("cls");
	printgame(player, dealer);

	if(dealer.bomb1 == 1){
		cout <<"Dealer has 1-bomb. He will choose to use it as 1 or 11. Dealer is thinking." << endl;
		thinking();
		if(dealerchange(player, dealer)){
			dealer.bomb1 = 11;
			dealer.bombpower += 10;
			system("cls");
			printgame(player, dealer);
			cout << "Dealer has decided to use 11 instead of 1." << endl;
		}else{
			printgame(player, dealer);
			cout << "Dealer has decided to use 1." << endl;
		}
	}


	Sleep(3000);

	//Round 2
	system("cls");
	printgame(player, dealer);
	cout << "Round 2!!" << endl;
	if(!playerhit){
		cout << player.name << " has chosen to hold." << endl;
	}
	char hitindex1;
	if(playerhit && playerdeath){
		cout << player.name << ", please decide whether or not to hit the next bomb. Y: HIT   N: HOLD" << endl;
		while(hitindex1 != 'y' && hitindex1 != 'Y' && hitindex1 != 'N' && hitindex1 != 'n'){
			cin >> hitindex1;
			if(hitindex1 == 'y' || hitindex1 == 'Y'){
				playerhit = true;
				system("cls");
				printgame(player, dealer);
				cout << player.name << " has decided to hit." << endl;
				Sleep(1000);
				player.bomb2 = 1+rand()%10;
				player.bombnumber++;
				player.bombpower += player.bomb2;

				system("cls");
				printgame(player, dealer);
				if(player.bomb2 == 1){
					cout << "You have 1-bomb. You can choose to use it as 1 or 11. Would you like to use 11 instead of 1? Y: YES   N: NO " << endl;
					char index1;
					while(index1 != 'Y' || index1 != 'y' || index1 != 'N' || index1 != 'n'){
						cin >> index1;
						if(index1 == 'Y' || index1 == 'y'){
							player.bomb2 = 11;
							player.bombpower += 10;
							cout << "You have chosen to use 11 instead of 1." << endl;
							break;
						}else if(index1 == 'N' || index1 == 'n'){
							break;
						}
					}
					bomboff(player.bombpower, playerdeath);

				}
				break;
			}else if(hitindex1 == 'N' || hitindex1 == 'n'){
				playerhit = false;
				system("cls");
				printgame(player, dealer);
				cout << player.name << " has decided to hold." << endl;
				break;
			}
		}
	}
	Sleep(3000);

	system("cls");
	printgame(player, dealer);
	if(!dealerhit){
		cout << "Dealer has decided to hold." << endl;
	}
	if(dealerhit && dealerdeath){
		cout <<"Dealer is deciding whether or not to hit the next bomb." << endl;
		thinking();
		if(dealerai(dealer.bombpower, player.bombpower)){
			dealerhit = true;
			system("cls");
			printgame(player, dealer);
			cout <<"Dealer has decided to hit." << endl;
			Sleep(1000);
				dealer.bomb2 = 1+rand()%10;
				if(dealer.bomb1 == 1){
				}
				dealer.bombnumber++;
				dealer.bombpower += dealer.bomb2;
				system("cls");
				printgame(player, dealer);


				if(dealer.bomb2 == 1){
					cout <<"Dealer has 1-bomb. He will choose to use it as 1 or 11. Dealer is thinking." << endl;
					thinking();
					if(dealerchange(player, dealer)){
						dealer.bomb2 = 11;
						dealer.bombpower += 10;
						system("cls");
						printgame(player, dealer);
						cout << "Dealer has decided to use 11 instead of 1." << endl;
					}else{
						printgame(player, dealer);
						cout << "Dealer has decided to use 1." << endl;
					}
				}

		}else{
			dealerhit = false;
			system("cls");
			printgame(player, dealer);
			cout <<"Dealer has decided to hold." << endl;
		}
		bomboff(dealer.bombpower, dealerdeath);
	}

	Sleep(3000);


	//Round 3
	system("cls");
	printgame(player, dealer);
	cout << "Round 3!!" << endl;
	if(!playerhit){
		cout << player.name << " has chosen to hold." << endl;
	}
	char hitindex2;
	if(playerhit && playerdeath){
		cout << player.name << ", please decide whether or not to hit the next bomb. Y: HIT   N: HOLD" << endl;
		while(hitindex2 != 'y' && hitindex2 != 'Y' && hitindex2 != 'N' && hitindex2 != 'n'){
			cin >> hitindex2;
			if(hitindex2 == 'y' || hitindex2 == 'Y'){
				playerhit = true;
				system("cls");
				printgame(player, dealer);
				cout << player.name << " has decided to hit." << endl;
				Sleep(1000);
				player.bomb3 = 1+rand()%10;
				player.bombnumber++;
				player.bombpower += player.bomb3;
				system("cls");
				printgame(player, dealer);
				if(player.bomb3 == 1){
					cout << "You have 1-bomb. You can choose to use it as 1 or 11. Would you like to use 11 instead of 1? Y: YES   N: NO " << endl;
					char index1;
					while(index1 != 'Y' || index1 != 'y' || index1 != 'N' || index1 != 'n'){
						cin >> index1;
						if(index1 == 'Y' || index1 == 'y'){
							player.bomb3 = 11;
							player.bombpower += 10;
							cout << "You have chosen to use 11 instead of 1." << endl;
							break;
						}else if(index1 == 'N' || index1 == 'n'){
							break;
						}
					}
				}
				bomboff(player.bombpower, playerdeath);
				break;
			}else if(hitindex2 == 'N' || hitindex2 == 'n'){
				playerhit = false;
				system("cls");
				printgame(player, dealer);
				cout << player.name << " has decided to hold." << endl;
				break;
			}
		}
	}
	Sleep(3000);

	system("cls");
	printgame(player, dealer);
	if(!dealerhit){
			cout << "Dealer has decided to hold." << endl;
		}
	if(dealerhit && dealerdeath){
	cout <<"Dealer is deciding whether or not to hit the next bomb." << endl;
	thinking();
		if(dealerai(dealer.bombpower, player.bombpower)){
			dealerhit = true;
			system("cls");
			printgame(player, dealer);
			cout <<"Dealer has decided to hit." << endl;
			Sleep(1000);
				dealer.bomb3 = 1+rand()%10;
				dealer.bombnumber++;
				dealer.bombpower += dealer.bomb3;
				system("cls");
				printgame(player, dealer);


				if(dealer.bomb3 == 1){
					cout <<"Dealer has 1-bomb. He will choose to use it as 1 or 11. Dealer is thinking." << endl;
					thinking();
					if(dealerchange(player, dealer)){
						dealer.bomb3 = 11;
						dealer.bombpower += 10;
						system("cls");
						printgame(player, dealer);
						cout << "Dealer has decided to use 11 instead of 1." << endl;
					}else{
						printgame(player, dealer);
						cout << "Dealer has decided to use 1." << endl;
					}
				}
		}else{
			dealerhit = false;
			system("cls");
			printgame(player, dealer);
			cout <<"Dealer has decided to hold." << endl;
		}
		bomboff(dealer.bombpower, dealerdeath);
	}
	Sleep(3000);

	//ROUND 4

	system("cls");
	printgame(player, dealer);
	cout << "Round 4!!" << endl;
	if(!playerhit){
		cout << player.name << " has chosen to hold." << endl;
	}
	char hitindex3;
	if(playerhit && playerdeath){
		cout << player.name << ", please decide whether or not to hit the next bomb. Y: HIT   N: HOLD" << endl;
		while(hitindex3 != 'y' && hitindex3 != 'Y' && hitindex3 != 'N' && hitindex3 != 'n'){
			cin >> hitindex3;
			if(hitindex3 == 'y' || hitindex3 == 'Y'){
				playerhit = true;
				system("cls");
				printgame(player, dealer);
				cout << player.name << " has decided to hit." << endl;
				Sleep(1000);
				player.bomb4 = 1+rand()%10;
				player.bombnumber++;
				player.bombpower += player.bomb4;
				system("cls");
				printgame(player, dealer);
				if(player.bomb4 == 1){
					cout << "You have 1-bomb. You can choose to use it as 1 or 11. Would you like to use 11 instead of 1? Y: YES   N: NO " << endl;
					char index1;
					while(index1 != 'Y' || index1 != 'y' || index1 != 'N' || index1 != 'n'){
						cin >> index1;
						if(index1 == 'Y' || index1 == 'y'){
							player.bomb4 = 11;
							player.bombpower += 10;
							cout << "You have chosen to use 11 instead of 1." << endl;
							break;
						}else if(index1 == 'N' || index1 == 'n'){
							break;
						}
					}
				}
				bomboff(player.bombpower, playerdeath);
				break;

			}else if(hitindex3 == 'N' || hitindex3 == 'n'){
				playerhit = false;
				system("cls");
				printgame(player, dealer);
				cout << player.name << " has decided to hold." << endl;
				break;
			}
		}
	}
	Sleep(3000);

	system("cls");
	printgame(player, dealer);
	if(!dealerhit){
			cout << "Dealer has decided to hold." << endl;
		}
	if(dealerhit && dealerdeath){
	cout <<"Dealer is deciding whether or not to hit the next bomb." << endl;
	thinking();
		if(dealerai(dealer.bombpower, player.bombpower)){
			dealerhit = true;
			system("cls");
			printgame(player, dealer);
			cout <<"Dealer has decided to hit." << endl;
			Sleep(1000);
				dealer.bomb4 = 1+rand()%10;
				dealer.bombnumber++;
				dealer.bombpower += dealer.bomb4;
				system("cls");
				printgame(player, dealer);


				if(dealer.bomb4 == 1){
					cout <<"Dealer has 1-bomb. He will choose to use it as 1 or 11. Dealer is thinking." << endl;
					thinking();
					if(dealerchange(player, dealer)){
						dealer.bomb4 = 11;
						dealer.bombpower += 10;
						system("cls");
						printgame(player, dealer);
						cout << "Dealer has decided to use 11 instead of 1." << endl;
					}else{
						printgame(player, dealer);
						cout << "Dealer has decided to use 1." << endl;
					}
				}
		}else{
			dealerhit = false;
			system("cls");
			printgame(player, dealer);
			cout <<"Dealer has decided to hold." << endl;
		}
		bomboff(dealer.bombpower, dealerdeath);
	}

	Sleep(3000);


	// Round 5


	system("cls");
	cout << "Round 5!!" << endl;
	printgame(player, dealer);

	cout <<"Round 5!!" << endl;
	if(!playerhit){
		cout << player.name << " has chosen to hold." << endl;
	}
	char hitindex4;
	if(playerhit && playerdeath){
		cout << player.name << ", please decide whether or not to hit the next bomb. Y: HIT   N: HOLD" << endl;
		while(hitindex4 != 'y' && hitindex4 != 'Y' && hitindex4 != 'N' && hitindex4 != 'n'){
			cin >> hitindex4;
			if(hitindex4 == 'y' || hitindex4 == 'Y'){
				playerhit = true;
				system("cls");
				printgame(player, dealer);
				cout << player.name << " has decided to hit." << endl;
				Sleep(1000);
				player.bomb5 = 1+rand()%10;
				player.bombnumber++;
				player.bombpower += player.bomb5;
				system("cls");
				printgame(player, dealer);
				if(player.bomb5 == 1){
					cout << "You have 1-bomb. You can choose to use it as 1 or 11. Would you like to use 11 instead of 1? Y: YES   N: NO " << endl;
					char index1;
					while(index1 != 'Y' || index1 != 'y' || index1 != 'N' || index1 != 'n'){
						cin >> index1;
						if(index1 == 'Y' || index1 == 'y'){
							player.bomb5 = 11;
							player.bombpower += 10;
							cout << "You have chosen to use 11 instead of 1." << endl;
							break;
						}else if(index1 == 'N' || index1 == 'n'){
							break;
						}
					}
				}
				bomboff(player.bombpower, playerdeath);
				break;
			}else if(hitindex4 == 'N' || hitindex4 == 'n'){
				playerhit = false;
				system("cls");
				printgame(player, dealer);
				cout << player.name << " has decided to hold." << endl;

				break;
			}
		}
	}
	Sleep(3000);

	system("cls");
	printgame(player, dealer);
	if(!dealerhit){
			cout << "Dealer has decided to hold." << endl;
		}
	if(dealerhit && dealerdeath){
	cout <<"Dealer is deciding whether or not to hit the next bomb." << endl;
	thinking();
		if(dealerai(dealer.bombpower, player.bombpower)){
			dealerhit = true;
			system("cls");
			printgame(player, dealer);
			cout <<"Dealer has decided to hit." << endl;
			Sleep(1000);
				dealer.bomb5 = 1+rand()%10;
				dealer.bombnumber++;
				dealer.bombpower += dealer.bomb5;
				system("cls");
				printgame(player, dealer);


				if(dealer.bomb5 == 1){
					cout <<"Dealer has 1-bomb. He will choose to use it as 1 or 11. Dealer is thinking." << endl;
					thinking();
					if(dealerchange(player, dealer)){
						dealer.bomb5 = 11;
						dealer.bombpower += 10;
						system("cls");
						printgame(player, dealer);
						cout << "Dealer has decided to use 11 instead of 1." << endl;
					}else{
						printgame(player, dealer);
						cout << "Dealer has decided to use 1." << endl;
					}
				}
		}else{
			dealerhit = false;
			system("cls");
			printgame(player, dealer);
			cout <<"Dealer has decided to hold." << endl;
		}
		bomboff(dealer.bombpower, dealerdeath);
	}else

	Sleep(3000);

	//Round 6
	system("cls");
		cout << "Round 6!!" << endl;
		printgame(player, dealer);

		cout <<"Round 6!!" << endl;
		if(!playerhit){
			cout << player.name << " has chosen to hold." << endl;
		}
		char hitindex5;
		if(playerhit && playerdeath){
			cout << player.name << ", please decide whether or not to hit the next bomb. Y: HIT   N: HOLD" << endl;
			while(hitindex5 != 'y' && hitindex5 != 'Y' && hitindex5 != 'N' && hitindex5 != 'n'){
				cin >> hitindex5;
				if(hitindex5 == 'y' || hitindex5 == 'Y'){
					playerhit = true;
					system("cls");
					printgame(player, dealer);
					cout << player.name << " has decided to hit." << endl;
					Sleep(1000);
					player.bomb6 = 1+rand()%10;
					player.bombnumber++;
					player.bombpower += player.bomb6;
					system("cls");
					printgame(player, dealer);
					if(player.bomb6 == 1){
						cout << "You have 1-bomb. You can choose to use it as 1 or 11. Would you like to use 11 instead of 1? Y: YES   N: NO " << endl;
						char index1;
						while(index1 != 'Y' || index1 != 'y' || index1 != 'N' || index1 != 'n'){
							cin >> index1;
							if(index1 == 'Y' || index1 == 'y'){
								player.bomb6 = 11;
								player.bombpower += 10;
								cout << "You have chosen to use 11 instead of 1." << endl;
								break;
							}else if(index1 == 'N' || index1 == 'n'){
								break;
							}
						}
					}
					bomboff(player.bombpower, playerdeath);
					break;
				}else if(hitindex4 == 'N' || hitindex4 == 'n'){
					playerhit = false;
					system("cls");
					printgame(player, dealer);
					cout << player.name << " has decided to hold." << endl;

					break;
				}
			}
		}
		Sleep(3000);

		system("cls");
		printgame(player, dealer);
		if(!dealerhit){
				cout << "Dealer has decided to hold." << endl;
			}
		if(dealerhit && dealerdeath){
		cout <<"Dealer is deciding whether or not to hit the next bomb." << endl;
		thinking();
			if(dealerai(dealer.bombpower, player.bombpower)){
				dealerhit = true;
				system("cls");
				printgame(player, dealer);
				cout <<"Dealer has decided to hit." << endl;
				Sleep(1000);
					dealer.bomb6 = 1+rand()%10;
					dealer.bombnumber++;
					dealer.bombpower += dealer.bomb6;
					system("cls");
					printgame(player, dealer);


					if(dealer.bomb6 == 1){
						cout <<"Dealer has 1-bomb. He will choose to use it as 1 or 11. Dealer is thinking." << endl;
						thinking();
						if(dealerchange(player, dealer)){
							dealer.bomb6 = 11;
							dealer.bombpower += 10;
							system("cls");
							printgame(player, dealer);
							cout << "Dealer has decided to use 11 instead of 1." << endl;
						}else{
							printgame(player, dealer);
							cout << "Dealer has decided to use 1." << endl;
						}
					}
			}else{
				dealerhit = false;
				system("cls");
				printgame(player, dealer);
				cout <<"Dealer has decided to hold." << endl;
			}
			bomboff(dealer.bombpower, dealerdeath);
		}else

		Sleep(3000);

	// Round 7
		system("cls");
			cout << "Round 7!!" << endl;
			printgame(player, dealer);

			cout <<"Round 7!!" << endl;
			if(!playerhit){
				cout << player.name << " has chosen to hold." << endl;
			}
			char hitindex6;
			if(playerhit && playerdeath){
				cout << player.name << ", please decide whether or not to hit the next bomb. Y: HIT   N: HOLD" << endl;
				while(hitindex6 != 'y' && hitindex6 != 'Y' && hitindex6 != 'N' && hitindex6 != 'n'){
					cin >> hitindex6;
					if(hitindex6 == 'y' || hitindex6 == 'Y'){
						playerhit = true;
						system("cls");
						printgame(player, dealer);
						cout << player.name << " has decided to hit." << endl;
						Sleep(1000);
						player.bomb7 = 1+rand()%10;
						player.bombnumber++;
						player.bombpower += player.bomb7;
						system("cls");
						printgame(player, dealer);
						if(player.bomb7 == 1){
							cout << "You have 1-bomb. You can choose to use it as 1 or 11. Would you like to use 11 instead of 1? Y: YES   N: NO " << endl;
							char index1;
							while(index1 != 'Y' || index1 != 'y' || index1 != 'N' || index1 != 'n'){
								cin >> index1;
								if(index1 == 'Y' || index1 == 'y'){
									player.bomb7 = 11;
									player.bombpower += 10;
									cout << "You have chosen to use 11 instead of 1." << endl;
									break;
								}else if(index1 == 'N' || index1 == 'n'){
									break;
								}
							}
						}
						bomboff(player.bombpower, playerdeath);
						break;
					}else if(hitindex4 == 'N' || hitindex4 == 'n'){
						playerhit = false;
						system("cls");
						printgame(player, dealer);
						cout << player.name << " has decided to hold." << endl;

						break;
					}
				}
			}
			Sleep(3000);

			system("cls");
			printgame(player, dealer);
			if(!dealerhit){
					cout << "Dealer has decided to hold." << endl;
				}
			if(dealerhit && dealerdeath){
			cout <<"Dealer is deciding whether or not to hit the next bomb." << endl;
			thinking();
				if(dealerai(dealer.bombpower, player.bombpower)){
					dealerhit = true;
					system("cls");
					printgame(player, dealer);
					cout <<"Dealer has decided to hit." << endl;
					Sleep(1000);
						dealer.bomb7 = 1+rand()%10;
						dealer.bombnumber++;
						dealer.bombpower += dealer.bomb7;
						system("cls");
						printgame(player, dealer);


						if(dealer.bomb7 == 1){
							cout <<"Dealer has 1-bomb. He will choose to use it as 1 or 11. Dealer is thinking." << endl;
							thinking();
							if(dealerchange(player, dealer)){
								dealer.bomb7 = 11;
								dealer.bombpower += 10;
								system("cls");
								printgame(player, dealer);
								cout << "Dealer has decided to use 11 instead of 1." << endl;
							}else{
								printgame(player, dealer);
								cout << "Dealer has decided to use 1." << endl;
							}
						}
				}else{
					dealerhit = false;
					system("cls");
					printgame(player, dealer);
					cout <<"Dealer has decided to hold." << endl;
				}
				bomboff(dealer.bombpower, dealerdeath);
			}else

			Sleep(3000);


			system("cls");
			cout << "Dealer  Bombs hit: " << dealer.bombnumber << " Total BombPower: " << dealer.bombpower << endl;
			cout << player.name << "  Bombs hit: " << player.bombnumber << " Total BombPower: " << player.bombpower << endl;
			Sleep(3000);
			if(dealer.bombpower > player.bombpower){
				cout << "Dealer has won with "<< dealer.bombpower << "!" << endl;
			}else if(player.bombpower > dealer.bombpower){
				cout << player.name << " has won with " << player.bombpower << "!" << endl;
			}else if(player.bombpower == dealer.bombpower && player.bombnumber > dealer.bombnumber){
				cout << player.name << " and dealer has same bombpower, but " << player.name << " has hit less number of bombs, so " << player.name << " has won!" << endl;
			}else if(player.bombpower == dealer.bombpower && player.bombnumber > dealer.bombnumber){
				cout << player.name << " and dealer has same bombpower, but dealer has hit less number of bombs, so dealer has won!" << endl;
			}else if(player.bombpower == dealer.bombpower && player.bombnumber == dealer.bombnumber){
				cout << player.name << " and dealer has same bombpower and same bombnumber. Nobody has won!" << endl;
			}
			Sleep(3000);
			cout << "\n" << endl;
			char goback = ' ';
			while(goback != '1'){
				cout << "Press 1 to go back to title." << endl;
				cin >> goback;
				if(goback == '1'){
					title();
					break;
				}
			}



	}




bool dealerchange(minion player, minion dealer){
	if(dealer.bombpower < 4 || dealer.bombpower == 11){
		return true;
	}else if(dealer.bombpower+10 < player.bombpower && dealer.bombpower < 11){
		return false;
	}else{
		return false;
	}
}




void howtoplay(){

	cout << "**************************************************************************************************" << endl;
	cout << "You and a dealer will play a game of blackjack using bombs!" << endl;
	cout << "Each time you hit a bomb, it will show bombpower from 1 to 10!" << endl;
	cout << "1-minibomb can be used as either 1 or 11!" << endl;
	cout << "Your goal is to get the total bombpower 21. If the total bombpower exceeds 21, bombs will go off and the total bombpower will become 0!" << endl;
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


void bomboff(int& bomb, bool& death){
	if(bomb > 21){
		cout << "Total bombpower exceeded 21! Bomb goes off and total bombpower becomes 0!" << endl;
		bomb = 0;
		death = false;
	}
}


void printgame(minion player, minion dealer){
	cout << "Dealer  Bombs hit: " << dealer.bombnumber << " Total BombPower: " << dealer.bombpower << endl;
	cout << player.name << "  Bombs hit: " << player.bombnumber << " Total BombPower: " << player.bombpower << endl;
	cout << "                                         ________                                              " << endl;
	cout << "                                        /        \\                                             " << endl;
	cout << "                                       /   ____   \\                                            " << endl;
	cout << "                                      |   / __ \\   |                                           " << endl;
	cout << "                                      |==| |__| |==|                                           " << endl;
	cout << "                                      |   \\____/   |                                           " << endl;
	cout << "                                      |            |                                           " << endl;
	cout << "                                      |   \\____/   |                                           " << endl;
	cout << "          ____________________________|____________|____________________________               " << endl;
	cout << "         /    __                                                                \\              " << endl;
	cout << "        /    /  \\      /  \\      /  \\      /  \\      /  \\      /  \\      /  \\    \\             " << endl;
	cout << "       /   _|_  **   _|_  **   _|_  **   _|_  **   _|_  **   _|_  **   _|_  **    \\            " << endl;
	cout << "      /   /   \\     /   \\     /   \\     /   \\     /   \\     /   \\     /   \\        \\           " << endl;
	cout << "     /   /     \\   /     \\   /     \\   /     \\   /     \\   /     \\   /     \\        \\          " << endl;
	cout << "    /    \\  ";
	printnumber(dealer.bomb1);
	cout <<" /   \\  ";
	printnumber(dealer.bomb2);
	cout <<" /   \\  ";
	printnumber(dealer.bomb3);
	cout <<" /   \\  ";
	printnumber(dealer.bomb4);
	cout <<" /   \\  ";
	printnumber(dealer.bomb5);
	cout <<" /   \\  ";
	printnumber(dealer.bomb6);
	cout <<" /   \\  ";
	printnumber(dealer.bomb7);
	cout <<" /         \\         " << endl;
	cout << "   /      \\___/     \\___/     \\___/     \\___/     \\___/     \\___/     \\___/           \\        " << endl;
	cout << "  /                                                                                    \\       " << endl;
	cout << " /______________________________________________________________________________________\\      " << endl;
	cout << "                                                                                               " << endl;
	cout << "                                                                                               " << endl;
	cout << "          ______________________________________________________________________               " << endl;
	cout << "         /    __                                                                \\              " << endl;
	cout << "        /    /  \\      /  \\      /  \\      /  \\      /  \\      /  \\      /  \\    \\             " << endl;
	cout << "       /   _|_  **   _|_  **   _|_  **   _|_  **   _|_  **   _|_  **   _|_  **    \\            " << endl;
	cout << "      /   /   \\     /   \\     /   \\     /   \\     /   \\     /   \\     /   \\        \\           " << endl;
	cout << "     /   /     \\   /     \\   /     \\   /     \\   /     \\   /     \\   /     \\        \\          " << endl;
	cout << "    /    \\  ";
	printnumber(player.bomb1);
	cout <<" /   \\  ";
	printnumber(player.bomb2);
	cout <<" /   \\  ";
	printnumber(player.bomb3);
	cout <<" /   \\  ";
	printnumber(player.bomb4);
	cout <<" /   \\  ";
	printnumber(player.bomb5);
	cout <<" /   \\  ";
	printnumber(player.bomb6);
	cout <<" /   \\  ";
	printnumber(player.bomb7);
	cout <<" /         \\         " << endl;
	cout << "   /      \\___/     \\___/     \\___/     \\___/     \\___/     \\___/     \\___/           \\        " << endl;
	cout << "  /                                      ________                                      \\       " << endl;
	cout << " /______________________________________/        \\______________________________________\\" << endl;
	cout << "                                       /          \\                                            " << endl;
	cout << "                                      |____________|                                      " << endl;
	cout << "                                      |============|                                       " << endl;
	cout << "                                      |            |  __                                         " << endl;
	cout << "                                      |            | / /                                        " << endl;
	cout << "                                     _|_          _|/ /                                           " << endl;
	cout << "                                    / |\\\\        //|_/                                  " << endl;
	cout << "                                   / /| \\\\______// |                      " << endl;
	cout << "                                  | | |  |      |  |                                                            " << endl;
	cout << "                                  |_| |__|      |__|                                                 " << endl;
	cout << "                                       \\__________/                                                         " << endl;
	cout << "                                        _||   _||                                                  " << endl;
	cout << "                                       /__|  /__|                                                     " << endl;
	cout << "                                                                                               " << endl;
	cout << "                                      " << player.name << endl;
	cout << "____________________________________________________________________________________________________________" << endl;

}

void printnumber(int a){
	if(a <10){
		cout << a << " ";
	}else if(a>=10){
		cout << a;
	}
}


void thinking(){
	cout <<"..";
	Sleep(500);
	cout <<"..";
	Sleep(500);
	cout <<"..";
	Sleep(500);
	cout <<"..";
	Sleep(500);
	cout <<"..";
	Sleep(500);
	system("cls");
}

bool dealerai(int a, int b){
	if(b == 0){
		return false;
	}else if(a<=16){
		return true;
	}else if(a <= 21 && a>=17 && a>b){
		return false;
	}else if(a <= 21 && a>=17 && a<b){
		return true;
	}
}




int main(){
	srand(time(NULL));
	title();
}


