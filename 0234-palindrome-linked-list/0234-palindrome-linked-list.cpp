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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL, *nextptr,*curr = head;
        
        while(curr != NULL){
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* curr=dummy, *temp = head;
        
        while(temp){
            curr->next = new ListNode(temp->val);
            temp = temp->next;
            curr = curr->next;
        }
        
        curr = reverse(dummy->next);
   
        while(head && curr){
            if(head->val != curr->val){
                return false;
            }
            head = head->next;
            curr = curr->next;
        }
        
        return true;
    }
};