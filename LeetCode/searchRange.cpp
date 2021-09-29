class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { //[5,7,7,8,8,10]
        vector<int> output(2, -1);
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (output[0] == -1) output[0] = i;
                output[1] = i;
            }
        }
        
        return output;
    }
};