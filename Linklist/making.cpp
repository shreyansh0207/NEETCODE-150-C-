#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

int main(){

    Node* head;
    head = new Node(10);   //creating dynamic memory for the first node
    cout<<head->data<<endl;
    cout<<head->next<<endl;
    return 0;
} 


// Traversing
// Node* temp = head;
// while(temp != NULL){
//     cout<<temp->data<<" ";
//     temp = temp->next;
// }