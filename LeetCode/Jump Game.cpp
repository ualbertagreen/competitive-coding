class Solution {
public:
    int recursiveCanJump(vector<int>& nums, int index, vector<char> & memo) {
        if (index + 1 >= nums.size()) return 2;
        if (memo[index] != 0) return memo[index];
        
        for (int i = nums[index]; i >= 1; i--) {
            if (recursiveCanJump(nums, index+i, memo) == 2) return memo[index] = 2;
        }
        
        return memo[index] = 1;
    }
    
    bool canJump(vector<int>& nums) {
        vector<char> memo(nums.size(), 0);
        return recursiveCanJump(nums, 0, memo) == 2;
    }
};