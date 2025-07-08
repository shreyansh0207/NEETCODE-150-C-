if(Head!= NULL){
    Node* temp = Head;
    Head = Head->next;
    delete temp; // Free the memory of the deleted node
      
}