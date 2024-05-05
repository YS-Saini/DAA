#include <iostream>
#include <vector>
using namespace std;

// Function to check if adding vertex 'v' to the path at 'pos' is safe
bool isSafeToAdd(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
    // Check if 'v' is adjacent to the previously added vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if 'v' has already been included in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Function to find a Hamiltonian cycle using backtracking
bool findHamiltonianCycle(vector<vector<int>>& graph, vector<int>& path, int pos, int totalVertices) {
    // Base case: If all vertices are included in the path
    if (pos == totalVertices) {
        // Check if there is an edge from the last vertex to the starting vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices as the next candidate in the path
    for (int v = 1; v < totalVertices; v++) {
        if (isSafeToAdd(v, graph, path, pos)) {
            path[pos] = v; // Add 'v' to the path
            // Recur to construct the rest of the path
            if (findHamiltonianCycle(graph, path, pos + 1, totalVertices))
                return true;
            // If adding 'v' doesn't lead to a solution, backtrack
            path[pos] = -1;
        }
    }

    return false;
}

// Function to find and print the Hamiltonian cycle
void printHamiltonianCycle(vector<vector<int>>& graph, int totalVertices) {
    vector<int> path(totalVertices, -1); // Initialize all vertices as not included in the path
    path[0] = 0; // Start from vertex 0 as the first vertex of the path

    if (!findHamiltonianCycle(graph, path, 1, totalVertices)) {
        cout << "No Hamiltonian cycle exists" << endl;
        return;
    }

    cout << "Hamiltonian cycle exists: ";
    for (int i = 0; i < totalVertices; i++)
        cout << path[i] << " ";
    cout << path[0] << endl;
}

int main() {
    // Example graph represented by an adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    int totalVertices = graph.size();
    printHamiltonianCycle(graph, totalVertices);

    return 0;
}
