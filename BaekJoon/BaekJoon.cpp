#include <iostream>
#include <string>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-17================
11651번 좌표 정렬하기2

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>>coords(N);
    for (int i = 0; i < N; ++i) {
        cin >> coords[i].first >> coords[i].second;
    }
    sort(coords.begin(), coords.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
        });
    for (auto a : coords) {
        cout << a.first << ' ' << a.second << '\n';
    }
}


