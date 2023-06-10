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
   ListNode* rev(ListNode* head){
        ListNode* pre = NULL,*nxt = NULL;
        
        while(head != NULL){
            nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head, *fast=head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = rev(slow->next);
        slow = slow->next;
        
        while(slow){
            if(head->val != slow->val){
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};