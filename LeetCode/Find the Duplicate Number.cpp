class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ i;
            ans = ans ^ nums[i];
        }
        */
        
        int tort = 0;
        int hare = 0;
        
        //tort (x - k) % L steps in the loop
        //hare (2x - k) % L steps in the loop
        //(x - k) == (2x - k) % L
        //(x == 2x) % L
        //x % L == 0
        do {
            tort = nums[tort];
            hare = nums[nums[hare]];
        } while (tort != hare);
        
        hare = 0;
        
        while (tort != hare) {
            tort = nums[tort];
            hare = nums[hare];            
        }
        
        return tort;
    }
};