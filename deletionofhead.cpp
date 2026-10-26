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

ListNode* deleteHead(ListNode*& head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode* temp = head;
    head = head->next;
    delete temp;

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
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);

    cout << "Original Linked List: ";
    printList(head);

    deleteHead(head);

    cout << "After deleting head: ";
    printList(head);

    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}