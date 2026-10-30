
#include <iostream>
using namespace std;

int minBitsFlip(int start, int goal) {

    // Optimal approach using XOR
    int x = start ^ goal;
    int cnt = 0;

    while (x != 0) {
        cnt += x & 1;
        x >>= 1;
    }

    return cnt;


    // Alternative approach: bit-by-bit comparison

    /*
    int cnt = 0;

    while (start != 0 && goal != 0) {
        if ((start & 1) != (goal & 1)) {
            cnt++;
        }

        start = start >> 1;
        goal = goal >> 1;
    }

    while (start != 0) {
        if (start & 1) cnt++;
        start = start >> 1;
    }

    while (goal != 0) {
        if (goal & 1) cnt++;
        goal = goal >> 1;
    }

    return cnt;
    */
}

int main() {
    int start, goal;

    cout << "Enter start: ";
    cin >> start;

    cout << "Enter goal: ";
    cin >> goal;

    cout << "Minimum bit flips: " << minBitsFlip(start, goal) << endl;

    return 0;
}
