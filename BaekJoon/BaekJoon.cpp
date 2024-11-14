#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-14================
11724 연결 요소의 개수
*/

vector<bool> visited;
vector<vector<int>> adjacent;
vector<int> visited_cnt;

void DFS(int here,int& cnt) {

    if (!visited[here]) {
        visited[here] = true;
        cnt++;
    }
    else {
        return;
    }

    int size = adjacent[here].size();
    for (int i = 0; i < size; ++i) {
        DFS(adjacent[here][i],cnt);
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    visited.resize(N+1, false);
    adjacent.resize(N+1);
    visited_cnt.resize(N+1, 0);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i) {
        DFS(i, visited_cnt[i]);
    }
    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        if (visited_cnt[i] > 0) {
            answer++;
        }
    }
    cout << answer;

}


