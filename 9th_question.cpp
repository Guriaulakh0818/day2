#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseInGroups(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* current = head;
    Node* prevTail = nullptr;
    Node* newHead = nullptr;

    while (current) {
        Node* groupHead = current;
        Node* prev = nullptr;
        int count = 0;

        while (current && count < k) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
            count++;
        }

        if (!newHead) newHead = prev;
        if (prevTail) prevTail->next = prev;

        prevTail = groupHead;
    }

    if (prevTail) prevTail->next = nullptr;

    return newHead;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 3;
    head = reverseInGroups(head, k);
    printList(head);

    return 0;
}
