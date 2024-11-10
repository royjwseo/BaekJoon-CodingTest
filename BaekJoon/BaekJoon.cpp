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
//1260 DFS와 BFS
*/
//DFS 방문한 목록
vector<bool>visited;
vector<vector<int>>adjacent;

//BFS 발견한 목록
vector<bool> discovered;

void DFS(int here){
    visited[here] = true;
    cout << here << ' ';
    int size = adjacent[here].size();
    for (int i = 0; i < size; ++i) {
        if (!visited[adjacent[here][i]]) {
            DFS(adjacent[here][i]);
        }
       
    }
}

void BFS(int here) {

    queue<int> q;
    q.push(here);
    discovered[here] = true;

    while (q.empty() == false) {
        here = q.front();
        q.pop();

        cout <<  here << ' ';

        int size = adjacent[here].size();
        for (int i = 0; i < size; ++i) {
            int there = adjacent[here][i];
            if (discovered[there])continue;

            q.push(there);
            discovered[there] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int M;
    cin >> M;
    int V;
    cin >> V;

 

    adjacent.resize(N+1);
    visited.resize(N + 1, false);
    discovered.resize(N + 1, false);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }
    int size = adjacent.size();
    for (int i = 0; i < size; ++i) {
        sort(adjacent[i].begin(), adjacent[i].end());
    }
    DFS(V);
    cout << '\n';
    BFS(V);


  
}


