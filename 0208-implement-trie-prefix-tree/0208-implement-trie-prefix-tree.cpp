struct Node{
    Node *links[26];
    bool flag=false;
    
    bool alreadyexists(char ch){
        return (links[ch-'a'] != NULL);
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};
class Trie {
public:
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        
        Node* curr = root;
        for(int i=0;i<word.size();i++){
            if(!curr->alreadyexists(word[i])){
                curr->put(word[i],new Node());
            }
            
            curr = curr->get(word[i]);
        }
        
        curr->flag = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0;i<word.size();i++){
            if(!curr->alreadyexists(word[i])){
                return false;
            }
            
            curr = curr->get(word[i]);
        }
        
        return curr->flag;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0;i<prefix.size();i++){
            if(!curr->alreadyexists(prefix[i])){
                return false;
            }
            
            curr = curr->get(prefix[i]);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */