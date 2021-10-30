    bool compareInts(string a, string b) {
        string x = a+b;
        string y = b+a;
        return x < y;
    }

class Solution {
public:
    
    string largestNumber(vector<int>& nums) {        
        vector<string> num_strings;
        for (int i : nums) {
            stringstream ss;
            ss<<i;
            string tmp;
            ss>>tmp;
            num_strings.push_back(tmp);
        }
        
        sort(num_strings.begin(), num_strings.end(), compareInts);
        
        string output = "";
        for (int i = num_strings.size()-1; i >= 0; i--) {
            output += num_strings[i];
        }
        
        if (output[0] == '0') return "0";
        return output;
    }
};