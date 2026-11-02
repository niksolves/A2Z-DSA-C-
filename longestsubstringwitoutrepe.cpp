

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {

    // Optimal
    int n = s.size();
    int maxlen = 0;
    int l = 0;
    int r = 0;

    vector<int> hash(256, -1);

    while (r < n) {

        if (hash[s[r]] != -1) {
            l = max(l, hash[s[r]] + 1);
        }

        hash[s[r]] = r;

        maxlen = max(maxlen, r - l + 1);

        r++;
    }

    // Better
    /*
    int n = s.size();
    int maxlen = 0;
    int l = 0;
    int r = 0;

    map<char, int> mpp;

    while (r < n) {
        mpp[s[r]]++;

        if (mpp[s[r]] > 1) {
            while (mpp[s[r]] > 1) {
                mpp[s[l]]--;
                l++;
            }
        }

        maxlen = max(r - l + 1, maxlen);
        r++;
    }
    */

    // Brute force
    /*
    for (int i = 0; i < n; i++) {
        map<char, int> mpp;

        for (int j = i; j < n; j++) {
            mpp[s[j]]++;

            if (mpp[s[j]] > 1) {
                break;
            }

            maxlen = max(maxlen, j - i + 1);
        }
    }
    */

    return maxlen;
}

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    cout << "Longest non-repeating substring length: "
         << lengthOfLongestSubstring(s) << endl;

    return 0;
}
