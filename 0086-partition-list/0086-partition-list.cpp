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
    ListNode* partition(ListNode* head, int x) {
        
       ListNode* dummy1 = new ListNode(-1);
       ListNode* dummy2 = new ListNode(-1);
        
        
        ListNode* curr = head,*sm = dummy1,*lar = dummy2;
        
        while(curr){
            if(curr->val < x){
                sm->next = curr;
                sm = sm->next;
            }
            else{
                lar->next = curr;
                lar = lar->next;
            }
            curr = curr->next;
        }
        lar->next = NULL;
        sm->next = dummy2->next;
        
        return dummy1->next;
    }
};