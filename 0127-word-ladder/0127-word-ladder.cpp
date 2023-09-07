class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>dic;
        
        for(auto i: wordList){
            dic.insert(i);
        }
        
       if(dic.find(endWord) == dic.end()) return 0;
        
        int len=1;
        
        queue<string>q;
        q.push(beginWord);
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                string word = q.front();
                q.pop();

                for(int i=0;i<word.size();i++){
                    char og = word[i];

                    for(char c = 'a';c <= 'z'; c++){
                        word[i] = c;

                        if(word == endWord){
                            return len + 1;
                        }

                        if(dic.find(word) != dic.end()){
                            q.push(word);
                            dic.erase(word);
                        }
                    }
                    word[i] = og;
                }
            }
            len++;
        }
        
        return 0;    
    }
};