#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template <class T>
class Algo
{
private:
	T* _data;
	int _size;
	void sort();
public:
	Algo(int size);
	void read();
	int find(T val);
};

template<class T>
Algo<T>::Algo(int size)
{
	_size = size;
	_data = new T[_size];
}

template<class T>
void Algo<T>::read()
{
	for (int i = 0; i < _size; i++)
	{
		cin >> _data[i];
	}
}

template<class T>
void Algo<T>::sort()
{
	if (_size <= 1)
		return;

	T t;
	for (int j = _size - 1; j > 0; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (_data[i] > _data[i + 1])
			{
				t = _data[i];
				_data[i] = _data[i + 1];
				_data[i + 1] = t;
			}

		}
	}
}

template<class T>
int Algo<T>::find(T val)
{
	sort();
	int cmp_ct = 0;
	int st = 0, ed = _size - 1, mid;
	while (st <= ed)
	{
		cmp_ct++;
		mid = (ed + st) / 2;
		if (_data[mid] > val)
		{
			ed = mid - 1;
		}
		else if (_data[mid] < val)
		{
			st = mid + 1;
		}
		else if (_data[mid] == val)
		{
			cout << cmp_ct;
			return mid;
		}
	}
	return -1;

}

