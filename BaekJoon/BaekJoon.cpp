#include <iostream>
#include <string>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-23================

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

template<typename T>
class MyIter {
private:
	T* _ptr;
public:
	MyIter(T* ptr):_ptr(ptr){}

	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }

	bool operator==(const MyIter& other) { return _ptr == other._ptr; }
	bool operator!=(const MyIter& other) { return _ptr != other._ptr; }

	MyIter& operator++() {
		++_ptr;
		return *this;
	}

	MyIter& operator++(int) {
		MyIter a = *this;
		_ptr++;
		return a;
	}
};

template<typename T>
class MyVector {
public:
	using Iterator = MyIter<T>;
	Iterator begin() { return Iterator(_data); }
	Iterator end() { return Iterator(_data + _size); }
	//생성자들
	MyVector() { _size = 0; _capacity = 0; _data = nullptr; }
	MyVector(size_t size, T data) {
		_size = size;
		_capacity = size * 2;
		_data = new T[_capacity];
		for (int i = 0; i < _size; ++i)_data[i] = data;
	}
	MyVector(const MyVector& other) {
		_capacity = other._capacity;
			_size = other._size;
		_data = new T[_capacity];
		for (int i = 0; i < _size; ++i) {
			_data[i] = other._data[i];
		}
	}
	~MyVector() { if (_data)delete[] _data; }
public:
	void reserve(const size_t new_capacity) {
		if (_capacity >= new_capacity)return;

		if (_data) {
			T* imsi = new T[new_capacity];
			for (int i = 0; i < _size; ++i) {
				imsi[i] = _data[i];
			}
			delete[] _data;
			_capacity = new_capacity;
			_data = imsi;
		}
		else {
			_data = new T[new_capacity];
			_capacity = new_capacity;
		}
	}

	void push_back(const T data) {
		if (_size == _capacity) {
			size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
			reserve(new_capacity);
		}
		_data[_size] = data;
		_size++;
		
	}

	void pop_back() {
		if (_data == nullptr)return;
		if (_size > 0) {
			_size--;
		}
	}

	bool empty() {
		return (_size > 0) ? false : true;
	}

	void clear() {
		_size = 0;
		if (_data) {
			delete[] _data;
			_data = new T[_capacity];
		}
	}

	T& at(size_t at) {
		if (at >= _size) {
			return nullptr;
		}
		return _data[at];
	}

	T& front() {
		if (_data) {
			return _data[0];
		}
		else {
			return nullptr;
		}
	}

	T& back() {
		if (_data) {
			return _data[_size - 1];
		}
		else {
			return nullptr;
		}
	}

	void shrink_to_fit() {
		_capacity = _size;
		T* imsi = new T[_size];
		for (int i = 0; i < _size; ++i) {
			imsi[i] = _data[i];
		}
		delete[] _data;
		_data = imsi;
	}

	

	const size_t size()const {
		return _size;
	}

	const size_t capacity()const {
		return _capacity;
	}



public:
	//입출력
	friend ostream& operator<<(const ostream& out,const T& other) {
		out << other;
	}

	T& operator[](size_t i) {
		return _data[i];
	}

private:
	size_t _size;
	size_t _capacity;
	T* _data;
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	MyVector<int> v(2,1);
	v.push_back(1);
	
	for (MyIter<int> It = v.begin(); It != v.end(); ++It) {
		cout << *It;
	}
}


