#include "algorithm.h"

// Function definition for depth-first traversal algorithm
// This function performs depth-first traversal on a graph and computes distances from a starting vertex to all other vertices
// Parameters:
//   - graph: The graph represented as an adjacency list
//   - start: The starting vertex for traversal
//   - distances: A vector to store distances from the starting vertex to all other vertices
template<typename T, typename Graph>
void dft(const Graph& graph, int start, std::vector<T>& distances) {
    // Assign maximum distance to all vertices initially
    distances.assign(graph.size(), std::numeric_limits<T>::max());
    // Set the distance of the starting vertex to 0
    distances[start] = 0;

    // Initialize a boolean vector to keep track of visited vertices
    std::vector<bool> visited(graph.size(), false);
    // Initialize a stack to perform depth-first traversal
    std::vector<int> stack;
    // Add the starting vertex to the stack
    stack.push_back(start);

    // Perform depth-first traversal until the stack is empty
    while (!stack.empty()) {
        // Get the vertex at the top of the stack
        int current = stack.back();
        // Remove the vertex from the stack
        stack.pop_back();

        // If the current vertex has not been visited
        if (!visited[current]) {
            // Mark the current vertex as visited
            visited[current] = true;

            // Iterate through the neighbors of the current vertex in reverse order
            for (int i = graph[current].size() - 1; i >= 0; --i) {
                // Get the neighbor vertex
                int neighbor = graph[current][i];

                // If the neighbor has not been visited
                if (!visited[neighbor]) {
                    // Add the neighbor to the stack for further traversal
                    stack.push_back(neighbor);
                }

                // Update the distance to the neighbor if a shorter path is found
                if (distances[current] + 1 < distances[neighbor]) {
                    distances[neighbor] = distances[current] + 1;
                }
            }
        }
    }
}
