class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        
        int l = left;
        int r = right;
        
        int ans = min(height[left], height[right]) * right;
        
        while (l < r) { //[2,3,4,5,18,17,6]
            if (height[l] < height[r]) l++;
            else r--;
            
            if (min(height[l], height[r]) * (r-l) > ans) { //12 < 15, 15 < 16
                left = l; //1, 2
                right = r;
                ans = min(height[left], height[right]) * (right-left);
            }
        }
        
        return ans;
    }
};