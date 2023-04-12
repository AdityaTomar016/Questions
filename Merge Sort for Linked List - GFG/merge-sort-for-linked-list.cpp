//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* merge(Node* l1, Node* l2){
        Node* dummy = new Node(-1);
        Node *curr = dummy;
        
         while(l1 && l2){
            if(l1->data > l2->data){
                curr->next = l2;
                l2 = l2->next;
            }
            else{
                curr->next = l1;
                l1 = l1->next;
            }
            curr = curr->next;
        }
        
        if(l1){
            curr->next = l1;
        }
        
        if(l2){
            curr->next = l2;
        }
        
        return dummy->next;
    }
    Node* mergeSort(Node* head) {
        
        if(!head || !head->next){
            return head;
        }
        Node* slow = head;
        Node* fast = head , *pre;
        
         while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        
        Node *l1 = mergeSort(slow);
        Node *l2 = mergeSort(head);
        
        return merge(l1,l2);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends