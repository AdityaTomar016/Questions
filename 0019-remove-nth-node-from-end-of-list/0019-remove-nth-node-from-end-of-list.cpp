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
    int length(ListNode* head){
        ListNode* curr = head;
        int len = 0;
        
        while(curr!=NULL){
            curr = curr->next;
            len++;
        }
        
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        
        int len = length(curr);
        len = len-n;
        
        if(len == 0) return head->next;
        
        while(curr != NULL && --len){
            curr = curr->next;
        }
        
        if(curr && curr->next){
            curr->next = curr->next->next;
        }
        
        return head;
    }
};