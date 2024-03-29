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

// End of header guard
#endif // ALGORITHM_H