class Solution {
public:
    bool recursiveSearch(vector<vector<char>>& board, string word, int index, int x, int y) {
        if (index == word.length()) return true;
        if (x < 0 || y < 0 || x >= board.size() || y >= board[x].size()) return false;
        if (board[x][y] != word[index]) return false; 
        
        char temp = board[x][y];
        board[x][y] = 0;
        if (recursiveSearch(board, word, index + 1, x - 1, y)) return true; 
        if (recursiveSearch(board, word, index + 1, x + 1, y)) return true; 
        if (recursiveSearch(board, word, index + 1, x, y - 1)) return true; 
        if (recursiveSearch(board, word, index + 1, x, y + 1)) return true; 
        board[x][y] = temp;
        
        return false;
    }
    
    //[["A","B","C","E"]
    // ["S","F","C","S"]
    // ["A","D","E","E"]]
    bool exist(vector<vector<char>>& board, string word) {
        set<pair<vector<vector<bool>>, pair<int, int>>> mask;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (recursiveSearch(board, word, 0, i, j)) 
                    return true;
            }
        }
        
        return false;
    }
};