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
1193번

--해결 방안--
처음에는 배열을 직접 만들어 분수를 넣어 인덱스 비교하려했는데, 무한한 배열을 만드는데 메모리 부족 및 낭비 느낌
이후 대각선의 패턴을 찾는데 짝수 대각선일때 col 인덱스가 증가, 홀수 대각선일 땐 row 인덱스 증가 원리 사용

결론 -> 몇번째 대각선인지 찾고, 해당 대각선이 짝/홀 인지 찾고 , 짝/홀의 경우 인덱스에 따른 값을 출력

*/

//array<array<string, 3200>, 3200> table{};
int main() {
	
	/*for (int i = 0; i < 3200; ++i) {
		for (int j = 0; j < 3200; ++j) {
			table[i][j] = to_string(j + 1) + '/' + to_string(i + 1);
		}
	}
	*/

	int X;
	cin >> X;
	int cnt=1;
	int add = 1;

	bool up{};
	int i = 1;
	while (add < X) {
		add += ++i;
		cnt++;
	}
	int left = X - add+i;
	if (cnt % 2 == 0) {
		up = false;
	}
	else {
		up = true;
	}

	string result{};
	if (up) {
		//result = table[left - 1][cnt - left - 1];
		result = to_string(cnt - left + 1) + '/' + to_string(left);
	}
	else {
		//result = table[cnt-left - 1][left - 1];
		result = to_string(left ) + '/' + to_string(cnt - left + 1);
		//result = to_string(left) + '/' + to_string(cnt-left);
	}

	cout << result;

}


