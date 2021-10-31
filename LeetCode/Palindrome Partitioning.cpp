class Solution {
public:
    int checkPal(string s, int l, int r, vector<vector<char>> & isPal) {
        if (isPal[l][r] != 0) return isPal[l][r];
        if (l >= r) {
            isPal[l][r] = 2;
            return 2;
        }
        if (s[l] != s[r]) {
            isPal[l][r] = 1;
            return 1;
        }
        isPal[l][r] = checkPal(s, l+1, r-1, isPal);
        return isPal[l][r];
    }
    
    void recursivePartition(string s, int index, vector<vector<char>> & isPal, vector<vector<string>> & output, vector<string> cur) {
        if (index >= s.length()) {
            output.push_back(cur);
            return;
        }
        
        for (int i = index; i < s.length(); i++) {
            if (checkPal(s, index, i, isPal) == 2) {
                vector<string> tmp = cur;
                tmp.push_back(s.substr(index, i - index + 1));
                recursivePartition(s, i + 1, isPal, output, tmp);
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<char>> isPal(s.length(), vector<char>(s.length(), 0));
        vector<vector<string>> output;
        recursivePartition(s, 0, isPal, output, vector<string>());
        return output;
    }
};