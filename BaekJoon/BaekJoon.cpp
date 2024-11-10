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
================= 2024-11-10================
//2606번 바이러스
*/

vector<vector<int>> adjacents;
vector<bool> visited;
int cnt{};
void BFS(int here) {
    visited[here] = true;
    cnt++;
    int size = adjacents[here].size();
    for (int i = 0; i < size; ++i) {
        if (!visited[adjacents[here][i]])
            BFS(adjacents[here][i]);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int E;
    cin >> N >> E;
    adjacents.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < E; ++i) {
        int a, b;
        cin >> a >> b;
        adjacents[a].push_back(b);
        adjacents[b].push_back(a);
    }
    BFS(1);
    cout << cnt-1;



}


