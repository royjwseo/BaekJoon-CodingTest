#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-10 ================
- 백준 단계별로 풀어보기 일반 수학 1

--2903번--
첫째 줄에 N이 주어짐 -> N번 거친 후 정사각형들에 걸쳐 
중복 점은 단일 저장 가정한 후 저장해야하는 점의 개수 출력

-> 점은 가로, 세로 증가량이 2의 제곱으로 이루어짐을 확인
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


