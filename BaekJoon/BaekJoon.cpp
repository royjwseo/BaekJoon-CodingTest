#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-10 ================
- ���� �ܰ躰�� Ǯ��� �Ϲ� ���� 1

--2903��--
ù° �ٿ� N�� �־��� -> N�� ��ģ �� ���簢���鿡 ���� 
�ߺ� ���� ���� ���� ������ �� �����ؾ��ϴ� ���� ���� ���

-> ���� ����, ���� �������� 2�� �������� �̷������ Ȯ��
-> 2->3->5->9->17->33...
*/


int main() {

	int TestCase{};
	cin >> TestCase;

	int PointNum = 2;

	for (int i = 0; i < TestCase; ++i) {
		PointNum += pow(2, i);
	}
	cout << int(pow(PointNum, 2));
	
	

}


