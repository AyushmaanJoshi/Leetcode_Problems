class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        // Step 1: Build the adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        
        // Step 2: Min-heap for Dijkstra (time, node)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> time(n, LLONG_MAX);  // Stores shortest time to reach each node
        vector<int> ways(n, 0);  // Stores number of ways to reach each node in shortest time
        
        // Step 3: Start Dijkstra from node 0
        pq.push({0, 0});  // {travel_time, node}
        time[0] = 0;
        ways[0] = 1;
        
        while (!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();
            
            if (currTime > time[node]) continue;  // Skip if this path is not the shortest
            
            for (auto& [neighbor, travelTime] : graph[node]) {
                long long newTime = currTime + travelTime;
                
                if (newTime < time[neighbor]) {
                    time[neighbor] = newTime;
                    ways[neighbor] = ways[node];  // Reset ways since we found a shorter path
                    pq.push({newTime, neighbor});
                } 
                else if (newTime == time[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;  // Add more ways
                }
            }
        }
        
        return ways[n - 1];  // Number of ways to reach the last node
    }
};
