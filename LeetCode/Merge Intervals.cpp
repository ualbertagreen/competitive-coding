class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) { //[[1,3],[2,6],[8,10],[15,18]], [[1,6],[2,3],[8,10],[15,18]]
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> output;
        output.push_back(intervals[0]); //[1,3]
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> cur = output[output.size()-1]; //[1,3]
            
            if (intervals[i][0] <= cur[1]) { //[2,6]
                output.pop_back();
                output.push_back({cur[0], max(intervals[i][1], cur[1])});//[1,6]
            }
            else {
                output.push_back(intervals[i]);
            }
        }
        
        return output;
    }
};