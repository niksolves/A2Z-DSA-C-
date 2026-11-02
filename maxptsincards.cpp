
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardScore, int k) {

        if (k == 0) return 0;

        int i = 0;
        int j = k - 1;
        int sum = 0;
        int lastptr;
        int n = cardScore.size();

        for (int i = 0; i <= k - 1; i++) {
            sum = sum + cardScore[i];
            lastptr = i;
        }

        i = lastptr;
        j = n - 1;

        int maxsum = sum;
        int poss = 1;

        while (poss < (k + 1)) {
            sum = sum - cardScore[i];
            sum = sum + cardScore[j];

            maxsum = max(sum, maxsum);

            i--;
            j--;
            poss++;
        }

        return maxsum;
    }
};

int main() {

    Solution obj;

    int n, k;

    cout << "Enter number of cards: ";
    cin >> n;

    vector<int> cardScore(n);

    cout << "Enter card scores: ";
    for (int i = 0; i < n; i++) {
        cin >> cardScore[i];
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "Maximum score: " << obj.maxScore(cardScore, k) << endl;

    return 0;
}