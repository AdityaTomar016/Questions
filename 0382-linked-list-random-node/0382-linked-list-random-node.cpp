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
    int n = 0;
    ListNode* start = NULL;
    
    Solution(ListNode* head) {
        
        start = head;
        
        while(head!=NULL){
            head = head->next;
            n++;
        }
    }
    
    int getRandom() {
        int i = rand() % n;
        ListNode* node = start;
        
        while(i--){
            node = node->next;
        }
        
        return node->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */