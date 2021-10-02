class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        
        int top = 0;
        int bottom = (int)matrix.size() - 1;
        int left = 0;
        int right = (int)matrix[0].size() - 1;
        
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                output.push_back(matrix[top][i]);
            }
                top++;
            if (top > bottom) break;
            
            for (int i = top; i <= bottom; i++) {
                output.push_back(matrix[i][right]);
            }
                right--;
            if (left > right) break;
            
            for (int i = right; i >= left; i--) {
                output.push_back(matrix[bottom][i]);
            }
                bottom--;
            if (top > bottom) break;
            
            for (int i = bottom; i >= top; i--) {
                output.push_back(matrix[i][left]);
            }
                left++;
        }
        
        return output;
    }
    
};