class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        
        for (int n : nums) {
            if (n == 0) zeros++;
            if (n == 1) ones++;
            if (n == 2) twos++;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (zeros) {
                nums[i] = 0;
                zeros--;
            }
            else if (ones) {
                nums[i] = 1;
                ones--;
            }
            else {
                nums[i] = 2;
            }
        }
    }
};