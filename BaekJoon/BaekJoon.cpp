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
================= 2024-12-31================
[2주차그래프이론,DFS, BFS] 1068 트리
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


vector<vector<int>>tree;
vector<bool>visited;

int DFS(int here, int del_num) {
	
	int cnt{};
	if (tree[here].size() > 1) {
		for (int a : tree[here]) {

			if (a == del_num) {
				continue;
			}
			else {
				cnt += DFS(a, del_num);
			}

		}
	}
	else {
		return 1;
	}
	return cnt;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	tree.resize(N);
	visited.resize(N, 0);

	int root{};
	for (int i = 0; i < N; ++i) {
		int node;
		cin >> node;
		if (node == -1) {
			root = i;
			continue;
		}
		tree[node].push_back(i);
	}


	int delete_node;
	cin >> delete_node;
	if (delete_node == root) {
		cout << 0;
	}
	else {
		cout << DFS(root, delete_node);
	}
}

