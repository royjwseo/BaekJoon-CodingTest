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
17298번 오큰수
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<int>st;
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		st.push(input);
	}
	vector<pair<int, int>>reversed_nums;
	int max = st.top();
	int before = -1;
	bool check = false;
	int real_max = -1;
	bool real_max_check = false;
	for (int i = 0; i < N; ++i) {
		int top = st.top();
		st.pop();
		if (top > real_max) {
			real_max = top;
		}
		
		if (!check) {
			reversed_nums.push_back({ top,max });
		}
		else if (real_max_check) {
			reversed_nums.push_back({ top,real_max });
			real_max_check = false;
		}
		else {
			reversed_nums.push_back({ top,top });
		}
		
		if (!st.empty()) {
			if (st.top() < top) {
				check = false;
				max = top;		
			}
			else if(st.top()>max) {
				if (st.top() < real_max) {
					real_max_check = true;
				}
				check = true;			
			}
		}
	
	}


	for (auto it = reversed_nums.rbegin(); it != reversed_nums.rend(); it++) {
		if (it->first == it->second) {
			cout << -1;
		}
		else {
			cout << it->second;
		}
		if(it!=reversed_nums.rend())
		cout << ' ';
	}

}


