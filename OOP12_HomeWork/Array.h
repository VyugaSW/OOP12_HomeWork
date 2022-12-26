#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
template <class T, int>
class Array
{
	T arr*;
	int size;

	//Функция для перегрузки операторов
	T copy(T* newArr, int newSize) {
		for (int i = 0; i < newSize; i++) {
			if (newArr[i] && arr[i])
				newArr[i] = arr[i];
			else
				newArr[i] = NULL;
		}
		delete[] arr;
		return newArr;
	}
public:
	Array(int s) : size{ s } arr { new T[size] } {};
	Array() : Array(1) {};
	//Неведома конкретная задача операторов, поэтому они будут изменять размер массива
	T operator+(int value) {		
		T* newArr = new T[size+value];
		arr = copy(newArr, size+value);
		size += value;
	}
	T operator-(int value) {	
		T* newArr = new T[size-value];
		arr = copy(newArr, size-value);
		size -= value;
	}
	T operator*(int value) {		
		T* newArr = new T[size*value];
		arr = copy(newArr, size*value);
		size *= value;
	}
	T operator/(int value) {
		T* newArr = new T[size/value];
		arr = copy(newArr, size/value);
		size /= value;
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
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
	void fillRand() {
		//Не стал уж добавлять все возможные варианты 
		srand(time(NULL));
		if (is_same<T, char>::value) {
			for (int i = 0; i < size; i++) {arr[i] = rand()%25+27}
		}
		else if (is_same<T, int>::value) {
			for (int i = 0; i < size; i++) { arr[i] = rand()%100 }
		}
		else if (is_same<T, float>::value || is_same<T, double>::value) {
			for (int i = 0; i < size; i++) { arr[i] = (rand()%100+10)/10 }
		}
		else if (is_same<T, long>::value){
			for (int i = 0; i < size; i++) { arr[i] = rand()% pow(10,5) }
		}
		else if (is_same<T, long long>::value) {
			for (int i = 0; i < size; i++) { arr[i] = rand() % pow(10,10) }
		}
	}
	void fill() {
		for (int i = 0; i < size; i++) {
			cout << "Etner a " i << " element - ";
			cin >> arr[i];
		}
		system("cls");
	}
	T clear() {
		delete[] arr;
		arr = new T[size];
		return arr;
	}
};

