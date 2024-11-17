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
================= 2024-11-17================
10814번 나이순 정렬

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, string>>members(N);
	for (int i = 0; i < N; ++i) {
		cin >> members[i].first >> members[i].second;
	}
	stable_sort(members.begin(), members.end(),[](const pair<int,string>& a, const pair<int,string>& b){
		return a.first < b.first;
		});
	for (auto a : members) {
		cout << a.first << ' ' << a.second << '\n';
	}


}


