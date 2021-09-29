class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {//nums = [1,1,1,2,2,3], k = 2
        unordered_map<int, int> count;
        
        for (int i : nums) { //1-3, 2-2, 3-1
            count[i]++;
        }
        
        vector<pair<int, int>> s;
        for (auto e : count) {
            s.push_back(pair<int, int>(e.second, e.first)); // 3-1, 2-2, 1-3
        }
        
        sort(s.begin(), s.end());
        
        vector<int> output;
        for (int i = (int)s.size() - 1; i >= (int)s.size() - k; i--) {
            output.push_back(s[i].second);
        }
        
        return output;
    }
};