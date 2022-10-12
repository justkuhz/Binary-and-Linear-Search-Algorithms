#include "Header.h"

using namespace std;

int main() {

	int n = 100; // size of vector

	// generate random vectors
	vector<int> v1 = randomVector(n); // used for binary search
	vector<int> v2 = randomVector(n); // used for linear search

	// key to search for (we are making sure the key cannot exist in the range to force worst case)
	int key = 3 * n + 1;

	// sort vector 1, track the time to sort one of the vectors
	auto start = chrono::steady_clock::now();
	sort(v1.begin(), v1.end());
	auto end = chrono::steady_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	cout << "quicksort sorting time: " << elapsed_seconds.count() << " (s)\n\n";

	// binary search
	cout << "Binary Search: " << endl;
	start = chrono::steady_clock::now();
	cout << "Key found: " << binarySearch(v1, key) << endl;
	end = chrono::steady_clock::now();
	elapsed_seconds = end - start;
	cout << "time: " << elapsed_seconds.count() << " (s)\n\n";

	// linear search
	cout << "Linear Search: " << endl;
	start = chrono::steady_clock::now();
	cout << "Key found: " << linearSearch(v2, key) << endl;
	end = chrono::steady_clock::now();
	elapsed_seconds = end - start;
	cout << "time: " << elapsed_seconds.count() << " (s)\n";

	return 0;
}
