// matrix = [[1, 4, 7, 11, 15],
//           [2, 5, 8, 12, 19],
//           [3, 6, 9, 16, 22],
//           [10,13,14,17, 24],
//           [18,21,23,26, 30]], target =5 

class Solution {
public:
    bool HLineSearch(vector<vector<int>>& matrix, int row, int a, int b, int target) {
        int lb = a;
        int rb = b+1;
        //[lb, rb)
        
        while (lb + 1 < rb) {
            int mid = (lb + rb) / 2;
            if (target < matrix[row][mid]) rb = mid;
            else lb = mid;
        }
        
        if (matrix[row][lb] == target) return true;
        else return false;
    }
    
    bool VLineSearch(vector<vector<int>>& matrix, int a, int b, int col, int target) {
        int lb = a;
        int rb = b+1;
        //[lb, rb)
        
        while (lb + 1 < rb) {
            int mid = (lb + rb) / 2;
            if (target < matrix[mid][col]) rb = mid;
            else lb = mid;
        }
        
        if (matrix[lb][col] == target) return true;
        else return false;
    }
    
    bool recursiveSearch(vector<vector<int>>& matrix, int ub, int bb, int lb, int rb, int target) {
        if (ub + 1 >= bb) {
            if (HLineSearch(matrix, ub, lb, rb, target)) return true;
            if (HLineSearch(matrix, bb, lb, rb, target)) return true;
            return false;
        }
        if (lb + 1 >= rb) {
            if (VLineSearch(matrix, ub, bb, lb, target)) return true;
            if (VLineSearch(matrix, ub, bb, rb, target)) return true;
            return false;
        }
        
        //[lb, rb], [ub, db]
        int Vmid = (ub + bb) / 2; //2, 1
        int Hmid = (lb + rb) / 2; //2, 1
        
        if (target < matrix[Vmid][Hmid]) { //9
            if (recursiveSearch(matrix, ub, Vmid, lb, Hmid, target)) return true; 
            if (target >= matrix[ub][Hmid+1]) //false,
                if (recursiveSearch(matrix, ub, Vmid-1, Hmid+1, rb, target)) return true; 
            if (target >= matrix[Vmid+1][lb]) //false,
                if (recursiveSearch(matrix, Vmid+1, bb, lb, Hmid-1, target)) return true; 
        }
        else { //5
            if (recursiveSearch(matrix, Vmid, bb, Hmid, rb, target)) return true; 
            if (target <= matrix[Vmid-1][rb]) //false
                if (recursiveSearch(matrix, ub, Vmid-1, Hmid+1, rb, target)) return true;
            if (target <= matrix[bb][Hmid-1]) //true
                if (recursiveSearch(matrix, Vmid+1, bb, lb, Hmid-1, target)) return true;
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lb = 0;
        int ub = 0;
        int bb = (int)matrix.size() - 1; //4
        int rb = (int)matrix[0].size() - 1; //4
        
        return recursiveSearch(matrix, ub, bb, lb, rb, target);
    }
};