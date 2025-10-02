#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

// Partition the array around a pivot value
int partition(vector<int>& arr, int left, int right, int pivot) {
    int i = left;
    for (int j = left; j <= right; j++) {
        if (arr[j] == pivot) {
            swap(arr[j], arr[right]);
            break;
        }
    }
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

// Forward declaration
int linearSelect(vector<int>& arr, int left, int right, int k);

// Median of Medians pivot selection
int medianOfMedians(vector<int>& arr, int left, int right) {
    int n = right - left + 1;

    // If small enough, just sort and return middle element
    if (n <= 5) {
        sort(arr.begin() + left, arr.begin() + right + 1);
        return arr[left + n / 2];
    }

    // Otherwise, compute medians of groups of 5
    vector<int> medians;
    for (int i = left; i <= right; i += 5) {
        int subRight = min(i + 4, right);
        sort(arr.begin() + i, arr.begin() + subRight + 1);
        medians.push_back(arr[i + (subRight - i) / 2]);
    }

    // Recurse to find median of medians
    return linearSelect(medians, 0, medians.size() - 1, medians.size() / 2);
}

// Linear-time selection (Median of Medians algorithm)
int linearSelect(vector<int>& arr, int left, int right, int k) {
    if (left == right) return arr[left];

    int pivot = medianOfMedians(arr, left, right);
    int pivotIndex = partition(arr, left, right, pivot);

    if (k == pivotIndex) 
        return arr[k];
    else if (k < pivotIndex) 
        return linearSelect(arr, left, pivotIndex - 1, k);
    else 
        return linearSelect(arr, pivotIndex + 1, right, k);
}

// Generate stock prices for testing
vector<int> generateStockPrices(int n) {
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        prices[i] = 1 + rand() % 10000; // random stock price between 1 and 10000
    return prices;
}

int main() {
    srand(time(0));

    // Different input sizes for benchmarking
    vector<int> sizes = {10000, 20000, 50000, 100000, 200000};

    ofstream outFile("selection_vs_sort.dat");
    outFile << "#Size LinearSelect(ms) STL_Sort(ms)\n";

    for (int n : sizes) {
        vector<int> prices = generateStockPrices(n);

        int k = n / 2; // median index

        // Test linear select (median of medians)
        vector<int> arr1 = prices;
        auto start1 = high_resolution_clock::now();
        int median1 = linearSelect(arr1, 0, n - 1, k);
        auto end1 = high_resolution_clock::now();
        double linearTime = duration<double, milli>(end1 - start1).count();

        // Test sorting
        vector<int> arr2 = prices;
        auto start2 = high_resolution_clock::now();
        sort(arr2.begin(), arr2.end());
        int median2 = arr2[k];
        auto end2 = high_resolution_clock::now();
        double sortTime = duration<double, milli>(end2 - start2).count();

        // Output results
        outFile << n << " " << linearTime << " " << sortTime << "\n";

        // Sanity check
        if (median1 != median2) {
            cerr << "Error: mismatch in median for size " << n << endl;
        }
    }

    outFile.close();
    cout << "Timing data saved to selection_vs_sort.dat\n";
    return 0;
}
