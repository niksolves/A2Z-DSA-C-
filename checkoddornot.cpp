
#include <iostream>
using namespace std;

bool isOdd(int n) {
    if ((n & 1) == 0) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (isOdd(n)) {
        cout << n << " is odd." << endl;
    } else {
        cout << n << " is even." << endl;
    }

    return 0;
}
