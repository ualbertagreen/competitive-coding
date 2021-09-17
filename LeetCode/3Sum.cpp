class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { //nums = [-1,0,1,2,-1,-4]
        sort(nums.begin(), nums.end()); // -4, -1, -1, 0, 1, 2
        vector<vector<int> > ans;
        
        
        for (int i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] > 0) break;
            
            int remain = 0 - nums[i];
            
            int a = i + 1;
            int b = nums.size() - 1;
            
            while (a < b) {
                if (nums[a] + nums[b] < remain)
                    do {
                        a++;
                    } while (a < b && nums[a-1] == nums[a]);
                else if (nums[a] + nums[b] > remain)
                    do {
                        b--;
                    } while (a < b && nums[b+1] == nums[b]);
                else {
                    ans.push_back({nums[i], nums[a], nums[b]});
                    do {
                        a++;
                    } while (a < b && nums[a-1] == nums[a]);
                    do {
                        b--;
                    } while (a < b && nums[b+1] == nums[b]);
                }
            }
            
            while (i + 1 < nums.size() && nums[i+1] == nums[i]) {
                i++;
            }
        }
        
        return ans;
    }
};