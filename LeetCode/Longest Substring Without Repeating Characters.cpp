class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        
        int last = 0;
        int ans = 0;
        for (int i = 1; i < s.length()+1; i++) {
            last = std::max(last, seen[s[i-1]]);
            ans = std::max(ans, i - last);
            seen[s[i-1]] = i;
        }
        
        return ans;
    }
};