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
================= 2024-11-21================
25501번 재귀의 귀재

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

int recursion(string s,int l,int r,int& cnt) {
	cnt++;
	if (l >= r)return 1;
	else if (s[l] != s[r])return 0;
	else return recursion(s, l + 1, r - 1,cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string input;
		cin >> input;
		int cnt{};
		cout << recursion(input, 0, input.size() - 1, cnt)<<' '<<cnt;

	}
	
}


