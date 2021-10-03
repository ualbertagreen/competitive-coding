class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) { //nums = [1,3,-1,-3,5,3,6,7], k = 3
        map<int, int> window;
        
        for (int i = 0; i < k; i++) {
            window[nums[i]]++;
        }
        
        vector<int> ans;
        ans.push_back(window.rbegin()->first);
        for (int i = 0; i < nums.size() - k; i++) {
            window[nums[i]]--;
            if (window[nums[i]] == 0)
                window.erase(nums[i]);
            window[nums[i+k]]++;
            ans.push_back(window.rbegin()->first);
        }
        
        return ans;
    }
};