class Solution {
public:
    int search(vector<int>& nums, int target) { //nums = [4,5,6,7,0,1,2], target = 0
        //interval [lb, rb)
        int lb = 0; //0, 3, 3, 4
        int rb = nums.size(); //7, 7, 5, 5
        
        while (lb < rb - 1) {
            int mid = (lb + rb) / 2; //3-7, 5-1, 4-0
            if (nums[lb] > nums[mid]) {
                if (target >= nums[lb] || target < nums[mid]) rb = mid;//5
                else lb = mid; //4
            }
            else if (nums[rb-1] < nums[mid]) {
                if (target >= nums[mid] || target < nums[lb]) lb = mid; //3
                else rb = mid;
            }
            else {
                if (target < nums[mid]) rb = mid;
                else lb = mid;
            }
        }
        
        if (nums[lb] == target) {
            return lb;
        }
        else {
            return -1;
        }
    }
};