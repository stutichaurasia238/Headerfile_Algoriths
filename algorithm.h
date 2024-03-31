#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <limits>  // Include for numeric_limits
#include <vector>  // Include for vector container

// This ifndef/define block is a standard C++ header guard. It ensures that
// the contents of this header file are included only once in a translation
// unit, preventing multiple definitions and potential linker errors.

// We're including <limits> for the numeric_limits template, which provides
// information about the properties of arithmetic types, such as minimum and
// maximum values.

// We're also including <vector> for the vector container, which is commonly
// used to store collections of objects in C++.


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

// Binary Search declaration for algorithm functions
template<typename T>
int binary_search(const std::vector<T>& arr, const T& target);
#include "binary_search_imp.cpp"

// End of header guard
#endif // ALGORITHM_H

