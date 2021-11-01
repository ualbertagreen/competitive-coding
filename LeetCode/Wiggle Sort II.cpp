class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> tmp = nums;
        
        for(int i = 0; i < nums.size(); i++) {
            if (i % 2) nums[i] = tmp[i/2];
            else nums[i] = tmp[(i + nums.size())/2];
        }
    }
};