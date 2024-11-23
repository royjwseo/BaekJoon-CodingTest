#include <iostream>
#include <string>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-23================
10815번 숫자 카드
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//set쓰면 logn에 찾음 unordered_set쓰면 O(1)~O(N)

	int N;
	cin >> N;
	unordered_set<int> set;
	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		set.insert(input);
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int input;
		cin >> input;
		auto It=set.find(input);
		if (It != set.end()) {
			cout << 1 << ' ';
		}
		else {
			cout << 0 << ' ';
		}
	}
}


