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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
    ListNode* reverse(ListNode* head) {
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
        ListNode* mid = middleNode(head);
        mid = reverse(mid);
        
        while(head && mid){
            if(head->val != mid->val){
                return false;
            }
            head = head->next;
            mid = mid->next;
        }
        
        return true;
    }
};