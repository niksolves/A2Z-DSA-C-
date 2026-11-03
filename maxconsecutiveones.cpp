#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int cnt = 0;
        int maxlen = 0;
        int n = nums.size();

        int l = 0;
        int r = 0;

        while (r < n) {

            if (nums[r] == 0) {
                cnt++;
            }

            while (cnt > k) {
                if (nums[l] == 0) {
                    cnt--;
                }
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};

int main() {
    Solution obj;

    int n, k;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "Longest consecutive ones: "
         << obj.longestOnes(nums, k) << endl;

    return 0;
}