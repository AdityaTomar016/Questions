struct Node{
    Node *forward;
    Node *back;
    string url;
    
    Node(Node* forward,Node *back, string url){
        this->forward = forward;
        this->back = back;
        this->url = url;
    }
};
class BrowserHistory {
public:
    Node *root;
    
    BrowserHistory(string homepage) {
        root = new Node(NULL,NULL,homepage);
    }
    
    void visit(string url) {
        
        // while(curr->forward != NULL){
        //     curr = curr->forward;
        // }
        
        Node* node = new Node(NULL,root,url);
        root->forward = node;
        root = root->forward;
    }
    
    string back(int steps) {
        
        while(steps-- && root->back != NULL){
            root = root->back;
        }
        
        return root->url;
    }
    
    string forward(int steps) {
        while(steps-- && root->forward != NULL){
            root = root->forward;
        }
        
        return root->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */