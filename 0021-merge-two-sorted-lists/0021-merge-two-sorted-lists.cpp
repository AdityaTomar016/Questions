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
        ListNode* first = list1,*second = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        while(first != NULL && second != NULL){
            if(first->val > second->val){
                curr->next = second;
                curr = curr->next;
                second = second->next;
            }
            else{
                curr->next = first;
                curr = curr->next;
                first = first->next;
            }
        }
        
        while(first != NULL){
            curr->next = first;
            curr = curr->next;
            first = first->next;
        }
        
        while(second != NULL){
            curr->next = second;
            curr = curr->next;
            second = second->next;
        }
        
        return dummy->next;
    }
};