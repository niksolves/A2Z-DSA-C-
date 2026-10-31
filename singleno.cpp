
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {2, 3, 5, 3, 2};

    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = ans ^ nums[i];
    }

    cout << "Single number is: " << ans << endl;

    return 0;
}
