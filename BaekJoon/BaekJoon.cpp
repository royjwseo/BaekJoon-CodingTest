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
25305번 커트라인

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int K;
    cin >> K;

    vector<int> grades(N);
    for (int i = 0; i < N; ++i) {
        cin >> grades[i];
    }
    partial_sort(grades.begin(), grades.begin() + K, grades.end(), [](int a, int  b) {
        return a > b;
        });
    cout << grades[K-1];
    
}


