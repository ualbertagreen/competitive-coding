class Solution {
public:
    int multi(vector<int>& nums, int l, int r, int i) {
        int tmp = nums[i];
        if (l > 0) tmp *= nums[l-1];
        if (r < nums.size()) tmp *= nums[r];
        return tmp;
    }
    int recursiveMaxCoins(vector<int>& nums, int l, int r, vector<vector<int>> & memo) { //[l, r)
        if (memo[l][r] != 0) return memo[l][r];
        if (l+1 == r) return multi(nums, l, r, l);
        
        int ans = 0;
        for (int i = l; i < r; i++) {
            int tmp = multi(nums, l, r, i);
            
            if (i != l) tmp += recursiveMaxCoins(nums, l, i, memo);
            if (i+1 != r) tmp += recursiveMaxCoins(nums, i+1, r, memo);
            
            ans = max(ans, tmp);
        }
        
        return memo[l][r] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size()+1, 0));
        
        return recursiveMaxCoins(nums, 0, nums.size(), memo);
    }
};