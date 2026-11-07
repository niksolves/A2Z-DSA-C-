
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        // Optimal: Sliding Window + Two Pointers

        int n = s.size();
        int m = t.size();

        int hash[256] = {0};

        // Store frequency of characters in t
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        int l = 0;
        int r = 0;
        int cnt = 0;

        int minLen = INT_MAX;
        int sIndex = -1;

        while (r < n) {

            // If character is still required
            if (hash[s[r]] > 0) {
                cnt = cnt + 1;
            }

            // Decrease frequency
            hash[s[r]]--;

            // When all required characters are found
            while (cnt == m) {

                // Update minimum window
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }

                // Shrink the window from left
                hash[s[l]]++;

                // Check if a required character is missing
                if (hash[s[l]] > 0) {
                    cnt = cnt - 1;
                }

                l++;
            }

            r++;
        }

        // Return the minimum window
        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);


        /*
        // Brute Force

        int n = s.size();
        int m = t.size();

        int minLen = INT_MAX;
        int sIndex = -1;

        int hash[256] = {0};

        // Store frequency of characters in t
        for (int j = 0; j < m; j++) {
            hash[t[j]]++;
        }

        for (int i = 0; i < n; i++) {

            // Make a fresh copy of hash for every starting index
            int temp[256];
            copy(hash, hash + 256, temp);

            int cnt = 0;

            // Generate substrings starting from i
            for (int j = i; j < n; j++) {

                if (temp[s[j]] > 0) {
                    cnt++;
                }

                temp[s[j]]--;

                // All required characters found
                if (cnt == m) {

                    if (j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        sIndex = i;
                    }

                    break;
                }
            }
        }

        if (sIndex == -1) return "";

        return s.substr(sIndex, minLen);
        */
    }
};

// Driver code
int main() {

    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution obj;

    cout << "Minimum Window Substring: "
         << obj.minWindow(s, t) << endl;

    return 0;
}
