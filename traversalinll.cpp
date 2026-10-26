#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

vector<int> LLTraversal(ListNode* head) {
    vector<int> ans;
    ListNode* temp = head;

    while (temp != nullptr) {
        ans.push_back(temp->val);
        temp = temp->next;
    }

    return ans;
}

int main() {
    // Creating linked list: 10 -> 20 -> 30 -> 40
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);

    vector<int> ans = LLTraversal(head);

    cout << "Linked List Traversal: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    // Freeing allocated memory
    ListNode* temp = head;
    while (temp != nullptr) {
        ListNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}