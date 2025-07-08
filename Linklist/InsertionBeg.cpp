#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Initial node
    Node* head = new Node(10); // First node with value 10
    cout << "Initial head data: " << head->data << endl;
    cout << "Initial head next: " << head->next << endl;

    // Insertion at beginning
    int arr[4] = {30, 40, 50, 60};
    for (int i = 0; i < 4; i++) {
        Node* temp = new Node(arr[i]);
        temp->next = head; // Point new node to current head
        head = temp;       // Update head to new node
    }

    // Print final list
    cout << "Final Linked List after insertions at beginning:\n";
    printList(head);

    return 0;
}
