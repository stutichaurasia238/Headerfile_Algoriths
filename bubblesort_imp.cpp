#include "algorithm.h"

// Bubble Sort function implementation
template<typename T>
void bubble_sort(std::vector<T>& arr) {
    int n = arr.size();
    bool swapped;

    // Traverse through all array elements
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; ++j) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped in the inner loop, then the array is already sorted
        if (!swapped)
            break;
    }
}