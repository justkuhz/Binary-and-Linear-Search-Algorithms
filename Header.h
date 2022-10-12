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

	for (auto i : vec) {
		cout << i << " ";
	}
	return vec;
}

/*
*/
void mergeSort(vector<int>& v) {

}

/*
*/
int binarySearch(vector<int> v) {

}

/*
*/
int linearSearch(vector<int> v) {


}