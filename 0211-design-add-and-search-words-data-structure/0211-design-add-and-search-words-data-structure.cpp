struct Node{
    Node *links[26];
    bool flag=false;
    
    bool contains(char ch){
        return (links[ch-'a'] != NULL);
    }
    void put(char ch){
        Node *node = new Node();
        links[ch-'a'] = node; 
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};
class WordDictionary {
public:
    Node *root;
    
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        
        Node* node = root;
        
        for(int i=0;i<word.size();i++){
            if(!node->contains(word[i])){
                node->put(word[i]);
            }
            
            node = node->get(word[i]);
        }
        
        node->flag = true;
    }
    
    bool search(string word) {
        return searchtrie(word,root);
    }
    
    bool searchtrie(string word,Node* node){
        
        for(int i=0;i<word.size() && node;i++){
            if(word[i] != '.'){
                node = node->get(word[i]);
            }
            else{
                Node* temp = node;
                for(char ch ='a';ch<='z';ch++){
                    node = temp->get(ch);
                    
                    if(searchtrie(word.substr(i+1),node)){
                        return true;
                    }
                }
            }
        }
        
        return node && node->flag;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */