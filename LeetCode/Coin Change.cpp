class Solution {
public:
    int recursiveCoinChange(vector<int>& coins, int amount, vector<int> & memo) {
        if (memo[amount] != -2) return memo[amount];
        
        for (int c : coins) {
            if (amount - c >= 0) {
                int tmp = recursiveCoinChange(coins, amount - c, memo);
                if (tmp != -1) {
                    if (memo[amount] < 0) memo[amount] = tmp + 1;
                    else memo[amount] = min(tmp + 1, memo[amount]);
                }
            }
        }
        
        if (memo[amount] == -2) memo[amount] = -1;
        return memo[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, -2);
        memo[0] = 0;
        return recursiveCoinChange(coins, amount, memo);
    }
};