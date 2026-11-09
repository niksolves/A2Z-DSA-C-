

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();
        int cnt = 0;

        // OPTIMAL APPROACH: Last Seen Index
        vector<int> lastseen = {-1, -1, -1};

        for(int i = 0; i < n; i++) {

            // Update the last seen index of the current character
            lastseen[s[i] - 'a'] = i;

            // Check whether all three characters have been seen
            if(lastseen[0] != -1 &&
               lastseen[1] != -1 &&
               lastseen[2] != -1) {

                // Count valid substrings ending at index i
                cnt = cnt + (1 + min(lastseen[0],
                                min(lastseen[1], lastseen[2])));
            }
        }

        /*
        // BRUTE FORCE APPROACH

        for(int i = 0; i < n; i++) {

            vector<int> hasharr(3, 0);

            for(int j = i; j < n; j++) {

                hasharr[s[j] - 'a'] = 1;

                if(hasharr[0] + hasharr[1] + hasharr[2] == 3) {

                    // cnt++; // Brute force

                    cnt = cnt + (n - j); // Brute force optimization

                    break;
                }
            }
        }
        */

        return cnt;
    }
};

int main() {

    Solution obj;

    string s = "abcabc";

    cout << obj.numberOfSubstrings(s) << endl;

    return 0;
}
