#include "algorithm.h"

// Binary search function to find the index of a target element in a sorted array
// Parameters:
//   - arr: The sorted array to search in
//   - target: The target element to search for
// Returns:
//   - The index of the target element if found, or -1 if not found
template<typename T>
int binary_search(const std::vector<T>& arr, const T& target) {
    int left = 0;
    int right = arr.size() - 1;

    // Perform binary search iteratively
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If the target is found at the middle index
        if (arr[mid] == target) {
            return mid;
        }
        // If the target is in the left half of the array
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        // If the target is in the right half of the array
        else {
            left = mid + 1;
        }
    }

    // If the target element is not found
    return -1;
}