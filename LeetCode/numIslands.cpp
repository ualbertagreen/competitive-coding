class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int> > bfs;
        
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs.push(pair<int, int>(i,j));
                    islands++;
                }
                
                while (!bfs.empty()) {
                    int x = bfs.front().first;
                    int y = bfs.front().second;
                    bfs.pop();

                    if (grid[x][y] == '1') {
                        if (x - 1 >= 0) bfs.push(pair<int, int>(x-1, y));
                        if (y - 1 >= 0) bfs.push(pair<int, int>(x, y-1));
                        if (x + 1 < grid.size()) bfs.push(pair<int, int>(x+1, y));
                        if (y + 1 < grid[x].size()) bfs.push(pair<int, int>(x, y+1)); 
                    }                    
                    grid[x][y] = '2';
                }
            }
        }
        
        return islands;
    }
};