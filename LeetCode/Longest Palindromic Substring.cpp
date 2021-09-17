class Solution {
public:
    //babad
    string longestPalindrome(string s) {
        int ans = 0;
        int a = 0;
        int b = -1;
        for (int i = 0; i < s.length(); i++) {
            int j = 0;
            while (i - j >= 0 && i + j < s.length()) {
                if (s[i-j] == s[i + j]) {
                    if (2 * j + 1 > ans) {
                        ans = 2 * j + 1;
                        a = i - j;
                        b = i + j;
                    }
                    j++;
                }
                else break;
            }
            
            j = 0;
            while (i - j >= 0 && i + j + 1 < s.length()) {
                if (s[i-j] == s[i + j + 1]) {
                    if (2 * (j + 1) > ans) {
                        ans = 2 * (j + 1);
                        a = i - j;
                        b = i + j + 1;
                    }
                    j++;
                }
                else break;
            }
        }
        
        string out = "";
        for (int i = a; i <= b; i++) {
            out += s[i];
        }
        
        return out;
    }
};