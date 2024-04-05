#include <iostream>
#include "dsa.h" // Include the custom header file

int main() {
    // Example graph represented as an adjacency list
    std::vector<std::vector<int>> graph = {
        {1, 2},     // Node 0 is connected to nodes 1 and 2
        {0, 2, 3},  // Node 1 is connected to nodes 0, 2, and 3
        {0, 1, 3},  // Node 2 is connected to nodes 0, 1, and 3
        {1, 2}      // Node 3 is connected to nodes 1 and 2
    };

    int start_vertex = 0; // Starting vertex for traversal or shortest path
    int end_vertex = 3;   // Ending vertex for shortest path

    // Test breadth-first traversal
    std::cout << "Breadth-First Traversal:\n";
    std::vector<int> bfs_distances(graph.size());
    bft(graph, start_vertex, bfs_distances);
    for (int i = 0; i < bfs_distances.size(); ++i) {
        std::cout << "Distance from " << start_vertex << " to " << i << ": " << bfs_distances[i] << "\n";
    }

    // Test depth-first traversal
    std::cout << "\nDepth-First Traversal:\n";
    std::vector<int> dfs_distances(graph.size());
    dft(graph, start_vertex, dfs_distances);
    for (int i = 0; i < dfs_distances.size(); ++i) {
        std::cout << "Distance from " << start_vertex << " to " << i << ": " << dfs_distances[i] << "\n";
    }

    // Test Dijkstra's shortest path algorithm
    std::cout << "\nDijkstra's Shortest Path:\n";
    std::vector<int> dijkstra_distances(graph.size());
    std::vector<int> shortest_path(graph.size(), -1); // Initialize path vector with -1
    dijkstra(graph, start_vertex, end_vertex, dijkstra_distances, shortest_path);

    // Print shortest path from start_vertex to end_vertex
    std::cout << "Shortest path from " << start_vertex << " to " << end_vertex << ":\n";
    int current_vertex = end_vertex;
    while (current_vertex != -1) {
        std::cout << current_vertex;
        if (current_vertex != start_vertex) {
            std::cout << " <- ";
        }
        current_vertex = shortest_path[current_vertex];
    }
    std::cout << "\nTotal distance: " << dijkstra_distances[end_vertex] << "\n";

    return 0;
}

/* output
Breadth-First Traversal:
Distance from 0 to 0: 0
Distance from 0 to 1: 1
Distance from 0 to 2: 1
Distance from 0 to 3: 2

Depth-First Traversal:
Distance from 0 to 0: 0
Distance from 0 to 1: 1
Distance from 0 to 2: 1
Distance from 0 to 3: 2

Dijkstra's Shortest Path:
Shortest path from 0 to 3:
3 <- 1 <- 0
Total distance: 4
*/