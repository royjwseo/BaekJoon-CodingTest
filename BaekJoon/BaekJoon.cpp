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
[이분 탐색 복습] 10816번 숫자 카드2
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

int upper(int value, vector<int>& cards) {
	int left = 0;
	int right = cards.size();

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (cards[mid] > value) {
			right = mid;
		}
		else {
			left = mid+1;
		}
	}
	return left;
}

int lower(int value, vector<int>& cards) {
	int left = 0;
	int right = cards.size();

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (cards[mid] >= value) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int>cards(N);
	for (int i = 0; i < N; ++i) {
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int input;
		cin >> input;
		int up = upper(input, cards);
		int low = lower(input, cards);
		cout << up-low << ' ';
	}

	
	
}

