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

    // GET METHODS

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
        int count = 0;
        Node* cur = head;
        
        while (count < index) {
            count++;
            cur = cur->next;            
        }

        return cur->value;
    }

    // PUSH METHODS

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

    void push(int index, int val) {
        if (index == 0)
            push_head(val);

        // continue here
    }

    // DELETE METHODS

    void delete_head() {
        if (head == nullptr)
            return;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }

        head = head->next;
    }

    void delete_tail() {
        if (tail == nullptr)
            return;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }

        Node* cur = head; 
        while (cur->next != tail) {
            cur = cur->next; 
        }

        cur->next = nullptr;
        tail = cur;
    }

    void delete(int index) {
        if (index == 0)
            delete_head();

        int count = 0;
        Node* cur = head;
        while (count < index - 1) {
            count++;
            cur = cur->next;
        }

        if (cur->next == tail)
            delete_tail();

        cur->next = cur->next->next; 
    }


    // UTILITY METHODS

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
