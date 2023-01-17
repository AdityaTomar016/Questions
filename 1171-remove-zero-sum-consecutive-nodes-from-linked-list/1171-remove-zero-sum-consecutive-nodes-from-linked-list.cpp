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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        vector<int>arr;
        ListNode *curr = head;
        
        while(curr != NULL){
            arr.push_back(curr->val);
            curr = curr->next;
        }
        
        for(int i=0;i<arr.size();i++){
            
            if(arr[i] == 1e9){
                continue;
            }
            
            int curr_sum=0;
            int stop;
            for(int j=i;j<arr.size();j++){
                curr_sum += arr[j];
                if(curr_sum == 0){
                    stop = j;
                    break;
                }
            }
            
            if(curr_sum == 0){
                for(int j=i;j<=stop;j++){
                    arr[j] = 1e9;
                }
            }
        }
        
        ListNode* dummy = new ListNode(0);
        curr = dummy;
        for(int i=0;i<arr.size();i++){
            if(arr[i] != 1e9){
                curr->next = new ListNode(arr[i]);
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};