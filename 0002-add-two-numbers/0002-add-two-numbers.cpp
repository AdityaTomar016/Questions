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
        
        int carry = 0;
        ListNode* res = l1;
        
        while(l1 && l2){
            int num = l1->val + l2->val + carry;
            
            if(num > 9){
                num = num%10;
                carry = 1;
            }
           else{ 
                carry = 0;
            }
            
            curr->next = new ListNode(num);
            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }
        
        while(l1){
            int num = l1->val + carry;
             if(num > 9){
                num = num%10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            
            curr->next = new ListNode(num);
            l1 = l1->next;
            curr = curr->next;
        }
        while(l2){
            int num = l2->val + carry;
             if(num > 9){
                num = num%10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            
            curr->next = new ListNode(num);
            l2 = l2->next;
            curr = curr->next;
        }
        
        if(carry == 1){
            curr->next = new ListNode(1);
        }
        return dummy->next;;
    }
};