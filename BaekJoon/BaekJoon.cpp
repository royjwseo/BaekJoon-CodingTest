#include <iostream>
#include <string>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-26================
1620번 나는야 포켓몬 마스터 이다솜

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	vector<pair<string, int>> pokemons(N+1);
	unordered_map<string,int> names(N + 1);

	for (int i = 1; i <= N; ++i) {
		string input;
		cin >> input;
		pokemons[i] = make_pair(input, i);
		names.insert({ input,i });
	}

	for (int i = 0; i < M; ++i) {
		string input;
		cin >> input;
		if (isdigit(input[0])) {
			int num = stoi(input);
			cout << pokemons[num].first << '\n';
		}
		else {
			auto a = names.find(input);
			if(a!=names.end())
			cout<<a->second<<'\n';
		}
	}
}


