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
================= 2025-02-04================
[이분 탐색 복습] 8983번 사냥꾼
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, N, L;
	cin >> M >> N >> L;
	vector<int>places(M);
	for (int i = 0; i < M; ++i) {
		cin >> places[i];
	}
	sort(places.begin(), places.end());
	
	vector<pair<int, int>>animals(N);
	for (int i = 0; i < N; ++i) {
		cin >> animals[i].first >> animals[i].second;
	}
	vector<bool>check_animal(N, false);

	

	for (int i = 0; i < N; ++i) {
		int left = 0;
		int right = M - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;

			if (abs(places[mid] - animals[i].first) + animals[i].second > L) {
				if (animals[i].first > places[mid]) {
					left = mid + 1;
				}
				else if(animals[i].first<places[mid]) {
					right = mid - 1;
				}
				else {
					break;
				}
			}
			else {
				check_animal[i] = true;
				break;
			}


		}
	}
	int cnt{};
	for (auto a : check_animal) {
		if (a)cnt++;
	}
	cout << cnt;

}

