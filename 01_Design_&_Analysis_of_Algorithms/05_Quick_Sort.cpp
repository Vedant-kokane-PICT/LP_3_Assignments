#include <bits/stdc++.h>
using namespace std;

int partition(int low,int high,vector<int> &arr){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        // from left find bigger element than pivot
        // from right find smaller element than pivot
        while(i <= high && arr[i] <= pivot){
            i++;
        }
        while(j >= low && arr[j] > pivot){
            j--;
        }
        
        // swap if i and j has not crossed each other
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // swap pivot (element at index low) and element at index j  as j < i
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    return j;
    
}

void quickSort(int low,int high,vector<int> &arr){
    if(low >= high){
        return;
    }
    int partitionIndex = partition(low,high,arr);
    quickSort(low,partitionIndex-1,arr);
    quickSort(partitionIndex+1,high,arr);
}

int main()
{
//     vector<int> arr = {1,3,6,4,7,2};
// 	int n = 6;
        vector<int> arr = {6,2,1,4,3,4,7};
	int n = 7;

	quickSort(0,n-1,arr);
	
	for(auto x:arr){
	    cout<<x<<" ";
	}

    return 0;
}

// TC - O(N*LogN)
// SC - O(N) (Recursion Stack space)
