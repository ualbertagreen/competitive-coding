class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        
        int cur = n; //19
        while (cur != 1) {
            if (seen.find(cur) != seen.end()) break;
            seen.insert(cur); //19, 82, 68, 100
            
            int next = 0;
            while (cur) {
                int digit = cur % 10; //9, 1, 2, 8, 8, 6
                cur /= 10; //1, 0, 8, 0, 6, 0
                next += digit * digit; //81->82, 4->68, 64->100
            }
            
            cur = next; //82, 68, 100
        }
        
        if (cur == 1) return true;
        else return false;
    }
};