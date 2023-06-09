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
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        curr->next = head;
        
        ListNode* slow = curr, *fast = curr;
        
       for(int i=0;i<n && fast;i++){
           fast = fast->next;
       }
        
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        
        if(slow->next)
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};