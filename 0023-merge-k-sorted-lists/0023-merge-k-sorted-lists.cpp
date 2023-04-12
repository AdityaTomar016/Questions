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
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        
       if(l1->val > l2->val){
           swap(l1,l2);
       }
        
        ListNode* res = l1;
        
         while(l1 && l2){
                ListNode* tmp = NULL;
            
                while(l1 && l1->val <= l2->val){
                    tmp = l1;
                    l1 = l1->next;
                }
                tmp->next = l2;
                
                swap(l1,l2);
            }
        
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0){
            return NULL;
        }
        while(lists.size() > 1){
            lists.push_back(merge(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
};