#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-12 ================
- 백준 11659 구간 합 구하기
시간 제한 1초 (1억 연산)
1<=N<=10만
1<=M<=10만
알고리즘 없이 단순히 구간 합 계산시 최악의 경우 N*M-> 10억 연산 
합배열 이용하여 O(N+M)으로 줄이기
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N,M;
	cin >> N >> M;

	vector<int> added_numbers(N+1, 0);
	int input{};
	for (int i = 1; i <= N; ++i) {
		cin >> input;
		added_numbers[i] = added_numbers[i-1] + input;
	}

	int x, y;
	for (int i = 0; i < M; ++i) {
		cin >> x >> y;
		cout << added_numbers[y] - added_numbers[x - 1] << '\n';
	}
}


