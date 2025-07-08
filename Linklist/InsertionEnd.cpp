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
    Node* head = NULL;

    // Inserting initial node
    head = new Node(10);

    // Insertion at the end
    int arr[4] = {30, 40, 50, 60};
    for (int i = 0; i < 4; i++) {
        Node* newNode = new Node(arr[i]);

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;  // move to last node
        }
        temp->next = newNode;  // attach new node at the end
    }

    // Print final list
    cout << "Linked List after insertion at end:\n";
    printList(head);

    return 0;
}
