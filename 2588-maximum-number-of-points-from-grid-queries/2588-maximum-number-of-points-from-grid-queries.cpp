class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int totalCells = m * n;
        vector<int> result(queries.size(), 0);

        // Sorting queries with original indices
        vector<pair<int, int>> queryIndices;
        for (int i = 0; i < queries.size(); i++)
            queryIndices.push_back({queries[i], i});
        sort(queryIndices.begin(), queryIndices.end());

        // Min-Heap (row, col, value)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        minHeap.push({grid[0][0], {0, 0}});

        // Visited grid
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        vector<int> dirX = {-1, 1, 0, 0}, dirY = {0, 0, -1, 1};

        int count = 0;  // Cells visited
        int threshold = 0;  // Smallest cell value we can access

        for (auto &[query, idx] : queryIndices) {
            while (!minHeap.empty() && minHeap.top().first < query) {
                auto [val, pos] = minHeap.top();
                minHeap.pop();
                int r = pos.first, c = pos.second;
                count++;  // We can reach this cell
                
                // Explore all 4 directions
                for (int d = 0; d < 4; d++) {
                    int nr = r + dirX[d], nc = c + dirY[d];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        minHeap.push({grid[nr][nc], {nr, nc}});
                    }
                }
            }
            result[idx] = count;  // Store result for this query
        }

        return result;
    }
};
