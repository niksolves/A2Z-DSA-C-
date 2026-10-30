#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int setRightmostUnsetBit(int n) {

        // Optimal approach
        if ((n & (n + 1)) == 0)
            return n;

        return n | (n + 1);


        // Approach 2: Using right shift
        /*
        int k = n;
        int i = 0;

        while (k != 0) {
            if ((k & 1) == 0) {
                break;
            }

            i++;
            k = k >> 1;
        }

        if (k == 0)
            return n;

        n = n | (1 << i);
        return n;
        */


        // Approach 3: Using binary string
        /*
        string res = "";

        if (n == 0)
            return 0;

        while (n != 0) {
            if (n % 2 == 1)
                res += '1';
            else
                res += '0';

            n = n / 2;
        }

        reverse(res.begin(), res.end());

        int len = res.size();

        for (int i = len - 1; i >= 0; i--) {
            if (res[i] == '0') {
                res[i] = '1';
                break;
            }
        }

        int value = 0;

        for (int i = len - 1; i >= 0; i--) {
            if (res[i] == '1')
                value += (1 << (len - i - 1));
        }

        return value;
        */
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Result: " << obj.setRightmostUnsetBit(n) << endl;

    return 0;
}