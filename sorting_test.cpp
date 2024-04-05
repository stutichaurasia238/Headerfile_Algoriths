#include <iostream>
#include <vector>
#include <cstdlib> // For srand and rand
#include <ctime>   // For time

// Include the sorting algorithms
#include "dsa.h"

// Function to generate a random vector of integers
std::vector<int> generate_random_vector(int size) {
    std::vector<int> vec;
    for (int i = 0; i < size; ++i) {
        vec.push_back(rand() % 1000); // Generate random integers in the range [0, 999]
    }
    return vec;
}

// Function to print the elements of a vector
void print_vector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random vector of integers
    std::vector<int> vec = generate_random_vector(10); // Adjust size as needed

    // Print the original vector
    std::cout << "Original vector: ";
    print_vector(vec);

    // Test Merge Sort
    std::vector<int> merge_sorted = vec;
    merge_sort(merge_sorted);
    std::cout << "Merge Sorted: ";
    print_vector(merge_sorted);

    // Test Bubble Sort
    std::vector<int> bubble_sorted = vec;
    bubble_sort(bubble_sorted);
    std::cout << "Bubble Sorted: ";
    print_vector(bubble_sorted);

    // Test Insertion Sort
    std::vector<int> insertion_sorted = vec;
    insertion_sort(insertion_sorted);
    std::cout << "Insertion Sorted: ";
    print_vector(insertion_sorted);

    // Test Selection Sort
    std::vector<int> selection_sorted = vec;
    selection_sort(selection_sorted);
    std::cout << "Selection Sorted: ";
    print_vector(selection_sorted);

    // Test Quick Sort
    std::vector<int> quick_sorted = vec;
    quick_sort(quick_sorted);
    std::cout << "Quick Sorted: ";
    print_vector(quick_sorted);

    return 0;
}
