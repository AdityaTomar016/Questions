/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        Node* curr = head,*store,*runner;
        
        while(curr){
            if(curr->child){
                store = curr->next;
                runner = curr->child;
                curr->next = curr->child;
                curr->child = NULL;
                curr->next->prev = curr;
                
                while(runner->next){
                    runner = runner->next;
                }
                
                runner->next = store;
                
                if(runner->next){
                    runner->next->prev = runner;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};