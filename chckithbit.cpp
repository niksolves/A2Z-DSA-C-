
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool checkIthBit(int n, int i) {
    // Optimal approach using bit manipulation
    return (n & (1 << i)) != 0;

    // String approach
    /*
    string res = "";
    if (n == 0) return false;

    while (n != 0) {
        if (n % 2 == 1) {
            res = res + '1';
        } else {
            res = res + '0';
        }
        n = n / 2;
    }

    reverse(res.begin(), res.end());

    int len = res.size();
    int k = len - 1 - i;

    for (int j = len - 1; j >= 0; j--) {
        if (j == k && res[j] == '1') {
            return true;
        }
    }

    return false;
    */
}

int main() {
    int n, i;

    cout << "Enter the number: ";
    cin >> n;

    cout << "Enter the bit position (0-based): ";
    cin >> i;

    if (i < 0 || i >= 31) {
        cout << "Invalid bit position." << endl;
        return 0;
    }

    if (checkIthBit(n, i)) {
        cout << "The " << i << "th bit is set (1)." << endl;
    } else {
        cout << "The " << i << "th bit is not set (0)." << endl;
    }

    return 0;
}
