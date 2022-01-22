#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;

    Node(int d) {
        next = nullptr;
        data = d;
    }

    void appendToTail(int d) {
        Node* end = new Node(d);
        Node* n = this;
        while (n->next != nullptr) {
            cout << n->data << endl;
            n = n->next;
        }
        n->next = end;
    }
};

int main() {
    Node* head = new Node(0);
    head->appendToTail(1);
    head->appendToTail(2);
    head->appendToTail(3);

    cout << "printing link list:" << endl;
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->data << endl;
        cur = cur->next;
    }

}
