

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Optimal approach: Counts subarrays with sum <= goal
    int goalless(vector<int>& nums, int n, int goal) {

        // If goal is negative, no valid subarray exists
        if(goal < 0) return 0;

        int sum = 0;
        int cnt = 0;
        int i = 0;

        for(int j = 0; j < n; j++) {

            // Expand the window
            sum = sum + nums[j];

            // Shrink the window if sum exceeds goal
            while(sum > goal) {
                sum = sum - nums[i];
                i++;
            }

            // Count all valid subarrays ending at j
            cnt = cnt + (j - i + 1);
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // BRUTE FORCE APPROACH
        /*
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n; i++) {

            int sum = 0;

            for(int j = i; j < n; j++) {

                sum = sum + nums[j];

                if(sum > goal) {
                    break;
                }

                if(sum == goal) {
                    cnt++;
                }
            }
        }

        return cnt;
        */

        // OPTIMAL APPROACH
        // Exactly(goal) = AtMost(goal) - AtMost(goal - 1)

        int n = nums.size();

        int ans = goalless(nums, n, goal)
                - goalless(nums, n, goal - 1);

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << obj.numSubarraysWithSum(nums, goal);

    return 0;
}
