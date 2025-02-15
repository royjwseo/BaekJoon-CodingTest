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
using namespace std;

/*
================= 2025-02-15================
1712번 손익분기점
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // A 고정 비용 , B 가변 비용, 

    int A, B, C;
    cin >> A >> B >> C;

    int total=A;
    int cnt{};
    if (B >= C)cout << -1;
    else {
        int div = C - B;
        cout<< A / div + 1;
    }

  
}


