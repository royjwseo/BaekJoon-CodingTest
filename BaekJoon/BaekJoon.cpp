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
1181번 단어 정렬

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<string> words(N);

	for (int i = 0; i < N; ++i) {
		cin >> words[i];
	}
	sort(words.begin(), words.end(), [](const string& a, const string& b) {
		if (a.length() == b.length()) {
			return a < b;
		}
		return a.length() < b.length();
		});
	words.erase(unique(words.begin(), words.end()), words.end());

	for (auto a : words) {
		cout << a << '\n';
	}


}


