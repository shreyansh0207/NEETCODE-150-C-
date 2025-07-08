//We have to make Two pointer because we need to track the previous node and the last node
//previous node = currrent node - 1;(end node)

Node* temp = Head;
Node* prev = NULL;

while(temp->next != NULL){
    prev= temp;
    temp = temp->next; // Move to the next node
}
delete temp;
prev->next= NULL;