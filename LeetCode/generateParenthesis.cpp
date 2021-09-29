class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<tuple<string, int, int> > output(1, tuple<string, int, int>("", 0, n));
        
        for (int i = 0; i < n * 2; i++) {
            vector<tuple<string, int, int> > temp = output;
            output.clear();
            
            for (int j = 0; j < temp.size(); j++) {
                if (get<1>(temp[j]) > 0) 
                    output.push_back(tuple<string, int, int>(get<0>(temp[j]) + ')', get<1>(temp[j])-1, get<2>(temp[j])));
                if (get<2>(temp[j]) > 0) 
                    output.push_back(tuple<string, int, int>(get<0>(temp[j]) + '(', get<1>(temp[j])+1, get<2>(temp[j])-1));
            }
        }
        
        vector<string> ans;
        for (int i = 0;  i < output.size(); i++) 
            ans.push_back(get<0>(output[i]));
        
        return ans;
    }
};