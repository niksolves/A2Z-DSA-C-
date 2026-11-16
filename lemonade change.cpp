
#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {

    int five = 0;
    int ten = 0;
    int n = bills.size();

    for (int i = 0; i < n; i++) {

        if (bills[i] == 5) {
            five++;
        }

        else if (bills[i] == 10) {

            if (five) {
                five = five - 1;
                ten = ten + 1;
            }
            else {
                return false;
            }
        }

        else {

            if (five && ten) {
                ten = ten - 1;
                five = five - 1;
            }

            else if (five >= 3) {
                five = five - 3;
            }

            else {
                return false;
            }
        }
    }

    return true;
}

int main() {

    int n;

    cout << "Enter the number of customers: ";
    cin >> n;

    vector<int> bills(n);

    cout << "Enter the bills received from customers: ";

    for (int i = 0; i < n; i++) {
        cin >> bills[i];
    }

    if (lemonadeChange(bills)) {
        cout << "Change can be provided to every customer!" << endl;
    }
    else {
        cout << "Change cannot be provided to every customer!" << endl;
    }

    return 0;
}
