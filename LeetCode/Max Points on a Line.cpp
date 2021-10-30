class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int output = min((int)points.size(), 2);
        
        for (vector<int> p : points) {
            for (vector<int> q : points) {
                if (p != q) {
                    int count = 2;
                    int run = p[0]-q[0];
                    int rise = p[1]-q[1];
                    int g = gcd(run, rise);
                    if (g != 0) {
                        run /= g;
                        rise /= g;
                    }
                    for (vector<int> r : points) {
                        if (r != p && r != q) {
                            if ((r[0] - p[0]) * rise == (r[1] - p[1]) * run) 
                                count++;
                        }
                    }
                    
                    output = max(count, output);
                }
            }
        }
        
        return output;
    }
};