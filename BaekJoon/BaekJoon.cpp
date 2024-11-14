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

void DFS(int here) {

    stack<int> st;

    st.push(here);

    while (!st.empty()) {

        int top = st.top();
        if (!visited[top]) {

            visited[top] = true;
        }
        

        st.pop();

        int size = adjacent[top].size();
        for (int i = 0; i < size; ++i) {
            if(!visited[adjacent[top][i]])
            st.push(adjacent[top][i]);
        }
        

    }



}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    visited.resize(N+1, false);
    adjacent.resize(N+1);
  
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }
    int cnt{};
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            cnt++;
            DFS(i);
        }
    }
    cout << cnt;

}


