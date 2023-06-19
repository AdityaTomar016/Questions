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
class comp{
  public:
     bool operator()(ListNode* a, ListNode* b){
         return a->val > b->val;
     }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0){
            return NULL;
        }
        
        priority_queue<ListNode*,vector<ListNode*>,comp>pq;
        
        
        for(auto i: lists){
            if(i != NULL)
            pq.push(i);
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        while(!pq.empty()){
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
            
            if(curr->next != NULL){
                pq.push(curr->next);
            }
            
            curr->next = NULL;
        }
        
        return dummy->next;
    }
};
