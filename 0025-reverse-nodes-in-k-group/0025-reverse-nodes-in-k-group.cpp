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
        
        while(curr != NULL){
            len++;
            curr = curr->next;
        }
        
        return len;
    }
    ListNode* reverse(ListNode* head,int k,int len){
        
        ListNode* curr = head, *prev = NULL, *nextptr;
        
        if(len >= k){
            
            int count=0;
            while(curr != NULL && count < k){
                nextptr = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextptr;
                count++;
            }
            
            if(nextptr != NULL){
                head->next = reverse(nextptr,k,len-k);
            }
            
            return prev;
        }
        
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = length(head);
        
        return reverse(head,k,len);      
    }
};