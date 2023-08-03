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
    int length(ListNode* node){
        int len = 0;
        while(node){
            len++;
            node = node->next;
        }
        return len;
    }
    ListNode* reverseK(ListNode* head, int k,int len){
        
        if(len < k){
            return head;
        }
        
        ListNode* curr = head, *prev = NULL, *next;
        int temp = k;
        
        while(curr && temp--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        if(next != NULL){
            head->next = reverseK(next,k,len-k);
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k){
        int len = length(head);
        return reverseK(head,k,len);
    }
};