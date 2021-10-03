class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != i) {
                if (nums[nums[i]] == nums[i]) break;
                else {
                    int temp = nums[nums[i]];
                    nums[nums[i]] = nums[i];
                    nums[i] = temp;
                }
            }
        }
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != i) return i;
        }
        
        return nums.size();
    }
};