#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-12-02================
[그리디] 2839번 설탕배달

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	//5 . 3 

	int fives = N / 5;
	int fives_leftover = N % 5;
	
	int result{};
	bool find_answer = true;
	for (int i = fives; i >= 0; --i) {
		int cur_five = 5 * i;
		int leftover = N - cur_five;
		if (leftover > 0) {
			if (leftover % 3 == 0) {
				find_answer = true;
				cout << i + (leftover / 3);
				break;
			}
			else {
				find_answer = false;
			}
		}
		else {
			find_answer = true;
			cout << fives;
			break;
		}	
	}
	if (!find_answer) {
		cout << -1;
	}
	
}

