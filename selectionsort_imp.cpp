#include "algorithm.h"

// Selection Sort function implementation
template<typename T>
void selection_sort(std::vector<T>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; ++i) {
        // Find the minimum element in the unsorted part of the array
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap the found minimum element with the first element
        std::swap(arr[min_index], arr[i]);
    }
}
