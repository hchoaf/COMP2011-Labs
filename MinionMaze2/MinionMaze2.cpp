/**
 * Sample Solution
 *
 * Reflection Quesiton: Have you read the dist function? I guarantee that you will learn something from it.
 *                      What happen if we take away the backtracking and restoring statements from the function?
 */

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

const int WIDTH = 15;
const int HEIGHT = 15;
const int ARRAY_COL_SIZE = WIDTH + 1;
const int MAX_MINIONS = 100;
const int INF = 1000;


const char PURPLE_MINION = '@';
const char MINION = 'v';
const char VISITED = 'X';
const char WALL = '*';


void print_maze(const char maze[][ARRAY_COL_SIZE], int x[], int y[], int count) {
    for (int i = 0; i < HEIGHT; i++) {
	char to_print[ARRAY_COL_SIZE];
	strncpy(to_print, maze[i], ARRAY_COL_SIZE); // this intended to copy the entire row to to_print
	for (int j = count; j > 0; j--) {
	    if (y[j] == i)
		to_print[x[j]] = PURPLE_MINION;
	}
	if (y[0] == i)
	    to_print[x[0]] = MINION;
	cout << to_print << endl;
    }
}
// check if that position is an valid position to land a minion/purple minion
bool is_valid(const char maze[][ARRAY_COL_SIZE], int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= WIDTH)
	return false;
    if (maze[y][x] == WALL) //remember this is row dominant, so the first index is y, not x.
	return false;
    return true;
}


void random_move(const char maze[][ARRAY_COL_SIZE], int &x, int &y) {
    if (!is_valid(maze, x + 1, y) && !is_valid(maze, x - 1, y) &&
        !is_valid(maze, x, y + 1) && !is_valid(maze, x, y - 1))
	return;
    int newx, newy;
    do {
	newx = x;
	newy = y;
	switch (rand() % 4) {
	    case 0: newx++; break;
	    case 1: newx--; break;
	    case 2: newy++; break;
	    case 3: newy--; break;
	}
    } while (!is_valid(maze, newx, newy));
    x = newx;
    y = newy;
}

//measure the distance (steps required) from x1 y1 to x2 y2
//It is easier if we compute the absolute distance between two points like
// | x1 - x2 | + | y1 - y2 |
//However, if you also consider the wall-factor the issue becomes much more complicate
//Here is one example that help you compute the distance with a recursion.
//The idea is that we try four directions and see which direction give us the minimum distance.
//Then the distance between the destination from  my current position will be the minimum distance + 1.
//
//To avoid possible infinite recursion, we need a technique call back-tracking
//Ref: https://course.cse.ust.hk/comp2011/labs/back_tracking_tutorial.pdf
//
//The idea behinds is that we don't want to revisit a cell more than one times in a search.
//So we will mark that cell VISITED when we visit it and restore its original value afterwards
//
int dist(char maze[][ARRAY_COL_SIZE], int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2)
	return 0;
    if (!is_valid(maze, x1, y1))
	return INF;
    if (maze[y1][x1] == VISITED)
	return INF;
    char backup = maze[y1][x1];
    maze[y1][x1] = VISITED;    //backtracking   //TRY TAKE IT AWAY
    int tmp, min_dist;
    min_dist   = dist(maze, x1, y1 - 1, x2, y2);  //going up
    tmp  =  dist(maze, x1, y1 + 1, x2, y2);       //going down
    min_dist = (min_dist > tmp) ? tmp : min_dist;
    tmp  = dist(maze, x1 - 1, y1, x2, y2);        //going left
    min_dist = (min_dist > tmp) ? tmp : min_dist;
    tmp = dist(maze, x1 + 1, y1, x2, y2);         //going right
    min_dist = (min_dist > tmp) ? tmp : min_dist;
    maze[y1][x1] = backup;     //restoring      //TRY TAKE IT AWAY

    //cout << x1 << y1 << " - " << x2 << y2 << ":" << min_dist << endl;
    if (min_dist == INF)
	return INF;

    return min_dist + 1;
}

//randomly generate a purple minion such that it is at least min_dist away from px, py.
//to avoid fall into infinite loop, x and y will be set to 1, 1 after 1000 trial.
void random_generate(char maze[][ARRAY_COL_SIZE], int &x, int &y, int px, int py, int min_dist) {
    do {
	x = rand() % WIDTH;
	y = rand() % HEIGHT;
    } while (!is_valid(maze, x, y) || dist(maze, x, y, px, py) < min_dist);
}


