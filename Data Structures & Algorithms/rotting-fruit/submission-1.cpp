class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        int fresh = 0;
        
        // 1. Collect all initially rotten oranges and count fresh ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        if (fresh == 0) return 0;
        
        int minutes = 0;
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        // 2. Multi-source BFS
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            minutes++;
            
            while (size--) {
                auto [r, c] = q.front();
                q.pop();
                
                for (auto& dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // Mark as rotten in-place (no visited matrix needed)
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return fresh == 0 ? minutes : -1;
    }
};