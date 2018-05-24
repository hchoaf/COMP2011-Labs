/*
 * BombTransporter.cpp
 *
 *  Created on: 2018. 2. 23.
 *      Author: Cho
 */


#include <iostream>
using namespace std;
/*
	Left / Right 에 각각 6자리씩 - 미니언은 aaabbb char로, 빈자리는 0으로 표현: Array
	미니언이 왼쪽에서 오른쪽으로 움직이면 (EX. 2,3이 오른쪽으로 움직이면) ARRAY는 LEFT aaaa00, 오른쪽 bb0000으로 바뀜
	한번 움직일때마다 시간 추가
	만약 b>a 면 게임오버 (a가 0일때 제외)

 */



int main(){

	char left[6] = {'A', 'A', 'A', 'B', 'B', 'B'};
	char right[6] = {'0', '0', '0', '0', '0', '0'};
	int leftNum = 6;
	int rightNum = 0;

		cout << "There are: " << left[0] << ", " << left[1] << ", " << left[2] << ", " << left[3] << ", " << left[4] << ", " << left[5] << "on the left." << endl;

		cout << "There are: " << right[0] << ", " << right[1] << ", " << right[2] << ", " << right[3] << ", " << right[4] << ", " << right[5] << "on the right." << endl;


	return 0;


}
