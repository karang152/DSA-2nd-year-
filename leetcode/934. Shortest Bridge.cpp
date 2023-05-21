//https://leetcode.com/problems/shortest-bridge/submissions/954660903/




class Solution {
public:
    void dfs(int r, int c, queue<pair<int, int>>& q, vector<vector<int>>& grid, int n) {
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] == -1 || grid[r][c] == 0) return;
        
        q.push({r, c});
        grid[r][c] = -1;
        
        dfs(r - 1, c, q, grid, n);
        dfs(r + 1, c, q, grid, n);
        dfs(r, c - 1, q, grid, n);
        dfs(r, c + 1, q, grid, n);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int ans = 0;
        int n = grid.size();
        bool ok = true;
        
        for (int i = 0; i < n; i++) {
            if (ok) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        dfs(i, j, q, grid, n);
                        ok = false;
                        break;
                    }
                }
            }
        }
        
        vector<int> dr = {0, 0, -1, 1};
        vector<int> dc = {-1, 1, 0, 0};
        
        while (!q.empty()) {
            int s = q.size();
            ans++;
            
            for (int i = 0; i < s; i++) {
                auto temp = q.front();
                q.pop();
                int curr_r = temp.first;
                int curr_c = temp.second;
                
                for (int j = 0; j < 4; j++) {
                    int nr = curr_r + dr[j];
                    int nc = curr_c + dc[j];
                    
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
                        if (grid[nr][nc] == 0) {
                            q.push({nr, nc});
                            grid[nr][nc] = -1;
                        } else if (grid[nr][nc] == 1) {
                            return ans - 1;
                        }
                    }
                }
            }
        }
        
        return ans - 1;
    }
};
