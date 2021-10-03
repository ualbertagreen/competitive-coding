class Solution {
public:
    bool subset(unordered_map<char, int>& s, unordered_map<char, int>& t){
        for (auto [c, v] : t) {
            if (s[c] < v) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;
        
        for (char c : t) {
            tMap[c]++;
        }
        
        //s = "ADOBECODEBANC", t = "ABC"
        unordered_map<char, int> sMap;
        int l = 0, r = s.size();
        for (int i = 0, j = 0; i < s.length(); i++) { //[j ,i]
            sMap[s[i]]++; //i = 5, 6
            bool restoreJ = false;
            while (subset(sMap, tMap)) { //CEODEBA
                sMap[s[j]]--;
                j++;
                restoreJ = true;
            }
            if (restoreJ) {
                j--;
                sMap[s[j]]++;
                if (i - j < r - l) { //0-5, 
                    l = j;
                    r = i;
                }
            }
        }
        
        if (r < s.size()) {
            string output = "";
            for (int i = l; i <= r; i++) {
                output+=s[i];
            }
            return output;
        }
        else return "";
    }
};