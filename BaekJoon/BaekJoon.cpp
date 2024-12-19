#include <iostream>
#include <string>
#include <numeric>
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
================= 2024-12-19================
[완전탐색, 브루트포스]  1065번 한수 
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<bool>check;

int Check(int i) {
	if (i < 100)return 1;
	
	string input = to_string(i);
	if (input[2] - input[1] == input[1] - input[0]) {
		return 1;
	}
	else {
		return 0;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int cnt{};
	for (int i = 1; i <= N; ++i) {
		cnt += Check(i);
	}
	cout << cnt;

}

