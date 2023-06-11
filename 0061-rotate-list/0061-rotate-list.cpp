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
        int len=0;
        ListNode* curr = head;
        
        while(curr){
            len++;
            curr = curr->next;
        }
        
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || k == 0) return head;
        
        int len = length(head);
        k = k%len;
        
        ListNode *curr = head;
        
        int diff = len-k;
        
        while(curr->next){
            curr = curr->next;
        }
        curr->next = head;
        curr = curr->next;
        
        while(--diff){
            curr = curr->next;
        }
        
        ListNode* res = curr->next;
        curr->next = NULL;
        
        return res;
    }
};