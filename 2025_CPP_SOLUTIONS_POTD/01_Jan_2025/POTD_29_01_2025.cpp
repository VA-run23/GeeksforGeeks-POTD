// User function Template for C++
class Solution {
public:
    double power(double b, int e) {
        // code here
        if (e == 0) return 1;  
        if (b == 0) return 0;  
        double result = 1.0;
        long long exp = abs((long long)e);  

        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= b;
            }
            b *= b;
            exp /= 2;
        }
        return e < 0 ? 1 / result : result;  
    }
};