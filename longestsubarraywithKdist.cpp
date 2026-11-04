

#include <bits/stdc++.h>
using namespace std;

int kDistinctChar(string& s, int k) {

    int n = s.size();
    int maxlen = 0;

    // ---------------- BRUTE FORCE ----------------

    /*
    for (int i = 0; i < n; i++) {

        int cnt = 0;
        unordered_map<char, int> mpp;

        for (int j = i; j < n; j++) {

            // Check if character is appearing for the first time
            if (mpp.find(s[j]) == mpp.end()) {
                cnt++;
            }

            // If distinct characters exceed k, stop
            if (cnt > k) {
                break;
            }

            // Store character frequency
            mpp[s[j]]++;

            // Update maximum substring length
            maxlen = max(maxlen, j - i + 1);
        }
    }

    return maxlen;
    */

    // ---------------- OPTIMAL: SLIDING WINDOW ----------------

    int cnt = 0;
    int l = 0;
    int r = 0;

    unordered_map<char, int> mpp;

    while (r < n) {

        // Check if current character is new
        if (mpp.find(s[r]) == mpp.end()) {
            cnt++;
        }

        // Add current character to map
        mpp[s[r]]++;

        // Shrink window if distinct characters exceed k
        while (cnt > k) {

            // Remove the leftmost character
            mpp[s[l]]--;

            // If its frequency becomes zero, distinct count decreases
            if (mpp[s[l]] == 0) {
                cnt--;
                mpp.erase(s[l]);
            }

            // Move left pointer forward
            l++;
        }

        // Update maximum valid substring length
        maxlen = max(maxlen, r - l + 1);

        // Expand window
        r++;
    }

    return maxlen;
}

int main() {

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    cout << "Maximum substring length: "
         << kDistinctChar(s, k) << endl;

    return 0;
}
