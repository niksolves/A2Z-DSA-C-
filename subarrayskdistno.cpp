
#include <bits/stdc++.h>
using namespace std;

// Function to count subarrays with at most K distinct elements
int fxndistk(vector<int> nums, int k) {

    if (k < 0) return 0;

    map<int, int> mpp;

    int n = nums.size();
    int l = 0;
    int r = 0;
    int cnt = 0;

    while (r < n) {

        mpp[nums[r]]++;

        while (mpp.size() > k) {

            mpp[nums[l]]--;

            if (mpp[nums[l]] == 0) {
                mpp.erase(nums[l]);
            }

            l++;
        }

        cnt = cnt + (r - l + 1);

        r++;
    }

    return cnt;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {

    // Brute force approach

    /*
    int n = nums.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {

        unordered_map<int, int> mpp;

        for (int j = i; j < n; j++) {

            mpp[nums[j]]++;

            if (mpp.size() == k) {
                cnt++;
            }
            else if (mpp.size() > k) {
                break;
            }
        }
    }

    return cnt;
    */

    // Optimal approach

    // Exactly K = At most K - At most (K-1)

    int ans = fxndistk(nums, k) - fxndistk(nums, k - 1);

    return ans;
}

int main() {

    int n, k;

    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "Number of subarrays with exactly "
         << k << " distinct elements: "
         << subarraysWithKDistinct(nums, k) << endl;

    return 0;
}
