#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void dfs(int node, unordered_set<int>& visited, vector<vector<int>>& graph, vector<int>& component) {
        visited.insert(node);
        component.push_back(node);
        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                dfs(neighbor, visited, graph, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        unordered_set<int> visited;

        // Build adjacency list
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int completeCount = 0;

        // Traverse all nodes
        for (int i = 0; i < n; i++) {
            if (!visited.count(i)) {
                vector<int> component;
                dfs(i, visited, graph, component);

                // Check if the component is complete
                int size = component.size();
                int expectedEdges = (size * (size - 1)) / 2;
                int actualEdges = 0;

                for (int node : component) {
                    actualEdges += graph[node].size();
                }
                actualEdges /= 2; // Since each edge is counted twice in adjacency list

                if (actualEdges == expectedEdges) {
                    completeCount++;
                }
            }
        }

        return completeCount;
    }
};
