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
    int getDecimalValue(ListNode* head) {
        ListNode* curr = head;
        int len = 0;
        while(curr->next != NULL){
            curr = curr->next;
            len++;
        }
        
        curr = head;
        int ans = 0;
        
        while(curr != NULL){
            if(curr->val == 1){
                ans += pow(2,len--);
            }
            else len--;
            curr = curr->next;
        }
        
        return ans;
    }
};