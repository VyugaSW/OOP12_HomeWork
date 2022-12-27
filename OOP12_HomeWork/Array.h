#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
template <class T>
class Array
{
	T *arr;
	int size;

	//Функция копирования из старого массива в новый
	T* copy(int newSize, int oldSize) {
		T* newArr = new T[newSize];
		for (int i = 0, k = 0; i < newSize; i++) {
			if (i < oldSize) {
				newArr[i] = arr[k];
				k++;
			}
			else
				newArr[i] = NULL;
		}
		return newArr;
	}
public:
	Array(int s) : size{ s } , arr { new T[size] } {};
	Array() : Array(1) {};
	//Неведома конкретная задача операторов, поэтому они будут изменять размер массива
	void operator+(int value) {
		int oldSize = size;
		size += value;
		arr = copy(size,oldSize);
		
	}
	void operator-(int value) {
		int oldSize = size;
		size -= value;
		arr = copy(size, oldSize);
	}
	void operator*(int value) {
		int oldSize = size;
		size *= value;
		arr = copy(size, oldSize);
	}
	void operator/(int value) {
		int oldSize = size;
		size /= value;
		arr = copy(size, oldSize);
	}


	T findMax() {
		if (is_same<T, char>::value) {
			char* max = new char[50];
			for (int i = 1; i < size; i++) {
				if (arr[i] > max)
					max = arr[i];
			}
			return max;
		}
		else {
			int max = arr[0];
			for (int i = 1; i < size; i++) {
				if (arr[i] > max)
					max = arr[i];
			}
			return max;
		}
	}
	T findMin() {
		if (is_same<T, char>::value) {
			char* min = new char[50];
			for (int i = 1; i < size; i++) {
				if (arr[i] < min)
					min = arr[i];
			}
			return min;
		}
		else {
			int min = arr[0];
			for (int i = 1; i < size; i++) {
				if (arr[i] < min)
					min = arr[i];
			}
			return min;
		}
	}
	void print() {
		for (int i = 0; i < size; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	void fillRand() {
		//Не стал уж добавлять все возможные варианты 
		srand(time(NULL));
		if (is_same<T, char>::value) {
			for (int i = 0; i < size; i++) { arr[i] = rand() % 25 + 27; }
		}
		else if (is_same<T, int>::value) {
			for (int i = 0; i < size; i++) { arr[i] = rand() % 100; }
		}
		else if (is_same<T, float>::value || is_same<T, double>::value) {
			for (int i = 0; i < size; i++) { arr[i] = (float)rand()/RAND_MAX/100; }
		}
		else if (is_same<T, long>::value){
			for (int i = 0; i < size; i++) { arr[i] = rand() % 10000000; }
		}
		else if (is_same<T, long long>::value) {
			for (int i = 0; i < size; i++) { arr[i] = rand() % 1000000000000000; }
		}
	}
	void fill() {
		for (int i = 0; i < size; i++) {
			cout << "Enter a " << i+1 << " element - ";
			cin >> arr[i];
		}

	}
	T clear() {
		delete[] arr;
		arr = new T[size];
		return arr;
	}
};

