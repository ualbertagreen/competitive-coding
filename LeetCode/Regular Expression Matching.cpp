class Solution {
public:
    int recursiveMatch(string s, string p, int is, int ip, vector<vector<int>> & memo) {
        if (is >= s.length() && ip >= p.length()) return 2;
        if (is >= s.length() || ip >= p.length()) return 1;
        
        if (memo[is][ip] != 0) return memo[is][ip];
        
        if (p[ip] == '.' || p[ip] == s[is]) {
            if (ip+1 < p.length() && p[ip+1] == '*') {
                if (recursiveMatch(s, p, is, ip+2, memo) == 2) return memo[is][ip] = 2;
                if (recursiveMatch(s, p, is+1, ip, memo) == 2) return memo[is][ip] = 2;
                if (recursiveMatch(s, p, is+1, ip+2, memo) == 2) return memo[is][ip] = 2;                
            }
            
            return memo[is][ip] = recursiveMatch(s, p, is+1, ip+1, memo);            
        }
        
        if (ip+1 < p.length() && p[ip+1] == '*') return memo[is][ip] = recursiveMatch(s, p, is, ip+2, memo);   
        return memo[is][ip] = 1;
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.length()+1, vector<int>(p.length()+1, 0));
        return recursiveMatch(s+"A", p+"A", 0, 0, memo) == 2;
    }
};