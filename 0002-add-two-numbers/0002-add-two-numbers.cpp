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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        int carry=0;
        
        while(l1!=NULL && l2!=NULL){
            int sum = l1->val + l2->val + carry;
            
            if(sum > 9){
                carry = 1;
            }
            else carry = 0;
            
            curr->next = new ListNode(sum%10);
            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }
        
        while(l1!=NULL){
            int sum = l1->val + carry;
            
            if(sum > 9){
                carry = 1;
            }
            else carry = 0;
            
            curr->next = new ListNode(sum%10);
            l1 = l1->next;
            curr = curr->next;
        }
        while(l2!=NULL){
            int sum = l2->val + carry;
            
            if(sum > 9){
                carry = 1;
            }
            else carry = 0;
            
            curr->next = new ListNode(sum%10);
            l2 = l2->next;
            curr = curr->next;
        }
        
        if(carry == 1){
            curr->next = new ListNode(carry);
        }
        return dummy->next;
    }
};