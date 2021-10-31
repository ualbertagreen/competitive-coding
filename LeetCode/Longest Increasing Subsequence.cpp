class Solution {
public:    
    int lengthOfLIS(vector<int>& nums) {
        map<int, int> leading;
        
        for (int i = 0; i < nums.size(); i++) {
            int length = 0;
            for (auto [l, n] : leading) { //use binary search for O(n log(n))
                if (n < nums[i]) length = max(length, l);
            }
            length++;

            if (leading.find(length) == leading.end()) leading[length] = nums[i];
            else leading[length] = min(leading[length], nums[i]);
        }
        
        return (leading.end()--)->first;
    }
};