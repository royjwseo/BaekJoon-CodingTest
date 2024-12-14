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
================= 2024-12-14================
[코테 강의 1주차 문자열,누적합,구현] 1159 농구 경기
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<string>names(N);
	array<int, 26>alphas{};
	for (int i = 0; i < N; ++i) {
		cin >> names[i];
		alphas[names[i][0] - 'a']++;
	}

	bool ifis = false;
	for (int i = 0; i < 26; ++i) {
		if (alphas[i] >= 5) {
			ifis = true;
			cout << (char)(i+'a');
		}
	}
	if (!ifis)cout << "PREDAJA";

}

