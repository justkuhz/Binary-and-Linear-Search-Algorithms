#pragma once
#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <iterator>
#include <random>

using namespace std;

/*
* Create and return a vector with of size n and randomly fill with values between a range of [-3*n, 3*n].
* We use the mersenne twister engine to generate random numbers that is based on the Mersenne Twister algo.
* 
* @param n - integer which determines the size of array and range of values we use to fill the array.
* @return a vector of size n that is randomly filled with integers within the range.
*/
vector<int> randomVector(int n) { 
	int upper = 3 * n, lower = -3 * n; //bounds for values we use to fill array

	random_device rd;
	mt19937 mersenee_engine{ rd() };
	uniform_int_distribution<int> dist{ lower, upper };

	auto gen = [&dist, &mersenee_engine]() {
		return dist(mersenee_engine);
	};

	vector<int> vec(n);
	generate(vec.begin(), vec.end(), gen);

	return vec;
}


/*
* A binary search algorithm. We take a sorted algorithm and cut the search area by half until we find the element
* or find that the element does not exist within the vector.
* 
* Prints out the number of comparisons or checks that are made against the key.
* 
* @param v - sorted vector of elements to search through.
* @param key - the key we are searching for within vector v.
* @return the index of the element matching key, otherwise -1 if key is not found.
*/
int binarySearch(vector<int> v, int key) {
	int pivot, left = 0, right = v.size() - 1, comp = 0;

	while (left <= right) {

		pivot = left + (right - left) / 2;

		comp++;
		if (v[pivot] == key) return pivot;
		comp++;
		if (key > v[pivot]) left = pivot + 1;
		else right = pivot - 1;
	}

	cout << "comparisons made: " << comp << endl;
	return -1;
}

/*
* A linear search algorithm. We traverse through all elements of the array checking if the element at
* index i is equal to the key. If we find a match, return index i. Otherwise, return -1.
* Prints the number of comparisons made.
* 
* @param v - vector of elements to search through.
* @param key - the key we are searching for within vector v.
* @return the index of the element matching key, otherwise -1 if key is not found.
*/
int linearSearch(vector<int> v, int key) {
	int comp = 0;
	for (int i = 0; i < v.size(); i++) {
		comp++;
		if (v[i] == key) {
			cout << "comparisons made: " << comp << endl;
			return i;
		}
	}
	cout << "comparisons made: " << comp << endl;
	return -1;
}