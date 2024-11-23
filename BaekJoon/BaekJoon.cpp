#include <iostream>
#include <string>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-23================
1158번 요세푸스 문제

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	int K;
	cin >> N >> K;

	// 1 2 3 4 5 6 7
	// 1 2 4 5 6 7 /  3
	// 1 2 4 5 7 / 3 6
	// 1 4 5 7 // 3 6 2

	vector<int>vec;
	for (int i = 1; i <= N; ++i) {
		vec.push_back(i);
	}

	int index = 0;

	vector<int>answer;
	while (!vec.empty()) {

		index += 2;
		if (index > vec.size()-1) {
			index -= vec.size();
			index = index % vec.size();
		}

		answer.push_back(vec[index]);
		vec.erase(vec.begin() + index);
		

	}

	for (vector<int>::iterator It = answer.begin(); It != answer.end(); It++) {
		if (It == answer.begin()) {
			cout << '<';
		}
		if (It == answer.end() - 1) {
			cout << *It << '>';
		}
		else {
			cout << *It << ", ";
		}
	}
	

	
	
}


