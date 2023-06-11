/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        
        // making new nodes in between the old nodes
        while(curr){
            Node *temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = curr->next->next;
        }
        
        curr = head;
        // filling the random pointer
        
        while(curr){
            if(curr->random != NULL){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        Node *dummy = new Node(-1);
        Node* temp = dummy,*fast;
        
        curr = head;
        
        while(curr){
            temp->next = curr->next;
            fast = curr->next->next;
            curr->next = fast;
            temp = temp->next;
            curr = fast;
        }
        
        return dummy->next;
    }
};