#include "algorithm.h"

// Function definition for breadth-first traversal algorithm
// This function performs breadth-first traversal on a graph and computes distances from a starting vertex to all other vertices
// Parameters:
//   - graph: The graph represented as an adjacency list
//   - start: The starting vertex for traversal
//   - distances: A vector to store distances from the starting vertex to all other vertices

template<typename T, typename Graph>
void bft(const Graph& graph, int start, std::vector<T>& distances) {
    // Assign maximum distance to all vertices initially
    distances.assign(graph.size(), std::numeric_limits<T>::max());
    // Set the distance of the starting vertex to 0
    distances[start] = 0;

    // Initialize a boolean vector to keep track of visited vertices
    std::vector<bool> visited(graph.size(), false);
    // Initialize a queue to perform breadth-first traversal
    std::vector<int> queue;
    // Add the starting vertex to the queue
    queue.push_back(start);

    // Perform breadth-first traversal until the queue is empty
    while (!queue.empty()) {
        // Get the vertex at the front of the queue
        int current = queue.front();
        // Remove the vertex from the queue
        queue.erase(queue.begin());

        // If the current vertex has not been visited
        if (!visited[current]) {
            // Mark the current vertex as visited
            visited[current] = true;

            // Iterate through the neighbors of the current vertex
            for (int i = 0; i < graph[current].size(); ++i) {
                // Get the neighbor vertex
                int neighbor = graph[current][i];

                // If the neighbor has not been visited
                if (!visited[neighbor]) {
                    // Add the neighbor to the queue for further traversal
                    queue.push_back(neighbor);
                }

                // Update the distance to the neighbor if a shorter path is found
                if (distances[current] + 1 < distances[neighbor]) {
                    distances[neighbor] = distances[current] + 1;
                }
            }
        }
    }
}
