#include <iostream>
#include <string>
#include <tuple>
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
================= 2025-01-15================
17218번 비밀번호 만들기
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	

	int N, M;
	cin >> N >> M;
	unordered_map<string, string>um;
	string flush;
	getline(cin,flush);
	for (int i = 0; i < N; ++i) {
		string input;
		getline(cin, input);
		int where = input.find(' ');
		um[input.substr(0, where)] = input.substr(where + 1);
	}




	for (int i = 0; i < M; ++i) {
		string input;
		cin >> input;
		if(!um[input].empty())
		cout << um[input]<<'\n';
	}
}

