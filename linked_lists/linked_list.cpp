#include <iostream>
using namespace std;

struct Node {
    Node* next;
    int data;

    Node(int d) {
        next = nullptr;
        data = d;
    }
};

class LinkedList {

public:
    Node* head;
    Node* tail;

    int get_head() {
        if (head == nullptr)
            return NULL;
    
        return head->val;
    }

    int get_tail() {
        if (tail == nullptr)
            return NULL;
    
        return tail->val;
    }

    int get(int index) {

    }

    void push_head(int d) {
        Node* new_head = new Node(d);
        new_head->next = head;
        head = new_head;
    }

    void push_tail(int d) {
        Node* new_tail = new Node(d);
        tail->next = new_tail;
        tail = new_tail;
    }

    void delete_head() {
        if (head == nullptr)
            return;

        head = head->next;
    }

    void delete_tail() {
        
    }

    void delete(int index) {

    }

    void push(int index) {

    }

    void print_list() {
        cout << head->data;
        Node* cur = head->next;
        while (cur != nullptr) {
            cout << " -> " << cur->data;
            cur = cur->next;
        }
        cout << endl;
    } 
};

int main() {
    LinkedList* l = new LinkedList(1);
    l->push_to_tail(2);
    l->push_to_tail(3);
    l->push_to_tail(4);
    l->push_to_tail(5);
    l->print_list();
}
