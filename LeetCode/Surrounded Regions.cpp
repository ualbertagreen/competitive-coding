class Solution {
public:
    char valBoard(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return 0;
        else return board[x][y];
    }
    
    void solve(vector<vector<char>>& board) {
        
        queue<pair<int, int>> fill;
        
        for (int i = 0; i < board.size(); i++) {
            fill.push({i, 0});
            fill.push({i, board[0].size()-1});
        }
        for (int i = 0; i < board[0].size(); i++) {
            fill.push({0, i});
            fill.push({board.size()-1, i});
        }
        
        while (!fill.empty()) {
            auto [x, y] = fill.front();
            fill.pop();
            
            if (valBoard(board, x, y) == 'O') {
                board[x][y] = '*';
                fill.push({x-1, y});
                fill.push({x, y-1});
                fill.push({x+1, y});
                fill.push({x, y+1});
            }
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '*') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};