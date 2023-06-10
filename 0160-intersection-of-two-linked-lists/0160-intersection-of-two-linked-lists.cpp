/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head){
        ListNode* curr = head;
        int len = 0;
        
        while(curr != NULL){
            curr = curr->next;
            len++;
        }
        
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lenA = length(headA);
        int lenB = length(headB);
        
        int diff = abs(lenB-lenA);
        
        if(lenA > lenB){
            while(headA && diff--){
            
                if(headB == headA){
                    return headB;
                }
                headA = headA->next;
            }
        }
        else{
            while(headB && diff--){
            
                if(headB == headA){
                    return headB;
                }
                headB = headB->next;
            }
        }
        
        
        
        
        while(headA && headB){
            
            if(headA == headB){
                return headB;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};