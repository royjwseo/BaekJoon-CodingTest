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
================= 2024-12-24================
[6주차 이분탐색 & LIS(최대증가부분수열)] 2343번 기타 레슨
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int>lessons(N);
	int max_len = 0;
	for (int i = 0; i < N; ++i) {
		cin >> lessons[i];
		max_len += lessons[i];
	}

	int left = *max_element(lessons.begin(), lessons.end());
	int right = max_len;
	int result = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt{};
		int val = 0;
		for (int i = 0; i < N; ++i) {
			
			if (val + lessons[i] > mid) {
				cnt++;
				val = lessons[i];
			}
			else {
				val += lessons[i];
			}
		}
		if (val >0)cnt++;

		if (cnt > M) {
			left = mid + 1;	
		}
		else{
			right = mid - 1;
			result = mid;
		}

	}
	cout << result;


}

