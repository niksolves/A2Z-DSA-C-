#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        if (divisor == 0)
            return INT_MAX;

        if (dividend == divisor)
            return 1;

        bool sign = true;

        if (dividend >= 0 && divisor < 0)
            sign = false;
        else if (dividend < 0 && divisor >= 0)
            sign = false;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long quotient = 0;

        while (n >= d) {

            int cnt = 0;

            while (n >= (d << (cnt + 1))) {
                cnt++;
            }

            quotient += (1LL << cnt);

            n -= (d << cnt);
        }

        // Overflow handling
        if (quotient == (1LL << 31) && sign) {
            return INT_MAX;
        }

        if (quotient == (1LL << 31) && !sign) {
            return INT_MIN;
        }

        return sign ? (int)quotient : -(int)quotient;
    }
};

int main() {

    Solution obj;

    int dividend, divisor;

    cout << "Enter dividend: ";
    cin >> dividend;

    cout << "Enter divisor: ";
    cin >> divisor;

    cout << "Result: " << obj.divide(dividend, divisor);

    return 0;
}