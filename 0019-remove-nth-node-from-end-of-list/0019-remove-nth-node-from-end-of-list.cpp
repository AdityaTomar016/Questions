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
        int len=0;
        ListNode* curr = head;
        
        while(curr){
            len++;
            curr = curr->next;
        }
        
        curr = head;
        len = len-n;
        
        if(len == 0){
            return head->next;
        }
        
        while(curr && --len){
            curr = curr->next;
        }
        
        if(curr && curr->next){
            curr->next = curr->next->next;
        }
    
        return head;
    }
};