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
vector<bool>visited_stack;
vector<vector<int>>adjacent;


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

void DFS_STACK(int here) {
    stack<int> st;
    st.push(here);

    while (!st.empty()) {
        int top = st.top();
        if (!visited_stack[top]) {
            visited_stack[top] = true;
            cout << top << ' ';
        }
          st.pop();

          int adj = adjacent[top].size();
          if (adj > 0) {
              for (int i = 0; i < adj; ++i) {
                  if (!visited_stack[adjacent[top][i]])
                      st.push(adjacent[top][i]);
              }
          }

    }
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    adjacent.resize(N + 1);
    visited.resize(N + 1, false);
    visited_stack.resize(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);

    }
  
    DFS(V);
    cout << '\n';
    for (int i = 0; i < adjacent.size(); ++i)
        sort(adjacent[i].begin(), adjacent[i].end(), std::greater<int>());

    DFS_STACK(V);
  
}


