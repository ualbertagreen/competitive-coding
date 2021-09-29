class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char> > key;
        
        key.push_back({}); //0
        key.push_back({}); //1
        key.push_back({'a', 'b', 'c'}); //2
        key.push_back({'d', 'e', 'f'}); //3
        key.push_back({'g', 'h', 'i'}); //4
        key.push_back({'j', 'k', 'l'}); //5
        key.push_back({'m', 'n', 'o'}); //6
        key.push_back({'p', 'q', 'r', 's'}); //7
        key.push_back({'t', 'u', 'v'}); //8
        key.push_back({'w', 'x', 'y', 'z'}); //9
        
        vector<string> output(1, "");
        for (int i = 0; i < digits.length(); i++) {
            int d = digits[i] - '0';
            
            vector<string> temp = output;
            output.clear();
            for (int j = 0; j < key[d].size(); j++) {
                for (int k = 0; k < temp.size(); k++) {
                    output.push_back(temp[k] + key[d][j]);
                }
            }
        }
        
        if (digits.length() == 0) output.clear();
        return output;
    }
};