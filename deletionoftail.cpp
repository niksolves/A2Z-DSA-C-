#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : data(x), next(next) {}
};

ListNode* deleteTail(ListNode*& head) {
    if (head == nullptr) {
        return nullptr;
    }

    // If there is only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return head;
    }

    ListNode* temp = head;

    // Reach the second-last node
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    // Delete the last node
    delete temp->next;
    temp->next = nullptr;

    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating linked list: 10 -> 20 -> 30 -> 40
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);

    cout << "Original Linked List: ";
    printList(head);

    head = deleteTail(head);

    cout << "After deleting tail: ";
    printList(head);

    // Free remaining nodes
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}