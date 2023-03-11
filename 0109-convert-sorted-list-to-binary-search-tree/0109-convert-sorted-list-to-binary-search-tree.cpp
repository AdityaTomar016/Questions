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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* maketree(int low,int high,vector<int>inorder){
        
        if(low >= high){
            return NULL;
        }
        
        int mid = (low+high)/2;
        
        TreeNode* root = new TreeNode(inorder[mid]);
        
        root->left = maketree(low,mid,inorder);
        root->right = maketree(mid+1,high,inorder);
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>inorder;
        
        while(head!=NULL){
            inorder.push_back(head->val);
            head = head->next;
        }
        
        return maketree(0,inorder.size(),inorder);
    }
};