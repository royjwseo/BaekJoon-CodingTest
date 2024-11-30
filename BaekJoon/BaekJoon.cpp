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
================= 2024-11-30================
10845번 큐

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	deque<int> dq;
	while (N--) {
		string input;
		cin >> input;
		if (input == "push_front") {
			int num;
			cin >> num;
			dq.push_front(num);
		}else if(input == "push_back") {
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (input == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else
				cout << -1 << '\n';
		}
		else if (input == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else
				cout << -1 << '\n';
		}
		else if (input == "size"){
			cout<<dq.size()<<'\n';
		}
		else if (input == "empty") {
			(dq.empty()) ? cout << "1\n" : cout << "0\n";
		}
		else if (input == "front") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << '\n';
			}
		}
		else if (input == "back") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.back() << '\n';
			}
		}
	}

}


