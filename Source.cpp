#include "Header.h"

using namespace std;

int main() {

	int n = 100; // size of vector

	// generate random vectors
	vector<int> v1 = randomVector(n); // used for binary search
	vector<int> v2 = randomVector(n); // used for linear search

	// key to search for (we are making sure the key cannot exist in the range to force worst case)
	int key = 3 * n + 1;

	// tracking comparisons made
	int BScomp = 0, LScomp = 0;

	// sort vector 1, track the time to sort to use for binary search
	auto start = chrono::steady_clock::now();
	sort(v1.begin(), v1.end());
	auto end = chrono::steady_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	cout << "Quicksort sorting time: " << elapsed_seconds.count() << " (s)\n\n";

	// binary search
	start = chrono::steady_clock::now();
	int bs = binarySearch(v1, key, BScomp);
	end = chrono::steady_clock::now();
	elapsed_seconds = end - start;
	printResults("Binary Search", bs, BScomp, elapsed_seconds);

	// linear search
	start = chrono::steady_clock::now();
	int ls = linearSearch(v2, key, LScomp);
	end = chrono::steady_clock::now();
	elapsed_seconds = end - start;
	printResults("Linear Search", ls, LScomp, elapsed_seconds);
	
	return 0;
}