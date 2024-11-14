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

vector<bool> visit;
vector<vector<int>> adjacent;

void BFS(int here) {

    queue<int> q;
 
    q.push(here);


    while (!q.empty()) {

        int front = q.front();

        if (!visit[front]) {
            visit[front] = true;
        }

        q.pop();

        int size = adjacent[front].size();
        for (int i = 0; i < size; ++i) {
            if (!visit[adjacent[front][i]]) {
                q.push(adjacent[front][i]);
            }
        }

    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;


    visit.resize(N+1, false);
    adjacent.resize(N+1);
  
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }
   
    int cnt{};
    for (int i = 1; i <= N; ++i) {
        if (!visit[i]) {
            cnt++;
            BFS(i);
        }
    }
    cout << cnt;

}


