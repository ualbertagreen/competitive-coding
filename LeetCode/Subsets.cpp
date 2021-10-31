class Solution {
public:
    void recursiveSubsets(vector<int>& nums, int index, vector<vector<int>> & output, vector<int> cur) {
        if (index >= nums.size()) {
            output.push_back(cur);
            return;
        }
        recursiveSubsets(nums, index+1, output, cur);
        cur.push_back(nums[index]);
        recursiveSubsets(nums, index+1, output, cur);        
    }
        
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        recursiveSubsets(nums, 0, output, vector<int>());
        return output;
    }
};