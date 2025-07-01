// approach 1: using dijkstras with queqe striver

class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n=grid.size();
            int m = grid[0].size();
            if(grid[0][0]!=0 || grid[n-1][m-1]!=0){
                return -1;
            }
             if(grid[0][0]==0 && n==1 && m==1){
                return 1;
            }
            vector<vector<int>> dist(n,vector<int>(m,1e7));
            dist[0][0]=0;
            queue<pair<int,pair<int,int>>> q;
            q.push({1,{0,0}});
            vector<int> drow = {0,1,-1,0,1,-1,1,-1};
            vector<int> dcol = {1,0,0,-1,1,1,-1,-1};
             while(!q.empty()){
                auto it = q.front();
                q.pop();
                int dis = it.first;
                int row = it.second.first;
                int col = it.second.second;
                for(int i=0; i<8; i++){
                    int nrow = row+drow[i];
                    int ncol = col+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && dis+1<dist[nrow][ncol] && grid[nrow][ncol]==0){
                        dist[nrow][ncol] = dis+1;
                        if(nrow == n-1 && ncol == m-1){
                            return dis+1;
                        }
                        q.push({dis+1,{nrow,ncol}});
                    }
                }
            }
            return -1;
        }
    };



// approach 2: using bfs

class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            
            // Check if start or end cell is blocked
            if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
                return -1;
            }
    
            // Directions for 8 possible moves
            vector<pair<int, int>> directions = {
                {0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
            };
    
            // BFS queue: {row, col, distance}
            queue<vector<int>> q;
            q.push({0, 0, 1});
    
            // Visited array
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            vis[0][0] = true;
    
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
    
                int row = cur[0];
                int col = cur[1];
                int dist = cur[2];
    
                // If we reach the bottom-right cell, return the distance
                if (row == n - 1 && col == n - 1) {
                    return dist;
                }
    
                // Explore all 8 directions
                for (auto& d : directions) {
                    int newRow = row + d.first;
                    int newCol = col + d.second;
    
                    // Check if the new cell is valid and unvisited
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                        grid[newRow][newCol] == 0 && !vis[newRow][newCol]) {
                        vis[newRow][newCol] = true; // Mark as visited
                        q.push({newRow, newCol, dist + 1});
                    }
                }
            }
    
            // If no path is found, return -1
            return -1;
        }
    };