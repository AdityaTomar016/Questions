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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next == NULL){
            return NULL;
        }
        int len=0;
        ListNode* curr = head;
        
        while(curr!=NULL){
            len++;
            curr = curr->next;
        }
        
        curr = head;

        int temp=len/2;
        
        while(--temp){
            curr = curr->next;
        }
        
        curr->next = curr->next->next;
        
        return head;
    }
};