/*
 * BombTransporter.cpp
 *
 *  Created on: 2018. 2. 23.
 *      Author: Cho
 */


#include <iostream>
using namespace std;
/*
	Left / Right �� ���� 6�ڸ��� - �̴Ͼ��� aaabbb char��, ���ڸ��� 0���� ǥ��: Array
	�̴Ͼ��� ���ʿ��� ���������� �����̸� (EX. 2,3�� ���������� �����̸�) ARRAY�� LEFT aaaa00, ������ bb0000���� �ٲ�
	�ѹ� �����϶����� �ð� �߰�
	���� b>a �� ���ӿ��� (a�� 0�϶� ����)

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
