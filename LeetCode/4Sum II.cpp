class Solution {
public:
    /*
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> sum12;
        map<int, int> sum34;
        
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums1.size(); j++) {
                sum12[nums1[i]+nums2[j]]++;
                sum34[nums3[i]+nums4[j]]++;
            }
        }
        
        int ans = 0;
        auto it12 = sum12.begin();
        auto it34 = sum34.end();
        
        while (it12 != sum12.end() && it34 != sum34.begin()) {
            auto it34t = it34;
            it34t--;
            if (it12->first + it34t->first == 0) {
                ans += it12->second * it34t->second;
                it12++;
                it34--;
            }
            else if (it12->first + it34t->first < 0) {
                it12++;
            }
            else {
                it34--;
            }
        }
        
        return ans;
    }
    */
    
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sum12;
        unordered_map<int, int> sum34;
        
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums1.size(); j++) {
                sum12[nums1[i]+nums2[j]]++;
                sum34[nums3[i]+nums4[j]]++;
            }
        }
        
        int ans = 0;
        for (auto [n, v] : sum12) {
            ans += v * sum34[-n];
        }
        
        return ans;
    }
};