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
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-28================
[실패 문제] 1406 에디터

0.3초-> vector사용하니까 중간 삽입 시 O(N)씩 M번하면 시간초과

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	deque<char> front;
	deque<char> back;

	string input;
	cin >> input;
	for (char a : input) {
		front.push_back(a);
	}

	int num;
	cin >> num;
	while (num--) {
		char order;
		cin >> order;
		switch (order) {
		case 'P':
			char factor;
			cin >> factor;
			front.push_back(factor);
			break;
		case 'L':
			if (!front.empty()) {
				back.push_front(front.back());
				front.pop_back();			
			}
			break;

		case 'D':
			if (!back.empty()) {
				front.push_back(back.front());
				back.pop_front();			
			}
			break;

		case 'B':
			if (!front.empty()) {
				front.pop_back();
			}
			break;
		}
	}
	
	for (auto p : front) {
		cout << p;
	}
	for (auto p : back) {
		cout << p;
	}
	

}