//move one step away from (dx, dy)
void get_away(char maze[][ARRAY_COL_SIZE], int &x, int &y, int dx, int dy) {
    int d = dist(maze, x, y, dx, dy);
    if (d == INF) //no need to move
	return;
    if (dist(maze, x - 1, y, dx, dy) == d + 1)
	x--;
    else if (dist(maze, x, y - 1, dx, dy) == d + 1)
	y--;
    else if (dist(maze, x + 1, y, dx, dy) == d + 1)
	x++;
    else if (dist(maze, x, y + 1, dx, dy) == d + 1)
	y++;
}

int main() {
    // We need size 16 per row although there are at most 15 char in a row.
    // It is because the following initializer uses a c-string to initize an array
    // A c-string will be terminated by an extra \0 symbol at the end which needs
    // one more char to store it.
    //
    // We can, instead initialize a row with
    // = {
    // {'*','*','*', ...total 15 of them },
    // {'*',' ',' ', ........            },
    //...
    // };
    // Then we can have the array index be [15][15] instead.
    char maze[HEIGHT][ARRAY_COL_SIZE] = {
	"***************",
	"*   *    *   D*",
	"*  *  **      *",
	"* *  *    *****",
	"* *  ****   ** ",
	"* **      * ***",
	"*  *  *****   *",
	"* *** ***    **",
	"*             *",
	"*    **   *   *",
	"*   *** ****  *",
	"* **  *     * *",
	"*   *   **    *",
	"*  ****  **** *",
	"***************"
    };
    srand(time(NULL));
    int x[MAX_MINIONS], y[MAX_MINIONS];  //Each minion is located at (x[i], y[i]). Index 0 represents the player
    int count = 0; //count of purple minions
    int fart_gun = 3;
    const int ORI_X = 1, ORI_Y = 13;
    x[0] = ORI_X;
    y[0] = ORI_Y;
    bool heading_back = false;

    float showup_odds;
    do {
        cout << "Enter the minions show up odds. Any decimal number between 0 to 1. 0 means purple minions never show up. 0.5 means there is 50% chance a purple minion will show up per each step you move" << endl;
	cin >> showup_odds;
    } while (showup_odds < 0 || showup_odds > 1);
    do {
	print_maze(maze, x, y, count);

	char input;
	bool valid_input;
	bool fart = false;
	do {
	    valid_input = true;
	    cout << "Enter u(up), d(down), l(left), r(right) to control the minion" << endl;
	    cout << "You also have " << fart_gun << " capsules for a fart gun. " <<
                    "Enter f(fart) to fire it." << endl;
	    cin >> input;
	    switch (input) {
		case 'u': case 'U':   if (is_valid(maze, x[0], y[0] - 1))
					  y[0]--;
				      else
					  valid_input = false;
				      break;
		case 'd': case 'D':   if (is_valid(maze, x[0], y[0] + 1))
					  y[0]++;
				      else
					  valid_input = false;
				      break;
		case 'l': case 'L':   if (is_valid(maze, x[0] - 1, y[0]))
					  x[0]--;
				      else
					  valid_input = false;
				      break;
		case 'r': case 'R':   if (is_valid(maze, x[0] + 1, y[0]))
					  x[0]++;
				      else
					  valid_input = false;
				      break;
		case 'f': case 'F':   if (fart_gun > 0) {
					  cout << "Fart gun!" << endl;
					  fart_gun--;
					  for (int i = 1; i <= count; i++) {
						get_away(maze, x[i], y[i], x[0], y[0]);
					  }
					  fart = true;
				      } else {
					  cout << "You have running out fart gun" << endl;
					  valid_input = false;
				      }
				      break;
		default : valid_input = false;
	    }
	    if (!valid_input)
		cout << "Invalid input, please enter again" << endl;
	} while (!valid_input);
	if (maze[y[0]][x[0]] == 'D') {
	    cout << "You save your mate, now heading back!" << endl;
	    heading_back = true;
	}
	if (!fart) {
	   for (int i = 1; i <= count; i++) {
	      random_move(maze, x[i], y[i]);
	      if (x[i] == x[0] && y[i] == y[0]) {
	  	 cout << "Oh no, you are caught" << endl;
		 print_maze(maze, x, y, count);
		 return 0;
	      }
	   }
	   if (rand() * 1.0 / RAND_MAX < showup_odds) {
	       cout << "A purple minions appear, don't be caught!" << endl;
 	       count++;
	       random_generate(maze, x[count], y[count], x[0], y[0], 3); //generate at least 3 steps away
	   }
	}
    } while (!(heading_back && x[0] == ORI_X && y[0] == ORI_Y));
    cout << "Yeah, you win!" << endl;
}
