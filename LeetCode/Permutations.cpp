class Solution {
public:
    void recursivePermute(unordered_set<int> pool, vector<vector<int>> & output, vector<int> cur) {
        if (pool.empty()) output.push_back(cur);
        
        for (int i : pool) {
            unordered_set<int> tmp = pool;
            tmp.erase(i);
            vector<int> curL = cur;
            curL.push_back(i);
            recursivePermute(tmp, output, curL);
        }            
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> pool;
        for (int n : nums) {
            pool.insert(n);
        }
        
        vector<vector<int>> output;
        recursivePermute(pool, output, vector<int>());
        return output;
    }
};