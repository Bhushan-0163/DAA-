#include <iostream>
using namespace std;

const int MAX_VERTICES = 5;
int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix to store the graph

// Function to add an edge between two vertices
void add_edge(int src, int dst) {
    adjMatrix[src][dst] = 1;
}

// Recursive function to count all paths from `src` to `dst`
void path_counter(int src, int dst, int& path_count, bool visited[]) {
    visited[src] = true; // Mark the current node as visited

    if (src == dst) {
        path_count++; // If destination is reached, increment the path count
    } else {
        // Recurse for all neighbors
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (adjMatrix[src][i] == 1 && !visited[i]) {
                path_counter(i, dst, path_count, visited);
            }
        }
    }
    
    visited[src] = false; // Backtrack and mark the current node as unvisited
}

// Function to initialize visited array and call the recursive path counter
int count_paths(int src, int dst) {
    int path_count = 0;
    bool visited[MAX_VERTICES] = {false}; // Keep track of visited nodes
    path_counter(src, dst, path_count, visited);
    return path_count;
}

int main() {
    // Create a graph given in the example
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(0, 4);
    add_edge(1, 3);
    add_edge(1, 4);
    add_edge(2, 3);
    add_edge(2, 1);
    add_edge(3, 2);

    // Count and print the number of paths from vertex 0 to vertex 4
    cout << count_paths(0, 4);

    return 0;
}
