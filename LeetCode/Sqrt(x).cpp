class Solution {
public:
    int mySqrt(int x) { // 30
        int lb = 0;
        int rb = 1;
        
        while ((long)rb * (long)rb <= (long)x) {
            lb = rb; //4, 4, 5
            rb *= 2; //8, 6, 6
        }
        
        //[lb, rb)
        while (lb + 1 < rb) {
            int mid = (lb + rb) / 2; //6, 5
            if ((long)x < (long)mid * (long)mid) rb = mid;
            else lb = mid;
        }
        
        return (int) lb;
    }
};