class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);
        
        for (int i = 1; i < nums.size(); i++) {
            output[i] = output[i-1] * nums[i-1];
        }
        
        int sufProd = 1;
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            output[i] *= sufProd;
            sufProd *= nums[i];
        }
        
        return output;
    }
};