#include "algorithm.h"

// Utility function to partition the array and return the index of the pivot element
template<typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[low]; // Choose the first element as the pivot
    int i = low + 1; // Index of the partitioning element

    for (int j = low + 1; j <= high; ++j) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            std::swap(arr[i], arr[j]);
            ++i;
        }
    }
    // Swap pivot (arr[low]) with the partitioning element (arr[i-1])
    std::swap(arr[low], arr[i - 1]);
    return i - 1;
}

// Utility function to perform the Quick Sort recursively
template<typename T>
void quick_sort_helper(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the index of the pivot element
        int pivot_index = partition(arr, low, high);

        // Recursively sort the elements before and after the pivot
        quick_sort_helper(arr, low, pivot_index - 1);
        quick_sort_helper(arr, pivot_index + 1, high);
    }
}

// Quick Sort function implementation
template<typename T>
void quick_sort(std::vector<T>& arr) {
    int n = arr.size();
    quick_sort_helper(arr, 0, n - 1);
}
