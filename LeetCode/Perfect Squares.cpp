class Solution {
public:
    int ans(int n, vector<int>& sums) {
        if (sums[n] != 10001) return sums[n];
        for (int i = 1; i*i <= n / 2; i++) {
            sums[n] = min(sums[n], ans(i*i, sums)+ans(n-i*i, sums));
        }
        return sums[n];
    }
    
    int numSquares(int n) {
        vector<int> sums(10001, 10001);
        for (int i = 1; i <= 100; i++) {
            sums[i*i] = 1;
        }
        
        return ans(n, sums);
    }
};