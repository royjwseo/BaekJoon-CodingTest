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
================= 2024-12-28================
[2주차그래프이론,DFS, BFS] 2910 빈도 정렬
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, C;
	cin >> N >> C;

	unordered_map<int, pair<int,int>> m;

	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		m[input].first++;
		if(m[input].second==0)m[input].second = i + 1;
	}
	vector<pair<int, pair<int,int>>>v;
	for (auto a : m) {	
		v.push_back(a);
	}

	sort(v.begin(), v.end(), [](const pair<int, pair<int,int>>& l, const pair<int, pair<int,int>>& r) {
		if (l.second.first == r.second.first)return l.second.second<r.second.second;
		return l.second.first > r.second.first;
		});

	for (auto a : v) {
		for(int i=0;i<a.second.first;++i)
		cout << a.first << ' ';
	}


}

