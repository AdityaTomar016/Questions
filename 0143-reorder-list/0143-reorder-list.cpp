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
//     ListNode* rev(ListNode* head){
//         ListNode* pre = NULL,*next = NULL;
        
//         while(head != NULL){
//             next = head->next;
//             head->next = pre;
//             pre = head;
//             head = next;
//         }
        
//         return pre;
//     }
    void reorderList(ListNode* head) {
        
        stack<ListNode*>st;
        
        ListNode* curr = head;
        int sz=0;
        
        while(curr){
            st.push(curr);
            sz++;
            curr = curr->next;
        }
        
        sz = sz/2;
        curr = head;
        
        while(sz--){
            ListNode* x = st.top();
            st.pop();
            x->next = curr->next;
            curr->next = x;
            curr = curr->next->next;
        }
        curr->next = NULL;
        
    }
};