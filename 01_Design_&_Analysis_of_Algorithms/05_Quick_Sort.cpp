#include <bits/stdc++.h>
using namespace std;

int deterministicCount = 0; // Count recursive calls for deterministic quicksort
int randomizedCount = 0;    // Count recursive calls for randomized quicksort

// Partition function using first element as pivot (for deterministic quicksort)
int partitionDeterministic(int low, int high, vector<int>& arr) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        // from left, find element greater than pivot
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        // from right, find element smaller than pivot
        while (j >= low && arr[j] > pivot) {
            j--;
        }
        // swap if i and j have not crossed each other
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // Swap pivot (element at index low) and element at index j as j < i
    swap(arr[j], arr[low]);
    return j;
}

// Deterministic Quick Sort (using first element as pivot)
void deterministicQuickSort(int low, int high, vector<int>& arr) {
    if (low < high) {
        deterministicCount++; // Count recursive call
        int partitionIndex = partitionDeterministic(low, high, arr);
        deterministicQuickSort(low, partitionIndex - 1, arr);
        deterministicQuickSort(partitionIndex + 1, high, arr);
    }
}

// Partition function for randomized quicksort (random pivot)
int partitionRandom(int low, int high, vector<int>& arr) {
    int randomPivotIndex = low + rand() % (high - low + 1);
    swap(arr[low], arr[randomPivotIndex]); // Move random pivot to start
    return partitionDeterministic(low, high, arr); // Use deterministic partition
}

// Randomized Quick Sort (using random pivot)
void randomizedQuickSort(int low, int high, vector<int>& arr) {
    if (low < high) {
        randomizedCount++; // Count recursive call
        int partitionIndex = partitionRandom(low, high, arr);
        randomizedQuickSort(low, partitionIndex - 1, arr);
        randomizedQuickSort(partitionIndex + 1, high, arr);
    }
}

int main()
{
//     vector<int> arr = {1,3,6,4,7,2};
// 	int n = 6;
    vector<int> arr = {6,2,1,4,3,4,7};
    int n = 7;
    vector<int> arrCopy1 = arr;
    vector<int> arrCopy2 = arr;

    deterministicCount = 0;
    randomizedCount = 0;

    deterministicQuickSort(0, n - 1, arrCopy1);
    randomizedQuickSort(0, n - 1, arrCopy2);
    cout << "Sorted Array using Deterministic Quick Sort: ";
    for (auto x : arrCopy1) {
	cout << x << " ";
    }
    cout << "\nDeterministic Quick Sort Recursive Calls: " << deterministicCount << endl;

    cout << "Sorted Array using Randomized Quick Sort: ";
    for (auto x : arrCopy2) {
	cout << x << " ";
    }
    cout << "\nRandomized Quick Sort Recursive Calls: " << randomizedCount << endl;

    return 0;
}

// TC - O(N*LogN)
// SC - O(N) (Recursion Stack space)
