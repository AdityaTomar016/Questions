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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* l1 = list1, *l2 = list2,*curr = dummy;
        
        while(l1 && l2){
            if(l1->val > l2->val){
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            }
            else{
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            }
        }
        
        while(l1){
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        }
        
        while(l2){
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
        
        return dummy->next;
    }
};