class Solution {
public:
    int findPeakElement(vector<int>& nums) { //[1,2,1,3,5,6,4], [1, 2, 3, 4, 5]
        if (nums.size() == 1) return 0;
        
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) return i;
        }
        
        return nums.size() - 1;
    }
};