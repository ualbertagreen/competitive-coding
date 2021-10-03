class Solution {
public:
    
    int cellVal(vector<vector<int>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return 0;
        }
        
        if (board[i][j] == 2) return 0;
        if (board[i][j] == 3) return 1;
        
        else return board[i][j];
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        // 0->0:0
        // 0->1:2
        // 1->0:3
        // 1->1:1
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int neighborSum = 0;

                for (int m = -1; m < 2; m++) {
                    for (int n = -1; n < 2; n++) {
                        neighborSum += cellVal(board, i+m, j+n);
                    }
                }
                
                if (board[i][j] == 1) {                    
                    if (neighborSum < 3) board[i][j] = 3;
                    if (neighborSum > 4) board[i][j] = 3;
                }
                else if (board[i][j] == 0) {
                    if (neighborSum == 3) board[i][j] = 2;
                }
            }
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {                
                if (board[i][j] == 2) board[i][j] = 1;
                else if (board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};