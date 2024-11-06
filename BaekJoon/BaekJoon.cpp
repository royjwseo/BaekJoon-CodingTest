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
================= 2024-11-05================

*/


template<class T>
class PriorityQueue
{
public:
    void push(const T& data) {

        // 우선 힙 구조부터 맞춰준다.
        _heap.push_back(data); 

        // 대소에 의한 정렬 시작
        int cur_index = static_cast<int>(_heap.size())-1;

        //루트 노드까지
        while (cur_index > 0) {
            int parent_index = (cur_index - 1) / 2;
            if (_heap[cur_index] > _heap[parent_index]) {
                swap(_heap[cur_index], _heap[parent_index]);
                cur_index = parent_index;
            }
            else {
                break;
            }
        }
    }
    
    void pop() {
        _heap[0] = _heap.back();
        _heap.pop_back();

        int cur_index = 0;

        while (true) {
            int left = (2 * cur_index) + 1;
            int right = (2 * cur_index) + 2;

            //리프에 도달한 경우
            if (left >= (int)_heap.size())
                break;

            int next = now;
            //왼쪽과 비교
            if (_heap[next] < _heap[left]) {
                next = left;
            }

            // 둘 중 승자를 오른쪽과 비교 (하지만 오른쪽이 없을수도 있으니 체크해주고)
            if (right < _heap.size() && _heap[next] < _heap[right]) {
                next = right;
            }

            //왼쪽 오른쪽 둘 다 현재 값보다 작으면 종료
            if (next == now)
                break;

            ::swap(_heap[now], _heap[next]);
            now = next;
        }
        
    }

    T& top() {
        return _heap[0];
    }

    bool empty() {
        return _heap.empty();
    }

private:
    vector<T> _heap;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
  
    
 
}


