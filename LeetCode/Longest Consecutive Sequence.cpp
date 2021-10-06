class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nSet;
        
        for (int n : nums) {
            nSet.insert(n);
        }
        
        int ans = 0;
        for (int n : nums) {
            int count = 0;
            if (nSet.find(n-1) == nSet.end()) {
                int tmp = n;
                while (nSet.find(tmp) != nSet.end()) {
                    tmp++;
                    count++;
                }
                
            }
            
            ans = max(ans, count);
        }
        
        return ans;
    }
};