#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap(int &a, int &b) {

        // Approach 1: Using XOR
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;


        // Approach 2: Using addition and subtraction
        /*
        a = a + b;
        b = a - b;
        a = a - b;
        */


        // Approach 3: Using a temporary variable
        /*
        int temp;
        temp = a;
        a = b;
        b = temp;
        */
    }
};

int main() {
    Solution obj;

    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    obj.swap(a, b);

    cout << "After swapping:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}