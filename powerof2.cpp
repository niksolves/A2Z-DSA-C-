
#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;

    // Optimal approach using bit manipulation
    if ((n & (n - 1)) == 0) {
        return true;
    }

    return false;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOfTwo(n)) {
        cout << n << " is a power of two." << endl;
    } else {
        cout << n << " is not a power of two." << endl;
    }

    return 0;
}
