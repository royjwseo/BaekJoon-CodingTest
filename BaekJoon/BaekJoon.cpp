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
[자료구조] 17299 오등큰수
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int N;
	cin >> N;

	vector<pair<int,int>>nums(N);
	unordered_map<int, int>um;
	for (int i = 0; i < N; ++i) {
		cin >> nums[i].first;
		um[nums[i].first]++;
	}
	for (int i = 0; i < N; ++i) {
		nums[i].second = um[nums[i].first];
	}
	
	stack <int>st;
	vector<int>ans(N, -1);
	for (int i = 0; i < N; ++i) {
		while (!st.empty()&&nums[st.top()].second < nums[i].second) {
			ans[st.top()] = nums[i].first;
			st.pop();
		}
		st.push(i);
	}

	for (int a : ans)cout << a << ' ';
}

