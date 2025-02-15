#include <iostream>
#include <string>
#include <tuple>
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
#include "h.h"
using namespace std;

/*
================= 2025-02-15================
4963번 섬의 개수
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/
int w, h;
vector<vector<int>>field;
vector<vector<bool>>visited;

int dirX[8] = { 1,0,0,-1,1 ,1,-1,-1};
int dirY[8] = { 0,1,-1,0 ,1,-1,1,-1};


void BFS(int y, int x) {

    queue<pair<int, int>>q;
    
    visited[y][x] = true;

    if(field[y][x]==1)
    q.push({ y,x });

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int dx = cur.second + dirX[i];
            int dy = cur.first + dirY[i];

            if (dx >= 0 && dx < w && dy >= 0 && dy < h && !visited[dy][dx] && field[dy][dx] == 1) {
                visited[dy][dx] = true;
                q.push({ dy,dx });
            }
        }

    }

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        
        cin >> w >> h;
        if (w == 0 && h == 0)break;

        field.assign(h, vector<int>(w));
        visited.assign(h, vector<bool>(w));
       
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> field[i][j];
                if (field[i][j] == 0)visited[i][j] = true;
            }
        }
        int cnt{};
        for (int i = 0; i < h; ++ i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j]) {
                    BFS(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';


    }

}


