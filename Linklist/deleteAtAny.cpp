/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 1){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    n--;

    ListNode* curr = head;
    ListNode* prev = NULL;

    while(n--){
        prev = curr;
        curr = curr->next;
    }
    prev->next =  curr->next;
    delete curr;
    return head;
    }
};