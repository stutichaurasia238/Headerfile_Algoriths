#include "algorithm.h"

// Function definition for Dijkstra's shortest path algorithm
// This function finds the shortest path from a starting vertex to an end vertex in a graph
// Parameters:
//   - graph: The graph represented as an adjacency list
//   - start: The starting vertex
//   - end: The end vertex
//   - distances: A vector to store distances from the starting vertex to all other vertices
//   - path: A vector to store the shortest path from the starting vertex to the end vertex
template<typename T, typename Graph>
void dijkstra(const Graph& graph, int start, int end, std::vector<T>& distances, std::vector<int>& path) {
    // Assign maximum distance to all vertices initially
    distances.assign(graph.size(), std::numeric_limits<T>::max());
    // Set the distance of the starting vertex to 0
    distances[start] = 0;

    // Initialize a boolean vector to keep track of visited vertices
    std::vector<bool> visited(graph.size(), false);
    // Initialize a queue to perform Dijkstra's algorithm
    std::vector<int> queue;
    // Add the starting vertex to the queue
    queue.push_back(start);

    // Perform Dijkstra's algorithm until the queue is empty or the end vertex is reached
    while (!queue.empty()) {
        // Get the vertex at the front of the queue
        int current = queue.front();
        // Remove the vertex from the queue
        queue.erase(queue.begin());

        // If the current vertex has not been visited
        if (!visited[current]) {
            // Mark the current vertex as visited
            visited[current] = true;

            // If the current vertex is the end vertex, exit the loop
            if (current == end) {
                break;
            }

            // Iterate through the neighbors of the current vertex
            for (int i = 0; i < graph[current].size(); ++i) {
                // Get the neighbor vertex
                int neighbor = graph[current][i];
                // Calculate the distance from the starting vertex to the neighbor
                T dist = distances[current] + graph[current][i];

                // If the calculated distance is shorter than the current distance to the neighbor
                if (dist < distances[neighbor]) {
                    // Update the distance to the neighbor
                    distances[neighbor] = dist;
                    // Update the shortest path to the neighbor
                    path[neighbor] = current;
                    // Add the neighbor to the queue for further exploration
                    queue.push_back(neighbor);
                }
            }
        }
    }
}