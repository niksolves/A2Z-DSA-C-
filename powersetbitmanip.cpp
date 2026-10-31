
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans;

    int n = nums.size();
    int nofbits = (1 << n);

    for (int i = 0; i < nofbits; i++) {
        vector<int> list;

        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                list.push_back(nums[j]);
            }
        }

        ans.push_back(list);
    }

    // Printing all subsets
    for (int i = 0; i < ans.size(); i++) {
        cout << "{ ";

        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }

        cout << "}" << endl;
    }

    return 0;
}
