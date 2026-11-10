
#include <bits/stdc++.h>
using namespace std;

// Function to count subarrays with at most 'goal' odd numbers
int goalless(vector<int>& nums, int n, int goal) {

    if (goal < 0) return 0;

    int sum = 0;
    int cnt = 0;
    int i = 0;

    for (int j = 0; j < n; j++) {

        sum = sum + (nums[j] % 2);

        while (sum > goal) {
            sum = sum - (nums[i] % 2);
            i++;
        }

        cnt = cnt + (j - i + 1);
    }

    return cnt;
}

int numberOfOddSubarrays(vector<int>& nums, int k) {

    int n = nums.size();

    // Optimal approach: Exactly K = At most K - At most (K-1)
    int ans = goalless(nums, n, k) - goalless(nums, n, k - 1);

    return ans;

    // Brute force approach:

    /*
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int checker = 0;

        for (int j = i; j < n; j++) {

            if (nums[j] % 2 != 0) {
                checker++;
            }

            if (checker == k) {
                cnt++;
            }
        }
    }

    return cnt;
    */
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
         << k << " odd numbers: "
         << numberOfOddSubarrays(nums, k) << endl;

    return 0;
}
