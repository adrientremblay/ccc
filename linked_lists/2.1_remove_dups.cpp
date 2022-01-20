#include <iostream>

using namespace std;

/**
Remove Dups: Write code to remove duplicates from an unstorted linked list. FOLLOW UP. How would you solve this problem
if a temporary buffer is not allowed?
**/

struct Node {
    int data;
    struct Node* next;
};

/**
Utility method. Constructs a linked list from an array.
**/
Node construct(int[] arr) {
    Node head;
    
    if (sizeof(arr) == 0)
        return head;

    head.data = arr[0]

    Node cur = head;
    for (int i = 1 ; i < sizeof(arr) ; i++) {
        cur->next = new Node;
        cur->next
        cur.
    } 

    return head;
}

int main() {
    int[] arr = {1, 2, 3, 4, 5};
    Node head = construct(arr); 
}
