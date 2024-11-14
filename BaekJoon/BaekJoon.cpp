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
11725 트리의 부모 찾기
*/


vector<vector<int>> adjacents;
vector<int> parent;

void BFS(int here) {

    queue<int> q;
    q.push(here);
 
    while (!q.empty()) {
        int front = q.front();
      
        q.pop();

        int size = adjacents[front].size();
        for (int i = 0; i < size; ++i) {
            if (parent[adjacents[front][i]] == 0) {
                parent[adjacents[front][i]] = front;
                q.push(adjacents[front][i]);
           }
        }
    }

   
  

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    adjacents.resize(N + 1);
    parent.resize(N + 1,0);

    for (int i = 0; i < N-1; ++i) {
        int a, b;
        cin >> a >> b;
        adjacents[a].push_back(b);
        adjacents[b].push_back(a);
    }

    BFS(1);

    for (int i = 2; i <= N; ++i) {
        cout << parent[i] << '\n';
    }





}


