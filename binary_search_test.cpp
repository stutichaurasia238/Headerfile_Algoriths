#include <iostream>
#include "dsa.h" // Include your algorithm header file

int main() {
    // Sorted array for testing binary search
    std::vector<int> sorted_array = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    // Target elements to search for
    int target1 = 7;
    int target2 = 10;

    // Perform binary search
    int index1 = binary_search(sorted_array, target1);
    int index2 = binary_search(sorted_array, target2);

    // Print results
    if (index1 != -1) {
        std::cout << "Element " << target1 << " found at index " << index1 << std::endl;
    } else {
        std::cout << "Element " << target1 << " not found" << std::endl;
    }

    if (index2 != -1) {
        std::cout << "Element " << target2 << " found at index " << index2 << std::endl;
    } else {
        std::cout << "Element " << target2 << " not found" << std::endl;
    }

    return 0;
}
