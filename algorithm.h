#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "dsa.h"

#include <limits>  // Include for numeric_limits
#include <vector>  // Include for vector container
#include <string>  // Include for string class

// This ifndef/define block is a standard C++ header guard. It ensures that
// the contents of this header file are included only once in a translation
// unit, preventing multiple definitions and potential linker errors.

// We're including <limits> for the numeric_limits template, which provides
// information about the properties of arithmetic types, such as minimum and
// maximum values.

// We're also including <vector> for the vector container, which is commonly
// used to store collections of objects in C++.


// ------------ ALGORITHMS----------------

//------------- SEARCHING ----------------

// Binary Search declaration for algorithm functions
template<typename T>
int binary_search(const std::vector<T>& arr, const T& target);
#include "binary_search_imp.cpp"

//***************************************************************

//------------- SORTING ------------------


// Function declaration for Merge Sort algorithm
template<typename T>
void merge_sort(std::vector<T>& arr);
#include "mergesort_imp.cpp"

// Function declaration for Bubble sort algorithm
template<typename T>
void bubble_sort(std::vector<T>& arr);
#include "bubblesort_imp.cpp"

// Function declaration for Insertion sort algorithm
template<typename T>
void insertion_sort(std::vector<T>& arr);
#include "insertionsort_imp.cpp"

// Function declaration for selection sort algorithm
template<typename T>
void selection_sort(std::vector<T>& arr);
#include "selectionsort_imp.cpp"

// Function declaration for quick sort algorithm
template<typename T>
void quick_sort(std::vector<T>& arr);
#include "quicksort_imp.cpp"

//**************************************************************************


//--------------- GRAPH TRAVERSAL ALGORITHMS ------------------------------


// Function definition for breadth-first traversal algorithm
template<typename T, typename Graph>
void bft(const Graph& graph, int start, std::vector<T>& distances);
#include "bft_imp.cpp"


// Function declarartion for depth-first traversal algorithm
template<typename T, typename Graph>
void dft(const Graph& graph, int start, std::vector<T>& distances); 
#include "dft_imp.cpp"


// Function declaration for Dijkstra's shortest path algorithm
template<typename T, typename Graph>
void dijkstra(const Graph& graph, int start, int end, std::vector<T>& distances, std::vector<int>& path); 
#include "dijikstra_imp.cpp"//header file inclusion

//*********************************************************************************

//----------STRING ALGORITHMS-----------------------------


//--------------Knuth-Morris-Pratt (KMP) Algorithm----------------

// Function to compute the partial match table for the KMP algorithm
void compute_partial_match_table(const std::string& pattern, std::vector<int>& table);

// Function to search for occurrences of a pattern in a text using the KMP algorithm
int kmp_search(const std::string& text, const std::string& pattern);
#include "kmp_imp.cpp"

//-----------------Rabin-Karp Algorithm-------------------

// Function to compute the hash value of a substring of a text
int compute_hash(const std::string& text, int start, int length, int base, int modulus);

// Function to search for occurrences of a pattern in a text using the Rabin-Karp algorithm
int rabin_karp_search(const std::string& text, const std::string& pattern, int base, int modulus);
#include "rabin_karp_imp.cpp"

//*******************************************************************************

//---------------------DYNAMIC PROGRAMMING-----------------------------

//----------------LCS ALGORITHM-----------------------------

// Function to compute the length of the longest common subsequence of two strings
int lcs_length(const std::string& a, const std::string& b);
#include "lcs_imp.cpp"

//--------------------KNAPSACK ALGORITHM----------------------

// Function to solve the 0/1 knapsack problem
int knapSack(int W, std::vector<int> wt, std::vector<int> val, int n);
#include "knapSack_imp.cpp"

//*******************************************************************************



// End of header guard
#endif // ALGORITHM_H

