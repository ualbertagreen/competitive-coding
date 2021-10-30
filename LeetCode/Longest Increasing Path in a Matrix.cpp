class Solution {
public:
    int findLongest(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& longest) {
        if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[x].size()) return 0;
        if (longest[x][y] != 0) return longest[x][y];
        
        int path = 0;
        
        if (x-1 >= 0 && matrix[x][y] > matrix[x-1][y])
            path = max(path, findLongest(matrix, x-1, y, longest));
        if (x+1 < matrix.size() && matrix[x][y] > matrix[x+1][y])
            path = max(path, findLongest(matrix, x+1, y, longest));
        if (y-1 >= 0 && matrix[x][y] > matrix[x][y-1])
            path = max(path, findLongest(matrix, x, y-1, longest));
        if (y+1 < matrix[x].size() && matrix[x][y] > matrix[x][y+1])
            path = max(path, findLongest(matrix, x, y+1, longest));
        
        longest[x][y] = path+1;
        return longest[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int path = 0;
        
        vector<vector<int>> longest(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                path = max(path, findLongest(matrix, i, j, longest));
            }
        }
        
        return path;
    }
};