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
================= 2024-11-04================
1377번 버블 소트

*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    //버블 정렬 특성상 만약 제일 오른쪽에 제일 작은 수가 있으면
    // 바깥 반복문의 i값이 n-1까지 돌아야 제일 왼쪽에 올 수 있다.
    // 그러므로 한번의 for문에 왼쪽 올 수 있는 거리가 1이므로
    // 해당 문제에서 모든 원소가 정렬되려면 안쪽 배열 몇번 수행되어야하는지 
    // 알기 위해서는 정렬된 인덱스와 아닌 인덱스의 차이 중 제일 최대값을 구하여 최초 수행 한번 더해준다.

    int N;
    cin >> N;
    vector<pair<int, int>>a(N + 1);
    
    for (int i = 1; i <= N; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    

    int Max = INT_MIN;
    for (int i = 1; i <= N; ++i) {
        if (Max < a[i].second - i)Max = a[i].second - i;
    }
    cout << Max + 1;

}


